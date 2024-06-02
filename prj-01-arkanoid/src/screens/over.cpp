#include"screens/over.hpp"

Game_Over::Game_Over(sf::RenderWindow& window, int& corent_screen, Setting& setting)
:   m_settings(setting)
,   m_window(window)
,   m_titel(make_title())
,   m_home_button()
{
    std::string str= "go to home";
    m_home_button.create(str, 20, (float)300 ,(float)60,(float)350,(float)300);
}

Game_Over::~Game_Over()
{
}

sf::Font* Game_Over::get_font()
{  
    sf::Font* font = new sf::Font();
    font->loadFromFile("fonts/arial.ttf");
    return font;
}

sf::Text* Game_Over::make_title()
{
    sf::Text* text = new sf::Text();
    text->setFont(*get_font());
    text->setString("GAME OVER");
    text->setCharacterSize(m_settings.titel_size);
    text->setFillColor(sf::Color::Blue);
    text->setPosition(100,100);
    return text;
}

void Game_Over::chack_butens(int& corent_screen)
{
    if(m_home_button.isButtonClicked(m_window))
    {
        corent_screen = 0;
    }

}
void Game_Over::display(int& corent_screen)
{
    m_settings.Background_screen = m_settings.Background_game_over_screen;   
    while (corent_screen == 2 and m_window.isOpen())
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
                        corent_screen = 0;
                            break;            
                        default:
                            break;
                    }
                    break;
                default:
                    ;// no handling for now;
            }   
        }
        m_window.clear(m_settings.Background_screen);  
        m_window.draw(*m_titel); 
        m_home_button.draw(m_window);
        m_window.display();
    }
    
} 