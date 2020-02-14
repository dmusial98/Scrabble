#include "Player.h"

Player::Player(Bag &bag, std::wstring n) : name(n)
{
	scale_x = GetSystemMetrics(16) / 1920.f;
	scale_y = GetSystemMetrics(17) / 1057.f;

	get_tiles(bag);
}

void Player::exchange_tiles(Bag &bag)
{
		if (bag.get_number_of_free_tiles() != -1)
		{
			for (int i = 0; i < no_of_tiles_for_player; i++)
			{
				if (own_tiles[i])
				{
					if (own_tiles[i]->get_last_used())
					{
						own_tiles[i] = bag.exchange_tile(own_tiles[i]);
					}
				}
			}
		}
		else
			throw Bag::EX_empty_bag{};
	
}

void Player::get_tiles(Bag &bag)
{
	if (empty_tiles && bag.get_number_of_free_tiles() != -1)
	{
		for(int i = 0; i< no_of_tiles_for_player; i++)
		{
			if (own_tiles[i] == nullptr) 
			{
				own_tiles[i] = bag.give_tile();
			}
		}
	}
	empty_tiles = false;
}

void Player::set_name(std::wstring n)
{
	name = n;
}

Tile * Player::get_tile(int index)
{
	if (index >= 0 && index < 7)
		return own_tiles[index];
	else 
		return nullptr;
}

void Player::set_tile(int index, Tile *t)
{
	own_tiles[index] = t;
}

void Player::set_empty_tiles(bool s)
{
	empty_tiles = s;
}

void Player::display_own_tiles(sf::RenderWindow & window)
{

	for (int i = 0; i < no_of_tiles_for_player; i++)
	{
		if (own_tiles[i] != nullptr) 
		{
			if (!own_tiles[i]->get_tick() && !own_tiles[i]->get_last_used())
			{
				own_tiles[i]->set_sprite_position(sf::Vector2f((left_border_own_tiles_pix * scale_x) + i * (tile_size_pix * scale_x + right_translation_own_tile * scale_x),
					up_border_own_tiles_pix * scale_y));
			}

			own_tiles[i]->display(window);
		}
	}
}

Player & Player::operator+=(int p)
{
	points += p;
	return *this;
}

Player & Player::operator-=(int p)
{
	points -= p;
	return *this;
}

bool Player::any_last_used()
{
	for (int i = 0; i < no_of_tiles_for_player; i++)
	{
		if (own_tiles[i])
		{
			if (own_tiles[i]->get_last_used())
				return true;
		}
		//empty space in own tiles when bag isn't empty
	}
	return false;
}

void Player::reset_all_last_used_and_outline()
{
	for (int i = 0; i < no_of_tiles_for_player; i++)
	{
		if (own_tiles[i])
		{
			own_tiles[i]->set_last_used(false);
			own_tiles[i]->reset_outline();
		}
	}
}

std::wstring Player::get_name()
{
	return name;
}

void Player::set_points(int p)
{
	points = p;
}

int Player::get_points()
{
	return points;
}

int Player::get_no_free_tiles()
{
	int number= 0;
	for (int i = 0; i < no_of_tiles_for_player; i++)
	{
		if (own_tiles[i])
			number++;
	}

	return number;
}

int Player::count_points_from_tiles()
{
	int points = 0;

	for (int i = 0; i < no_of_tiles_for_player; i++)
	{
		if (own_tiles[i])
		{
			points += own_tiles[i]->get_value();
		}
	}

	return points;
}

