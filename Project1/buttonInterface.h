#pragma once
#include "Button.h"
#include <iostream>


class buttonInterface
{
private:
	std::vector <Button*> Buttons;
	int integerButtons[9];
	std::string stringButtons[2];
	sf::RenderWindow* window;
	sf::Vector2f position;

public:
	buttonInterface(sf::Vector2f position, sf::RenderWindow* window, int integers[]);

	void draw();

	bool clickedOnBoard(sf::Vector2i mousePosition);
	bool clickedInteger(sf::Vector2i mousePosition);
	int getClickedInt(sf::Vector2i mousePosition);
	bool minusClicked(sf::Vector2i mousePosition);
	bool dotClicked(sf::Vector2i mousePosition);
};

