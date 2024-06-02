#ifndef MY_SPRITE_HPP
#define MY_SPRITE_HPP

#include <SFML/Graphics.hpp>

class My_Sprite {
public:
    My_Sprite();
    ~My_Sprite();
    sf::Sprite* get_img(const char* path);
private:
    sf::Texture* load_img(const char* path);
    sf::Sprite* set_sprite(sf::Texture* texture);   
};

#endif // MY_SPRITE_HPP


