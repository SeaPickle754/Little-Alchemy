#include "Application.hpp"

Application::Application(sf::RenderWindow* win) : tileatlas("images/tiles.png", 16, 16), sidebar(&tileatlas),
 maingame(&tileatlas){
    tileatlas.set_scale(global::scale);
    window = win;
}

void Application::startApp()
{
    // is window closes, then so should the game
    while(window->isOpen()){
        handleEvents();
        update();
        render();
    }
}

void Application::handleEvents()
{
    sf::Event event;
    while (window->pollEvent(event)){
        // first if statement!
        if (event.type == sf::Event::Closed) {window->close();}
        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Escape) {window->close();}
            if (event.key.code == sf::Keyboard::A) {maingame.spawnItem(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)),
                                                                       sf::Vector2i(1,0), "Earth.");}
        }
    }
}

void Application::render()
{
    window->clear(sf::Color(90,90,90));
    // render code here
    sidebar.render(*window);
    maingame.render(*window);
    // too far!
    window->display();
}

void Application::update(){
}
