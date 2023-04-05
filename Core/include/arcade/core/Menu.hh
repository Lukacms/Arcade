/*
** EPITECH PROJECT, 2023
** core
** File description:
** Menu
*/

#pragma once

#include <arcade/Geometry.hh>
#include <arcade/interfaces/IGame.hh>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <arcade/interfaces/IWindow.hh>

namespace arc
{
    /**
     * to display menu and make actions from it
     * all events are handled by the Core
     */

    constexpr const arc::Vector TITLE_POSTION{8, 1};
    constexpr const arc::Vector NAME_POSTION{8, 10};
    constexpr const arc::Vector GRAPHIC_POSITION{2, 6};
    constexpr const arc::Vector CURSOR_BASE_POSITION{1, 6};
    constexpr const arc::Vector GAME_POSITION{10, 6};
    constexpr const arc::Color TEXT_COLOR_MENU{255, 255, 255};

    enum class MenuState { SELECT_NOM, SELECT_GAME, SELECT_LIB };

    struct MenuTile {
            int x_coord;
            int y_coord;
    };

    struct MenuResult {
            int index_lib_grah{-1};
            int index_lib_game{-1};
    };

    class Menu : public IGame
    {
        public:
            Menu() = default;
            Menu(Menu const &to_copy) = delete;
            Menu(Menu &&to_move) = default;
            ~Menu() override = default;
            Menu &operator=(Menu const &to_copy) = delete;
            Menu &operator=(Menu &&to_move) = default;

            // class methods
            // to display
            void EventAnalisys(const arc::Event &event) final;
            void DisplayGame(IWindow &window) final;
            void ResetGame() final;
            void PlayGame() final;
            void InitGame() final;
            void SetSprite(arc::IDisplay &display) final;
            void SetText(arc::IDisplay &display) final;
            [[nodiscard]] std::string get_lib_graph() const;
            [[nodiscard]] std::string get_lib_game() const;
            void set_lib_graph(std::vector<std::string> &graph);
            void set_lib_game(std::vector<std::string> &game);

        private:
            void move_up();
            void move_down();
            void enter_info();
            void select_nom(const arc::Event &event);

            MenuState m_state{MenuState::SELECT_NOM};
            std::unique_ptr<IText> m_text{};
            std::unique_ptr<ISprite> m_sprite{};
            std::string m_name{};
            MenuResult m_player_selection{};
            arc::MenuTile m_cursor_tile{CURSOR_BASE_POSITION.x, CURSOR_BASE_POSITION.y};
            std::vector<MenuTile> m_menu_tiles{};
            std::vector<std::string> m_graphic_lib{};
            std::vector<std::string> m_game_lib{};
    };
} // namespace arc
