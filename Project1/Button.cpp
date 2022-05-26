#include "Button.h"


Button::Button(std::string string, std::string fontPath, int scaleX, int scaleY, int shapeSizeX, int shapeSizeY, int positionX, int positionY, sf::RenderWindow* window)
{
	// Configuring font
	this->font = new sf::Font();
	font->loadFromFile(fontPath);


	// Configuring Shape
	this->shapeSize = new sf::Vector2f(shapeSizeX, shapeSizeY);
	this->shape = new sf::RectangleShape(*shapeSize);
	this->shape->setOutlineColor(sf::Color(30, 30, 30));
	this->shape->setOutlineThickness(1);
	this->position = new sf::Vector2f(positionX, positionY);
	this->shape->move(*this->position);

	// Configuring Text
	this->string = string;
	this->text = new sf::Text();
	this->textScale = new sf::Vector2f(scaleX, scaleY);
	this->text->setScale(*this->textScale);
	this->text->setString(this->string);
	this->text->setFont(*this->font);
	this->text->setPosition(positionX + this->shapeSize->x / 2 - this->text->getLocalBounds().width * scaleX / 2, positionY + this->shapeSize->y / 2 - this->text->getLocalBounds().height * scaleY);
	this->text->setFillColor(sf::Color::Black);

	// Configuring Window
	this->window = window;
}


void Button::draw()
{
	this->window->draw(*this->shape);
	this->window->draw(*this->text);
}


bool Button::wasClicked(sf::Vector2i mousePosition)
{
	if (mousePosition.x < this->position->x + this->shapeSize->x && mousePosition.x > this->position->x)
	{
		if (mousePosition.y < this->position->y + this->shapeSize->y && mousePosition.y > this->position->y)
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}


