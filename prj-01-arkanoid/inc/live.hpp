#ifndef Live_HPP
#define Live_HPP

#include"setting.hpp"
#include"sprite.hpp"

class Live
{
public:
    Live(Setting& setting, sf::RenderWindow& window);
    ~Live();
    void display();
    Setting& m_setting;
    sf::RenderWindow& m_window;
    char amount;
    sf::Sprite* m_img;
private:
    My_Sprite* m_sprite;

};

#endif