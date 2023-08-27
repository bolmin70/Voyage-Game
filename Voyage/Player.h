#pragma once
#include "SFML/Graphics.hpp"


class Player
{
public:
	//player stats
	static int player_health;
	static int player_current_health;

	static int player_stamina;
	static int player_current_stamina;
	
	static int player_energy;
	static int player_current_energy;

	static int durability_table[5];


	static int player_exp;

	static int player_damage;

	static int gold;

	static int souls;

	static int visibility;

	static int item_type_table[16];
	static int item_amount_table[16];

	static int select_item_table_x[4];
	static int select_item_table_y[4];

	static int back_item;
	static int sling_item;
	
	static int Armor;




	//stamina regeneration
	static void Regeneration();

};

class Effects {
public:
	static sf::Clock anim_clock;
	static sf::Clock move_clock;

	static int anim_x;


	static sf::Texture soul_texture;

	static sf::Sprite soul;


	static sf::Texture poison_texture;

	static sf::Sprite poison;


	static sf::Texture heal_texture;

	static sf::Sprite heal;


	static bool effect_start;


	
	static void Effect_Textures();
	static void Effect_Manager(sf::RenderWindow& x_window, sf::Sprite& sprite, int x, int y, int fps, int frame_x, int frame_y, int max);
};