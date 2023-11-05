#include <SFML/Graphics.hpp>
#include "Application.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(900, 700), "Little alchemy 3", sf::Style::Close);

    Application app(&window);

    app.startApp();
    return 0;
}
