#pragma once
#include <SFML/Graphics.hpp>
#include "TextureAtlas.hpp"
#include "globals.h"

class Button{
private:
    TextureAtlas* m_texture;
    sf::Vector2f m_position;
    sf::Vector2i m_offset;
    sf::RectangleShape rect;
    sf::String m_name;
    sf::Font* m_font;
    sf::Text m_text;
public:
    Button(sf::Vector2f position, sf::Vector2i offset, TextureAtlas* texture, sf::Font* font);
    // this function returns true if clicked on.
    inline bool onClick(sf::Vector2f position){if(rect.getGlobalBounds().contains(position)){return true;} return false;}
    void render(sf::RenderWindow& window);
    vec getPosition(){return m_position;}
    void move(vec);
    // to identify the offset
    // useful later I promise
    inline offset getOffset() {return m_offset; }
};
