#include "TextureAtlas.hpp"

TextureAtlas::TextureAtlas(const char* filepath, int image_h, int image_w){
    m_scale = 1;
    img = new sf::Texture();
    img->loadFromFile(filepath);
    sprite.setTexture(*img);

    image_height = image_h;
    image_width = image_w;
}

void TextureAtlas::render(sf::Vector2f position, sf::Vector2i index, sf::RenderWindow& window){
    /*
    So basically what this does, is it changes the current texture rect value to what the
    offset says it should be.
    Just so you know when you inevitably forget.
    */
    sprite.setTextureRect(sf::IntRect(sf::Vector2i(index.x*image_width*m_scale, index.y*image_height*m_scale),
                                      sf::Vector2i(image_width*m_scale, image_height*m_scale)));
    sprite.setPosition(position);
    window.draw(sprite);
}
