#include "Sidebar.hpp"


Sidebar::Sidebar(TextureAtlas* atlas){
    bg.setPosition(sf::Vector2f(0,0));
    // this just gets the correct width and height of the sidebar relative to the window.
    bg.setSize(sf::Vector2f(std::floor(global::width / 4), global::height));
    bg.setFillColor(bgcolor);
    bg.setOutlineColor(sf::Color(127,124, 127));
    m_atlas = atlas;

}


void Sidebar::init(sf::Font* font){
    m_font = font;
    for(int i = 0; i < 4; i++){
        items.push_back(Button(vec(0, i*32), offset(i, 0), m_atlas, m_font));
    }
}


void Sidebar::render(sf::RenderWindow& window){
    window.draw(bg);
    for(auto i = items.begin(); i != items.end(); i++){
        i->render(window);
    }
}


bool Sidebar::isMouseOver(float mouseX){
    if(mouseX > 0 && mouseX < std::floor(global::width/4))
        return true;
    return false;
}


offset Sidebar::buttonclicked(vec position){
    for(auto i = items.begin(); i != items.end(); i++){
        if(i->onClick(position)){
            return i->getOffset();
        }
    }
    return offset(-1, -1);
}


void Sidebar::scroll(float delta, float mouseX){
    // delta is change (scroll distance)
	printf("Delta: %f\n", delta);
	if(isMouseOver(mouseX)){
		// if scrolling down
		if(delta > 0){
			// dont allow the top element to scroll farther down than top of screen
			if(!(items.begin()->getPosition().y > 0)){
				for(auto i = items.begin(); i != items.end(); i++){
					i->move({0, delta*global::SCROLL_MULTIPLIER});
				}
			}
		}
		// if scrolling down dont allow the bottom element to leave the bottom of the screen
		else if(delta < 0){
			sf::Vector2f bePos = items.back().getPosition();
			// if it is lower than bottom of screen scroll
			printf("bePos+32: %f\n", (bePos.y+32));
			// TODO: Swap height and width
			if(bePos.y+32>(global::width)){
				for(auto i = items.begin(); i != items.end(); i++){
					i->move({0, delta*global::SCROLL_MULTIPLIER});
				}

			}
		}
    }
}



void Sidebar::addElement(offset n_offset){
    // assert that the vec is never empty
    assert(items.size() != 0);
    // if not already in the list
    for(auto i = items.begin(); i!= items.end(); i++){
        if(i->getOffset() == n_offset)
            return;
    }
// add it to the list
    auto last = items[items.size()-1];
    vec pos = last.getPosition();
    pos.y += global::buttony;
    Button button = Button(pos, n_offset, m_atlas, m_font);
    sf::String name = button.getName();
    items.push_back(button);
    // electricity
    if(n_offset == sf::Vector2i({0, 3})){
        m_achievement->createAchievement("The Modern Age","Create Electricity.",false);
    }
    // time
    else if (n_offset == sf::Vector2i({0,7})){
        m_achievement->createAchievement("Master of It", "Create Time", true);
    }
    // Sunset
    else if (n_offset == sf::Vector2i({1,5})){
        m_achievement->createAchievement("The Skyfire Circle", "Create Sunset.", false);
    }
    // water bottle
    else if (n_offset == sf::Vector2i({3, 7})){
        m_achievement->createAchievement("Bottl o' water", "Create a way to store water.", false);
    }
    else if (n_offset == sf::Vector2i({2, 6})){
        m_achievement->createAchievement("sussus amogus","Create a masterpiece.", true);
    }
}

