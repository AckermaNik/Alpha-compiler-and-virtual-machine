# Alpha Compiler and Virtual Machine

This project implements a complete compiler toolchain for the Alpha programming language. It covers the full path from source text to executable bytecode:

~~~text
Alpha source file
        │
        ▼
Flex lexer
        │ tokens
        ▼
Bison parser and semantic actions
        │ symbol table and quadruples
        ▼
Target-code generator
        │ Alpha VM instructions and constant tables
        ▼
Binary bytecode file: output.ax
        │
        ▼
Alpha Virtual Machine
        │
        ▼
Program execution
~~~

The compiler is written in C and uses Flex and Bison for the frontend. The generated target code is executed by a custom Alpha Virtual Machine (AVM).

## What the project implements

The compiler supports a dynamically typed language with:

- Numeric, string, boolean, and nil values
- Variables, local variables, formal parameters, and global-variable access
- Arithmetic and comparison expressions
- Boolean expressions with and, or, and not
- Assignment and increment/decrement operators
- if/else, while, and for statements
- break and continue
- Named and anonymous functions
- Function parameters, return values, and recursion
- Tables with array-style and key-value initialization
- Table indexing and member access
- Method-style calls using the .. operator
- Built-in library functions
- Lexical and syntax diagnostics
- Intermediate quadruple generation
- Alpha VM bytecode generation
- Binary bytecode loading and execution

## Repository layout

~~~text
Final_Project/
├── Makefile
├── README.md
├── .vscode/
├── build/
│   ├── avm
│   ├── out
│   ├── output.ax
│   ├── run.sh
│   └── runvm.sh
├── src/
│   ├── bison/
│   │   ├── parser.y
│   │   ├── parser.c
│   │   └── parser.h
│   └── flex/
│       ├── scanner.l
│       └── al.c
├── test_files/
│   └── bisontest
└── utils/
    ├── alpha_bison_utilities.h
    ├── alpha_definitions.h
    ├── alpha_general_types.h
    ├── alpha_general_utilities.c
    ├── alpha_general_utilities.h
    ├── alpha_stack.h
    ├── alpha_target_utilities.h
    ├── alpha_utilities.h
    ├── alpha_vm.c
    ├── alpha_vm_utilities.c
    └── alpha_vm_utilities.h
~~~

## Compiler pipeline

### 1. Lexical analysis

src/flex/scanner.l defines the lexical rules of Alpha. Flex converts these rules into the generated scanner src/flex/al.c.

The scanner:

- Recognizes reserved words such as if, else, while, for, and function
- Recognizes return, break, continue, local, true, false, and nil
- Recognizes built-in library names such as print, typeof, and sqrt
- Recognizes identifiers
- Recognizes integer and real numeric literals
- Recognizes strings and translates supported escape sequences
- Recognizes arithmetic, comparison, assignment, punctuation, and member-access operators
- Tracks source line numbers using Flex's yylineno support
- Records token numbers for lexer output
- Detects undefined characters
- Detects unclosed strings
- Detects unclosed multiline comments

The lexer supports line comments beginning with //. Multiline comments begin with /* and are processed by parseMultilineComment(). The implementation also tracks nested multiline comment delimiters.

String processing is implemented by find_special_chars(). Supported escapes include newline, tab, backslash, and quotation marks. The scanner forwards token values through the Bison semantic-value structure declared in parser.h.

### 2. Parsing and semantic actions

src/bison/parser.y is the main frontend source file. It contains both the grammar and the C semantic actions executed when grammar rules reduce.

Bison converts it into:

- src/bison/parser.c: generated shift/reduce parser implementation
- src/bison/parser.h: generated token declarations and YYSTYPE definition

The grammar defines operator precedence and associativity for assignments, boolean operators, comparisons, arithmetic, unary operators, member access, indexing, and calls. Semantic actions do substantially more than validate syntax: they create expression objects, update the symbol table, emit intermediate quads, maintain scope information, and prepare control-flow backpatching.

### 3. Symbol-table management

The parser creates and maintains a scoped symbol table while it parses the program. Symbols represent:

- Global variables
- Local variables
- Formal function arguments
- User-defined functions
- Built-in library functions
- Compiler-generated temporary variables

The parser tracks scope depth, function-local offsets, formal-argument offsets, global offsets, loop nesting, and whether a return appears inside a function.

The following forms have different scope behavior:

