#ifndef Game_Manager_HPP
#define Game_Manager_HPP
#include"paddel/manage_pad.hpp"
#include"ball/manage_ball.hpp"
#include"blocks/manage_blocks.hpp"
#include "setting.hpp"
#include "live.hpp"
#include <vector>


class Game_Manager
{
public:
    Game_Manager(Setting& setting, sf::RenderWindow& window);
    ~Game_Manager();
    void disply_elements();
    void handle_key(sf::Event event);
    bool over{false}; 
private: 
    bool check_collisson(sf::Sprite* element1, sf::Sprite* element2);
    void handle_collisson();
    void ball_pad_col_hndler();
    void ball_rebound();
    void ball_block_col_handler();
    void ball_falling();
    void pop_live();
    void game_over();
    Player m_player;
    Manage_Ball m_ball_manager;
    Manage_Blocks m_blocks_manager;
    Setting& m_setting; 
    sf::RenderWindow& m_window;
};


#endif