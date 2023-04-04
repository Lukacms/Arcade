# Arcade - Graphics / Display
Implementation of the shared libraries for the different Display methods

## Description
Here's the source code for the three display methods, which are [`SDL2`](https://wiki.libsdl.org/SDL2/FrontPage), [`Ncurses`](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/) and [`SFML`](https://www.sfml-dev.org/).

## How to make a new display method ?
You have to create a class inheriting from the [`IDisplay`](https://github.com/Lukacms/Arcade/blob/main/Core/include/arcade/interfaces/IDisplay.hh) interface, which implements the following methods:
* createSprite
* createText
* getEvent

You also have to implement the [`IWindow`](https://github.com/Lukacms/Arcade/blob/main/Core/include/arcade/interfaces/IWindow.hh), [`ISprite`](https://github.com/Lukacms/Arcade/blob/main/Core/include/arcade/interfaces/ISprite.hh) and [`IText`](https://github.com/Lukacms/Arcade/blob/main/Core/include/arcade/interfaces/IText.hh) interfaces whith your chosen library.


To load the IDisplay classe, an `entryPoint` function need to be done and to be able to be loaded using `dlsym` (after `dlopen`); it looks like this:
```c++
extern "C" {

    std::unique_ptr<arc::IDisplay> entryPoint() {
        std::unique_ptr<arc::Display> display = std::make_unique<arc::Display>();

        return display;
    }
}
```
The `extern "C"` line desactivate C++ polymorphysm, and blocks the compiler to change the function name ([mangling](https://www.ibm.com/docs/en/i/7.3?topic=linkage-name-mangling-c-only)). The function name is recognizable and loadable with dlsym.
