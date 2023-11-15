#include "Application.hpp"

// prototype for dumb function i use later
bool isOffset(offset o);

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
    // if a mouse button pressed...
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        if(isOffset(sidebar.buttonclicked(vec(sf::Mouse::getPosition(*window))))){
            offset offset_ = sidebar.buttonclicked(vec(sf::Mouse::getPosition(*window)));
            maingame.spawnItem(vec(300, 300), offset_, "n");
        }
    }
}

// Not part of application class, but needs to be here
bool isOffset(offset o){
    if (o.x != -1 || o.y != -1){
        return true;
    }
    return false;
}
