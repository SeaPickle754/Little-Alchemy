#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class TextureAtlas{
private:
    sf::Texture* img;
    float m_scale;
    int image_height;
    int image_width;
public:
    sf::Sprite sprite;
    // Filepath: Path to the texture
    // image_height: how high the sub-image is
    // image_width: how wide the sub image is
    TextureAtlas(const char* filepath, int image_height, int image_width);
    void render(sf::Vector2f, sf::Vector2i, sf::RenderWindow&);
    // set global scale
    inline void set_scale(float scale = 1.f){sprite.scale(sf::Vector2f(scale, scale));}
};
