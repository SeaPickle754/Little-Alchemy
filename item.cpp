#include "item.hpp"


Item::Item(sf::Vector2i n_offset, sf::String name, sf::Vector2f position, TextureAtlas* texture){
    m_offset = n_offset;
    m_name = name;
    m_position = position;
    m_texture = texture;
    // this is horrible but ok
    m_hitbox = sf::FloatRect({(float)position.x, (float)position.y}, {global::tileWidth*global::scale, global::tileHeight*global::scale});
    m_rect.setPosition(m_hitbox.position);
    m_rect.setOutlineColor(global::button_outline_color);
    m_rect.setSize({global::tileWidth*global::scale, global::tileHeight*global::scale});
    m_rect.setOutlineThickness(3.f);
    m_rect.setFillColor(sf::Color::Transparent);
}

void Item::set_position(vec new_position)
{
    m_position = new_position;
    m_rect.setPosition(m_position);
}
bool Item::isColliding(sf::Rect<float> otherRect){
    // make sure it is updated.
    m_hitbox.position.x = (m_position.x);
    m_hitbox.position.y = (m_position.y);
    m_rect.setPosition(m_hitbox.position);
    if(m_hitbox.findIntersection(otherRect)){
        return true;
    }
    return false;
}

bool Item::isClicked(vec position){
    m_hitbox.position.x = (m_position.x);
    m_hitbox.position.y = (m_position.y);
    m_rect.setPosition(m_hitbox.position);
    if(m_hitbox.contains(position)){
        return true;
    }
    return false;
}

void Item::render(sf::RenderWindow& window){
    //m_rect.setPosition(m_position);
    window.draw(m_rect);
    m_texture->render(m_position, m_offset, window);
}
