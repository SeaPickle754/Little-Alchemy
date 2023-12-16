#pragma once
#include <SFML/Graphics.hpp>
#include "../globals.h"

class uiButton{
public:
    uiButton (sf::Texture* normal,sf::Texture* clicked,sf::Vector2f location);
    bool checkClick (sf::Vector2f);
    // if true, it is being clicked.
    inline void setState(bool state) {state ? m_currentSpr = &m_clicked : m_currentSpr = &m_normal;}
    sf::Sprite* getSprite() {return m_currentSpr;};
    void render(sf::RenderWindow&);
private:
    sf::Sprite m_normal;
    sf::Sprite m_clicked;
    sf::Sprite* m_currentSpr;
};
