#include "sidebar.hpp"

Sidebar::Sidebar(){
    testItem = new Item();
    bg.setPosition(sf::Vector2f(0,0));
    // this just gets the correct width and height of the sidebar relative to the window.
    bg.setSize(sf::Vector2f(std::floor(global::width / 4), global::height));
    bg.setFillColor(bgcolor);
    bg.setOutlineColor(sf::Color(127,124, 127));
}

void Sidebar::render(sf::RenderWindow& window){
    window.draw(bg);
    for(int i = 0; i < 4; i++){
        testItem->render(window, 0, i*32, sf::Vector2i(i, 0));
    }
}
