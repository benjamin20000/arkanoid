#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Button
{

public:
    Button();
    // void create(std::string ButtonText, int TextSize, sf::Color Color, float buttonWidth, float buttonHeight, float x, float y, sf::Color HoverColor);

    void create(std::string ButtonText, int TextSize, float buttonWidth, float buttonHeight, float x, float y);
    bool CursorOverButton(sf::RenderWindow &window);

    bool isButtonClicked(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);

private:
    sf::Font m_font;
    sf::Text m_text;
    sf::Vector2f m_textPos;
    sf::Vector2f m_textBounds;

    sf::RectangleShape m_shape;
    sf::Vector2f m_pos;
    sf::Vector2f m_size;

    sf::Color m_DefaultColor;
    sf::Color m_hColor;

    // bool m_wFocus = false;

    bool m_ButtonClick = false;
};
#endif