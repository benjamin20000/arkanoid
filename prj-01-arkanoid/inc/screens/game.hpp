#ifndef Play_Screen_HPP
#define Play_Screen_HPP

#include"screen.hpp"
#include <SFML/Window.hpp>
#include"setting.hpp"
#include"game_manager.hpp"

class Play_Screen : public Screen
{
public:
    Play_Screen(sf::RenderWindow& window, int& corent_screen, Setting& setting);
    ~Play_Screen();
    void display(int& current_screen) override;
    Game_Manager m_game_manager;

private:
    Setting& m_settings;
    sf::RenderWindow& m_window;
};



#endif