#include "Game.h"

//convert string to wstring
std::wstring wstring_from_bytes(std::string const& str)
{
	size_t requiredSize = 0;
	std::wstring answer;
	wchar_t *pWTempString = NULL;

	/*
	* Call the conversion function without the output buffer to get the required size
	*  - Add one to leave room for the NULL terminator
	*/
	requiredSize = mbstowcs(NULL, str.c_str(), 0) + 1;

	/* Allocate the output string (Add one to leave room for the NULL terminator) */
	pWTempString = (wchar_t *)malloc(requiredSize * sizeof(wchar_t));
	if (pWTempString == NULL)
	{
		printf("Memory allocation failure.\n");
	}
	else
	{
		// Call the conversion function with the output buffer
		size_t size = mbstowcs(pWTempString, str.c_str(), requiredSize);
		if (size == (size_t)(-1))
		{
			printf("Couldn't convert string\n");
		}
		else
		{
			answer = pWTempString;
		}
	}


	if (pWTempString != NULL)
	{
		delete[] pWTempString;
	}

	return answer;
}

//friend functions
void enter_key_service(Game * game, Button * button, bool & button_pressed) //arguments are non-used
{
	try
	{
		if (!game->control_enter())
			return;
	}
	catch (Game::EX_end_game)
	{
		game->end_game();
		//service of end game

		return;
	}
	return;
}

void pass_function(Game* game, Button* button, bool& button_pressed)
{
	if (game->check_tiles_on_board())
	{
		if (game->bag.get_language() == Tile::English)
			game->create_inf_window(L"Tiles on board!", L"You can't pass turn,\nbecause some tiles \nare on board.", false);
		else
			game->create_inf_window(L"Litery na planszy!", L"Nie mo¿esz oddaæ \nkolejki. Na planszy \nznajduj¹ siê litery.", false);
		return;
	}
	else
	{
		if (game->bag.get_language() == Tile::English)
			std::wcout << game->number++ << L". Player " << game->players[game->turn - 1].get_name() << L" passed turn.\n";
		else
			std::wcout << game->number++ << L". Gracz " << game->players[game->turn - 1].get_name() << L" odda³ ruch.\n";

		game->change_turn();
		return;
	}
}

void exchange_tiles_main(Game* game, Button* button, bool& button_pressed)
{
	try
	{
		game->exchange_tiles();
	}
	catch (Bag::EX_empty_bag)
	{
		if (game->bag.get_language() == Tile::English)
			game->create_inf_window(L"Empty bag", L"You can't exchange\ntiles, because \nthe bag is empty.", false);
		else
			game->create_inf_window(L"Pusty worek", L"Nie mozesz wymieniæ\nliter, poniewa¿ \nworek jest pusty.", false);
			game->reset_outline_own_tiles();
		return;
	}
	return;
}



Game::Game()
{
	for (int i = 0; i < no_of_field; i++) {
		for (int j = 0; j < no_of_field; j++) {
			if ((i == 0 && j == 0) || (i == 7 && j == 0)
				|| (i == 14 && j == 0) || (i == 0 && j == 7)
				|| (i == 14 && j == 7) || (i == 0 && j == 14)
				|| (i == 7 && j == 14) || (i == 14 && j == 14))
				board[i][j] = new Triple_Word_Score(i, j);

			else if ((i == 1 && j == 1) || (i == 13 && j == 1)
				|| (i == 2 && j == 2) || (i == 12 && j == 2)
				|| (i == 3 && j == 3) || (i == 11 && j == 3)
				|| (i == 4 && j == 4) || (i == 10 && j == 4)
				|| (i == 4 && j == 10) || (i == 10 && j == 10)
				|| (i == 3 && j == 11) || (i == 11 && j == 11)
				|| (i == 2 && j == 12) || (i == 12 && j == 12)
				|| (i == 1 && j == 13) || (i == 13 && j == 13))
				board[i][j] = new Double_Word_Score(i, j);

			else if ((i == 3 && j == 0) || (i == 11 && j == 0)
				|| (i == 6 && j == 2) || (i == 8 && j == 2)
				|| (i == 0 && j == 3) || (i == 7 && j == 3)
				|| (i == 14 && j == 3) || (i == 2 && j == 6)
				|| (i == 6 && j == 6) || (i == 8 && j == 6)
				|| (i == 12 && j == 6) || (i == 3 && j == 7)
				|| (i == 11 && j == 7) || (i == 3 && j == 7)
				|| (i == 12 && j == 8) || (i == 2 && j == 8)
				|| (i == 6 && j == 8) || (i == 8 && j == 8)
				|| (i == 12 && j == 8) ||  (i == 0 && j == 11)
				|| (i == 7 && j == 11) || (i == 14 && j == 11)
				|| (i == 6 && j == 12) || (i == 8 && j == 12)
				|| (i == 3 && j == 14) || (i == 11 && j == 14))
				board[i][j] = new Double_Letter_Score(i, j);

			else if ((i == 5 && j == 1) || (i == 9 && j == 1)
				|| (i == 1 && j == 5) || (i == 5 && j == 5)
				|| (i == 9 && j == 5) || (i == 13 && j == 5)
				|| (i == 1 && j == 9) || (i == 5 && j == 9)
				|| (i == 9 && j == 9) || (i == 13 && j == 9)
				|| (i == 5 && j == 13) || (i == 9 && j == 13))
				board[i][j] = new Triple_Letter_Score(i, j);

			else board[i][j] = new Normal_Field(i, j);
		}
	}

	dictionary = new Dictionary(bag.get_language());

	count_scale();

	set_font();
	set_texts_start();
	setSprite();
	set_buttons();
	set_text_no_tiles_in_bag();

	window.create(sf::VideoMode(static_cast<unsigned int>(1286 * scale_x), static_cast<unsigned int>(965 * scale_y)), "Scrabble");

	std::vector<std::wstring> players_strings;

	try
	{
		players_strings = menu();
	}
	catch (EX_exit)
	{
		return;
	}

	for (int i = 0; i < players_strings.size(); i++)
	{
		players.push_back(Player(bag, players_strings[i]));
		players_texts.push_back(sf::Text(players_strings[i] + L"   0", font, 35));
	}
	//display points with names of players

	set_players_pos(players_strings);
}

Game::~Game()
{
	for (int i = 0; i < no_of_field; i++)
	{
		for (int j = 0; j < no_of_field; j++)
		{
			delete board[i][j];
		}
	}
}

void Game::count_scale()
{
	scale_x = GetSystemMetrics(16) / 1920.f;
	scale_y = GetSystemMetrics(17) / 1057.f;
}

void Game::display_players()
{
	for (int i = 0; i < players_texts.size(); i++)
	{
		players_texts[i].setFillColor(sf::Color::White);
	}
	players_texts[turn - 1].setFillColor(sf::Color::Blue);

	for (int i = 0; i < players_texts.size(); i++)
	{
		window.draw(players_texts[i]);
	} //names of players with their points
}

void Game::set_players_pos(std::vector<std::wstring>& vec)
{
	int max_length = static_cast<int>(vec[0].length());
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].length() > max_length)
			max_length = static_cast<int>(vec[i].length());
	}

	float x = 60.f * scale_x, y = 60.f * scale_y;

	if (max_length <= 3)
	{
		x = 990.f * scale_x;
	}
	else if(max_length < 5)
	{
		x = 950.f * scale_x;
	}
	else if (max_length < 8)
	{
		x = 920.f * scale_x;
	}
	else 
	{
		x = 890.f * scale_x;
	}
	
	for (int i = 0; i < players_texts.size(); i++)
	{
		players_texts[i].setPosition(x, y);
		players_texts[i].setCharacterSize(static_cast<unsigned int>(players_texts[i].getCharacterSize() * scale_x));
		y += 50.f * scale_y;
	}
}

