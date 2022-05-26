#pragma once
#include "textField.h"
class historyTab
{
private:
	std::vector <textField*> tabs;
	sf::RenderWindow* window;
	sf::Vector2f* position;
	sf::RectangleShape* shape;
	sf::RectangleShape* shape2;
	sf::Font* font;
	sf::Text* text;

public:
	historyTab(int posX, int posY, std::string fontPath, sf::RenderWindow* window);

	void draw();
	void addField(std::string result);
};

