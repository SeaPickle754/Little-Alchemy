#include <SFML/Graphics.hpp>
#include "TextureAtlas.hpp"


// TODO: make this a singleton!!!!
// just to ensure it's not coppied and have 2000000k of mem taken up
class Item{
private:
    TextureAtlas atlas;
public:
    Item();
    void render(sf::RenderWindow& window, float x, float y, sf::Vector2i index);
};
