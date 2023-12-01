#ifndef GLOBALS_H
#define GLOBALS_H
// we don't want our globals coupled to everything, so we will just include specific files.
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
// TODO: change to glob.
namespace global{
    const int height = 900;
    const int width = 700;
    // these are for the default tile height and width
    // before scaling is applied
    const int tileHeight = 16;
    const int tileWidth = 16;
    const float scale = 2.f;
    // file names for itemparser.hpp
    // TODO: make this dynamic
    const int buttonx = 175;
    const int buttony = 35;
    const sf::Color button_outline_color = sf::Color(0,0,0);
    const sf::Color button_color = sf::Color(100, 100, 100);
};
typedef sf::Vector2i offset;
typedef sf::Vector2f vec;
#define OFFSET_FILE "resources/offsets.csv"
#define REACTION_FILE "resources/combinations.csv"
    // i love the name of this
#define TILE_FILE "resources/images/tiles.png"

#define SAFE_DELETE(ptr) if (ptr != NULL){delete ptr; ptr = 0;}

#endif // GLOBALS_H
