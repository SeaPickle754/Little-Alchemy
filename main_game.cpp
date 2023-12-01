#include "main_game.hpp"

MainGame::MainGame(TextureAtlas* texture) : fileParser(){
    m_texture = texture;

}

void MainGame::spawnItem(sf::Vector2f position, sf::Vector2i n_offset, sf::String name){
    Item n_item(n_offset, name, position, m_texture);
    for(auto i = items.begin(); i!= items.end(); i++){
        offset checker;
        checker = (i->isColliding(n_item.getRect()));
        if(checker.y != -1 && checker.x != -1){
                sf::Vector2i product = fileParser.getProduct(n_item.get_offset(), checker);
                items.push_back(Item(product, "e.", n_item.get_position(), m_texture));
                items.erase(i);
                return;
        }
    }

    items.push_back(Item(n_offset, name, position, m_texture));
}

void MainGame::render(sf::RenderWindow& window){
    for(auto i = items.begin(); i != items.end(); i++){
        i->render(window);
    }

}
