#include "Bag.h"

Bag::Bag()
{
	int temp_num = 0;
	for (int i = 0; i < a_number_eng; i++) {
		eng_tiles[temp_num] = new Tile(L'a', a_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < b_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'b', b_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < c_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'c', c_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < d_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'd', d_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < e_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'e', e_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < f_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'f', f_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < g_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'g',g_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < h_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'h', h_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < i_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'i', i_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < j_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'j', j_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < k_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'k', k_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < l_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'l', l_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < m_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'm', m_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < n_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'n', n_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < o_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'o', o_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < p_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'p', p_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < q_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'q', q_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < r_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'r', r_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < s_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L's', s_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < t_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L't', t_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < u_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'u', u_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < w_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'w', w_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < v_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'v', v_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < x_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'x', x_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < y_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'y', y_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for (int i = 0; i < z_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(L'z', z_value_eng, Tile::Language_ver::English);
		temp_num++;
	}
	for(int i =0;i< blank_number_eng; i++)
	{
		eng_tiles[temp_num] = new Tile(0, 0, Tile::Language_ver::English);
		temp_num++;
	}

	temp_num = 0;
	for (int i = 0; i < a_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'a', a_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < ¹_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'¹', ¹_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < b_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'b', b_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < c_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'c', c_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < æ_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'æ', æ_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < d_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'd', d_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < e_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'e', e_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < ê_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'ê', ê_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < f_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'f', f_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < g_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'g', g_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < h_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'h', h_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < i_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'i', i_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < j_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'j', j_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < k_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'k', k_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < l_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'l', l_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < ³_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'³', ³_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < m_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'm', m_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < n_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'n', n_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < ñ_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'ñ', ñ_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < o_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'o', o_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < ó_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'ó', ó_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < p_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'p', p_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < r_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'r', r_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < s_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L's', s_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < œ_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'œ', œ_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < t_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L't', t_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < u_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'u', u_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < w_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'w', w_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < y_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'y', y_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < z_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'z', z_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < ¿_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'¿', ¿_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < Ÿ_number_pl; i++) {
		pl_tiles[temp_num] = new Tile(L'Ÿ', Ÿ_value_pl, Tile::Language_ver::Polish);
		temp_num++;
	}
	for (int i = 0; i < blank_number_eng; i++)
	{
		pl_tiles[temp_num] = new Tile(0, 0, Tile::Language_ver::Polish);
		temp_num++;
	}
}

Bag::~Bag()
{
	for (int i = 0; i < no_of_tiles_in_bag; i++)
	{
		if(eng_tiles[i])
			delete eng_tiles[i];
		if (pl_tiles[i])
			delete pl_tiles[i];
	}
}

void Bag::set_language(Tile::Language_ver lv)
{
	lang_ver = lv;
}

Tile::Language_ver Bag::get_language()
{
	return lang_ver;
}

Tile * Bag::give_tile()
{
	if (lang_ver == Tile::Language_ver::English)
		tiles = eng_tiles;
	

	if (no_of_free_tiles != -1)
	{
		std::mt19937 random_generator(time(NULL));
		std::uniform_int_distribution<int>	draw_lots(0, no_of_free_tiles);

		Tile * temp_tile;

		do
		{
			temp_tile = eng_tiles[draw_lots(random_generator)];
		} while (temp_tile->get_used());

		temp_tile->set_used(true);

		int _index = 0;
		while (eng_tiles[_index] != temp_tile)
		{
			_index++;
		}

		Tile * for_swap = eng_tiles[no_of_free_tiles];
		eng_tiles[no_of_free_tiles] = eng_tiles[_index];
		eng_tiles[_index] = for_swap;

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
	if (lang_ver == Tile::Language_ver::English)
		tiles = eng_tiles;
	

	if (no_of_free_tiles)
	{
		std::mt19937 random_generator(time(NULL));
		std::uniform_int_distribution<int>	draw_lots(0, no_of_free_tiles);

		Tile * temp_tile;

		do
		{
			temp_tile = eng_tiles[draw_lots(random_generator)];
		} while (temp_tile->get_used());
		//drawing lots of new tile from bag

		temp_tile->set_used(true); //the new tile 
		old_tile->set_used(false);
		old_tile->set_last_used(false);
		old_tile->reset_outline();

		int _index = 0;
		while (eng_tiles[_index] != temp_tile)
		{
			_index++;
		}

		int old_index = 0;
		while (eng_tiles[old_index] != old_tile)
		{
			old_index++;
		} //getting index of old tile for exchange

		Tile * for_swap = eng_tiles[_index];
		eng_tiles[_index] = eng_tiles[old_index];
		eng_tiles[old_index] = for_swap;
		//swaping a new tile with an old tile

		return temp_tile;
	}
	else 
		throw EX_empty_bag();
}
