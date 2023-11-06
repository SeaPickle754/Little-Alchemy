#include <SFML/Graphics.hpp>
#include "Application.hpp"
#include "globals.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(global::height, global::width), "Little alchemy 3", sf::Style::Close);

    Application app(&window);

    app.startApp();
    return 0;
}
