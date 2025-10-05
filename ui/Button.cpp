#include "Button.hpp"

uiButton::uiButton (sf::Texture* normal,sf::Texture* clicked, sf::Vector2f location)
:m_normal(*normal), m_clicked(*clicked){
    m_normal.setPosition(location);
    m_clicked.setPosition(location);
    m_currentSpr = &m_normal;

}

bool uiButton::checkClick(sf::Vector2f position){
    if(m_currentSpr->getGlobalBounds()
       .contains(position)){
        m_currentSpr = &m_clicked;
        return true;
    }
    m_currentSpr = &m_clicked;
    return false;
}

void uiButton::render(sf::RenderWindow& window){
    window.draw(*m_currentSpr);
}
