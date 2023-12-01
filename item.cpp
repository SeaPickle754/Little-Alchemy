#include "item.hpp"


Item::Item(sf::Vector2i n_offset, sf::String name, sf::Vector2f position, TextureAtlas* texture){
    m_offset = n_offset;
    m_name = name;
    m_position = position;
    m_texture = texture;
    // this is horrible but ok
    m_hitbox = sf::Rect<int>((int)position.x, (int)position.y, global::tileWidth*global::scale, global::tileHeight*global::scale);
}

void Item::set_position(vec new_position)
{
    m_position = new_position;
}
offset Item::isColliding(sf::Rect<int> otherRect){
    m_hitbox.left = (int)(m_position.x);
    m_hitbox.top = (int)(m_position.y);
    if(m_hitbox.intersects(otherRect)){
        return m_offset;
    }
    return offset(-1, -1);
}

void Item::render(sf::RenderWindow& window){
    m_texture->render(m_position, m_offset, window);
}
