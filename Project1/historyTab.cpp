#include "historyTab.h"


historyTab::historyTab(int posX, int posY, std::string fontPath, sf::RenderWindow* window)
{
	this->position = position;
	this->window = window;

	// Configuring tab's window
	this->position = new sf::Vector2f(posX, posY);
	this->shape = new sf::RectangleShape(sf::Vector2f(200, 400));
	this->shape->move(*this->position);
	this->shape2 = new sf::RectangleShape(sf::Vector2f(200, 50));
	this->shape2->move(*this->position);
	this->shape2->setOutlineColor(sf::Color::Black);
	this->shape2->setOutlineThickness(1);
	this->font = new sf::Font();
	this->font->loadFromFile(fontPath);
	this->text = new sf::Text();
	this->text->setFont(*this->font);
	this->text->setString("History");
	this->text->setPosition(posX + this->shape2->getLocalBounds().width / 2 - this->text->getLocalBounds().width / 2, posY + this->shape2->getLocalBounds().height / 2 - this->text->getLocalBounds().height);
	this->text->setFillColor(sf::Color::Black);
}


void historyTab::draw()
{
	this->window->draw(*this->shape);
	this->window->draw(*this->shape2);
	this->window->draw(*this->text);
	if (tabs.size() > 0)
	{
		for (int i = 0; i < this->tabs.size(); i++)
		{
			tabs[i]->draw();
		}
	}
}


void historyTab::addField(std::string result)
{
	if (tabs.size() == 7)
	{
		this->tabs.erase(this->tabs.begin());
	}
	if (tabs.size() > 0)
	{
		for (int i = 0; i < this->tabs.size(); i++)
		{
			tabs[i]->move(0, 50);
		}
	}
	this->tabs.push_back(new textField(result, "font/ostrich-regular.ttf", "Last", 1, 1, 200, 50, this->shape->getPosition().x, this->shape->getPosition().y + this->shape2->getLocalBounds().height, this->window));
}