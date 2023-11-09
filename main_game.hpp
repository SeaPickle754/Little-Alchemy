#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureAtlas.hpp"
#include "item.hpp"

class MainGame{
private:
    std::vector<Item> items;
    TextureAtlas* m_texture;
public:
    MainGame(TextureAtlas* texture);
    void spawnItem(sf::Vector2f position, sf::Vector2i offset, sf::String name);
    void render(sf::RenderWindow& window);
};
