#include "Sidebar.hpp"


Sidebar::Sidebar(TextureAtlas* atlas){
    bg.setPosition(sf::Vector2f(0,0));
    // this just gets the correct width and height of the sidebar relative to the window.
    bg.setSize(sf::Vector2f(std::floor(global::width / 4), global::height));
    bg.setFillColor(bgcolor);
    bg.setOutlineColor(sf::Color(127,124, 127));
    m_atlas = atlas;
   
}
void Sidebar::init(sf::Font* font){
    m_font = font;
    for(int i = 0; i < 4; i++){
        items.push_back(Button(vec(0, i*32), offset(i, 0), m_atlas, m_font));
    }
}
void Sidebar::render(sf::RenderWindow& window){
    window.draw(bg);
    for(auto i = items.begin(); i != items.end(); i++){
        i->render(window);
    }
}

offset Sidebar::buttonclicked(vec position){
    for(auto i = items.begin(); i != items.end(); i++){
    if(i->onClick(position)){
        return i->getOffset();
    }
    }
    return offset(-1, -1);
}
void Sidebar::addElement(offset n_offset){
    // assert that the vec is never empty
    assert(items.size() != 0);
    // if not already in the list
    for(auto i = items.begin(); i!= items.end(); i++){
        if(i->getOffset() == n_offset)
            return;
    }
// add it to the list
    auto last = items[items.size()-1];
    vec pos = last.getPosition();
    pos.y += global::buttony;
    items.push_back(Button(pos, n_offset, m_atlas, m_font));
}

