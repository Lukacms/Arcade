/*
** EPITECH PROJECT, 2023
** src
** File description:
** sfml
*/

#include <SFML/SFMLDisplay.hh>
#include <memory>

extern "C" {

    std::unique_ptr<arc::IDisplay> entryPoint() { // NOLINT
        std::unique_ptr<SFMLDisplay> sfml = std::make_unique<SFMLDisplay>();
        sfml->GetWindow().get().OpenWindow();
        return sfml;
    }
}
