#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureAtlas.hpp"
#include "item.hpp"
// a class that allows me to read in reactions
#include "itemparser.hpp"

class MainGame{
private:
    std::vector<Item> items;
    TextureAtlas* m_texture;
    FileParser fileParser;
public:
    MainGame(TextureAtlas* texture);
    void spawnItem(sf::Vector2f position, sf::Vector2i offset, sf::String name);
    void render(sf::RenderWindow& window);
    inline void spawnItem(Item& i) {spawnItem(i.get_position(), i.get_offset(), i.getName());}
};
