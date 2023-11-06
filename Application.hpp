#include <SFML/Graphics.hpp>
#include "sidebar.hpp"
class Application{
public:
  Application(sf::RenderWindow*);
  // when this method returns, the game ends.
  // that or shit goes wrong.
  void startApp();
private:
    void handleEvents();
    void render();
    void update();
    Sidebar sidebar;
    sf::RenderWindow* window;
};
