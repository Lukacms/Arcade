rm -rf build
mkdir build ; cd build

if [ "$1" = "--gcc" ]; then
    cmake .. -DCMAKE_BUILD_TYPE=Build -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_EXPORT_COMPILE_COMMANDS=true
    cmake --build .
    cd ..
elif [ "$1" = "--ninja" ]; then
    cmake .. -GNinja -DCMAKE_BUILD_TYPE=Build -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=true
    ninja
    cd ..
elif [ "$1" = "--debug" ]; then
    cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_EXPORT_COMPILE_COMMANDS=true
    cmake --build .
    cd ..
else
    echo "argument required: --gcc, --ninja or --debug"
fi
