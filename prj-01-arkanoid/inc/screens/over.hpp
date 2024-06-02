// screen.hpp
#ifndef Game_Over_HPP
#define Game_Over_HPP

#include"screen.hpp"
#include <SFML/Window.hpp>
#include"setting.hpp"
#include"buten.hpp"


class Game_Over : public Screen
{
public:
    Game_Over(sf::RenderWindow& window, int& corent_screen, Setting& setting);
    ~Game_Over();
    void display(int& current_screen) override;
private:
    Setting& m_settings;
    sf::RenderWindow& m_window;
    sf::Text* m_titel;
    Button m_home_button;
    sf::Font* get_font();
    sf::Text* make_title();  
    void chack_butens(int& corent_screen); 
};


#endif