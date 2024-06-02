#include"setting.hpp"
#include"paddel/pad.hpp"
#include"sprite.hpp"
#include"live.hpp"
#include"ball/ball.hpp"
#include<vector>



class Player
{
public:
    Player(Setting& setting, sf::RenderWindow& window,Ball& ball);
    ~Player(); 
    sf::Sprite* get_sprite();
    void handle_right();
    void handle_left();
    void display_live();
private:
    void creat_lives();
    void set_img();
    Setting& m_setting;
    sf::RenderWindow& m_window;
    My_Sprite* m_sprite;
    sf::Sprite* m_img;
    Ball& m_ball;
public:    
    Pad m_pad;
    std::vector<Live> m_lives;   
};