~~~alpha
x = 10;          // ordinary identifier lookup/assignment
local y = 20;    // local declaration
::x = 30;        // explicit global access
~~~

Function entry and exit create and invalidate scopes. The compiler assigns offsets to variables so that target instructions can later address globals, locals, and formal arguments in the AVM stack frame.

### 4. Intermediate representation

The compiler emits quadruples while reducing grammar rules. A quad contains:

- An intermediate opcode
- Up to two source expressions
- A result expression
- A branch label when applicable
- The source line and quad line
- A target-code address assigned during lowering

The intermediate opcode set includes:

| Intermediate opcode | Purpose |
| --- | --- |
| assign_i | Copy a value into a destination |
| add_i, sub_i, mul_i, div_i, mod_i | Arithmetic |
| uminus_i | Unary negation |
| jump_i | Unconditional branch |
| if_eq_i, if_noteq_i | Equality branches |
| if_lesseq_i, if_greatereq_i | Inclusive comparison branches |
| if_less_i, if_greater_i | Strict comparison branches |
| call_i | Function or library call |
| param_i | Push an argument |
| funcstart_i, funcend_i | Function boundaries |
| tablecreate_i | Create a table |
| tablegetelem_i | Read a table element |
| tablesetelem_i | Write a table element |
| getretval_i | Read the return register |
| ret_i | Return from a function |

Boolean expressions are represented with true and false backpatch lists. Control-flow instructions are emitted with unresolved labels and patched after the target location becomes known. This is used for:

- if and else branches
- while loops
- for loops
- Short-circuit and and or
- break and continue
- Function returns

### 5. Target-code generation

utils/alpha_target_utilities.h lowers intermediate quads to Alpha VM instructions.

The generator maintains constant and function tables for:

- Numeric constants
- String constants
- User functions
- Referenced library functions

It converts compiler expressions into VM arguments with types such as:

- global_a
- formal_a
- local_a
- number_a
- string_a
- bool_a
- nil_a
- userfunc_a
- libfunc_a
- retval_a
- label_a

The target instruction set contains assignments, arithmetic, jumps, comparisons, calls, argument pushes, function entry/exit, table operations, and no-op instructions.

Function return jumps and forward branches are handled through return lists and incomplete-jump lists. Once all quads have been translated, unresolved targets are patched with their final instruction addresses.

### 6. Binary output

The compiler serializes the generated program with generateBinaryFile() into output.ax.

The binary format is written in this order:

1. Number-constant table length
2. Number constants
3. String-constant table length
4. String lengths and string bytes
5. User-function table length
6. User-function addresses, local sizes, and names
7. Library-function table length
8. Library-function names
9. Number of global variables
10. Instruction count
11. Serialized bytecode instructions

The VM reads the same structure in loadBinaryFile(). The compiler and VM therefore share the data structures in alpha_general_types.h and must agree on opcode, argument, and serialized-table layouts.

## Alpha language features

### Values and constants

The grammar supports:

~~~alpha
42;
3.14;
"hello";
true;
false;
nil;
~~~

Numbers are represented internally as double values. Strings are stored in the compiler's string constant table and later loaded into VM string memory cells.

### Arithmetic and assignment

Supported arithmetic operators are:

~~~text
+ - * / %
~~~

Unary minus is supported through the UMINUS precedence rule. Assignment is right-associative. Postfix and prefix increment/decrement are also handled:

~~~alpha
x++;
++x;
x--;
--x;
~~~

The parser emits temporary variables for intermediate results. Temporary reuse is managed by the frontend utility functions to reduce unnecessary local/global slots.

### Boolean expressions

Supported operators include:

~~~text
== != > < >= <=
and or not
~~~

Comparisons are translated into conditional branches followed by backpatching. Boolean values used as ordinary expressions are materialized into temporary variables by assigning true or false after their branch lists have been resolved.

### Control flow

The grammar supports:

~~~alpha
if (condition) statement
if (condition) statement else statement

while (condition) statement

for (initialization; condition; update) statement

break;
continue;
~~~

The parser keeps a loop counter so that break and continue outside loops can be reported. Loop control-flow lists are merged and patched when the complete loop construct is reduced.

### Functions

Alpha supports named functions, anonymous functions, parameters, returns, and recursion:

