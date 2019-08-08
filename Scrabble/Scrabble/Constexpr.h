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

constexpr int a_number = 9;
constexpr int b_number = 2;
constexpr int c_number = 2;
constexpr int d_number = 4;
constexpr int e_number = 12;
constexpr int f_number = 2;
constexpr int g_number = 3;
constexpr int h_number = 2;
constexpr int i_number = 9;
constexpr int j_number = 1;
constexpr int k_number = 1;
constexpr int l_number = 4;
constexpr int m_number = 2;
constexpr int n_number = 6;
constexpr int o_number = 8;
constexpr int p_number = 2;
constexpr int q_number = 1;
constexpr int r_number = 6;
constexpr int s_number = 4;
constexpr int t_number = 6;
constexpr int u_number = 4;
constexpr int w_number = 2;
constexpr int v_number = 2;
constexpr int x_number = 1;
constexpr int y_number = 2;
constexpr int z_number = 1;
constexpr int blank_number = 2;

constexpr int a_value = 1;
constexpr int b_value = 3;
constexpr int c_value = 3;
constexpr int d_value = 2;
constexpr int e_value = 1;
constexpr int f_value = 4;
constexpr int g_value = 2;
constexpr int h_value = 4;
constexpr int i_value = 1;
constexpr int j_value = 8;
constexpr int k_value = 5;
constexpr int l_value = 1;
constexpr int m_value = 3;
constexpr int n_value = 1;
constexpr int o_value = 1;
constexpr int p_value = 3;
constexpr int q_value = 10;
constexpr int r_value = 1;
constexpr int s_value = 1;
constexpr int t_value = 1;
constexpr int u_value = 1;
constexpr int v_value = 4;
constexpr int w_value = 4;
constexpr int x_value = 8;
constexpr int y_value = 4;
constexpr int z_value = 10;

#pragma endregion

#endif