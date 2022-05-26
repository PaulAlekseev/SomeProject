#include "buttonInterface.h"


buttonInterface::buttonInterface(sf::Vector2f position, sf::RenderWindow* window, int integers[])
{
	this->position = position;
	for (int i = 0; i < 10; i++)
	{
		this->integerButtons[i] = integers[i];
	}
	int number2 = 0;
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			std::string str = std::to_string(integerButtons[number2]);
			this->Buttons.push_back(new Button(str, "font/ostrich-regular.ttf", 1, 1, 50, 50, this->position.x + 50 * k, this->position.y + 50 * j, window));
			number2++;
		}
	}
	std::string str = std::to_string(integerButtons[9]);
	Buttons.push_back(new Button(str, "font/ostrich-regular.ttf", 1, 1, 50, 50, this->position.x + 50 * 1, this->position.y + 50 * 3, window));
	Buttons.push_back(new Button("-/+", "font/ostrich-regular.ttf", 1, 1, 50, 50, this->position.x + 50 * 0, this->position.y + 50 * 3, window));
	Buttons.push_back(new Button("'", "font/ostrich-regular.ttf", 1, 1, 50, 50, this->position.x + 50 * 2, this->position.y + 50 * 3, window));

}


void buttonInterface::draw()
{
	for (int i = 0; i < 12; i++)
	{
		Buttons[i]->draw();
	}
}


bool buttonInterface::clickedOnBoard(sf::Vector2i mousePosition)
{
	if (mousePosition.x < this->position.x + 150 && mousePosition.x > this->position.x)
	{
		if (mousePosition.y < this->position.y + 200 && mousePosition.y > this->position.y)
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


bool buttonInterface::clickedInteger(sf::Vector2i mousePosition)
{
	if (mousePosition.x < this->position.x + 150 && mousePosition.x > this->position.x)
	{
		if (mousePosition.y < this->position.y + 150 && mousePosition.y > this->position.y)
			return true;
		else
			return false;
	}
	else
		return false;
}


int buttonInterface::getClickedInt(sf::Vector2i mousePosition)
{
	for (int i = 0; i < 10; i++)
	{
		if (this->Buttons[i]->wasClicked(mousePosition))
		{
			return integerButtons[i];
		}
	}
}

bool buttonInterface::minusClicked(sf::Vector2i mousePosition)
{
	if (this->Buttons[10]->wasClicked(mousePosition))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool buttonInterface::dotClicked(sf::Vector2i mousePosition)
{
	if (this->Buttons[11]->wasClicked(mousePosition))
	{
		return true;
	}
	else
	{
		return false;
	}
}