~~~alpha
function fib(n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
~~~

Function definitions emit funcstart_i and funcend_i quads. Function-local and formal-argument offsets are tracked separately. Calls emit parameter and call quads, followed by a getretval_i quad when a result is required.

Anonymous functions receive compiler-generated names such as $1, $2, and so on.

### Tables and member access

Tables can be created with array-style values:

~~~alpha
values = [10, 20, 30];
~~~

They can also be initialized with explicit key-value pairs:

~~~alpha
person = [
    {"name": "Nikoleta"},
    {"age": 24}
];
~~~

The grammar supports both dot access and bracket indexing:

~~~alpha
person.name;
person["age"];
~~~

The .. operator implements method-style calls. The receiver is passed as an implicit first argument:

~~~alpha
list..append(value);
~~~

The compiler represents table access with tableitem_e, emits tablegetelem_i for reads, and replaces unnecessary read quads with tablesetelem_i when a table member is assigned.

### Built-in library functions

The lexer recognizes the following library names:

~~~text
print
input
objectmemberkeys
objecttotalmembers
objectcopy
totalarguments
argument
typeof
strtonum
sqrt
cos
sin
~~~

The compiler preloads these names into the global symbol table and records referenced library functions in the target constant table.

The current AVM runtime directly implements:

- print
- typeof
- totalarguments
- argument

The other names are recognized by the frontend but are not registered by avm_getlibraryfunc() in the current runtime implementation. Calling one of them may therefore produce an unsupported-library-function runtime error.

## File-by-file documentation

### Root files

#### Makefile

The Makefile is the main build description.

The default target builds the compiler executable at build/out. It:

1. Creates build/ when necessary.
2. Runs Flex on src/flex/scanner.l to generate src/flex/al.c.
3. Runs Bison on src/bison/parser.y to generate src/bison/parser.c and src/bison/parser.h.
4. Compiles the generated scanner, generated parser, and alpha_general_utilities.c.
5. Links the compiler with the math library using -lm.

The avm target builds build/avm from:

- utils/alpha_vm.c
- utils/alpha_vm_utilities.c
- utils/alpha_general_utilities.c

The Makefile uses GCC with debug symbols and adds utils/ to the include path. The clean target removes the entire build/ directory, including the helper scripts stored there.

#### README.md

This document explains the language, compiler pipeline, runtime, source files, build process, and generated artifacts.

### Frontend source files

#### src/flex/scanner.l

The hand-written Flex specification for Alpha's lexer. It defines regular expressions and actions for tokens, comments, strings, identifiers, numbers, operators, and punctuation. It also reports lexical information to yyout and passes semantic values to the parser.

#### src/flex/al.c

The generated C scanner produced from scanner.l. It contains Flex's state-machine implementation and the compiled lexical rules. scanner.l is the source of truth; al.c should normally be regenerated rather than edited manually.

#### src/bison/parser.y

The hand-written Bison grammar and the most important compiler frontend source file. It defines tokens, precedence, grammar productions, semantic actions, symbol-table interactions, quad emission, backpatching, error checks, and the compiler executable's main() function.

#### src/bison/parser.c

The generated Bison parser implementation. It contains the shift/reduce parsing tables and the C code generated from the grammar actions in parser.y. It is compiled into build/out.

#### src/bison/parser.h

The generated Bison interface. It declares the token enumeration, the semantic-value union YYSTYPE, and the yyparse() interface consumed by the scanner and parser build.

### Shared compiler utilities

#### utils/alpha_definitions.h

Central compile-time definitions and diagnostics. It defines:

- Debug and error switches
- VM stack and hash-table sizes
- Stack-frame offsets
- VM instruction limits
- Assertion and logging macros
- Compiler and VM error-reporting macros
- Optional colored diagnostics

The file also defines aliases that map related VM operations to shared implementations, such as arithmetic and comparison handlers.

#### utils/alpha_general_types.h

Shared low-level target-code types. It declares:

- VM opcodes
- VM argument types
- vmarg
- instruction
- userFunc
- Function return lists

Both the target generator and the AVM depend on these definitions, so their enum ordering and structure layouts must remain compatible.

#### utils/alpha_general_utilities.h

Declarations for general-purpose helpers:

- Safe memory allocation
- String equality
- Integer and floating-point conversion to strings
- Numeric-integrality checks

#### utils/alpha_general_utilities.c

Implementations of the helpers declared in alpha_general_utilities.h. safe_malloc() terminates with an error if allocation fails, while the conversion functions are used for temporary names, expression printing, and diagnostics.

#### utils/alpha_stack.h

Header-only integer stack implementation used by the compiler. It provides the stack data structure and operations needed for:

- Scope bookkeeping
- Loop state
- Function nesting
- Formal-argument offsets
- Local-variable offsets
- Function jump patching

#### utils/alpha_utilities.h

Lexer-oriented support utilities. It defines the token-list node and list structures used for token tracking and multiline-comment processing. It also provides token construction, insertion, unlinking, ordered insertion, list traversal, and debug printing.

The lexer uses this support to preserve comment information and print token metadata such as source line, token number, category, and type.

### Parser and intermediate-code utilities

#### utils/alpha_bison_utilities.h

The main support library for the Bison parser. Although it has a header extension, it contains substantial implementation code and global compiler state. It provides:

- Symbol-table data structures and hash-table operations
- Variable and function symbol constructors
- Scope lookup, insertion, invalidation, and shadowing behavior
- Expression constructors and expression-type helpers
- Temporary-variable generation and reuse
- Quad and opcode definitions
- Quad allocation and emission
- Quad printing
- Arithmetic, boolean, and table-expression support
- Break/continue list construction and merging
- Boolean-expression backpatching
- Scope and offset management
- Function-stack management
- Library-function registration

The parser includes this file to execute semantic actions while reducing grammar productions.

Important frontend structures include:

- SymbolTableEntry_t: a variable or function symbol
- SymbolTable_t: the hash table containing symbols
- expr: an intermediate expression object
- quad: an intermediate instruction
- Function_t: function metadata such as scope, argument count, local count, and return locations

#### utils/alpha_target_utilities.h

The target-code-generation library. It consumes quads and produces VM instructions. It owns the constant tables, user-function table, library-function table, incomplete-jump list, instruction buffer, operand conversion, generator dispatch table, and binary serializer.

The generateTcode() function dispatches each intermediate opcode to a specialized generator. make_operand() converts frontend expressions into VM arguments, while generateBinaryFile() writes the complete bytecode file consumed by the AVM.

### Virtual machine files

#### utils/alpha_vm_utilities.h

The AVM public interface and runtime data model. It declares:

- VM execution handlers
- Binary-file loading
- Stack initialization
- Operand translation
- Library-function interfaces
- Memory-cell cleanup functions
- Runtime globals
- AVM memory-cell types
- Hash-table and table structures

An avm_memcell can hold a number, string, boolean, table, user function, library function, nil, or undef value.

#### utils/alpha_vm_utilities.c

The main AVM runtime implementation. It provides:

- The program stack and return register
- Program-counter and execution-state management
- Arithmetic execution
- Equality and inequality execution
- Numeric comparisons
- Unconditional jumps
- Assignments
- Function calls and stack-frame entry/exit
- Argument passing
- Table creation, lookup, and update
- Reference counting for tables
- Memory-cell cleanup
- Runtime conversions to boolean and string
- Library-function dispatch
- Binary bytecode loading
- The fetch/decode/execute cycle

The runtime uses an operand-translation layer to map compiler-level operands to stack locations, constants, the return register, functions, or library functions.

#### utils/alpha_vm.c

The AVM executable entry point. It accepts one binary bytecode path, loads it with loadBinaryFile(), initializes the stack, calculates the initial stack position after global allocation, and repeatedly calls execute_cycle() until execution finishes.

### Generated and runtime artifacts

#### build/out

The compiled Alpha compiler executable. It accepts an Alpha source file and optionally a lexer-output file:

~~~text
out <source-file> [token-output-file]
~~~

The compiler prints symbol-table, quad, and target-instruction information to standard output. It writes the final binary as output.ax in its current working directory.

#### build/avm

The compiled Alpha Virtual Machine executable. It accepts one Alpha bytecode file:

~~~text
avm <bytecode-file>
~~~

#### build/output.ax

A previously generated Alpha binary output file. It is a build artifact, not a source file. Its contents are binary and should be executed through the AVM rather than opened as text.

#### build/run.sh

A convenience script intended to be run from inside build/. It removes and rebuilds the compiler, returns to the build directory, and runs out with the provided arguments.

Example:

~~~bash
cd build
./run.sh ../test_files/bisontest
~~~

Because the script uses POSIX shell commands, use a Unix-like shell such as Linux, WSL, or Git Bash.

#### build/runvm.sh

A convenience script intended to be run from inside build/. It rebuilds the AVM and executes it with the provided bytecode path.

Example:

~~~bash
cd build
./runvm.sh output.ax
~~~

#### test_files/bisontest

A broad Alpha-language test program. It exercises:

- Arrays and tables
- Named and anonymous functions
- Recursion
- Member access
- Method calls
- if/else
- while and for
- break and continue
- typeof
- Table-linked-list behavior

It is useful as an integration test because it passes through the lexer, parser, symbol table, quad generator, target generator, binary serializer, and AVM runtime.

### Editor configuration

#### .vscode/c_cpp_properties.json

Visual Studio Code C/C++ IntelliSense configuration. It points IntelliSense at the workspace and specifies a GCC toolchain.

#### .vscode/launch.json

Visual Studio Code debugger configuration generated for local development. It contains machine-specific Windows paths and should be adjusted if the project is opened on another computer.

#### .vscode/settings.json

Editor settings for C/C++ file associations, compiler and debugger commands, warning flags, include search paths, and excluded build directories.

## Building the project

### Required tools

The build expects:

- GCC
- GNU Make
- Flex
- Bison
- The standard C library
- The math library used through -lm
- A POSIX-compatible shell for the helper scripts

On Debian or Ubuntu-based systems, the usual packages are:

~~~bash
sudo apt install build-essential flex bison
~~~

### Build the compiler

From the project root:

~~~bash
make
~~~

This generates or refreshes the Flex/Bison C files and produces build/out.

### Build the virtual machine

From the project root:

~~~bash
make avm
~~~

This produces build/avm.

### Compile an Alpha program

From the project root:

~~~bash
./build/out ./test_files/bisontest
~~~

The compiler generates output.ax in the current working directory and prints diagnostic/intermediate information to standard output.

To send the lexer output to a file as well:

~~~bash
./build/out ./test_files/bisontest ./build/tokens.log
~~~

The optional second argument is the scanner output destination. It is not the bytecode destination.

### Execute generated bytecode

If the compiler was run from the project root:

~~~bash
./build/avm ./output.ax
~~~

If the compiler was run through build/run.sh, the binary is normally created in build/ because that is the script's working directory:

~~~bash
cd build
./run.sh ../test_files/bisontest
./runvm.sh output.ax
~~~

## Diagnostics and error handling

The project uses compile-time switches in alpha_definitions.h to control assertions, logging, compiler errors, user errors, AVM errors, warnings, and colored output.

Examples of errors handled by the implementation include:

- Undefined lexical tokens
- Unclosed strings
- Unclosed multiline comments
- Invalid expression types
- return outside a function
- break or continue outside a loop
- Division or modulo by zero
- Invalid table operations
- Invalid function calls
- Unsupported library functions
- Corrupt binary files
- Stack overflow and invalid stack operations

The parser sets the shared error_found flag for user-level compilation errors. Code generation is only continued when compilation succeeds.

## Design notes

### Why the project has both source and generated frontend files

scanner.l and parser.y are the maintainable frontend sources. al.c, parser.c, and parser.h are generated artifacts that make the project buildable without regenerating the frontend immediately. If the grammar or lexer rules change, regenerate the generated files through make.

### Why quads are used

Quads provide a convenient representation between parsing and machine-specific code generation. They make expression evaluation, branches, function calls, table operations, and backpatching explicit before the final VM instruction format is chosen.

### Why the VM uses constant tables

Numbers, strings, user functions, and library functions are stored in indexed tables. Instructions then use compact indexes rather than embedding complete values repeatedly. The same indexes are reconstructed when the AVM loads output.ax.

### Function-call model

The AVM uses a stack-based calling convention. It records actual-argument counts and saved execution values, including the return program counter, the previous stack-top information, and the previous frame pointer. funcenter_v establishes a function frame, while funcexit_v restores the caller's state.

### Table implementation

Tables use separate hash buckets for string and numeric indexes. Table values are reference-counted, and table entries are cleaned when their owning memory cells are cleared. This supports both array-like numeric indexing and object-like string indexing.

## Project status

This is an academic compiler-construction project for the HY-340 course. It contains a complete educational pipeline from source code to executable virtual-machine bytecode, including a lexer, parser, semantic frontend, intermediate representation, target-code generator, binary format, and runtime. The implementation is intended for learning and experimentation rather than production use.

