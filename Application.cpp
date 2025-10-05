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
Application::Application(sf::RenderWindow* win) : m_font(new sf::Font()), tileatlas(TILE_FILE, global::tileHeight, global::tileWidth), draggedItem(offset(-1, -1), "", vec(0, 0), &tileatlas),
    maingame(&tileatlas), sidebar(&tileatlas) {
    tileatlas.set_scale(global::scale);
    printf("created application constructor \n");
    tileatlas.setFileParser(maingame.getFileParser());
    maingame.setSidebar(&sidebar);
    // open font
    m_font->openFromFile(FONT_FILE);
    // create completion text and start to setup
    elementNumber = new sf::Text(*m_font);
    elementNumber->setString("4/"+std::to_string(maingame.getFileParser()->getElementNumber()));
    
    elementNumber->setPosition({(global::width+50), (global::height-250)});

    // done with fonts
    // give the sidebar a reference to the font
    sidebar.init(m_font);
    sf::Texture* clritems;
    clritems = new sf::Texture;
    clritems->loadFromFile("resources/images/clearitems.png");
    clearItems = new uiButton(clritems, clritems, vec(global::width+128, 0));
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
    
    while (const std::optional event = window->pollEvent()){
        // first if statement!
        if (event->is<sf::Event::Closed>()) {window->close();}
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                window->close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
               // ====================================================================
                offset o = {-1, -1};
                if(!isMouseDragging){
                    o = sidebar.buttonclicked(vec(sf::Mouse::getPosition(*window)));
                    if(isOffset(o)){
                        draggedItem.set_offset(o);
                        isMouseDragging = true;
                    }
                }
                if(isMouseDragging)
                    draggedItem.set_position(vec(sf::Mouse::getPosition(*window)));
                if(!isMouseDragging)
                    o = maingame.getClickedItem(vec(sf::Mouse::getPosition(*window)));
                if(isOffset(o))
                    {
                        draggedItem.set_offset(o);
                        draggedItem.set_position(vec(sf::Mouse::getPosition(*window)));
                        isMouseDragging = true;
                    }
                if(clearItems->checkClick(vec(sf::Mouse::getPosition(*window)))){
                    maingame.clearItems();
                }
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
            isMouseDragging){
                draggedItem.set_position(vec(sf::Mouse::getPosition(*window)));
                maingame.spawnItem(draggedItem);
                isMouseDragging = false;
                clearItems->checkClick(vec(sf::Mouse::getPosition(*window)));
    }
}
}

void Application::render()
{
    window->clear(sf::Color(90,90,90));
    // render code here
    sidebar.render(*window);
    maingame.render(*window);
    if(isMouseDragging){
        draggedItem.render(*window);
    }
    clearItems->render(*window);
    // draw text for progress completion
    window->draw(*elementNumber);
    // too far!
    window->display();
}

void Application::update(){
    if(isMouseDragging){
        draggedItem.set_position(vec(sf::Mouse::getPosition(*window)));
    }
    elementNumber->setString(std::to_string(sidebar.getFoundElements())+" / "+std::to_string(maingame.getFileParser()->getElementNumber()));

}

// Not part of application class, but needs to be here
bool isOffset(offset o){
    if (o.x != -1 || o.y != -1){
        return true;
    }
    return false;
}
