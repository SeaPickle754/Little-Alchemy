#include "sidebar.hpp"

Sidebar::Sidebar(TextureAtlas* atlas){
    bg.setPosition(sf::Vector2f(0,0));
    // this just gets the correct width and height of the sidebar relative to the window.
    bg.setSize(sf::Vector2f(std::floor(global::width / 4), global::height));
    bg.setFillColor(bgcolor);
    bg.setOutlineColor(sf::Color(127,124, 127));
    m_atlas = atlas;
    for(int i = 0; i < 4; i++){
        items.push_back(Item(sf::Vector2i(i, 0), "Aqui.", sf::Vector2f(0, i*32), m_atlas));
    }
}

void Sidebar::render(sf::RenderWindow& window){
    window.draw(bg);
    for(auto i = items.begin(); i != items.end(); i++){
        i->render(window);
    }
}
