#include "main_game.hpp"

MainGame::MainGame(TextureAtlas* texture, Sidebar* sidebr) : fileParser(){
    m_texture = texture;
    m_sidebar = sidebr;

}

offset MainGame::getClickedItem(vec position){
    for(auto i = items.begin(); i != items.end(); i++){
        if(i->isClicked(position)){
            offset o = i->get_offset();
            items.erase(i);
            return o;
        }
    }
    return offset(-1, -1);
}

void MainGame::spawnItem(sf::Vector2f position, sf::Vector2i n_offset, sf::String name){
    Item n_item(n_offset, name, position, m_texture);
    for(auto i = items.begin(); i!= items.end(); i++){
        bool checker;
        checker = (i->isColliding(n_item.getRect()));
        if(checker){
            offset product = fileParser.getProduct(n_item.get_offset(), i->get_offset());
            if(product.x != -1 && product.y != -1){
                n_item.set_offset(product);
                m_sidebar->addElement(product);
                items.erase(i);
                break;
            }
        }
    }

    items.push_back(n_item);
}

void MainGame::render(sf::RenderWindow& window){
    for(auto i = items.begin(); i != items.end(); i++){
        i->render(window);
    }

}
