#ifndef SCREEM_MANAGER_HPP
#define SCREEM_MANAGER_HPP

#include "setting.hpp"
#include<vector>
#include "screen.hpp"
#include "home.hpp"
#include "game.hpp"
#include "over.hpp"



class Screen_Manager
{
public:
    Screen_Manager(Setting& setting, sf::RenderWindow& window);
    ~Screen_Manager();
    void disply();

private:
    // void set_window();

    Setting& m_setting;
    sf::RenderWindow& m_window;
    // Home:0,  Game:1, GaveOver:2,  Top10:3
    int m_current_screen;
    Screen* m_home;
    Screen* m_game;
    Screen* m_top10;
    Screen* m_game_over;
    std::vector<Screen*> m_screens_vector{};
};

#endif