void Game::update_points()
{
	char temp[5];

	

	for (int i = 0; i < players_texts.size(); i++)
	{
		std::string str = _itoa(players[i].get_points(), temp, 10);
		std::wstring wstr = wstring_from_bytes(str);

		players_texts[i].setString(players[i].get_name() + L"   " +  wstr);
	}
}

void Game::update_no_tiles_in_bag()
{
	char temp[5];


	std::string str = (_itoa(bag.get_number_of_free_tiles() + 1, temp, 10));
	std::wstring result_str;
	if(bag.get_language() == Tile::English)
		result_str = L"Tiles in bag: " + wstring_from_bytes(str);
	else 
		result_str = L"Liter w worku: " + wstring_from_bytes(str);
	tiles_in_bag.setString(result_str);
}

void Game::set_font()
{
	if (!font.loadFromFile("font/JMH_Typewriter.ttf"))
		std::cout << "font load error";
}

void Game::setSprite()
{	
	if (!texture.loadFromFile("Textures/Plansza.png"))
		std::cout << "Board loading error\n";
	if (!menu_texture.loadFromFile("Textures/Background.png"))
		std::cout << "Menu texture's loading error\n";
	board_sprite.setTexture(texture);
	board_sprite.setScale(board_scale * scale_x, board_scale* scale_y);
	menu_sprite.setTexture(menu_texture);
	menu_sprite.setScale(board_scale * scale_x, board_scale* scale_y);
}

void Game::set_buttons()
{
	if (bag.get_language() == Tile::English)
	{
		exit_button.set_borders(780.f * scale_y, 815.f * scale_y, 1095.f * scale_x, 1185.f * scale_x);
		exit_button.set_text(L"Exit");
		
		options_button.set_text(L"Options");
		options_button.set_borders(780.f * scale_y, 821.f * scale_y, 935.f * scale_x, 1085.f * scale_x);
		
		help_button.set_text(L"Help");
		help_button.set_borders(730.f * scale_y, 775.f * scale_y, 965.f * scale_x, 1055.f * scale_x);
		help_button.set_scale(scale_x, scale_y);

		pass_button.set_text(L"Pass");
		pass_button.set_borders(730.f * scale_y, 770.f * scale_y, 1095.f * scale_x, 1185.f * scale_x);
		
		exchange_button.set_text(L"Exchange");
		exchange_button.set_borders(680.f * scale_y, 720.f * scale_y, 980.f * scale_x, 1150.f * scale_x);
		
		confirm_button.set_text(L"Confirm");
		confirm_button.set_borders(630.f * scale_y, 670.f * scale_y, 989.f * scale_x, 1150.f * scale_x);

		yes_button.set_text(L"Yes");
		yes_button.set_borders(160.f * scale_y, 190.f * scale_y, 90.f * scale_x, 145.f * scale_x);
		yes_button.set_charachter_size(29);

		no_button.set_text(L"No");
		no_button.set_borders(160.f * scale_y, 190.f * scale_y, 225.f * scale_x, 265.f * scale_x);
		no_button.set_charachter_size(29);
	}
	else
	{
		exit_button.set_borders(780.f * scale_y, 815.f * scale_y, 1095.f * scale_x, 1238.f * scale_x);
		exit_button.set_text(L"Wyjœcie");

		options_button.set_text(L"Opcje");
		options_button.set_borders(780.f * scale_y, 821.f * scale_y, 935.f * scale_x, 1085.f * scale_x);

		help_button.set_text(L"Pomoc");
		help_button.set_borders(730.f * scale_y, 775.f * scale_y, 935.f * scale_x, 1025.f * scale_x);
		help_button.set_scale(scale_x, scale_y);

		pass_button.set_text(L"Poddaj");
		pass_button.set_borders(730.f * scale_y, 770.f * scale_y, 1095.f * scale_x, 1225.f * scale_x);

		exchange_button.set_text(L"Wymiana");
		exchange_button.set_borders(680.f * scale_y, 720.f * scale_y, 990.f * scale_x, 1160.f * scale_x);

		confirm_button.set_text(L"ZatwierdŸ");
		confirm_button.set_borders(630.f * scale_y, 670.f * scale_y, 979.f * scale_x, 1170.f * scale_x);


		yes_button.set_text(L"Tak");
		yes_button.set_borders(160.f * scale_y, 190.f * scale_y, 90.f * scale_x, 145.f * scale_x);
		yes_button.set_charachter_size(29);

		no_button.set_text(L"Nie");
		no_button.set_borders(160.f * scale_y, 190.f * scale_y, 225.f * scale_x, 275.f * scale_x);
		no_button.set_charachter_size(29);
	}

	confirm_button.set_scale(scale_x, scale_y);
	options_button.set_scale(scale_x, scale_y);
	pass_button.set_scale(scale_x, scale_y);
	exchange_button.set_scale(scale_x, scale_y);
	exit_button.set_scale(scale_x, scale_y);
	yes_button.set_scale(scale_x, scale_y);
	no_button.set_scale(scale_x, scale_y);
}

void Game::set_texts_start()
{
	if (bag.get_language() == Tile::English)
	{
		welcome_text.setString("Welcome in Scrabble");
		info_text.setString("Please type number of players:");
	}
	else 
	{
		welcome_text.setString(L"Witaj w Scrabble");
		info_text.setString(L"Proszê wpisaæ liczbê graczy:");
	}
	welcome_text.setFont(font);
	info_text.setFont(font);
	in_text.setFont(font);
	
	welcome_text.setCharacterSize(static_cast<unsigned int>(50 * scale_x));
	info_text.setCharacterSize(static_cast<unsigned int>(30 * scale_x));
	in_text.setCharacterSize(static_cast<unsigned int>(28 * scale_x));

	if (bag.get_language() == Tile::English)
	{
		welcome_text.setPosition(360.f * scale_x, 380.f * scale_y);
		info_text.setPosition(385.f * scale_x, 480.f * scale_y);
	}
	else
	{
		welcome_text.setPosition(420.f * scale_x, 380.f * scale_y);
		info_text.setPosition(415.f * scale_x, 480.f * scale_y);
	}
	in_text.setPosition(635.f * scale_x, 550.f * scale_y);
}

void Game::set_texts_pl_names(int number)
{
	std::wstring str;

	if (bag.get_language() == Tile::English)
	{
		if (number == 0)
			str = L"first";
		else if (number == 1)
			str = L"second";
		else if (number == 2)
			str = L"third";
		else if (number == 3)
			str = L"fourth";

		info_text.setString(L"Please type name of " + str + L" player");
	}
	else
	{
		if (number == 0)
			str = L"pierwszego";
		else if (number == 1)
			str = L"drugiego";
		else if (number == 2)
			str = L"trzeciego";
		else if (number == 3)
			str = L"czwartego";

		info_text.setString(L"Proszê wpisaæ nazwê " + str + L" gracza");
	}
}

void Game::set_texts_pl_names()
{
	in_text.setString("");
	welcome_text.setString("");
	if(bag.get_language() == Tile::English)
		info_text.setPosition(250.f * scale_x, 400.f * scale_y);
	else 
		info_text.setPosition(193.f * scale_x, 400.f * scale_y);

	info_text.setCharacterSize(static_cast<unsigned int>(45 * scale_x));

	in_text.setPosition(580.f * scale_x, 520.f * scale_y);
	in_text.setCharacterSize(static_cast<unsigned int>(35 * scale_x));
}

