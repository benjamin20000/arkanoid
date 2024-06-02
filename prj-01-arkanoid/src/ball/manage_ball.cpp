#include"ball/manage_ball.hpp"


Manage_Ball::Manage_Ball(Setting& setting, sf::RenderWindow& window)
:   m_setting(setting)
,   m_ball(setting, window) 
{
    //TODO seprait to difrents functoins
    m_sprite = new My_Sprite();
    m_img = m_sprite->get_img(m_setting.ball_path);
    m_ball.m_img = m_img;
    m_img->setPosition(m_setting.ball_pos);
    // set_img();
}

Manage_Ball::~Manage_Ball()
{
    delete m_sprite;
    delete m_img;
}

 sf::Sprite* Manage_Ball::get_sprite()
 {
    return m_ball.m_img;
 }

 void Manage_Ball::change_speed(sf::Vector2f& new_v)
 {
    m_ball.update_dir(new_v);
 }