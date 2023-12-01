#pragma once
#include <SFML/Graphics.hpp>
#include "TextureAtlas.hpp"
#include "globals.h"

class Item{
private:
    sf::Vector2i m_offset;
    sf::Vector2f m_position;
    sf::String m_name;
    sf::Rect<int> m_hitbox;
    // dont need 2 free bc freeing would delete the texture
    TextureAtlas* m_texture;
public:
    Item(sf::Vector2i n_offset, sf::String name, sf::Vector2f position, TextureAtlas* texture);
    void render(sf::RenderWindow& window);
    inline sf::String getName() {return m_name;}
    inline void set_offset(sf::Vector2i offset){m_offset=offset;}
    void set_position(sf::Vector2f position);
    inline sf::Vector2f get_position() {return m_position;}
    inline sf::Vector2i get_offset() {return m_offset;}
    // returns offset of item if rect intersects
    offset isColliding(sf::Rect<int>);
    inline sf::Rect<int> getRect() {return m_hitbox;};
};
