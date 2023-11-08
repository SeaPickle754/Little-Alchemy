#include "TextureAtlas.hpp"

TextureAtlas::TextureAtlas(const char* filepath, int image_h, int image_w){
    img = new sf::Texture();
    img->loadFromFile(filepath);
    sprite.setTexture(*img);
    image_height = image_h;
    image_width = image_w;
}

void TextureAtlas::render(sf::Vector2f position, sf::Vector2i index, sf::RenderWindow& window){
    sprite.setTextureRect(sf::IntRect(sf::Vector2i(index.x*image_width, index.y*image_height),
                                      sf::Vector2i(image_width, image_height)));
    sprite.setPosition(position);
    window.draw(sprite);
}
