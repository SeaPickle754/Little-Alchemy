#include <SFML/Graphics.hpp>
#include <cassert>
#include "globals.h"
#include "TextureAtlas.hpp"
#include "sidebar.hpp"
#include "item.hpp"
#include "main_game.hpp"
// include various UI elements
#include "ui/Button.hpp"
#include <string>
class Application{
public:
    Application(sf::RenderWindow*);
    // when this method returns, the game ends.
    // that or ---- goes wrong.
    void startApp();
    TextureAtlas* getTextureAtlas();
private:
    void handleEvents();
    void render();
    void update();
    Sidebar sidebar;
    Item draggedItem;
    TextureAtlas tileatlas;
    MainGame maingame;
    sf::RenderWindow* window;
    uiButton* clearItems;
    bool isMouseDragging;

    // for storing which button the mouse clicked on
    offset selection;
};
