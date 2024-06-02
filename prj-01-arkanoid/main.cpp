#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "inc/screens/screen_manager.hpp"
#include "setting.hpp"


int main() {
    Setting setting;
    sf::RenderWindow window(sf::VideoMode((unsigned int)setting.screen_width, (unsigned int)setting.screen_high), setting.game_name);    
    window.setVerticalSyncEnabled(true);
    window.setPosition(sf::Vector2i(400, 200));
    Screen_Manager screen_manager(setting, window);
    screen_manager.disply();
}

