#include <SFML/Graphics.hpp>
// for globals.
#include "globals.h"
#include "item.hpp"
#include "TextureAtlas.hpp"
#include <vector>
#include <cmath>
using std::floor;

const sf::Color bgcolor = sf::Color(255, 255, 200);

class Sidebar{
private:
    sf::RectangleShape bg;
    std::vector<Item> items;
    TextureAtlas* m_atlas;
public:
    Sidebar(TextureAtlas*);
    void render(sf::RenderWindow&);
};
