#pragma once
#include "globals.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <stdio.h>

struct AchievementData
{
    sf::String name;
    sf::String description;
    bool rare;
};

class Achievement{
public:
    Achievement(sf::Font* font);
    void init(sf::Font* font);
    void createAchievement(sf::String name, sf::String description, bool isRare);
    // frame time in ms
    void updateAchievements(sf::RenderWindow&, float frameTime);
    ~Achievement();
private:
    sf::Font* m_font;
    sf::Text topText;
    sf::Text bottomText;
    float timer = -1.f;
    sf::RectangleShape bg;
    bool isAchievementDisplaying;
    // create vector of name/description pairs
    std::vector<AchievementData> achievements;
    void drawAchievement(sf::RenderWindow&);
    // given a created element given, check if it is equal to the trigger element.
    // if so, create the given achievement.
    // returns whether it created an achievement or not.
    bool achievementOnCreation(offset given, offset trigger, sf::String name, sf::String description, bool isRare);
};
