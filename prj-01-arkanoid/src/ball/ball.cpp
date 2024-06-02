#include "ball/ball.hpp"

Ball::Ball(Setting& setting, sf::RenderWindow& window)
:   m_settings(setting)
,   m_window(window)
,   live(true)
,   rest(true)
{
}

Ball::~Ball()
{
}

void Ball::display()
{
    adjustSpeed();
    m_img->move(m_settings.ball_speed);
    m_window.draw(*m_img);
}

void Ball::ball_fall()
{
    live = false;
}

void Ball::adjustSpeed(){
    sf::Vector2f pos = m_img->getPosition();        

    if(pos.x  >= m_settings.screen_width -20)    m_settings.ball_speed.x *= -1;
    if(pos.x  <= -1)        m_settings.ball_speed.x *= -1;
    if(pos.y  >= m_settings.screen_width)    ball_fall();   ;
    if(pos.y  <= 0)         m_settings.ball_speed.y *= -1;;    
}

void Ball::update_dir(sf::Vector2f& new_v)
{
    m_settings.ball_speed = new_v;
}
