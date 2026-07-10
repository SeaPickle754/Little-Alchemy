# pragma once
#include <SFML/Graphics.hpp>
// for globals.
#include "globals.h"
#include "item.hpp"
#include "TextureAtlas.hpp"
#include "itemButton.hpp"
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
using std::floor;
#include "logger.hpp"
#include "Achievement.hpp"
const sf::Color bgcolor = sf::Color(255, 255, 200);

class Sidebar{
private:
    sf::RectangleShape bg;
    std::vector<Button> items;
    TextureAtlas* m_atlas;
    sf::Font* m_font;
    Achievement* m_achievement;
public:
    Sidebar(TextureAtlas*);
    inline int getFoundElements(){return items.size();}
    void scroll(float delta, float);
    bool isMouseOver(float);
    void init(sf::Font*);
    void render(sf::RenderWindow&);
    offset buttonclicked(vec position);
    void addElement(offset n_offset);
    Achievement* getAchievement(){return m_achievement;}
    void setAchievement(Achievement* achievement){m_achievement = achievement;}
};
