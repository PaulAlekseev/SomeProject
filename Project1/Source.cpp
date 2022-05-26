#include "Header.h"

int main()
{
	window->setFramerateLimit(30);
	sf::Vector2f pos(50, 200);
	buttonInterface inter(pos, window, integers);
	historyTab tab(250, 25, "font/ostrich-regular.ttf", window);
	Button finish("COUNT", "font/ostrich-regular.ttf", 1, 1, 150, 50, 50, 425, window);
	Button clear("clear", "font/ostrich-regular.ttf", 1, 1, 150, 30, 50, 170, window);
	bool pressed = false;
	textField field1("0", "font/ostrich-regular.ttf", "L", 1, 1, 200, 50, 25, 25, window);
	textField field2("0", "font/ostrich-regular.ttf", "C", 1, 1, 200, 50, 25, 100, window);
	bool field1MinState = false;
	bool field2MinState = false;
	bool field1DotState = false;
	bool field2DotState = false;
	int floatnumber1 = 1;
	int floatnumber1eq = 0;
	int floatnumber2 = 1;
	int floatnumber2eq = 0;
	float number1 = 0;
	float number2 = 0;
	float result;
	while (window->isOpen())
	{
		sf::Event ev;
		while (window->pollEvent(ev))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (pressed) continue;
				else
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
					if (inter.clickedOnBoard(mousePosition))
					{
						if (inter.dotClicked(mousePosition))
						{
							if (field1.isActive())
							{
								if (field1DotState)
									field1DotState = false;
								else
									field1DotState = true;
							}
							if (field2.isActive())
							{
								if (field2DotState)
									field2DotState = false;
								else
									field2DotState = true;
							}
						}
						else
						{
							if (inter.minusClicked(mousePosition))
							{
								if (field1.isActive())
								{
									if (field1MinState)
										field1MinState = false;
									else
										field1MinState = true;
									number1 = -number1;
								}
								if (field2.isActive())
								{
									if (field2MinState)
										field2MinState = false;
									else
										field2MinState = true;
									number2 = -number2;
								}
							}
							else
							{
								float clickedNumber = (float)inter.getClickedInt(mousePosition);
								if (field1.isActive())
								{
									if (field1DotState)
									{
										if (field1MinState)
										{
											number1 = number1 + (float)floatnumber1eq / floatnumber1;
											floatnumber1 = floatnumber1 * 10;
											floatnumber1eq = floatnumber1eq * 10 + clickedNumber;
											number1 = number1 - (float)floatnumber1eq / floatnumber1;
										}
										if (!field1MinState)
										{
											number1 = number1 - (float)floatnumber1eq / floatnumber1;
											floatnumber1 = floatnumber1 * 10;
											floatnumber1eq = floatnumber1eq * 10 + clickedNumber;
											number1 = number1 + (float)floatnumber1eq / floatnumber1;
										}
									}
									else
									{
										if (field1MinState)
										{
											number1 = number1 * 10 - clickedNumber;
										}
										if (!field1MinState)
										{
											number1 = number1 * 10 + clickedNumber;
										}
									}
								}
								else
								{
									if (field2.isActive())
									{
										if (field2DotState)
										{
											if (field2MinState)
											{
												number2 = number2 + (float)floatnumber2eq / floatnumber2;
												floatnumber2 = floatnumber2 * 10;
												floatnumber2eq = floatnumber2eq * 10 + clickedNumber;
												number2 = number2 - (float)floatnumber2eq / floatnumber2;
											}
											if (!field2MinState)
											{
												number2 = number2 - (float)floatnumber2eq / floatnumber2;
												floatnumber2 = floatnumber2 * 10;
												floatnumber2eq = floatnumber2eq * 10 + clickedNumber;
												number2 = number2 + (float)floatnumber2eq / floatnumber2;
											}
										}
										else
										{
											if (field2MinState)
											{
												number2 = number2 * 10 - clickedNumber;
											}
											if (!field2MinState)
											{
												number2 = number2 * 10 + clickedNumber;
											}
										}
									}
								}
							}
						}
					}
					if (field1.wasClicked(mousePosition))
					{
						field1.activate();
						field2.deactivate();
					}
					if (field2.wasClicked(mousePosition))
					{
						field2.activate();
						field1.deactivate();
					}
					if (finish.wasClicked(mousePosition))
					{
						if ((number1 * number2) < 0)
						{
							tab.addField("ERROR");
						}
						else
						{
							result = 2 * M_PI * sqrt(number1 * number2);
							std::string string1 = std::to_string(result);
							tab.addField(string1);
						}
					}
					if (clear.wasClicked(mousePosition))
					{
						number1 = 0;
						number2 = 0;
						floatnumber1 = 1;
						floatnumber2 = 1;
						floatnumber1eq = 0;
						floatnumber2eq = 0;
						field1MinState = false;
						field2MinState = false;
						field1DotState = false;
						field2DotState = false;
					}
					pressed = true;
					continue;
				}
				continue;
			}
			pressed = false;
		}
		field1.changeText(std::to_string(number1));
		field2.changeText(std::to_string(number2));
		window->clear(sf::Color(30, 30, 30));
		field1.draw();
		field2.draw();
		inter.draw();
		finish.draw();
		clear.draw();
		tab.draw();
		window->display();
	}
}