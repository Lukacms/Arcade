# Arcade - Compilation
The build system

## Description
The project is built using [`CMake`](https://cmake.org/). You can learn how to use it with the [official tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html).

You can build the project with g++ or clangd, depending of the options. We've made a `compile.sh` file to make the task easier. The differents options are:
* `./compile.sh --gcc` to compile project with the `-fno-gnu-unique` flag needed to correctly close shared libraries:
```sh
    cmake .. -DCMAKE_BUILD_TYPE=Build -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_EXPORT_COMPILE_COMMANDS=true
    cmake --build .
```
* `./compile.sh --debug` to compile with g++ and the debug flags:
```sh
    cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_EXPORT_COMPILE_COMMANDS=true
    cmake --build .
```
* `./compile.sh --ninja` to compile with clangd and ninja. It is useful for clang-based [LSP](https://en.wikipedia.org/wiki/Language_Server_Protocol):
```sh
    cmake .. -GNinja -DCMAKE_BUILD_TYPE=Build -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=true
    ninja
```
It will put all the files generated by the compilation in a `build` directory.

## How to add a new CMakeFile to compile a shared library ?
To compile a sub CMakeFile (equivalent to `make -C [path]`) for Makefile, you can simply add the line `add_subdirectory([Folder])` in your CMake.

In the CMakeFile of the library you wish to implement, you have to add the following elements:
* `add_library([library name] SHARED [source files])`: will add the source files to a library that is shared.
* `set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)`: set the output produced to the lib/ folder in which all the shared libraries must be.
* `target_include_directories([library name] PRIVATE include)`: set the include path to the include/ directory (can change depending on the way you're developping).
* `target_compile_options([library name] PRIVATE ${WARNING_FLAGS})`: set the warning flags defined in the CMakeFile at the root. You can override them.
* `target_link_libraries([library name] PRIVATE arcade-interface [library flags if needed])`: link the arcade-interface library, to have access to the interfaces and their contents.
* `set_property(TARGET [library name] PROPERTY CXX_STANDARD 20)`: set CXX_STANDARD 20 for the compiler
* `set_property(TARGET [library name] PROPERTY CXX_STANDARD_REQUIRED ON)`: tells the compiler this option is required