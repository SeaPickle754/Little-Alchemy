#include "itemButton.hpp"

Button::Button(sf::Vector2f position, sf::Vector2i offset, TextureAtlas* texture, sf::Font* font):m_text(sf::Text(*font)){
m_texture = texture;
m_position = position;
m_offset = offset;
m_font = font;
m_text.setString(m_texture->getFileParser()->getName(m_offset));
m_text.setPosition({m_position.x+40, m_position.y+8});
m_text.setCharacterSize(15);
rect.setOutlineColor(global::button_outline_color);
// thicc
rect.setOutlineThickness(3);
rect.setPosition(position);
rect.setFillColor(global::button_color);
// see global.h definition of vec :)
rect.setSize(vec(global::buttonx, global::buttony));
}
void Button::move(vec offset){
    m_position = m_position+offset;
    m_text.setPosition(m_text.getPosition()+offset);
    rect.setPosition(rect.getPosition()+offset);
}
void Button::render(sf::RenderWindow& window){
    window.draw(rect);
    window.draw(m_text);
    m_texture->render(m_position, m_offset, window);

}
