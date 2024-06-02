#include"screens/screen_manager.hpp"


Screen_Manager::Screen_Manager(Setting& setting, sf::RenderWindow& window)
:   m_setting(setting)
,   m_window(window)  
,   m_current_screen(0)
,   m_home(new Home(m_window, m_current_screen, m_setting))
,   m_game(new Play_Screen(m_window, m_current_screen, m_setting))
,   m_game_over(new Game_Over(m_window, m_current_screen, m_setting))
,   m_screens_vector({m_home, m_game, m_game_over})       
{
}


Screen_Manager::~Screen_Manager()
{
    for (Screen* screen : m_screens_vector) {
        delete screen;
    }
}



void Screen_Manager::disply()
{
    while (m_window.isOpen())
    {
        if (m_current_screen == 2) {
            m_game_over->display(m_current_screen);
            m_screens_vector.erase(m_screens_vector.begin() + 1);
            m_game = new Play_Screen(m_window, m_current_screen, m_setting);
            m_screens_vector.insert(m_screens_vector.begin() + 1, m_game);
        }
        m_screens_vector[m_current_screen]->display(m_current_screen);        
    }    
}