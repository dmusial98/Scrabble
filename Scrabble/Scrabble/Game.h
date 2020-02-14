//TO_DO
//
//- Wyb�r w polskim menu
//- Po najechaniu na blanku niech wy�wietla informacj� jak� liter� zast�puje
//- Wybrane sprawdzenie
//- Okno z zapytaniem czy chcesz wyj�� z gry?
//
//- Dodanie licznika czasu
//
//	Dla multiplayer :
//- ��czno��(opanowa� za pomoc� SFML mam nadziej�)
//- Wy�wietlenie swoich p�ytek zawsze

#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "Player.h"
#include "Bag.h"
#include "Dictionary.h"
#include "Normal_Field.h"
#include "Triple_Letter_Score.h"
#include "Triple_Word_Score.h"
#include "Double_Letter_Score.h"
#include "Double_Word_Score.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <Windows.h>
#include <locale.h>

#pragma warning(disable:4996)

class Game {

	Field * board[no_of_field][no_of_field];
	std::vector<Player> players;
	int turn = 1;
	int number = 1;
	Bag bag;
	Dictionary* dictionary = nullptr;
	float scale_x = 1, scale_y = 1;
	Button confirm_button, exchange_button, help_button, pass_button, options_button, exit_button;

	
	//SFML variables
	sf::Texture texture, menu_texture;
	sf::Sprite board_sprite, menu_sprite;
	sf::RenderWindow window, info_window;
	sf::Font font;
	std::vector<sf::Text> players_texts;
	sf::Text welcome_text, info_text, in_text, tiles_in_bag;
	sf::Event event;
	
	typedef bool (Game::*fun_ptr) ();
	typedef void (Game::*fun_ptr_button_service) (Player&);
	enum Orientation { upright = 0, horizontally, none, _exception };

	struct EX_not_common_line {};
	struct EX_bad_start {};
	struct EX_bad_start_with_one_tile {};
	struct EX_lack_of_tiles_on_board {};
	struct EX_empty_space_between_tiles {};
	struct EX_lack_of_crossword {};
	struct EX_exit {};
	struct EX_end_game {};
	//exceptions

	void count_scale();

	void set_players_pos(std::vector<std::wstring> &vec);
	void update_points();
	void update_no_tiles_in_bag();

	void set_font();
	void setSprite();
	void set_buttons();

	void set_texts_start();
	void set_texts_pl_names(int number);
	void set_texts_pl_names();
	void set_text_no_tiles_in_bag();

	void display_start();
	void display_players();
	void display_tiles_in_bag();
	void display_buttons();
	void display_all();
	//setting and displaying game
	
	sf::Vector2u get_field_index();
	sf::Vector2u get_field_index(sf::Vector2i & mouse_position);
	void set_tile_on_board(sf::Vector2u vect_index, Tile &tile);
	int get_number_own_tile(bool from);
	//for putting tiles on board
	
	void button_service_control_main(Button & button, fun_ptr fun);
	bool in_area(sf::Vector2i vec, float left, float right, float up, float down);

	void exchange_tiles();
	void change_turn();
	void check_first_move();
	bool check_crossword();
	bool check_adjacent_field(Field array[], int number);
	bool check_adjacent_field_x(Field array[], int number, int position);
	bool check_adjacent_field_y(Field array[], int number, int position);
	bool check_tiles_in_one_line(sf::Vector2i min, sf::Vector2i max, Orientation orient);
	Field * get_new_tiles(Field array[], int &index);

	bool check_tiles_on_board();
	void blank(bool reset);
	void count_points(int mini_ind, int max_ind, std::vector<int> &points, Field field, Orientation orient);
	bool check_bonus();
	int any_player_without_tiles();
	void end_game();
	//game logic

	void check_words(std::vector<int> &points, std::vector<std::wstring> &incorrect_words, std::vector<std::wstring> &correct_words);
	void get_main_word_horizontally(Field *array, std::vector<std::wstring> &words, std::vector<int> &points);
	void get_main_word_upright(Field array[], std::vector<std::wstring> &words, std::vector<int> &points);
	void get_word_from_one_tile(Field field, Orientation orient, std::vector<std::wstring> &words, std::vector<int> &points);
	void search_letter(int &value, int border, bool &end, bool increase);
	//tools for searching words from board 

	void create_inf_window(std::vector<std::wstring> &inc_words);
	int create_inf_window(std::wstring title, std::wstring comment, bool wait_letter);
	void create_exit_window();
	void display_inc_words(std::vector<std::wstring> &words);
	void set_inf_window(std::wstring name);
	void wait_close_event();
	int wait_close_event_letter();
	//tools for creating window with info about errors	

	void reset_outline_own_tiles();
	void reset_outline_tiles_on_board();
	//displaying outline of tile

	std::vector<std::wstring> menu();
	int player_no_input();
	bool check_players_no_input(int no);
	std::vector<std::wstring> get_players_names(int no);
	//service of inputting names of players
	void wait_time();

	void control_own_tiles(sf::Vector2i & mouse_position);
	void control_board_left(sf::Vector2i & mouse_position);
	void control_board_right(sf::Vector2i & mouse_position);
	bool control_enter();
	//controlling through mouse and keyboard 

	bool exchange_tiles_main();
	bool close_window();
	bool enter_key_service();
	bool pass_function();


	bool button_service_exchange(Button &button, Player &player, bool exit, bool &button_pressed);

public:
	Game();
	~Game();
	void control();
};

#endif 