#include "Tile.h"

Tile::Tile(char let, int val) : value(val), letter(let), used(false), last_used(false)
{
	float scale_x = GetSystemMetrics(16) / 1920.f;
	float scale_y = GetSystemMetrics(17) / 1057.f;

	set_sprite(scale_x, scale_y);
}

bool Tile::get_used()
{
	return used;
}

void Tile::set_used(bool set)
{
	used = set;
}

bool Tile::get_last_used()
{
	return last_used;
}

void Tile::set_last_used(bool s)
{
	last_used = s;
}

bool Tile::get_tick()
{
	return tick;
}

void Tile::set_tick(bool s)
{
	tick = s;
}

char Tile::get_letter()
{
	return letter;
}

void Tile::set_letter(char let)
{
	letter = let;
}

int Tile::get_value()
{
	return value;
}

sf::Vector2f Tile::get_sprite_position()
{
	return sprite.getPosition();
}

void Tile::set_sprite_position(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void Tile::set_outline(sf::Color col)
{
	sprite.setOutlineThickness(outline_thickness_tile);
	sprite.setOutlineColor(col);
}

void Tile::reset_outline()
{
	sprite.setOutlineThickness(0.0f);
}

void Tile::set_sprite(float scale_x, float scale_y)
{
	std::string file_name{ "Textures/Tiles/English/"};
	file_name += static_cast<char>(letter - 32);
	file_name += ".png";

	if (letter)
	{
		if (!texture.loadFromFile(file_name))
			std::cout << "tile texture load error" << std::endl;
	}
	else 
	{
		if (!texture.loadFromFile("Textures/Tiles/English/Blank.png"))
			std::cout << "tile texture load error" << std::endl;
	}

	sprite.setTexture(&texture);
	sprite.setSize(sf::Vector2f(49.f * scale_x, 49.f * scale_y));
}

void Tile::display(float x, float y, sf::RenderWindow &window)
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void Tile::display(sf::RenderWindow & window)
{
	window.draw(sprite);
}
