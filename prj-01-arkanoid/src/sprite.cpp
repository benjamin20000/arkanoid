#include"sprite.hpp"


My_Sprite::My_Sprite()
{
}

My_Sprite::~My_Sprite()
{
}

sf::Texture* My_Sprite::load_img(const char* path)
{
    sf::Texture* texture = new sf::Texture(); 
    texture->loadFromFile(path);
    return texture; 
}

sf::Sprite* My_Sprite::set_sprite(sf::Texture* texture)
{
    sf::Sprite* sprite = new sf::Sprite(); 
    sprite->setTexture(*texture);
    return sprite;
}

sf::Sprite* My_Sprite::get_img(const char* path)
{
    sf::Texture* texture = load_img(path);
    return set_sprite(texture);
}