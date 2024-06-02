#include"blocks/manage_blocks.hpp"

Manage_Blocks::Manage_Blocks(Setting& setting, sf::RenderWindow& window)
:   m_setting(setting)
,   m_window(window)
{
    creat_blocks();
}

Manage_Blocks::~Manage_Blocks()
{
}

#include<iostream>

void Manage_Blocks::creat_blocks()
{
    float y = 50;
    for (int i = 0; i <m_setting.block_rows; i++){
        float x = 80;
        for (int i = 0; i < m_setting.block_columns; i++){
        Block a(m_setting, m_window);
        a.m_img->setPosition(x , y);
        m_blocks_vector.push_back(a);
        x += m_setting.spase_for_blocks;
        }
        y += 100;
    }  
}


void Manage_Blocks::disply_vector()
{
    auto first = m_blocks_vector.begin();
    auto end = m_blocks_vector.end();
    while (first != end)
    {
        first->display();
        ++first;
    }
}
