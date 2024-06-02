// setting.hpp
#ifndef SETTING_HPP
#define SETTING_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Setting
{
public:
    //screen
    std::string game_name = "my game";
    float screen_high = 700;
    float screen_width = 1000;
    std::string home_titel = "to start press enter";
    int titel_size = 100;
    sf::Color Background_Home_screen = sf::Color::Green;
    sf::Color Background_game_screen = sf::Color::Blue;
    sf::Color Background_game_over_screen = sf::Color::Magenta;
    sf::Color Background_screen = Background_Home_screen;

    //paddel
    const char* pad_path = "images/paddle.png";
    float padel_stert_x_pos = screen_width/2 - 100;
    float padel_stert_y_pos = screen_high -40; 
    const sf::Vector2f pad_start_pos{padel_stert_x_pos, padel_stert_y_pos};
    float paddel_speed = 10;   

    //ball
    const char* ball_path = "images/ball.png";
    sf::Vector2f ball_speed{0.f, 0.f};
    sf::Vector2f ball_pos = {padel_stert_x_pos+95,padel_stert_y_pos-23};
    sf::Vector2f ball_first_jump = {2, -10};

    // block
    const char* block_path = "images/brick-green.png";
    float block_high = 0.25;
    float block_width = (float)0.20;
    int block_columns = 5;
    int block_rows = 3;
    float spase_for_blocks = 170;

    //live
    const char* live_path = "images/heart.png";
    char lives = 3;  
};


    

#endif // SETTING_HPP
