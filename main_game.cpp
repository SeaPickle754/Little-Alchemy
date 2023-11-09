#include "main_game.hpp"

MainGame::MainGame(TextureAtlas* texture){
    m_texture = texture;
}

void MainGame::spawnItem(sf::Vector2f position, sf::Vector2i offset, sf::String name){
    items.push_back(Item(offset, name, position, m_texture));
}

void MainGame::render(sf::RenderWindow& window){
    for(auto i = items.begin(); i != items.end(); i++){
        i->render(window);
    }

}
