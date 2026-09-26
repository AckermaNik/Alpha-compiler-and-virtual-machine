#Place in the ./build directory and run 
#(the executable will be compiled automatically)
rm ./avm
cd ..
make avm -B
cd build
./avm "$@"