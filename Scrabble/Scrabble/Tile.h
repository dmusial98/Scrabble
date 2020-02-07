#ifndef LETTER_H
#define LETTER_H

#include <SFML\Graphics.hpp>
#include "Constexpr.h"
#include <iostream>
#include <string>
#include <Windows.h>

class Tile {
public:
	enum Language_ver { Polish, English };

private:
	char letter;
	int value;
	Language_ver language;
	bool used = false;  //if is in own tiles
	bool last_used = false;  //if is on the board
	bool tick = false;
	
	//SFML variables
	sf::Texture texture;
	sf::RectangleShape sprite;

public:
	

	Tile(char let, int val, Language_ver lang);
	Tile() = default;
	~Tile() = default;

	
	bool get_used();
	void set_used(bool set);
	bool get_last_used();
	void set_last_used(bool s);
	bool get_tick();
	void set_tick(bool s);
	char get_letter();
	void set_letter(char let);
	int get_value();
	Language_ver get_language();

	sf::Vector2f get_sprite_position();
	void set_sprite_position(sf::Vector2f pos);
	void set_outline(sf::Color col);
	void reset_outline();
	
	void set_sprite(float scale_x, float scale_y);
	void display(float x, float y, sf::RenderWindow &window);
	void display(sf::RenderWindow &window);


};


#endif LETTER_H