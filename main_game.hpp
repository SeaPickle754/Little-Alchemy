#include <SFML/Graphics.hpp>
#include <vector>
#include "TextureAtlas.hpp"
#include "Sidebar.hpp"
#include "item.hpp"
#include <stdio.h>
// a class that allows me to read in reactions
#include "itemparser.hpp"

class MainGame{
private:
    std::vector<Item> items;
    TextureAtlas* m_texture;
    FileParser* m_fileParser;
    Sidebar* m_sidebar;
public:
    MainGame(TextureAtlas* texture);
    inline void clearItems() {items.erase(items.begin(), items.end());}
    void spawnItem(sf::Vector2f position, sf::Vector2i offset, sf::String name);
    offset getClickedItem(vec position);
    void render(sf::RenderWindow& window);
    inline void spawnItem(Item& i) {spawnItem(i.get_position(), i.get_offset(), i.getName());}
    inline void setSidebar(Sidebar* sidebar) {m_sidebar = sidebar;}
    inline FileParser* getFileParser(){return m_fileParser;}
};
