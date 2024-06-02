#include"blocks/block.hpp"


Block::Block(Setting& setting, sf::RenderWindow& window)
:   m_settings(setting)
,   m_window(window)   
{
    m_sprite = new My_Sprite();
    m_img = m_sprite->get_img(m_settings.block_path);
    m_img->setScale(m_settings.block_width,m_settings.block_high);
}

Block::~Block()
{
}

void Block::display()
{
    m_window.draw(*m_img);
}

Block& Block::operator=(const Block& other)
{
        *m_sprite = *(other.m_sprite);
        *m_img = *(other.m_img);
        return *this;
}