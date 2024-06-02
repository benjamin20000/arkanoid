#include"paddel/pad.hpp"


Pad::Pad(Setting& setting, sf::RenderWindow& window)  
:   m_settings(setting)
,   m_window(window)
{
   
}


Pad::~Pad()
{
}


void Pad::update_pos(float speed)
{
    m_img->move(speed, 0);
}

void Pad::display()
{
    m_window.draw(*m_img);
}