void Game::set_text_no_tiles_in_bag()
{
	tiles_in_bag.setFont(font);
	if (bag.get_language() == Tile::English)
	{
		tiles_in_bag.setCharacterSize(static_cast<unsigned int>(40 * scale_x));
		tiles_in_bag.setPosition((right_border_own_tiles_pix + 240.f)* scale_x, up_border_own_tiles_pix * scale_y);
	}
	else
	{
		tiles_in_bag.setCharacterSize(static_cast<unsigned int>(40 * scale_x));
		tiles_in_bag.setPosition((right_border_own_tiles_pix + 220.f)* scale_x, up_border_own_tiles_pix * scale_y);
	}
	update_no_tiles_in_bag();
}

void Game::control()
{
	bool exit_button_pressed = false;
	bool confirm_button_pressed = false;
	bool pass_button_pressed = false;
	bool exchange_button_pressed = false;

	while (window.isOpen()) {

		sf::Vector2i mouse_position;

		update_no_tiles_in_bag();
		display_all();
		window.waitEvent(event);

		button_service(&exit_button, [](Game* game, Button *button, bool &button_pressed) {button_pressed = true; return; }, exit_button_pressed, window);
		if (exit_button_pressed)
		{
			exit_button_pressed = false;
			create_exit_window();
		}

		button_service(&confirm_button, (fun_ptr_button_service)(&enter_key_service), confirm_button_pressed, window);
		
		button_service(&pass_button, pass_function, pass_button_pressed, window);
			
		button_service(&exchange_button, exchange_tiles_main, exchange_button_pressed, window);
			
		if (event.type == sf::Event::MouseButtonPressed)
		{
			mouse_position = sf::Mouse::getPosition(window);

			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				if (in_area(mouse_position, left_border_own_tiles_pix, right_border_own_tiles_pix,
					up_border_own_tiles_pix, down_border_own_tiles_pix))
					//get tile from own tiles of player
				{
					control_own_tiles(mouse_position);
				}
				else if
					(in_area(mouse_position, left_border_pix, right_border_pix,
						up_border_pix, down_border_pix))
					//shift tile from field on different field or own tiles
				{
					control_board_left(mouse_position);
				}
			}
			else if (event.mouseButton.button == sf::Mouse::Button::Right)
			{
				if (in_area(mouse_position, left_border_pix, right_border_pix,
					up_border_pix, down_border_pix))
				{
					control_board_right(mouse_position);
				}
			}
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				create_exit_window();
			else if (event.key.code == sf::Keyboard::Enter)
			{
				enter_key_service(this, &confirm_button, confirm_button_pressed); //arguments aren't used
				continue;
					
			}
			else if (event.key.code == sf::Keyboard::E)
			{
				exchange_tiles_main(this, &exchange_button, exchange_button_pressed); //arguments aren't used
				continue;
			}
			else if (event.key.code == sf::Keyboard::P)
			{
				pass_function(this, &pass_button, pass_button_pressed); //arguments aren't used
			}
		}
		else if (event.type == sf::Event::Closed)
			create_exit_window();	
	}
}

void Game::change_turn()
{
	if (turn == players.size())
		turn = 1;
	else
		turn++;
}

void Game::display_start()
{
	window.clear();
	window.draw(menu_sprite);
	window.draw(welcome_text);
	window.draw(info_text);
	window.draw(in_text);
	window.display();
}

void Game::display_tiles_in_bag()
{
	window.draw(tiles_in_bag);
}

void Game::display_buttons()
{
	exit_button.draw(window);
	options_button.draw(window);
	help_button.draw(window);
	pass_button.draw(window);
	exchange_button.draw(window);
	confirm_button.draw(window);
}

void Game::display_all()
{
	window.clear();
	window.draw(board_sprite);

	for (int i = 0; i < no_of_field; i++)
	{
		for (int j = 0; j < no_of_field; j++)
		{
			board[i][j]->display(window, scale_x, scale_y);
		}
	}  //all tiles on board

	display_buttons();
	display_players();
	display_tiles_in_bag();

	players[turn - 1].display_own_tiles(window);

	window.display();
}

bool Game::in_area(sf::Vector2i vec, float left, float right, float up, float down)
{
	if (
		vec.x > left * scale_x
		&& vec.x < right * scale_x
		&&	vec.y > up * scale_y
		&&	vec.y < down * scale_y
		)
		return true;
	else
		return false;
}

void Game::button_service(Button *button, fun_ptr_button_service func, bool &button_pressed, sf::RenderWindow &window)
{
	if (button->mouse_over(window)) //when mouse is over confirm button
	{
		if (!button->is_iluminating())
		{
			button->iluminate();
			display_all();
			display_info_window(true);
		}

		while (button->mouse_over(window) && !button_pressed)
		{		//waiting for pressing confirm button
			window.waitEvent(event);
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
			{
				button->reset_iluminate();

				(*func)(this, button, button_pressed);
					return;				
			}
		}
	}
	else //when mouse isn't over confirm button
	{
		if (button->is_iluminating())
		{
			button->reset_iluminate();
			display_all();
			display_info_window(true);
		}
	}

	return; //return from function
}

void Game::exchange_tiles()
{
	if (check_tiles_on_board()) //if on the board are own tiles 
	{
		if(bag.get_language() == Tile::English)
			create_inf_window(L"Error with tiles!", L"You can't exchange\ntiles, because some\nare on board.", false);
		else
		{
			create_inf_window(L"Litery na planszy!", L"Nie mo¿esz wymieniæ\nliter, gdy¿ twoje\nlitery znajduj¹ siê \nna planszy.", false);
		}
		reset_outline_own_tiles();
	}
	else
	{
		if (bag.get_language() == Tile::English)
			create_inf_window(L"Exchange", L"Please select tiles\nfor exchange, \nthen press Enter.", false);
		else
			create_inf_window(L"Wymiana", L"Proszê wybraæ litery\ndo wymiany, \nnastêpnie nacisn¹æ \nenter/zatwierdŸ.", false);

		sf::Event event;
		window.waitEvent(event);
		bool confirm_button_pressed = false;
		bool exit_button_pressed = false;

		while ((event.key.code != sf::Keyboard::Enter && !confirm_button_pressed) || event.type == sf::Event::LostFocus || event.key.code == sf::Keyboard::LAlt)
		{ //waiting for pressed enter, escape key or confirm button
			
			button_service(&confirm_button, [](Game *game, Button *button, bool &button_pressed) {button_pressed = true; game->display_all(); button->iluminate(); game->display_all(); return; }, confirm_button_pressed, window);

			button_service(&exit_button, [](Game *game, Button *button, bool &button_pressed) {game->players[game->turn - 1].reset_all_last_used_and_outline(); game->display_all(); button_pressed = true; return; }, exit_button_pressed, window);
			if (exit_button_pressed)
				return;

			//service of choosing tiles for exchange
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
					if
						(
							mouse_position.x > left_border_own_tiles_pix * scale_x
							&&	mouse_position.x < right_border_own_tiles_pix * scale_x
							&&	mouse_position.y > up_border_own_tiles_pix * scale_y
							&&	mouse_position.y < down_border_own_tiles_pix * scale_y
							)  //choosing tiles to exchange
					{
						int index = get_number_own_tile(true);
						if (players[turn - 1].get_tile(index))
						{
							if (players[turn - 1].get_tile(index)->get_last_used())
							{
								players[turn - 1].get_tile(index)->set_last_used(false);
								players[turn - 1].get_tile(index)->reset_outline();
							}
							else
							{
								players[turn - 1].get_tile(index)->set_last_used(true);
								players[turn - 1].get_tile(index)->set_outline(sf::Color(255, 20, 5, 150));
							}
						}
					}
					display_all();
				}
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				players[turn - 1].reset_all_last_used_and_outline();
				display_all();
				return;
			}
			else if (event.type == sf::Event::Closed)
			{
				create_exit_window();
			}

			display_all();
			window.waitEvent(event);
		}

		if (players[turn - 1].any_last_used())
		{
			if (!check_tiles_on_board())
			{
				players[turn - 1].exchange_tiles(bag);
				if (bag.get_language() == Tile::English)
					std::wcout << number++ << L". Player " << players[turn - 1].get_name() << L" exchanged own tiles.\n";
				else 
					std::wcout << number++ << L". Gracz " << players[turn - 1].get_name() << L" wymieni³ w³asne litery.\n";
				
				change_turn();
			}
		}
		else
		{
			if (bag.get_language() == Tile::English)
				create_inf_window(L"No tiles for exchange!", L"You haven't choosed\nany tiles \nfor exchange.", false);
			else
				create_inf_window(L"Brak liter do wymiany!", L"Nie wybra³eœ\nliter na wymianê.", false);
		}
		display_all();

		return;
	}
}

