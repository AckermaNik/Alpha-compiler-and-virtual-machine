# Makefile
# 
# @author Dimitris Segkesser, A.M.: 5006
#
# @date 25/2/2024
#
# This is the makefile of the 1st phase of the
# project for the course HY-340,
# spring semester 2024.
# 
# Implementation of a lexical analyzer for the
# 'alpha' programming language.
# 
# Computer Science Department, Heraklion, Crete, Greece

# **Usage: make/make all**
# Uses flex to produce scanner.c from scanner.l and compiles it,
# placing it under the ./build directory (created if not present).

#To compile the avm (virtual machine) use 'make avm'

SRC_DIR = ./src
BUILD_DIR = ./build
FLEX_DIR = flex
BISON_DIR = bison
UTILS_DIR = ./utils

CC = gcc -g 
CFLAGS = -I$(UTILS_DIR) #-fsanitize=address # -Wfatal-errors 
#-I is a compiler flag that specifies an additional include directory for the compiler to look for header files (.h files).

LEX = flex
BISON = bison
BISON_FLAGS = --yacc --defines# -Wcounterexamples

all: $(BUILD_DIR)/out | $(BUILD_DIR)

$(BUILD_DIR)/out: $(SRC_DIR)/$(FLEX_DIR)/al.c $(SRC_DIR)/$(BISON_DIR)/parser.c $(UTILS_DIR)/alpha_general_utilities.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(SRC_DIR)/$(FLEX_DIR)/al.c: $(SRC_DIR)/$(FLEX_DIR)/scanner.l | $(BUILD_DIR)
	$(LEX) -o $@ $<

$(SRC_DIR)/$(BISON_DIR)/parser.c: $(SRC_DIR)/$(BISON_DIR)/parser.y | $(BUILD_DIR)
	$(BISON) $(BISON_FLAGS) --output=$@ $<

# Ensure the build directory exists.
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#Target for the avm (virtual machine)
avm: $(UTILS_DIR)/alpha_vm_utilities.c $(UTILS_DIR)/alpha_vm.c $(UTILS_DIR)/alpha_general_utilities.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)/avm -lm

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
