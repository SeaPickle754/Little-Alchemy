#include "itemButton.hpp"

Button::Button(sf::Vector2f position, sf::Vector2i offset, TextureAtlas* texture){
m_texture = texture;
m_position = position;
m_offset = offset;

rect.setOutlineColor(global::button_outline_color);
rect.setPosition(position);
rect.setFillColor(global::button_color);
// see global.h definition of vec :)
rect.setSize(vec(global::buttonx, global::buttony));
}

void Button::render(sf::RenderWindow& window){
    window.draw(rect);
    m_texture->render(m_position, m_offset, window);
}