sf::Vector2u Game::get_field_index()
{
	int x = no_of_field + 1;
	int y = no_of_field + 1;
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

	if (mouse_position.x > left_border_pix * scale_x
		&& mouse_position.y > up_border_pix * scale_y
		&& mouse_position.x < right_border_pix * scale_x
		&& mouse_position.y < down_border_pix * scale_y
		)
	{
		x = static_cast<int>((mouse_position.x - left_border_pix * scale_x) / (tile_size_pix * scale_x));
		y = static_cast<int>((mouse_position.y - up_border_pix * scale_y) / (tile_size_pix * scale_y));
	}

	return sf::Vector2u(x, y);
}

sf::Vector2u Game::get_field_index(sf::Vector2i & mouse_position)
{
	int x = no_of_field + 1;
	int y = no_of_field + 1;

	if (mouse_position.x > left_border_pix * scale_x
		&& mouse_position.y > up_border_pix * scale_y
		&& mouse_position.x < right_border_pix * scale_x
		&& mouse_position.y < down_border_pix * scale_y
		)
	{
		x = static_cast<int>((mouse_position.x - left_border_pix * scale_x) / (tile_size_pix * scale_x));
		y = static_cast<int>((mouse_position.y - up_border_pix * scale_y) / (tile_size_pix * scale_y));
	}

	return sf::Vector2u(x, y);
}

void Game::set_tile_on_board(sf::Vector2u vect_index, Tile &tile)
{
	if (vect_index.x < no_of_field)
		board[vect_index.x][vect_index.y]->set_tile(&tile);

	display_all();
}

int Game::get_number_own_tile(bool from)
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

	int index = static_cast<int>((mouse_position.x - left_border_own_tiles_pix * scale_x) / (tile_size_pix * scale_x + right_translation_own_tile * scale_x));

	if (from)
	{
		if (players[turn - 1].get_tile(index) != nullptr)
			return index;
		else 
			return -1;
	}
	else
		return index;
}

void Game::get_main_word_horizontally(Field * array, std::vector<std::wstring> &words, std::vector<int> &points)
{
	int index = 0;
	int arr_min[no_of_tiles_for_player]{ 100, 100, 100, 100, 100, 100, 100 };
	int arr_max[no_of_tiles_for_player]{ -1, -1, -1, -1, -1, -1,-1 };
	int min_ind, max_ind;
	std::wstring word;
	int temp_points = 0;

	for (int i = 0; i < no_of_tiles_for_player; i++)
	{
		if (array[i].get_x() >= 0)
		{
			arr_min[index] = array[i].get_x();
			arr_max[index] = array[i].get_x();
		}
		index++;
	}  //initialize arrays for searching mainimum and maximum index

	min_ind = std::min(arr_min[0], arr_min[6]);
	max_ind = *std::max_element(arr_max, arr_max + 6);

	if (!check_tiles_in_one_line(sf::Vector2i(min_ind, array[0].get_y()), sf::Vector2i(max_ind, array[0].get_y()), horizontally))
	{
		EX_empty_space_between_tiles exception;
		throw exception;
	}

	bool end = false;
	while (min_ind != 0 && board[min_ind - 1][array[0].get_y()]->get_tile() || end)
	{
		search_letter(min_ind, 0, end, false);
	}  //setting new min_ind for whole word

	end = false;
	while (max_ind != no_of_field - 1 && board[max_ind + 1][array[0].get_y()]->get_tile() || end)
	{
		search_letter(max_ind, no_of_field - 1, end, true);
	} //setting new max_ind for whole word

	for (int i = min_ind; i <= max_ind; i++)
	{
		word += board[i][array[0].get_y()]->get_tile()->get_letter();
	}  //getting main word for dictionary

	count_points(min_ind, max_ind, points, array[0], horizontally);

	words.push_back(word);

	for (int i = min_ind; i <= max_ind; i++)
	{
		if (board[i][array[0].get_y()]->get_tile()->get_last_used())
			get_word_from_one_tile(*board[i][array[0].get_y()], upright, words, points);
	}
}

void Game::get_main_word_upright(Field array[], std::vector<std::wstring> &words, std::vector<int> &points)
{
	int index = 0;
	int arr_min[no_of_tiles_for_player]{ 100, 100, 100, 100, 100, 100, 100 };
	int arr_max[no_of_tiles_for_player]{ -1, -1, -1, -1, -1, -1,-1 };
	int min_ind, max_ind;
	std::wstring word;


	for (int i = 0; i < no_of_tiles_for_player; i++)
	{
		if (array[i].get_y() >= 0)
		{
			arr_min[index] = array[i].get_y();
			arr_max[index] = array[i].get_y();
		}
		index++;
	} //initialize arrays for searching mainimum and maximum index

	min_ind = std::min(arr_min[0], arr_min[6]);
	max_ind = *std::max_element(arr_max, arr_max + 6);

	if (!check_tiles_in_one_line(sf::Vector2i(array[0].get_x(), min_ind), sf::Vector2i(array[0].get_x(), max_ind),upright))
	{
		EX_empty_space_between_tiles exception;
		throw exception;
	}

	bool end = false;
	while (min_ind != 0 && board[array[0].get_x()][min_ind - 1]->get_tile() || end)
	{
		search_letter(min_ind, 0, end, false);
	}  //setting new min_ind for whole word

	end = false;
	while (max_ind != no_of_field - 1 && board[array[0].get_x()][max_ind + 1]->get_tile() || end)
	{
		search_letter(max_ind, no_of_field - 1, end, true);
	} //setting new max_ind for whole word

	for (int i = min_ind; i <= max_ind; i++)
	{
		word += board[array[0].get_x()][i]->get_tile()->get_letter();
	}

	count_points(min_ind, max_ind, points, array[0], upright);

	words.push_back(word);

	for (int i = min_ind; i <= max_ind; i++)
	{
		if (board[array[0].get_x()][i]->get_tile()->get_last_used())
			get_word_from_one_tile(*board[array[0].get_x()][i], horizontally, words, points);
		//function check words horizontally from one tile
	}
}

