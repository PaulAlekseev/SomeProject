#pragma once
#include "buttonInterface.h"

class textField
{

private:
	sf::Font* font;
	sf::Text* text;
	sf::Text* activeText;
	sf::RectangleShape* shape;
	sf::Vector2f* shapeSize;
	sf::Vector2f* textScale;
	std::string string;
	sf::Vector2f* position;
	sf::RenderWindow* window;
	bool active;

public:
	textField(std::string string, std::string fontPath, std::string activeString, int scaleX, int scaleY, int shapeSizeX, int shapeSizeY, int positionX, int positionY, sf::RenderWindow* window);

	void draw();
	bool wasClicked(sf::Vector2i mousePosition);
	void deactivate();
	void activate();
	void move(int x, int y);
	void changeText(std::string text);
	bool isActive();
};

