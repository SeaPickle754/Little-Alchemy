#pragma once
// we don't want our globals coupled to everything, so we will just include specific files.
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
// TODO: change to glob.
namespace global{
    const int height = 900;
    const int width = 700;
    const float scale = 2.f;
    // TODO: make this dynamic
    const int buttonx = 175;
    const int buttony = 35;
    const sf::Color button_color = sf::Color(100, 100, 100);
};
typedef sf::Vector2i offset;
typedef sf::Vector2f vec;
#define SAFE_DELETE(ptr) if (ptr != NULL){delete ptr; ptr = 0;}
