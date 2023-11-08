#include <SFML/Graphics.hpp>
// for globals.
#include "globals.h"
#include "item.hpp"
#include <cmath>
using std::floor;

const sf::Color bgcolor = sf::Color(255, 255, 200);

class Sidebar{
private:
    sf::RectangleShape bg;
    Item* testItem;
public:
    Sidebar();
    void render(sf::RenderWindow&);
};
