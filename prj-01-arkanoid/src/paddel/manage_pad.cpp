#include"paddel/manage_pad.hpp"


Player::Player(Setting& setting, sf::RenderWindow& window,Ball& ball)
:   m_setting(setting)
,   m_window(window)
,   m_ball(ball)
,   m_pad(setting, window) 
{
    m_sprite = new My_Sprite();
    m_img = m_sprite->get_img(m_setting.pad_path);
    m_pad.m_img = m_img;
    set_img();
    creat_lives();
}


Player::~Player()
{
    delete m_sprite;
    delete m_img;
}

sf::Sprite* Player::get_sprite()
{
    return m_pad.m_img;
}


void Player::handle_right()
{
    //TODO remove magic number 
    if(m_pad.m_img->getPosition().x + 220 < m_setting.screen_width){
        m_pad.update_pos(m_setting.paddel_speed);
        if(m_ball.rest == true){
            m_ball.m_img->move(m_setting.paddel_speed,0);
        }
    }    
}

void Player::handle_left()
{
    if(m_pad.m_img->getPosition().x > 0){
        m_pad.update_pos(m_setting.paddel_speed*-1);
        if(m_ball.rest == true){
            m_ball.m_img->move(m_setting.paddel_speed*-1,0);
        }
    }
    
}

void Player::set_img()
{
    m_img->setScale(0.25,0.25);
    m_img->setPosition(m_setting.pad_start_pos);
}

void Player::creat_lives()
{
    float y = 5;
    for (char i = 0; i < m_setting.lives; i++)
    {
        Live live(m_setting, m_window);
        live.m_img->setPosition(3,y);
        m_lives.push_back(live);
        y += 50;
    }
}

void Player::display_live()
{
    for(Live live: m_lives){
        live.display();
    }
}