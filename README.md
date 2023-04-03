# Arcade
A retro platform

## Project
Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of player scores.\
To be able to deal with the elements of the gaming plate-form at run-time, the graphics libraries and the games must be implemented as dynamic libraries, loaded at run-time.\
Each GUI available for the program must be used as a shared library that will be loaded and used dynamically by the main program.

### Dependencies
The project is done in [C++](https://en.wikipedia.org/wiki/C%2B%2B), and build using [CMake](https://cmake.org/)

### Details
* More informations about the [core project](github.com/Lukacms/Arcade/tree/main/Core).
* How to implement your [Graphical library](https://github.com/Lukacms/Arcade/tree/main/Graphics).
* How to implement another [Game](https://github.com/Lukacms/Arcade/tree/main/Games).

## How to build project
CMake is used to build the project, and the `compile.sh` file is used to make it easier:
* to compile with g++, which is needed to start project, because it compile with the flaf `-gno-gnu-unique` to correctly close shared libraries:
```sh
./compile.sh --gcc
```
* to compile in debug mode:
```sh
./compile.sh --debug
```
* to compile with [Ninja](https://ninja-build.org/manual.html) (it is advised to build if using a clang-based lsp)
```sh
./compile.sh --ninja
```

## Authors
* [Luka Camus](https://github.com/Lukacms)
* [Louis Bassagal](https://github.com/LouisBassagal)
* [Samuel Florentin](https://github.com/SamuelFlorentin)

### Group
* [Édouard](https://github.com/EdouardPradie)
* [Léandre](https://github.com/Leandre17)
* [Johanna](https://github.com/Johannabureau)
