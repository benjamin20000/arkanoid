#include"screens/game.hpp"
#include "setting.hpp"
#include"game_manager.hpp"


Play_Screen::Play_Screen(sf::RenderWindow& window, int& corent_screen, Setting& setting)
:   m_game_manager(setting, window)
,   m_settings(setting)
,   m_window(window)
{
}




Play_Screen::~Play_Screen()
{
}


void Play_Screen::display(int& current_screen)
{
    m_settings.Background_screen = m_settings.Background_game_screen;   
    while (current_screen == 1 and m_window.isOpen())
    {
        if (m_game_manager.over == true){
            current_screen = 2;
        }

        sf::Event event;                
        while (m_window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code){
                        case sf::Keyboard::Escape:
                            m_window.close();
                            break;   
                        default:
                            break;
                    }
                    m_game_manager.handle_key(event);  
                    break;
                default:
                    ;// no handling for now;
            }   
        }
        m_window.clear(m_settings.Background_screen); 
        m_game_manager.disply_elements();  
        m_window.display();
    }

}