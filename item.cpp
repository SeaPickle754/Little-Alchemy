#include "item.hpp"


Item::Item(sf::Vector2i n_offset, sf::String name, sf::Vector2f position, TextureAtlas* texture){
    m_offset = n_offset;
    m_name = name;
    m_position = position;
    m_texture = texture;
    // this is horrible but ok
    m_hitbox = sf::Rect<float>((float)position.x, (float)position.y, global::tileWidth*global::scale, global::tileHeight*global::scale);
}

void Item::set_position(vec new_position)
{
    m_position = new_position;
}
bool Item::isColliding(sf::Rect<float> otherRect){
    // make sure it is updated.
    m_hitbox.left = (m_position.x);
    m_hitbox.top = (m_position.y);
    if(m_hitbox.intersects(otherRect)){
        return true;
    }
    return false;
}

void Item::render(sf::RenderWindow& window){
    m_texture->render(m_position, m_offset, window);
}
