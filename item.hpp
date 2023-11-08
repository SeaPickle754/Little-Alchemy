#pragma once
#include <SFML/Graphics.hpp>
#include "TextureAtlas.hpp"

class Item{
private:
    sf::Vector2i m_offset;
    sf::Vector2f m_position;
    sf::String m_name;
    // dont need 2 free bc freeing would delete the texture
    TextureAtlas* m_texture;
public:
    Item(sf::Vector2i offset, sf::String name, sf::Vector2f position, TextureAtlas* texture);
    void render(sf::RenderWindow& window);
    inline void set_offset(sf::Vector2i offset){m_offset=offset;}
    inline void set_position(sf::Vector2f position){m_position=position;}
    inline sf::Vector2f get_position() {return m_position;}
    inline sf::Vector2i get_offset() {return m_offset;}
};
