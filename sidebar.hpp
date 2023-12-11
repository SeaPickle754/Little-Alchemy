# pragma once
#include <SFML/Graphics.hpp>
// for globals.
#include "globals.h"
#include "item.hpp"
#include "TextureAtlas.hpp"
#include "itemButton.hpp"
#include <vector>
#include <cassert>
#include "logger.hpp"

const sf::Color bgcolor = sf::Color(255, 255, 200);

class Sidebar{
private:
    sf::RectangleShape bg;
    std::vector<Button> items;
    TextureAtlas* m_atlas;
public:
    Sidebar(TextureAtlas*);
    void render(sf::RenderWindow&);
    offset buttonclicked(vec position);
    void addElement(offset n_offset);
};
