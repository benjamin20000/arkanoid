#ifndef Ball_HPP
#define Ball_HPP

#include"setting.hpp"

class Ball
{
public:
    Ball(Setting& setting, sf::RenderWindow& window);
    ~Ball();
    void display();
    void update_dir(sf::Vector2f&);
    void adjustSpeed();
    Setting& m_settings;
    sf::Sprite* m_img;
    sf::RenderWindow& m_window; 
    bool live;
    bool rest;

private:
    void ball_fall();

};


#endif

