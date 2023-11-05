#include "Application.hpp"

Application::Application(sf::RenderWindow* win){
    // mem leak??
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
    window->display();
}

void Application::update(){
}
