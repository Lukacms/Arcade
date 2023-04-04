# Arcade - Core
Central part of the project

## Description
The `Core` is the part that allow the program to be launched, and to link the [`Graphic`](https://github.com/Lukacms/Arcade/tree/main/Graphics) and [`Game`](https://github.com/Lukacms/Arcade/tree/main/Games) parts.\
All objects are in the `arc` namespace to recognize what is in the project or not.

### Shared libraries
As the program uses shared libraries, it load them using [`dlopen`](https://man7.org/linux/man-pages/man3/dlopen.3.html), close them with [`dlclose`](https://linux.die.net/man/3/dlclose). It also loads the games and graphics with [`dlsym`](https://linux.die.net/man/3/dlsym) and analyse possible errors with [`dlerror`](https://linux.die.net/man/3/dlsym).
* The Games are based off the `IGames` interface, which look like this:
```c++
class IGame
{
    public:
        IGame() = default;
        IGame(IGame const &to_copy) = default;
        IGame(IGame &&to_move) = default;
        virtual ~IGame() = default;
        IGame &operator=(IGame const &to_copy) = default;
        IGame &operator=(IGame &&to_move) = default;

        virtual void EventAnalisys(const arc::Event &event) = 0;
        virtual void DisplayGame(IWindow &window) = 0;
        virtual void ResetGame() = 0;
        virtual void PlayGame() = 0;
        virtual void InitGame() = 0;
        virtual void SetSprite(arc::IDisplay &display) = 0;
        virtual void SetText(arc::IDisplay &display) = 0;
};
```
* And the Graphics with the IDisplay:
```c++
class IDisplay
{
    public:
        virtual ~IDisplay() = default;
        IDisplay() = default;
        IDisplay(IDisplay const &to_copy) = default;
        IDisplay(IDisplay &&to_move) = default;
        IDisplay &operator=(IDisplay const &to_copy) = default;
        IDisplay &operator=(IDisplay &&to_move) = default;
        virtual std::unique_ptr<arc::ISprite> createSprite() = 0;
        virtual std::unique_ptr<arc::IText> createText() = 0;
        [[nodiscard]] virtual std::reference_wrapper<arc::IWindow>
        GetWindow() = 0;
        [[nodiscard]] virtual arc::Event GetEvent() = 0;
};
```

More details about this in the corresponding folders.
