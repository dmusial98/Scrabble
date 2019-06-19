#include "Bag.h"

Bag::Bag()
{
	int temp_num = 0;
	for (int i = 0; i < a_number; i++) {
		tiles[temp_num] = new Tile('a', a_value);
		temp_num++;
	}
	for (int i = 0; i < b_number; i++)
	{
		tiles[temp_num] = new Tile('b', b_value);
		temp_num++;
	}
	for (int i = 0; i < c_number; i++)
	{
		tiles[temp_num] = new Tile('c', c_value);
		temp_num++;
	}
	for (int i = 0; i < d_number; i++)
	{
		tiles[temp_num] = new Tile('d', d_value);
		temp_num++;
	}
	for (int i = 0; i < e_number; i++)
	{
		tiles[temp_num] = new Tile('e', e_value);
		temp_num++;
	}
	for (int i = 0; i < f_number; i++)
	{
		tiles[temp_num] = new Tile('f', f_value);
		temp_num++;
	}
	for (int i = 0; i < g_number; i++)
	{
		tiles[temp_num] = new Tile('g',g_value);
		temp_num++;
	}
	for (int i = 0; i < h_number; i++)
	{
		tiles[temp_num] = new Tile('h', h_value);
		temp_num++;
	}
	for (int i = 0; i < i_number; i++)
	{
		tiles[temp_num] = new Tile('i', i_value);
		temp_num++;
	}
	for (int i = 0; i < j_number; i++)
	{
		tiles[temp_num] = new Tile('j', j_value);
		temp_num++;
	}
	for (int i = 0; i < k_number; i++)
	{
		tiles[temp_num] = new Tile('k', k_value);
		temp_num++;
	}
	for (int i = 0; i < l_number; i++)
	{
		tiles[temp_num] = new Tile('l', l_value);
		temp_num++;
	}
	for (int i = 0; i < m_number; i++)
	{
		tiles[temp_num] = new Tile('m', m_value);
		temp_num++;
	}
	for (int i = 0; i < n_number; i++)
	{
		tiles[temp_num] = new Tile('n', n_value);
		temp_num++;
	}
	for (int i = 0; i < o_number; i++)
	{
		tiles[temp_num] = new Tile('o', o_value);
		temp_num++;
	}
	for (int i = 0; i < p_number; i++)
	{
		tiles[temp_num] = new Tile('p', p_value);
		temp_num++;
	}
	for (int i = 0; i < q_number; i++)
	{
		tiles[temp_num] = new Tile('q', q_value);
		temp_num++;
	}
	for (int i = 0; i < r_number; i++)
	{
		tiles[temp_num] = new Tile('r', r_value);
		temp_num++;
	}
	for (int i = 0; i < s_number; i++)
	{
		tiles[temp_num] = new Tile('s', s_value);
		temp_num++;
	}
	for (int i = 0; i < t_number; i++)
	{
		tiles[temp_num] = new Tile('t', t_value);
		temp_num++;
	}
	for (int i = 0; i < u_number; i++)
	{
		tiles[temp_num] = new Tile('u', u_value);
		temp_num++;
	}
	for (int i = 0; i < w_number; i++)
	{
		tiles[temp_num] = new Tile('w', w_value);
		temp_num++;
	}
	for (int i = 0; i < v_number; i++)
	{
		tiles[temp_num] = new Tile('v', v_value);
		temp_num++;
	}
	for (int i = 0; i < x_number; i++)
	{
		tiles[temp_num] = new Tile('x', x_value);
		temp_num++;
	}
	for (int i = 0; i < y_number; i++)
	{
		tiles[temp_num] = new Tile('y', y_value);
		temp_num++;
	}
	for (int i = 0; i < z_number; i++)
	{
		tiles[temp_num] = new Tile('z', z_value);
		temp_num++;
	}
	for(int i =0;i< blank_number; i++)
	{
		tiles[temp_num] = new Tile(0, 0);
		temp_num++;
	}
}

Bag::~Bag()
{
	for (int i = 0; i < no_of_tiles_in_bag; i++)
	{
		if(tiles[i])
			delete tiles[i];
	}
}

Tile * Bag::give_tile()
{
	if (no_of_free_tiles != -1)
	{
		std::mt19937 random_generator(time(NULL));
		std::uniform_int_distribution<int>	draw_lots(0, no_of_free_tiles);

		Tile * temp_tile;

		do
		{
			temp_tile = tiles[draw_lots(random_generator)];
		} while (temp_tile->get_used());

		temp_tile->set_used(true);

		int _index = 0;
		while (tiles[_index] != temp_tile)
		{
			_index++;
		}

		Tile * for_swap = tiles[no_of_free_tiles];
		tiles[no_of_free_tiles] = tiles[_index];
		tiles[_index] = for_swap;

		//swaping tiles used and not used
		no_of_free_tiles--;

		return temp_tile;
	}
	else
		return nullptr;
}

int Bag::get_number_of_free_tiles()
{
	return no_of_free_tiles;
}

Tile* Bag::exchange_tile(Tile* old_tile)
{
	if (no_of_free_tiles)
	{
		std::mt19937 random_generator(time(NULL));
		std::uniform_int_distribution<int>	draw_lots(0, no_of_free_tiles);

		Tile * temp_tile;

		do
		{
			temp_tile = tiles[draw_lots(random_generator)];
		} while (temp_tile->get_used());
		//drawing lots of new tile from bag

		temp_tile->set_used(true); //the new tile 
		old_tile->set_used(false);
		old_tile->set_last_used(false);
		old_tile->reset_outline();

		int _index = 0;
		while (tiles[_index] != temp_tile)
		{
			_index++;
		}

		int old_index = 0;
		while (tiles[old_index] != old_tile)
		{
			old_index++;
		} //getting index of old tile for exchange

		Tile * for_swap = tiles[_index];
		tiles[_index] = tiles[old_index];
		tiles[old_index] = for_swap;
		//swaping a new tile with an old tile

		return temp_tile;
	}
	else 
		throw EX_empty_bag();
}
