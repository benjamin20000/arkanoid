#ifndef Block_HPP
#define BLock_HPP
#include"setting.hpp"
#include"sprite.hpp"

class Block
{
public:
    Block(Setting& m_setting, sf::RenderWindow& window);
    ~Block();
    Block& operator=(const Block& other);
    void display();
    sf::Sprite* m_img;
    My_Sprite* m_sprite;
private:
    Setting& m_settings;
    sf::RenderWindow& m_window;    
};

#endif