void Game::get_word_from_one_tile(Field field, Orientation orient, std::vector<std::wstring> &words, std::vector<int> &points)
{
	std::wstring word;
	bool end = false, new_word = false;

	if (orient == horizontally)
	{
		int min_ind_x = field.get_x();
		int max_ind_x = field.get_x();

		if (max_ind_x != no_of_field - 1 && board[max_ind_x + 1][field.get_y()]->get_tile()) //on right side
		{
			new_word = true;
			while (max_ind_x != no_of_field -1 && board[max_ind_x + 1][field.get_y()]->get_tile() || end)
			{
				search_letter(max_ind_x, no_of_field - 1, end, true);
			}
		}

		end = false;

		if (min_ind_x != 0 && board[min_ind_x - 1][field.get_y()]->get_tile()) //on left side
		{
			new_word = true;
			while (min_ind_x != 0 && board[min_ind_x - 1][field.get_y()]->get_tile() || end)
			{
				search_letter(min_ind_x, 0, end, false);
			}
		}
		for (int i = min_ind_x; i <= max_ind_x; i++)
		{
			word += board[i][field.get_y()]->get_tile()->get_letter();
		}
		if (new_word)
		{
			words.push_back(word);
			count_points(min_ind_x, max_ind_x, points, field, horizontally);
		}
	}
	else if (orient == upright)
	{
		end = false;
		int min_ind_y = field.get_y();
		int max_ind_y = field.get_y();

		if (max_ind_y != no_of_field - 1 && board[field.get_x()][max_ind_y + 1]->get_tile()) //on down side
		{
			new_word = true;
			while (max_ind_y != no_of_field -1 && board[field.get_x()][max_ind_y + 1]->get_tile() || end)
			{
				search_letter(max_ind_y, no_of_field - 1, end, true);
			}
		}

		end = false;

		if (min_ind_y != 0 && board[field.get_x()][min_ind_y - 1]->get_tile()) //on up side
		{
			new_word = true;
			while (min_ind_y != 0 && board[field.get_x()][min_ind_y - 1]->get_tile() || end)
			{
				search_letter(min_ind_y, 0, end, false);
			}
		}

		for (int i = min_ind_y; i <= max_ind_y; i++)
		{
			word += board[field.get_x()][i]->get_tile()->get_letter();
		}
		if (new_word)
		{
			words.push_back(word);
			count_points(min_ind_y, max_ind_y, points, field, upright);
		}
	}
}

void Game::search_letter(int &value, int border, bool &end, bool increase)
{
	if (value == border)
		end = true;
	else
	{
		if (increase)
			value++;
		else
			value--;
	}
}

void Game::count_points(int min_ind, int max_ind, std::vector<int> &points, Field field, Orientation orient)
{  
	if (orient == horizontally)
	{
		int temp_points = 0;
		int double_word = 0, triple_word = 0;

		for (int i = min_ind; i <= max_ind; i++)
		{
			if (dynamic_cast<Double_Letter_Score*>(board[i][field.get_y()]))
				if(board[i][field.get_y()]->get_tile()->get_last_used())
					temp_points += board[i][field.get_y()]->get_tile()->get_value() * 2;
				else 
					temp_points += board[i][field.get_y()]->get_tile()->get_value();
			else if (dynamic_cast<Triple_Letter_Score*>(board[i][field.get_y()]))
				if (board[i][field.get_y()]->get_tile()->get_last_used())
					temp_points += board[i][field.get_y()]->get_tile()->get_value() * 3;
				else 
					temp_points += board[i][field.get_y()]->get_tile()->get_value();
			else
				temp_points += board[i][field.get_y()]->get_tile()->get_value();

			if (dynamic_cast<Double_Word_Score*>(board[i][field.get_y()]))
				if (board[i][field.get_y()]->get_tile()->get_last_used())
					double_word++;
			if (dynamic_cast<Triple_Word_Score*>(board[i][field.get_y()]))
				if (board[i][field.get_y()]->get_tile()->get_last_used())
					triple_word++;
		}  //count value of this word

		if (!double_word && !triple_word)
			points.push_back(temp_points);
		else
			points.push_back(temp_points * 2 * double_word + temp_points * 3 * triple_word);
		//when aren't word_bonuses
	}
	else if (orient == upright)
	{
		int temp_points = 0;
		int double_word = 0, triple_word = 0;

		for (int i = min_ind; i <= max_ind; i++)
		{
			if (dynamic_cast<Double_Letter_Score*>(board[field.get_x()][i]))
				if(board[field.get_x()][i]->get_tile()->get_last_used())
					temp_points += board[field.get_x()][i]->get_tile()->get_value() * 2;
				else
					temp_points += board[field.get_x()][i]->get_tile()->get_value();
			else if (dynamic_cast<Triple_Letter_Score*>(board[field.get_x()][i]))
				if (board[field.get_x()][i]->get_tile()->get_last_used())
					temp_points += board[field.get_x()][i]->get_tile()->get_value() * 3;
				else 
					temp_points += board[field.get_x()][i]->get_tile()->get_value();
			else
				temp_points += board[field.get_x()][i]->get_tile()->get_value();

			if (dynamic_cast<Double_Word_Score*>(board[field.get_x()][i]))
				if (board[field.get_x()][i]->get_tile()->get_last_used())
					double_word++;
			if (dynamic_cast<Triple_Word_Score*>(board[field.get_x()][i]))
				if (board[field.get_x()][i]->get_tile()->get_last_used())
					triple_word++;
		}  //count value of this word

		if (!double_word && !triple_word)
			points.push_back(temp_points);
		else
			points.push_back(temp_points * 2 * double_word + temp_points * 3 * triple_word);
		//when aren't bonuses
	}
}

bool Game::check_bonus()
{
	Field array[no_of_tiles_for_player];
	int index = 0;

	get_new_tiles(array, index);

	if (index == 7)
		return true;
	else 
		return false;
}

int Game::any_player_without_tiles() 
//return number of player without tiles
//when all players have tiles function return -1
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].get_no_free_tiles() == 0) 
		{
			return i;
		}
	}

	return -1;
}

void Game::end_game()
{
	int pl_without_tiles = any_player_without_tiles();
	int all_points = 0;

	for (int i = 0; i < players.size(); i++)
	{
		if (i != pl_without_tiles)
		{
			int points = players[i].count_points_from_tiles();
			players[i] -= points;
			all_points += points;
		}
	}

	players[pl_without_tiles] += all_points;
	//adding and substracting points after last move
	update_points();
	update_no_tiles_in_bag();
	reset_outline_tiles_on_board();

	display_all();

	if (bag.get_language() == Tile::English)
	{
		std::wstring str = L"Congratulations,\n";
		str += players[any_player_without_tiles()].get_name();
		str += L"\nwon.";
		create_inf_window(L"End game", str, false);
	}
	else
	{
		std::wstring str = L"Gratulacje,\n";
		str += players[any_player_without_tiles()].get_name();
		str += L"\nwygra³(a).";
		create_inf_window(L"Koniec gry", str, false);
	}
	
}

void Game::check_words(std::vector<int> &points, std::vector<std::wstring> &incorrect_words, std::vector<std::wstring> &correct_words)
{
	std::vector<std::wstring> words;
	Orientation orientation = _exception;
	Field array[no_of_tiles_for_player];
	int index = 0;

	get_new_tiles(array, index);
	
	bool common_row = true, common_column = true;

	if (index == 0)
	{
		throw EX_lack_of_tiles_on_board{};
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < index; j++)
			{
				if (array[i].get_x() != array[j].get_x())
					common_column = false;

				if (array[i].get_y() != array[j].get_y())
					common_row = false;
			}
		}  //determine common row or column

		if (common_column && common_row) orientation = none;
		else if (common_row) orientation = horizontally;
		else if (common_column) orientation = upright;
	}	

	if (orientation == none)
	{
		get_word_from_one_tile(array[0], upright, words, points);
		get_word_from_one_tile(array[0], horizontally, words, points);
	}
	else if (orientation == horizontally) 
			get_main_word_horizontally(array, words, points);
	else if (orientation == upright)
			get_main_word_upright(array, words, points);
	else
	{
		throw EX_not_common_line{};
	}
	check_first_move();
	
	if (!check_crossword())
	{
		throw EX_lack_of_crossword();
	}
	for (int i = 0; i < words.size(); i++)
	{
		if (!dictionary->correct_word(words[i], bag.get_language())) 
		{
			incorrect_words.push_back(words[i]);
		}
		else
		{
			correct_words.push_back(words[i]);
		}
	}
	//checking in dictionary
}

