#include "Achievement.hpp"

Achievement::Achievement(sf::Font* font) : topText(*font), bottomText(*font){
	timer = -1.f;
    bg.setPosition(sf::Vector2f(global::width/3,0));
    bg.setSize(sf::Vector2f(global::width/2, 40));
    bg.setFillColor(sf::Color(255, 255, 200));
    bg.setOutlineColor(sf::Color(127,124, 127));
    isAchievementDisplaying = false;
}

void Achievement::init(sf::Font* font){
    m_font = font;
	topText.setString("");
    topText.setPosition(sf::Vector2f(global::height/3+5, +5));
    topText.setCharacterSize(15);
    topText.setFont(*m_font);
    topText.setFillColor(sf::Color(0,0,0));
    bottomText.setFillColor(sf::Color(0,0,0));
    bottomText.setFont(*m_font);
    bottomText.setString("");
    bottomText.setPosition(sf::Vector2f(global::height/3+5, +18));
    bottomText.setCharacterSize(15);
}

void Achievement::createAchievement(sf::String name, sf::String description, bool isRare){
    printf("Adding new achievement!\n");
    achievements.push_back({name,description,isRare});
    puts("Finished adding new achievement.");
}

void Achievement::drawAchievement(sf::RenderWindow& window){
    window.draw(bg);
    window.draw(bottomText);
    window.draw(topText);
}

void Achievement::updateAchievements(sf::RenderWindow& window, float frameTime){
    // if there is an acheivement but there isnt a timer running we must have just gotten it
    // therefore start the timer and display the acheivement
    if(!achievements.empty()&& timer==-1){
        puts("detected new achievement");
        if(achievements.begin()->rare)
            timer = global::ACHIEVEMENT_RARE_TIME;
        else
            timer = global::ACHIEVEMENT_NORMAL_TIME;
        isAchievementDisplaying = true;
        topText.setString(achievements.begin()->name);
        bottomText.setString(achievements.begin()->description);
        puts("setup achievement");
    }
    if(timer > 0 && isAchievementDisplaying){
        timer-=frameTime;
        drawAchievement(window);
    }
    if(isAchievementDisplaying && timer <= 0){
        isAchievementDisplaying = false;
        achievements.erase(achievements.begin());
        timer = -1;
    }
}
bool Achievement::achievementOnCreation(offset given, offset trigger, sf::String name, sf::String description, bool isRare){
    if(given == trigger){
        createAchievement(name, description, isRare);
        return true;
    }else{
        return false;
    }

}
// destructor
Achievement::~Achievement(){

}
