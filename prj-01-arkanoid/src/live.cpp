#include"live.hpp"

Live::Live(Setting& setting, sf::RenderWindow& window)
:   m_setting(setting)
,   m_window(window)
,   amount(m_setting.lives)
{
    m_sprite = new My_Sprite();
    m_img = m_sprite->get_img(m_setting.live_path);
    m_img->setPosition(3,m_setting.screen_high-60);
    m_img->setScale(0.1f,0.1f);
}

Live::~Live()
{
}

void Live::display()
{
    m_window.draw(*m_img);

}