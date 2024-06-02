#include "screens/home.hpp"
#include "setting.hpp"

Home::Home(sf::RenderWindow& window, int& corent_screen, Setting& setting)
:   m_settings(setting)
,   m_window(window)
,   m_titel(make_title())
,   m_game_button()
{
    std::string str = "start game";
    m_game_button.create(str, 20, (float)300 ,(float)60,(float)350,(float)300);
}

Home::~Home()
{
}

sf::Font* Home::get_font()
{  
    sf::Font* font = new sf::Font();
    font->loadFromFile("fonts/arial.ttf");
    return font;
}

sf::Text* Home::make_title()
{
    sf::Text* text = new sf::Text();
    text->setFont(*get_font());
    text->setString(m_settings.home_titel);
    text->setCharacterSize(m_settings.titel_size);
    text->setFillColor(sf::Color::Red);
    text->setPosition(100,100);
    return text;
}

void Home::chack_butens(int& corent_screen)
{
    if(m_game_button.isButtonClicked(m_window)){
        corent_screen = 1;
    }
}

void Home::display(int& corent_screen)
{    
    m_settings.Background_screen = m_settings.Background_Home_screen;   
    while (corent_screen == 0 and m_window.isOpen())
    { 
        chack_butens(corent_screen);
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
                        case sf::Keyboard::Enter:
                        corent_screen = 1;
                            break;            
                        default:
                            break;
                    }
                    break;
                default:
                ;
            }   
        }

        m_window.clear(m_settings.Background_screen);
        // m_window.draw(*m_titel);
        m_game_button.draw(m_window);
        m_window.display();
    }
    
} 