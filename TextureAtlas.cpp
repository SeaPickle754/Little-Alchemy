#include "TextureAtlas.hpp"

TextureAtlas::TextureAtlas(const char* filepath, int image_h, int image_w)
: img(new sf::Texture()), sprite(*img){
    m_scale = 1;
    img->loadFromFile(filepath);
    image_height = image_h;
    image_width = image_w;
}

void TextureAtlas::render(vec position, offset index, sf::RenderWindow& window){
    /*
    So basically what this does, is it changes the current texture rect value to what the
    offset says it should be.
    Just so you know when you inevitably forget.
    */
    // this code makes sure that a null offset does not try to get drawn.
    assert(index != offset(-1, -1));
    sprite.setTextureRect(sf::IntRect(sf::Vector2i(index.x*image_width*m_scale, index.y*image_height*m_scale),
                                      sf::Vector2i(image_width*m_scale, image_height*m_scale)));
    sprite.setPosition(position);
    window.draw(sprite);
}
