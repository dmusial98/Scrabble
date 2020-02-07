#ifndef BUTTON_H
#define BUTTON_H

#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include"Constexpr.h"

class Button
{
	sf::Color blue{ outline_color_tile };
	float up_border, down_border, left_border, right_border;
	sf::Text text;
	sf::Font font;

public:
	Button();

	void set_borders(float up, float down, float left, float right);
	
	void set_text(std::string str);
	void set_scale(float x, float y);

	bool mouse_over(sf::RenderWindow &window);
	void iluminate();
	void reset_iluminate();

	void display(sf::RenderWindow & window);

};

#endif