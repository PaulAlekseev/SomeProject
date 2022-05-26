#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>



class Button
{

private:
	sf::Font* font;
	sf::Text* text;
	sf::RectangleShape* shape;
	sf::Vector2f* shapeSize;
	sf::Vector2f* textScale;
	std::string string;
	sf::Vector2f* position;
	sf::RenderWindow* window;

public:
	Button(std::string string, std::string fontPath, int scaleX, int scaleY, int shapeSizeX, int shapeSizeY, int positionX, int positionY, sf::RenderWindow* window);

	void draw();
	bool wasClicked(sf::Vector2i mousePosition);
};