void Game::check_first_move()
{
	int points = 0;

	for (int i = 0; i < players.size(); i++)
	{
		points += players[i].get_points();
	} //counting points for players

	if (points)
		return;
	else
	{
		Field array[no_of_tiles_for_player];
		get_new_tiles(array, points); 
		if (!std::any_of(array, array + 7, [](Field f) {if (f.get_x() == 7 && f.get_y() == 7) return true; else return false; }))
			throw EX_bad_start{};
		else if (points == 1)
			throw EX_bad_start_with_one_tile{};
	}
	
	return;
}

bool Game::check_crossword()
{
	int points = 0;

	for (int i = 0; i < players.size(); i++)
	{
		points += players[i].get_points();
	}

	if (points)
	{
		Field array[no_of_tiles_for_player];
		int index = 0;
		get_new_tiles(array, index);

		if (check_adjacent_field(array, index))
		{
			return true;
		}
		return false;
	}
	else
	{
		return true;
	}
	return false;
}

bool Game::check_adjacent_field(Field array[], int number)
{
	for(int i = 0; i < number; i++)
	{
		if (check_adjacent_field_x(array, i, 1))
			return true;
		else if (check_adjacent_field_x(array, i, -1))
			return true;
		else if (check_adjacent_field_y(array, i, 1))
			return true;
		else if (check_adjacent_field_y(array, i, - 1))
			return true;
	}
	return false;
}

bool Game::check_adjacent_field_x(Field array[], int number, int position)
{
	if (position == 1 && array[number].get_x() != no_of_field - 1)
	{
		if (board[array[number].get_x() + position][array[number].get_y()]->get_tile())
		{
			if (!board[array[number].get_x() + position][array[number].get_y()]->get_tile()->get_last_used())
				return true;
		}
	}
	else if (position == -1 && array[number].get_x() != 0)
	{
		if (board[array[number].get_x() + position][array[number].get_y()]->get_tile())
		{
			if (!board[array[number].get_x() + position][array[number].get_y()]->get_tile()->get_last_used())
				return true;
		}
	}
	
	return false;
}

bool Game::check_adjacent_field_y(Field array[], int number, int position)
{
	if (position == -1 && array[number].get_y() != zero)
	{
		if (board[array[number].get_x()][array[number].get_y() + position]->get_tile())
		{
			if (!board[array[number].get_x()][array[number].get_y() + position]->get_tile()->get_last_used())
				return true;
		}
	}
	else if (position == 1 && (array[number].get_y() != no_of_field - 1))
	{
		if (board[array[number].get_x()][array[number].get_y() + position]->get_tile())
		{
			if (!board[array[number].get_x()][array[number].get_y() + position]->get_tile()->get_last_used())
				return true;
		}
	}
	return false;
}

bool Game::check_tiles_in_one_line(sf::Vector2i min, sf::Vector2i max, Orientation orient)
{
	if(orient == horizontally)
	{	
		for (int i = min.x; i < max.x; i++)
		{
			if (!board[i][min.y]->get_tile())
				return false;
		}
		return true;
	} 
	else if (orient == upright)
	{
		for (int i = min.y; i < max.y; i++)
		{
			if (!board[min.x][i]->get_tile())
				return false;
		}
		return true;
	}
	else return false;
}

Field * Game::get_new_tiles(Field array[], int &index)
{
	for (int i = 0; i < no_of_field; i++)
	{
		for (int j = 0; j < no_of_field; j++)
		{
			if (board[i][j]->get_tile())
			{
				if (board[i][j]->get_tile()->get_last_used())
				{
					array[index] = *board[i][j];
					index++;
				}
			}
		}
	} //copy all fields of new tiles on board
	return array;
}

bool Game::check_tiles_on_board()
{
	for (int i = 0; i < no_of_field; i++)
	{
		for (int j = 0; j < no_of_field; j++)
		{
			if (board[i][j]->get_tile())
			{
				if (board[i][j]->get_tile()->get_last_used())
					return true;
			}
		}
	}
	return false;
}

void Game::blank(bool reset)
{
	for (int i = 0; i < no_of_field; i++)
	{
		for (int j = 0; j < no_of_field; j++)
		{
			if (board[i][j]->get_tile())
			{
				if (!board[i][j]->get_tile()->get_value() && board[i][j]->get_tile()->get_last_used())
				{
					if (!reset)
					{
						wchar_t letter;
						if(bag.get_language() == Tile::English)
							 letter = create_inf_window(L"Blank", L"Please type letter,\nwhich will replace\nblank.", true);
						else
							letter = create_inf_window(L"Blank", L"Proszê wpisaæ literê,\nktór¹ zamieniasz \nza blanka.", true);
						
						//getting letter for blank

						board[i][j]->get_tile()->set_letter(letter);
					}
					else 
						board[i][j]->get_tile()->set_letter(0);
				}
			}
		}
	}

}

void Game::create_inf_window(std::vector<std::wstring> &inc_words)
{	
	if (bag.get_language() == Tile::English)
		set_inf_window(L"Incorrect words!");
	else
		set_inf_window(L"Niepoprawne s³owo(a)!");
	display_inc_words(inc_words);
	wait_close_event();
}

void Game::set_inf_window(std::wstring name)
{
	info_window.create(sf::VideoMode(static_cast<unsigned int>(400 * scale_x), static_cast<unsigned int>(250 * scale_y) ), name);
	menu_sprite.setPosition(-30.f, -30.f);
	info_window.draw(menu_sprite);
}

void Game::wait_close_event()
{
	sf::Event event;

	while (info_window.isOpen()) {
		info_window.waitEvent(event);
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)

					while(event.type != sf::Event::KeyReleased)
						info_window.pollEvent(event);

					info_window.close();
			}
			else if (event.type == sf::Event::Closed)
				info_window.close();
		}
	}
}

int Game::wait_letter_in_close_event_()
{
	sf::Event event;

	while (info_window.isOpen()) {
		info_window.waitEvent(event);
		{
			if (event.type == sf::Event::TextEntered)
			{
					info_window.close();
					return event.text.unicode;
			}
		}
	}
}

void Game::reset_outline_own_tiles()
{
	for (int i = 0; i < no_of_tiles_for_player; i++)
	{
		if (players[turn - 1].get_tile(i))
		{
			players[turn - 1].get_tile(i)->reset_outline();
			players[turn - 1].get_tile(i)->set_last_used(false);
		}
	}
}

void Game::reset_outline_tiles_on_board()
{
	for (int i = 0; i < no_of_field; i++) {
		for (int j = 0; j < no_of_field; j++) {
			if (board[i][j]->get_tile()) {
				board[i][j]->get_tile()->set_last_used(false);
				board[i][j]->get_tile()->reset_outline();
			}
		}
	}
}

std::vector<std::wstring> Game::menu()
{
	display_start();
	std::vector<std::wstring> players = get_players_names(player_no_input());
	return players;
}

int Game::player_no_input()
{
	std::string str;
	sf::Event event;

	while (window.waitEvent(event)) {
		if (event.type == sf::Event::TextEntered)
		{
			// Handle ASCII characters only
			if (event.text.unicode < 128)
			{
				if (event.text.unicode != Enter && event.text.unicode != Escape_ &&
					event.text.unicode >= '0' && event.text.unicode <= '9')
					//Handle only digitals
				{

					if (event.text.unicode == Backspace) {
						if (str.length() != 0) {
							str.pop_back();
							in_text.setString(str);
						}
					}
					else {
						str += static_cast<char>(event.text.unicode);
						in_text.setString(str);
					}
				}
				else if (event.text.unicode == Enter) {
					if (str.length() > 0) {

						if (check_players_no_input(atoi(str.c_str())))
						{
							return atoi(str.c_str());
						}
						else 
						{
							if(bag.get_language() == Tile::English)
								create_inf_window(L"Incorrect data", L"You can choose only\n1, 2, 3 or 4 players.", false);
							else
								create_inf_window(L"Niepoprawne dane", L"Mo¿esz wybraæ\n1, 2, 3 lub 4 \ngraczy.", false);
							
							menu_sprite.setPosition(0.f, 0.f);
						}
					}
				}
				else if (event.text.unicode == Backspace)
				{
					if (str.length() != 0) {
						str.pop_back();
						in_text.setString(str);
					}
				}
				else if (event.text.unicode == Escape_)
				{
					window.close();
					throw EX_exit{};
				}
				display_start();
			}
		}
		else if (event.type == sf::Event::Closed)
		{
			window.close();
			throw EX_exit{};
		}
	}
}

