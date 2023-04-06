#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

using namespace sf;
using namespace std;

class game
{
private:
	//window
	RenderWindow* window;
	VideoMode videomode;
	Event ev;

	//game objects
	vector<Sprite> triggers;

	//letter array
	string string_letter_array [26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

	
	//trigger sprites
	Sprite trigger;

	Sprite bubble, sponge, glass, foam, blender, oil, aerosol, slime,
		   hairbrush, towel, soap, glitter, keyboard, cosmetic_bag, cotton_candy,
		   notebook, crystal, computer_mouse, candle, ice, kinetic_sand, rose,
		   light_bulb, gel, can, ball;

	//trigger textures
	Texture bubble_texture, sponge_texture, glass_texture, foam_texture,
		    blender_texture, oil_texture, aerosol_texture, slime_texture,
		    hairbrush_texture, towel_texture, soap_texture, glitter_texture, 
		    keyboard_texture, cosmetic_bag_texture, cotton_candy_texture,
		    notebook_texture, crystal_texture, computer_mouse_texture, 
		    candle_texture, ice_texture, kinetic_sand_texture, rose_texture,
		    light_bulb_texture, gel_texture, can_texture, ball_texture;

	//alphabet background
	RectangleShape alphabet_bg;
	Texture alphabet_bg_texture;

	//trigger background
	RectangleShape trigger_bg;
	Texture trigger_bg_texture;
	
	//game over screen
	RectangleShape game_over_bg;
	Texture game_over_bg_texture;
	Text game_over_text;

	//sounds
	Sound sound;

	SoundBuffer bubbleb, spongeb, glassb, foamb, blenderb, oilb, aerosolb, slimeb,
		        hairbrushb, towelb, soapb, glitterb, keyboardb, cosmetic_bagb, cotton_candyb,
		        notebookb, crystalb, computer_mouseb, candleb, iceb, kinetic_sandb, roseb,
		        light_bulbb, gelb, canb, ballb;

	//mouse positions
	Vector2i mouse_pos_window;
	Vector2f mouse_pos_view;

	//font
	Font font;

	//text
	Text instructions_text;
	Text letter_text_array[26];
	
	//game logic
	float trigger_spawn_timer;
	float trigger_spawn_timer_max;
	int max_triggers;
	bool mouse_held;
	bool endGame;
	bool quit;

	//functions
	void initialize_var();
	void initialize_win();
	void initialize_fonts();
	void initialize_text_and_background();
	void initialize_triggers();
	void initialize_sounds();
	

public:
	game();
	virtual ~game();

	//accessors
	const bool running() const;
	const bool get_end_game() const;
	const bool get_quit() const;

	//functions
	void spawn_trigger();

	void poll_events();
	void upd_mouse_positions();
	void upd_text();
	void upd_triggers();
	void update();

	void render_text(RenderTarget& target);
	void render_triggers(RenderTarget& target);
	void render();
};