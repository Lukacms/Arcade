# Arcade - Games
Implementation of the Games in shared libraries

## Descriptions
Here is the source code for the games, loaded in shared libraries. We made two games, `Snake` and `Nibbler`, but you are welcome to do more if you'd like. The lines below describe how to make one, which methods to implement, ...

## How to make a new Game ?
You have to create a class heriting from the [`IGame`](https://github.com/Lukacms/Arcade/blob/main/Core/include/arcade/interfaces/IGame.hh), and implement the following methods:
* EventAnalisys
* DisplayGame
* ResetGame
* PlayGame
* InitGame
* SetSprite
* SetText

You also have to make an `entryPoint` method, which will allow the `Core` to load the class, and look like this:
```c++
extern "C" {

    std::unique_ptr<arc::IGame> entryPoint() { // NOLINT
        std::unique_ptr<arc::IGame> game = std::make_unique<arc::Game>();

        game->InitGame();
        return snake_game;
    }
}
```
The `extern "C"` line desactivate C++ polymorphysm, and blocks the compiler to change the function name ([mangling](https://www.ibm.com/docs/en/i/7.3?topic=linkage-name-mangling-c-only)). The function name is recognizable and loadable with dlsym.
