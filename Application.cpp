#include "Application.hpp"

// prototype for dumb function i use later
bool isOffset(offset o);

/*
* Bad code: a poem
* a locater class would be much better
* but whatever
* i could do all that work
* or i could just be a jerk
* arcitecture is good
* but getting a working game is better
* Thank you!!
*/
Application::Application(sf::RenderWindow* win) : tileatlas("images/tiles.png", 16, 16), sidebar(&tileatlas),
draggedItem(offset(-1, -1), "", vec(0, 0), &tileatlas), maingame(&tileatlas){
    tileatlas.set_scale(global::scale);
    window = win;
    isMouseDragging = false;
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
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
               // if a mouse button pressed...
               // TODO: put this in a function
               // ====================================================================
                offset o = sidebar.buttonclicked(vec(sf::Mouse::getPosition(*window)));
                if(isOffset(o)){
                    draggedItem.set_offset(o);
                    isMouseDragging = true;
                }
        }
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left &&
            isMouseDragging){
                draggedItem.set_position(vec(sf::Mouse::getPosition(*window)));
                maingame.addItem(draggedItem);
                isMouseDragging = false;
    }
    }
}

void Application::render()
{
    window->clear(sf::Color(90,90,90));
    // render code here
    if(isMouseDragging){
        draggedItem.render(*window);
    }
    sidebar.render(*window);
    maingame.render(*window);
    // too far!
    window->display();
}

void Application::update(){
    if(isMouseDragging){
        draggedItem.set_position(vec(sf::Mouse::getPosition(*window)));
    }
}

// Not part of application class, but needs to be here
bool isOffset(offset o){
    if (o.x != -1 || o.y != -1){
        return true;
    }
    return false;
}
