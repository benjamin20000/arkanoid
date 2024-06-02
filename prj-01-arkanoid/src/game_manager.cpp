#include"game_manager.hpp"

Game_Manager::Game_Manager(Setting& setting, sf::RenderWindow& window)
:   m_player(setting, window, m_ball_manager.m_ball)
,   m_ball_manager(setting, window)
,   m_blocks_manager(setting, window)
,   m_setting(setting)
,   m_window(window)
   
{
}

Game_Manager::~Game_Manager()
{
}
 

void Game_Manager::disply_elements()
{
    handle_collisson();
    m_blocks_manager.disply_vector();
    m_player.m_pad.display();
    m_player.display_live();
    m_ball_manager.m_ball.display();
    if(!m_ball_manager.m_ball.live){
        ball_falling();
        m_ball_manager.m_ball.live = true;
    }
}


void Game_Manager::handle_key(sf::Event event)
{
    switch (event.key.code)
    {     
    case sf::Keyboard::Right:
        m_player.handle_right();
        break;
    case sf::Keyboard::Left:
        m_player.handle_left();
        break;
    case sf::Keyboard::Space:
        if(m_ball_manager.m_ball.rest == true){
            m_ball_manager.m_ball.rest = false;
            m_ball_manager.change_speed(m_setting.ball_first_jump);
        };
        break;        
    default:
        break;
    }
}


bool Game_Manager::check_collisson(sf::Sprite* element1, sf::Sprite* element2)
{
    return(element1->getGlobalBounds().intersects(element2->getGlobalBounds()));
}


void Game_Manager::ball_rebound()
{
    float x = m_player.m_pad.m_img->getPosition().x + 90;//set x to the midel of the pad
    float i = m_ball_manager.get_sprite()->getPosition().x;
    float xp = m_setting.ball_speed.x;
    float y = m_setting.ball_speed.y;
        if(x-i > 30){ 
            if(xp > 0){ //ball go to rhgt
                xp = xp*-1;
            }
        }
            if(x-i < -30){
                 if(xp < 0){ //ball go to left
                    xp = xp*-1;
            }
        }
    sf::Vector2f newSpeed(xp, y*-1);
    m_ball_manager.change_speed(newSpeed);
}


void Game_Manager::ball_pad_col_hndler()
{
    if(check_collisson(m_player.get_sprite(), m_ball_manager.get_sprite())){
        if(m_setting.ball_speed.y == 0){
            return;
        }
    ball_rebound();    
           
    }
}

void Game_Manager::ball_block_col_handler()
{   
    auto begin =m_blocks_manager.m_blocks_vector.begin();
    auto end = m_blocks_manager.m_blocks_vector.end();
    while (begin != end)
    {
        if(check_collisson(begin->m_img, m_ball_manager.get_sprite())){
            float x = m_setting.ball_speed.x;
            float y = m_setting.ball_speed.y;
            sf::Vector2f newSpeed(x, y*-1);
            m_ball_manager.change_speed(newSpeed);
            m_blocks_manager.m_blocks_vector.erase(begin); 
        }
        ++begin;
    }
}


void Game_Manager::pop_live()
{
    m_player.m_lives.pop_back();
    if(m_player.m_lives.size() == 0){
        game_over();
    }
}

void Game_Manager::game_over()
{
    over = true;
}


void Game_Manager::ball_falling()
{
    float x = m_player.get_sprite()->getPosition().x;
    float y = m_player.get_sprite()->getPosition().y;
    m_ball_manager.m_ball.m_img->setPosition(x+90 ,y-25);
    sf::Vector2f v(0.f, 0.f);
    m_ball_manager.change_speed(v);
    m_ball_manager.m_ball.rest =true;
    pop_live();
    
}

void Game_Manager::handle_collisson(){
    ball_pad_col_hndler();
    ball_block_col_handler();
}

