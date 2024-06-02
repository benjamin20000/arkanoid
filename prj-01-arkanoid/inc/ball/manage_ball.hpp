#include"ball/ball.hpp"
#include"setting.hpp"
#include"sprite.hpp"


class Manage_Ball
{
public:
    Manage_Ball(Setting& setting, sf::RenderWindow& window);
    ~Manage_Ball();
    void change_speed(sf::Vector2f&);
    sf::Sprite* get_sprite();
    Setting& m_setting;
    Ball m_ball;
private:
    // void set_img();
    My_Sprite* m_sprite;
    sf::Sprite* m_img;
};



