#Place in the ./build directory and run 
#(the executable will be compiled automatically)
rm ./out
cd ..
make -B
cd build
./out "$@"