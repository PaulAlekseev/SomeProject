#include "textField.h"


textField::textField(std::string string, std::string fontPath, std::string activeString, int scaleX, int scaleY, int shapeSizeX, int shapeSizeY, int positionX, int positionY, sf::RenderWindow* window)
{
	// Configuring font
	this->font = new sf::Font();
	font->loadFromFile(fontPath);


	// Configuring Shape
	this->shapeSize = new sf::Vector2f(shapeSizeX, shapeSizeY);
	this->shape = new sf::RectangleShape(*shapeSize);
	this->position = new sf::Vector2f(positionX, positionY);
	this->shape->setOutlineColor(sf::Color::Black);
	this->shape->setOutlineThickness(1);
	this->shape->move(*this->position);

	// Configuring Text
	this->string = string;
	this->text = new sf::Text();
	this->textScale = new sf::Vector2f(scaleX, scaleY);
	this->text->setScale(*this->textScale);
	this->text->setString(this->string);
	this->text->setFont(*this->font);
	this->text->setPosition(positionX + this->shapeSize->x - this->text->getLocalBounds().width * scaleX - 5, positionY + this->shapeSize->y / 2 - this->text->getLocalBounds().height * scaleY);
	this->text->setFillColor(sf::Color::Black);

	// Configuring active indicator
	this->activeText = new sf::Text();
	this->activeText->setScale(*this->textScale);
	this->activeText->setString(activeString);
	this->activeText->setFont(*this->font);
	this->activeText->setPosition(positionX + 5, positionY + this->shapeSize->y / 2 - this->text->getLocalBounds().height * scaleY);
	this->activeText->setFillColor(sf::Color::Black);

	// Configuring Window
	this->window = window;

	// Configuring boolean parameters
	this->active = false;
}

void textField::draw()
{
	this->window->draw(*this->shape);
	this->window->draw(*this->text);
	if (this->active)
	{
		this->window->draw(*this->activeText);
	}
}

bool textField::wasClicked(sf::Vector2i mousePosition)
{
	if (mousePosition.x < this->position->x + this->shapeSize->x && mousePosition.x > this->position->x)
	{
		if (mousePosition.y < this->position->y + this->shapeSize->y && mousePosition.y > this->position->y)
			return true;
		else
			return false;
	}
	else
		return false;
}

void textField::deactivate()
{
	this->active = false;
}

void textField::activate()
{
	this->active = true;
}

void textField::move(int x, int y)
{
	sf::Vector2f pos = sf::Vector2f(x, y);
	this->shape->move(pos);
	this->text->move(pos);
	this->activeText->move(pos);
}

void textField::changeText(std::string text)
{
	this->text->setString(text);
	this->text->setPosition(this->shape->getPosition().x + this->shapeSize->x - this->text->getLocalBounds().width * this->text->getScale().x - 5, this->shape->getPosition().y + this->shapeSize->y / 2 - this->text->getLocalBounds().height * this->text->getScale().y);
}

bool textField::isActive()
{
	if (this->active)
	{
		return true;
	}
	else
	{
		return false;
	}
}