bool Game::check_players_no_input(int no)
{
	if (no > 0 && no < 5)
		return true;
	else
		return false;
}

std::vector<std::wstring> Game::get_players_names(int no)
{
	int temp_num = 0;
	std::vector<std::wstring> vec;

	std::wstring str;
	sf::Event event;
	
	set_texts_pl_names();
	set_texts_pl_names(temp_num);
	display_start();

	while (window.isOpen()) {

		window.waitEvent(event);
		if (event.type == sf::Event::TextEntered)
		{			
				if (event.text.unicode != Enter && event.text.unicode != Escape_)
				{
					if (event.text.unicode == Backspace) {
						if (str.length() != 0) {
							str.pop_back();
							in_text.setString(str);
						}
					}
					else {
						str += static_cast<wchar_t>(event.text.unicode);
						in_text.setString(str);
					} //putting new sign into string
				}
				else if (event.text.unicode == Enter) 
				{
					if (str.length() > 0 && str.length() < 11)
					{
						vec.push_back(str);
						str = L"";
						temp_num++;
						
						if (temp_num == no)
							return vec;

						set_texts_pl_names(temp_num);
						in_text.setString(str);
					}
					else 
					{
						if(bag.get_language() == Tile::English)
							create_inf_window(L"Incorrect data", L"Name of player\nshould have from\n1 to 10 characters", false);
						else
							create_inf_window(L"Niepoprawne dane", L"Nazwa gracza \nmo¿e zawieraæ \nod 1 do 10 \nznaków", false);
						menu_sprite.setPosition(0.f, 0.f);
					}
				}
				else if (event.text.unicode == Backspace)
				{
					if (str.length() != 0) {
						str.pop_back();
						in_text.setString(str);
					}
				}
				else if (event.text.unicode == Escape_)
				{
					window.close();
					throw EX_exit{};
				}
				display_start();
		}
		else if (event.type == sf::Event::Closed)
		{
			window.close();
			throw EX_exit{};
		}
	}
}

void Game::wait_time()
{
	sf::Clock clock;
	clock.restart();
	sf::Time elapsed1 = clock.getElapsedTime();

	while (elapsed1 < sf::microseconds(500000))
	{
		sf::Time elapsed1 = clock.getElapsedTime();
	}
}

void Game::control_own_tiles(sf::Vector2i & mouse_position)
{
	{
		int index = get_number_own_tile(true); //with "from" option

		if (index >= 0)
		{
			sf::Vector2f tile_position = players[turn - 1].get_tile(index)->get_sprite_position();
			sf::Vector2f shift_vector = tile_position - sf::Vector2f(mouse_position);
			//setting up the vector of shift between mouse and left-up corner of sprite

			do {
				window.pollEvent(event);
				players[turn - 1].get_tile(index)->set_tick(true);
				players[turn - 1].get_tile(index)->set_sprite_position(
					sf::Vector2f(sf::Mouse::getPosition(window)) + shift_vector);
				display_all();
			} while (event.type != sf::Event::MouseButtonReleased);
			sf::Vector2u index_2d = get_field_index();

			players[turn - 1].get_tile(index)->set_tick(false);
			players[turn - 1].get_tile(index)->set_last_used(true);
			players[turn - 1].get_tile(index)->set_outline(sf::Color(outline_color_tile));

			mouse_position = sf::Mouse::getPosition(window);

			if (index_2d.x <= no_of_field && !board[index_2d.x][index_2d.y]->get_tile())
			{ //when on field isn't different tile
				set_tile_on_board(index_2d, *players[turn - 1].get_tile(index));

				if (index_2d.x < no_of_field) //when not out of board
					players[turn - 1].set_tile(index, nullptr);
			}
			else if 
			(mouse_position.x > left_border_own_tiles_pix * scale_x 
			&& mouse_position.x < right_border_own_tiles_pix  * scale_x
			&& mouse_position.y > up_border_own_tiles_pix * scale_y
			&& mouse_position.y < down_border_own_tiles_pix * scale_y
			)
			{
				int index2 = get_number_own_tile(false);
				Tile * temp_tile = players[turn - 1].get_tile(index);

				if (players[turn - 1].get_tile(index2) == nullptr)
				{
					players[turn - 1].set_tile(index, nullptr);
					players[turn - 1].set_tile(index2, temp_tile);
					players[turn - 1].get_tile(index2)->set_last_used(false);
					players[turn - 1].get_tile(index2)->reset_outline();
				} //from own tiles to own tiles
				else
				{
					players[turn - 1].get_tile(index)->reset_outline();
					players[turn - 1].get_tile(index)->set_last_used(false);
				}
			}
			else
			{
				players[turn - 1].get_tile(index)->reset_outline();
				players[turn - 1].get_tile(index)->set_last_used(false);
			}//setting tile on board or cancelling to own tiles
		}
	}
}

void Game::control_board_left(sf::Vector2i & mouse_position)
//left mouse button support
{
	{
		sf::Vector2u index = get_field_index();

		if (board[index.x][index.y]->get_tile())
		{
			if (board[index.x][index.y]->get_tile()->get_last_used())
			{
				sf::Vector2f tile_position = board[index.x][index.y]->get_tile()->get_sprite_position();
				sf::Vector2f shift_vector = tile_position - sf::Vector2f(mouse_position);
				//setting up the vector of shift between mouse and left-up corner of sprite

				do {
					window.pollEvent(event);
					board[index.x][index.y]->get_tile()->set_tick(true);
					board[index.x][index.y]->get_tile()->set_sprite_position(
						sf::Vector2f(sf::Mouse::getPosition(window)) + shift_vector * scale_x);
					display_all();
				} while (event.type != sf::Event::MouseButtonReleased);


				board[index.x][index.y]->get_tile()->set_tick(false);
				sf::Vector2u index2 = get_field_index();
				mouse_position = sf::Mouse::getPosition(window);

				if (index2.x < no_of_field && !board[index2.x][index2.y]->get_tile() && index2 != index)
				{
					set_tile_on_board(index2, *board[index.x][index.y]->get_tile());
					board[index.x][index.y]->set_tile(nullptr);
					//setting tile on board or cancelling last move
				}
				else if
					( //from board to own tiles
						mouse_position.x > left_border_own_tiles_pix * scale_x
						&&	mouse_position.x < right_border_own_tiles_pix * scale_x
						&&	mouse_position.y > up_border_own_tiles_pix * scale_y
						&&	mouse_position.y < down_border_own_tiles_pix * scale_y
						)
				{
					int index_own_tile = get_number_own_tile(false);
					if (!players[turn - 1].get_tile(index_own_tile)) 
					{
						players[turn - 1].set_tile(index_own_tile, board[index.x][index.y]->get_tile());
						players[turn - 1].get_tile(index_own_tile)->set_last_used(false);
						players[turn - 1].get_tile(index_own_tile)->reset_outline();
						board[index.x][index.y]->set_tile(nullptr);
					}
				}
			}
		}
	}
}

