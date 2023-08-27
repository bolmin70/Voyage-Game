#pragma once
#include "sfml/graphics.hpp"
#include "sfml/audio.hpp"

class Walk
{
public:

	static bool is_running;
	static bool tutorial_moving;
	static bool right;

	static sf::Clock anim_clock;
	static sf::Clock move_clock;

	static int anim_x;
	static int player_position;


	static int player_position_y;


	static int x_plx;

	static bool right_clicked;
	static bool left_clicked;

	static int Run_Anim;

	static int tired;

	//Idle
	static sf::Texture character_idle_texture;

	static sf::Texture character_idle_sword_texture;

	static sf::Sprite character_idle;



	//Run
	
	static sf::Sprite character_run;

	static sf::Texture character_run_texture;


	//Walk (with weapon)

	static sf::Sprite character_walk;

	static sf::Texture character_walk_texture;





	static void Run(int& x_parralax, sf::RenderWindow& x_window);
	static void Run_Textures();
	static void Run_Events(sf::Event& x_event);

	

};

class Equipment
{
public:

	static sf::Clock anim_clock;
	static sf::Clock move_clock;


	static int anim_x;

	static bool sword_equipped;

	static bool sword_equip_start;


	static sf::Texture character_drink_texture;

	static sf::Sprite character_drink;


	static sf::Texture character_equip_sword_texture;

	static sf::Texture character_unequip_sword_texture;

	static sf::Sprite character_equip_sword;

	

	static void Equip_Textures();
	static void Equip(int& x_parralax, sf::RenderWindow& x_window);
	static void Equip_Events(sf::Event& x_event);
};

class Rolling
{
public:

	static sf::Clock anim_clock;
	static sf::Clock move_clock;


	static int anim_x;
	static bool roll_begin;


	static sf::Texture character_roll_texture;

	static sf::Sprite character_roll;



	static void Roll_Textures();
	static void Roll(int& x_parralax, sf::RenderWindow& x_window);
	static void Roll_Events(sf::Event& x_event);
};

class Jumping {
	public:
		static sf::Clock anim_clock;
		static sf::Clock move_clock;


		static int anim_x;
		static bool jump_begin;

		static int jump_y;

		static int double_jump;

		static sf::Texture character_jump_texture;

		static sf::Sprite character_jump;



		static void Jump_Textures();
		static void Jump(int& x_parralax, sf::RenderWindow& x_window);
		static void Jump_Events(sf::Event& x_event);

};

class Sitting {
public:
	//Sit
	static sf::Clock anim_clock;
	static sf::Clock move_clock;
	static int anim_x;

	static sf::Sprite character_sit;

	static sf::Texture character_sit_texture;


	static sf::Sprite character_sit_start;

	static sf::Texture character_sit_start_texture;


	static sf::Sprite character_sit_end;

	static sf::Texture character_sit_end_texture;



	static int sit;
	static int sit_begin;
	static int sit_end;


	static void Sit(int& x_parralax, sf::RenderWindow& x_window);
	static void Sit_Textures();
	static void Sit_Events(sf::Event& x_event);

};

class Physics {
public:

	static int G;
	static bool on_platform;

	static bool cycle_f12;


	static sf::Texture character_hitbox_texture;
	static sf::Texture character_hitbox_full_texture;

	static sf::Sprite character_hitbox;

	static void Hitbox_Textures();
	static void Gravity(int& x_parralax, sf::RenderWindow& x_window);


};

class Hit {
public:
	static sf::Clock anim_clock;
	static sf::Clock move_clock;

	static int anim_x;

	static bool hit;

	static sf::Sprite character_hit_right;

	static sf::Texture character_hit_right_texture;


	static sf::Sprite character_hit_left;

	static sf::Texture character_hit_left_texture;


	
	static void Hitt_Textures();

	static void Hitt(int& x_parralax, sf::RenderWindow& x_window);

};

class Movement_SFX{
public:
	static sf::SoundBuffer sword_unsheath_buffer;

	static sf::Sound sword_unsheath;

	static void Load_SFX();


};