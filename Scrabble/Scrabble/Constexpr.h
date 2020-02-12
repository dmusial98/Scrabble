#ifndef CONSTEXPR_H
#define CONSTEXPR_H

#pragma region DISPLAY
constexpr float left_border_pix = 99.f;
constexpr float right_border_pix = left_border_pix + 750.f; 
constexpr float up_border_pix = 60.f;
constexpr float down_border_pix = up_border_pix + 750.f;
constexpr float tile_size_pix = 50.f;

constexpr int outline_color_tile = 0x2064c5;
constexpr int outline_color_tile_exchange = 0xee140f;
constexpr float outline_thickness_tile = 3.0;

constexpr float left_border_own_tiles_pix = 290.5f;
constexpr float up_border_own_tiles_pix = 866.5f;
constexpr float right_border_own_tiles_pix = 657.3f;
constexpr float down_border_own_tiles_pix = 916.5f;
constexpr float right_translation_own_tile = 2.4f;

constexpr float board_scale = 1.071428f;

#pragma endregion


#pragma region KEYS 

constexpr int Enter = 13;
constexpr int Escape_ = 27;
constexpr int Backspace = 8;
constexpr int zero = 0;
constexpr int nine = 57;

#pragma endregion


constexpr int no_of_field = 15;
constexpr int no_of_tiles_in_bag = 100;
constexpr int no_of_tiles_for_player = 7;
constexpr int no_of_normal_fields = 165;
constexpr int no_of_double_letter_fields = 24;
constexpr int no_of_double_word_fields = 16;
constexpr int no_of_triple_letter_fields = 12;
constexpr int no_of_triple_word_fields = 8;

constexpr int bonus = 50;

#pragma region DECLARATION

constexpr int a_number_eng = 9;
constexpr int b_number_eng = 2;
constexpr int c_number_eng = 2;
constexpr int d_number_eng = 4;
constexpr int e_number_eng = 12;
constexpr int f_number_eng = 2;
constexpr int g_number_eng = 3;
constexpr int h_number_eng = 2;
constexpr int i_number_eng = 9;
constexpr int j_number_eng = 1;
constexpr int k_number_eng = 1;
constexpr int l_number_eng = 4;
constexpr int m_number_eng = 2;
constexpr int n_number_eng = 6;
constexpr int o_number_eng = 8;
constexpr int p_number_eng = 2;
constexpr int q_number_eng = 1;
constexpr int r_number_eng = 6;
constexpr int s_number_eng = 4;
constexpr int t_number_eng = 6;
constexpr int u_number_eng = 4;
constexpr int w_number_eng = 2;
constexpr int v_number_eng = 2;
constexpr int x_number_eng = 1;
constexpr int y_number_eng = 2;
constexpr int z_number_eng = 1;
constexpr int blank_number_eng = 2;

constexpr int a_value_eng = 1;
constexpr int b_value_eng = 3;
constexpr int c_value_eng = 3;
constexpr int d_value_eng = 2;
constexpr int e_value_eng = 1;
constexpr int f_value_eng = 4;
constexpr int g_value_eng = 2;
constexpr int h_value_eng = 4;
constexpr int i_value_eng = 1;
constexpr int j_value_eng = 8;
constexpr int k_value_eng = 5;
constexpr int l_value_eng = 1;
constexpr int m_value_eng = 3;
constexpr int n_value_eng = 1;
constexpr int o_value_eng = 1;
constexpr int p_value_eng = 3;
constexpr int q_value_eng = 10;
constexpr int r_value_eng = 1;
constexpr int s_value_eng = 1;
constexpr int t_value_eng = 1;
constexpr int u_value_eng = 1;
constexpr int v_value_eng = 4;
constexpr int w_value_eng = 4;
constexpr int x_value_eng = 8;
constexpr int y_value_eng = 4;
constexpr int z_value_eng = 10;

constexpr int a_number_pl = 9;
constexpr int ¹_number_pl = 1;
constexpr int b_number_pl = 2;
constexpr int c_number_pl = 3;
constexpr int æ_number_pl = 1;
constexpr int d_number_pl = 3;
constexpr int e_number_pl = 7;
constexpr int ê_number_pl = 1;
constexpr int f_number_pl = 1;
constexpr int g_number_pl = 2;
constexpr int h_number_pl = 2;
constexpr int i_number_pl = 8;
constexpr int j_number_pl = 2;
constexpr int k_number_pl = 3;
constexpr int l_number_pl = 3;
constexpr int ³_number_pl = 2;
constexpr int m_number_pl = 3;
constexpr int n_number_pl = 5;
constexpr int ñ_number_pl = 1;
constexpr int o_number_pl = 6;
constexpr int ó_number_pl = 1;
constexpr int p_number_pl = 3;
constexpr int r_number_pl = 4;
constexpr int s_number_pl = 4;
constexpr int œ_number_pl = 1;
constexpr int t_number_pl = 3;
constexpr int u_number_pl = 2;
constexpr int w_number_pl = 4;
constexpr int y_number_pl = 4;
constexpr int z_number_pl = 5;
constexpr int Ÿ_number_pl = 1;
constexpr int ¿_number_pl = 1;
constexpr int blank_number_pl = 2;

constexpr int a_value_pl = 1;
constexpr int ¹_value_pl = 5;
constexpr int b_value_pl = 3;
constexpr int c_value_pl = 2;
constexpr int æ_value_pl = 6;
constexpr int d_value_pl = 2;
constexpr int e_value_pl = 1;
constexpr int ê_value_pl = 5;
constexpr int f_value_pl = 5;
constexpr int g_value_pl = 3;
constexpr int h_value_pl = 3;
constexpr int i_value_pl = 1;
constexpr int j_value_pl = 3;
constexpr int k_value_pl = 2;
constexpr int l_value_pl = 2;
constexpr int ³_value_pl = 3;
constexpr int m_value_pl = 2;
constexpr int n_value_pl = 1;
constexpr int ñ_value_pl = 7;
constexpr int o_value_pl = 1;
constexpr int ó_value_pl = 5;
constexpr int p_value_pl = 2;
constexpr int r_value_pl = 1;
constexpr int s_value_pl = 1;
constexpr int œ_value_pl = 5;
constexpr int t_value_pl = 2;
constexpr int u_value_pl = 3;
constexpr int w_value_pl = 1;
constexpr int y_value_pl = 2;
constexpr int z_value_pl = 1;
constexpr int Ÿ_value_pl = 9;
constexpr int ¿_value_pl = 5;

#pragma endregion

#endif