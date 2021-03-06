#include "Button.h"

Button::Button()
{
	if (!font.loadFromFile("font/JMH_Typewriter.ttf"))
		std::cout << "font load error";

	text.setFont(font);
	text.setCharacterSize(36);
	
}

void Button::set_borders(float up, float down, float left, float right)
{
	up_border = up;
	down_border = down;
	left_border = left;
	right_border = right;

	text.setPosition(left_border, up_border);
}


void Button::set_text(std::wstring str)
{
	text.setString(str);
}

void Button::set_scale(float x, float y)
{
	text.setScale(sf::Vector2f(x, y));
}

bool Button::mouse_over(sf::RenderWindow &window)
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

	if (mouse_position.x > left_border
		&&	mouse_position.x < right_border
		&& 	mouse_position.y > up_border
		&&	mouse_position.y < down_border)
	{
		return true;
	}
	else
		return false;
}

void Button::iluminate()
{
	text.setFillColor(blue);
	is_iluminating_ = true;
}

void Button::reset_iluminate()
{
	text.setFillColor(sf::Color::White);
	is_iluminating_ = false;
}

bool Button::is_iluminating()
{
	return is_iluminating_;
}

void Button::set_charachter_size(unsigned int size)
{
	text.setCharacterSize(size);
}

void Button::draw(sf::RenderWindow & window)
{
	window.draw(text);
}