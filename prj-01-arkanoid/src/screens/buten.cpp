#include "screens/buten.hpp"
#include <iostream>

Button::Button()
{
    m_font.loadFromFile("fonts/arial.ttf");
};

void Button::create(std::string ButtonText, int TextSize, float buttonWidth, float buttonHeight, float x, float y)
{
    m_pos.x = x;
    m_pos.y = y;
    m_size.x = buttonWidth;
    m_size.y = buttonHeight;
    m_DefaultColor = sf::Color::Blue;
    m_hColor = sf::Color::White;

    m_text.setFont(m_font);
    m_text.setCharacterSize(TextSize);
    m_text.setString(ButtonText);
    m_text.setOutlineColor(sf::Color::Black);
    m_text.setOutlineThickness(2);
    sf::FloatRect fr = m_text.getGlobalBounds();
    m_textBounds.x = fr.width + fr.left;
    m_textBounds.y = fr.height + fr.top;

    m_shape.setSize(m_size);
    m_shape.setFillColor(m_DefaultColor);
    m_shape.setPosition(m_pos);

    m_text.setOrigin(m_textBounds.x / 2, m_textBounds.y / 2);
    m_text.setPosition(m_pos.x + (m_size.x / 2), m_pos.y + (m_size.y / 2) - 1);
}
void Button::draw(sf::RenderWindow &window) // draws button on window(with text)
{
    window.draw(m_shape);
    // if (m_textBounds.x < m_size.x || m_textBounds.y < m_size.y)
    window.draw(m_text);
}

bool Button::CursorOverButton(sf::RenderWindow &window)
{
    sf::Vector2i CursorPos = sf::Mouse::getPosition(window);
    sf::Vector2f world_mouse_position = window.mapPixelToCoords(CursorPos);

    if (m_shape.getGlobalBounds().contains(world_mouse_position))
    {
        if (m_shape.getFillColor() != m_hColor)
        {
            m_shape.setFillColor(m_hColor);
        }

        return true;
    }
    else
    {
        if (m_shape.getFillColor() == m_hColor)
        {
            m_shape.setFillColor(m_DefaultColor);
        }
        return false;
    }
}

bool Button::isButtonClicked(sf::RenderWindow &window) // When button is pressed down whis executes
{
    // if (!CursorOverButton(window))
    // {
    //     m_wFocus = (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) ? true : false;
    // }
    if (CursorOverButton(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_ButtonClick = true;
        return true;
    }
    else
    {
        m_ButtonClick = false;
    }
    return false;
}