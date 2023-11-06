#include <SFML/Graphics.hpp>
// for globals.
#include "globals.h"
#include <cmath>
using std::floor;

const sf::Color bgcolor = sf::Color(255, 255, 200);

class Sidebar{
private:
    sf::RectangleShape bg;
public:
    Sidebar();
    void render(sf::RenderWindow&);
};
