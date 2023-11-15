#include "sidebar.hpp"

Sidebar::Sidebar(TextureAtlas* atlas) : testButton(vec(0,0), sf::Vector2i(0,0), atlas){
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
    testButton.render(window);
    for(auto i = items.begin(); i != items.end(); i++){
        i->render(window);
    }
}

offset Sidebar::buttonclicked(vec position){
    if(testButton.onClick(position)){
            // hard coded 4 now
        return offset(0, 0);
    }
    // this tells it not to run some code some where else.
    return offset(-1, -1);
}
