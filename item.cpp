#include "item.hpp"


Item::Item(sf::Vector2i offset, sf::String name, sf::Vector2f position, TextureAtlas* texture){
    m_offset = offset;
    m_name = name;
    m_position = position;
    m_texture = texture;
}


void Item::render(sf::RenderWindow& window){
    m_texture->render(m_position, m_offset, window);
}
