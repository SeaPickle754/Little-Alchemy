#include "item.hpp"

Item::Item(): atlas("images/tiles.png", 16, 16){
    // all items are scaled up...
    atlas.sprite.scale(sf::Vector2f(2, 2));
    // this class should be used like a singleton in the main game renderer, and the sidebar can be passed a reference of it.
}

void Item::render(sf::RenderWindow& window, float x, float y, sf::Vector2i index){
    atlas.render(sf::Vector2f(x, y), index, window);
}