void Game::control_board_right(sf::Vector2i & mouse_position)
//right mouse button support
{
	sf::Vector2u index = get_field_index(mouse_position);

	if (index.x < no_of_field && index.y < no_of_field)
	{
		if (board[index.x][index.y]->get_tile())
		{
			if (board[index.x][index.y]->get_tile()->get_last_used())
			{
				int counter = 0;
				bool done = false;
				while (!done)
				{
					if (!players[turn - 1].get_tile(counter))
					{
						board[index.x][index.y]->get_tile()->set_last_used(false);
						board[index.x][index.y]->get_tile()->reset_outline();
						players[turn - 1].set_tile(counter, board[index.x][index.y]->get_tile());
						board[index.x][index.y]->set_tile(nullptr);
						done = true;
					}

					counter++;
				}
			}
		}
	}
	display_all();
	
}

bool Game::control_enter()
{
	{
		std::vector<int> points;
		std::vector<std::wstring> incorrect_words, correct_words;

		blank(false);

		try
		{
			check_words(points, incorrect_words, correct_words);
		}
		catch (EX_lack_of_tiles_on_board)
		{
			if(bag.get_language() == Tile::English)
				create_inf_window(L"No tiles on board!", L"You haven't added\nnew tiles during\nyour turn!", false);
			else
				create_inf_window(L"Brak liter na planszy!", L"Podczas twojego \nruchu nie po³o¿y³eœ\n¿adnej litery.", false);
			blank(true);
			return false;
		}
		catch (EX_empty_space_between_tiles)
		{
			if (bag.get_language() == Tile::English)
				create_inf_window(L"Empty space betwwen tiles!", L"Tiles, which you \nhave put have empty \nspace between them.", false);
			else
				create_inf_window(L"Wolne pola pomiêdzy literami!", L"Miêdzy twoimi \nliterami znajduj¹ \nsiê wolne pola.", false);
			blank(true);
			return false;
		}
		catch (EX_not_common_line)
		{
			if (bag.get_language() == Tile::English)
				create_inf_window(L"Lack of common row or column!", L"Lack of common\nrow or column!", false);
			else
				create_inf_window(L"Brak wspólnej kolumny lub wiersza!", L"Brak wspólnej\nkolumny lub \nwiersza!", false);
			blank(true);
			return false;
		}
		catch (EX_bad_start)
		{
			if (bag.get_language() == Tile::English)
				create_inf_window(L"Bad start!", L"In first move\none of tiles\nhave to lay\non middle field!", false);
			else
				create_inf_window(L"Niepoprawny pocz¹tek!", L"W pierwszym ruchu\nmusisz po³o¿yæ\nliterê na\nœrodkowym polu.", false);
			blank(true);
			return false;
		}
		catch (EX_bad_start_with_one_tile)
		{
			if (bag.get_language() == Tile::English)
				create_inf_window(L"Incorrect word!", L"You mustn't put\nonly one tile\nat the begining\nof game.", false);
			else
				create_inf_window(L"Niepoprawne s³owo!", L"Nie mo¿esz u³o¿yæ\ntylko jednej litery\nna pocz¹tku gry.", false);
			blank(true);
			return false;
		}
		catch (EX_lack_of_crossword)
		{
			if (bag.get_language() == Tile::English)
				create_inf_window(L"Lack of crossword!", L"Your tiles don't\nforms a crossword!", false);
			else
				create_inf_window(L"Brak krzy¿ówki!", L"Twoje litery\nnie tworz¹ \nkrzy¿ówki!", false);
			blank(true);
			return false;
		}

		if (incorrect_words.size() == 0)
		{
			if (check_bonus())
				players[turn - 1] += bonus;
			
			reset_outline_tiles_on_board();
			players[turn - 1].set_empty_tiles(true);
			players[turn - 1].get_tiles(bag);

			for(int i = 0; i < points.size(); i++)
				players[turn - 1] += points[i];
			
			update_points();
			update_no_tiles_in_bag();

			if(bag.get_language() == Tile::English)
				std::wcout << number << L". Player " << players[turn - 1].get_name() << L" played with words: ";
			else
				std::wcout << number << L". Gracz " << players[turn - 1].get_name() << L" u³o¿y³ s³owo(a): ";
			
			for (int i = 0; i < correct_words.size(); i++)
			{
				std::wcout << correct_words[i] << L" +" << points[i];
			
				if (i != correct_words.size() - 1)
				{
					std::cout << ", ";
				}
				else
				{
					std::cout << ".\n";
				}
			}
			//service of correct move

			if (bag.get_number_of_free_tiles() == -1 && any_player_without_tiles() != -1)
			{
				throw EX_end_game();
			}
			else
			{
				number++;
				change_turn();
			}
		}
		else
		{
			create_inf_window(incorrect_words);
			//information about incorrect words

			blank(true);
		}
	}

	return true;
}

int Game::create_inf_window(std::wstring title, std::wstring comment, bool wait_letter)
{
	set_inf_window(title);
	announcement_text.setString(comment);
	announcement_text.setFont(font);
	announcement_text.setCharacterSize(30 * scale_x);
	announcement_text.setPosition(50 * scale_x, 30 * scale_y);
	display_info_window(false);
	if (!wait_letter)
	{
		wait_close_event();

		return 0; //returnig value doesn't matter in this situation
	}
	else 
		return wait_letter_in_close_event_();
}

void Game::display_info_window(bool exit)
{
	info_window.draw(menu_sprite);
	info_window.draw(announcement_text);
	if (exit)
	{
		yes_button.draw(info_window);
		no_button.draw(info_window);
	}
	info_window.display();
}

void Game::create_exit_window()
{
	

	if (bag.get_language() == Tile::Language_ver::English)
	{
		set_inf_window(L"Exit game");
		announcement_text.setString(L"Do you want to \nquit the game?");
	}
	else
	{
		set_inf_window(L"Wyjœcie z gry");
		announcement_text.setString(L"Czy chcesz \nzakoñczyæ grê?");
	}

	announcement_text.setFont(font);
	announcement_text.setCharacterSize(30 * scale_x);
	announcement_text.setPosition(50 * scale_x, 30 * scale_y);

	display_info_window(true);

	bool yes_button_pressed = false;
	bool no_button_pressed = false;
	
	while (info_window.isOpen()) 
	{
		button_service(&yes_button, [](Game* game, Button* button, bool &button_pressed) {button_pressed = true; game->display_info_window(true);  return; }, yes_button_pressed, info_window);
		if (yes_button_pressed)
		{
			info_window.close();
			window.close();
		}

		button_service(&no_button, [](Game* game, Button* button, bool &button_pressed) {button_pressed = true;  return; }, no_button_pressed, info_window);
		if (no_button_pressed)
			info_window.close();

		info_window.waitEvent(event);
		
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::T || event.key.code == sf::Keyboard::Y || event.key.code == sf::Keyboard::Enter))
			{
				info_window.close();
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::N || event.key.code == sf::Keyboard::Escape))
				info_window.close();
			else if (event.type == sf::Event::Closed)
				info_window.close();
	}
}

void Game::display_inc_words(std::vector<std::wstring> &words)
{
	sf::Text text1, text2;
	text1.setFont(font);
	text2.setFont(font);
	if (bag.get_language() == Tile::English)
		text1.setString("Incorrect words:");
	else
		text1.setString(L"Niepoprawne s³owa:");
	text1.setPosition(72 * scale_x, 30 * scale_y);
	text1.setCharacterSize(static_cast<unsigned int>(text1.getCharacterSize() * scale_x));
	text2.setCharacterSize(static_cast<unsigned int>(text2.getCharacterSize() * scale_x));


	std::wstring str;
	for (int i = 0; i < words.size(); i++) 
	{
		str += words[i];
		str += L"\n";
	}

	text2.setString(str);
	text2.setPosition(150* scale_x, 70 * scale_y);

	info_window.draw(text1);
	info_window.draw(text2);
	info_window.display();

}
