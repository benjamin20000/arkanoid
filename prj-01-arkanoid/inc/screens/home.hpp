    #ifndef HOME_HPP
    #define HOME_HPP

    #include"screen.hpp"
    #include <SFML/Window.hpp>
    #include"setting.hpp"
    #include"buten.hpp"

    class Home : public Screen
    {

    public:
        Home(sf::RenderWindow& window, int& corent_screen, Setting& setting);
        ~Home();
        void display(int& corent_screen) override;  
    private:
        Setting& m_settings;
        sf::RenderWindow& m_window;
        sf::Text* m_titel;
        Button m_game_button;
        sf::Font* get_font();
        sf::Text* make_title();
        void chack_butens(int& corent_screen);

        
    };

    #endif

