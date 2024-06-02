#ifndef Pad_HPP
#define Pad_HPP


#include"setting.hpp"


class Pad
{
public:
    Pad(Setting& m_setting, sf::RenderWindow& window);
    ~Pad();
    void display();
    void update_pos(float speed);
    Setting& m_settings;
    sf::Sprite* m_img;
private:
    sf::RenderWindow& m_window;  
};

#endif
