#pragma once
#include "sfml/graphics.hpp"
#include "Movement.h"




class Enemy
{
public:
	
	static sf::Clock move_clock;

	static bool level_alerted;

	static struct Enemy_Struct {
		int anim_x;
		int enemy_position_x;
		int enemy_position_y;
		int enemy_dead;
		int enemy_hp;
		int enemy_damage;
		int enemy_attack_begin;
		bool enemy_right;
		int enemy_alerted;
		bool enemy_hit;
		bool enemy_exists;


	};


	static sf::Clock attack_clock;
	static sf::Clock anim_clock;
	static Enemy_Struct Skeleton1;

	static sf::Clock attack_clock2;
	static sf::Clock anim_clock2;
	static Enemy_Struct Skeleton2;

	static sf::Clock attack_clock3;
	static sf::Clock anim_clock3;
	static Enemy_Struct Skeleton3;

	static sf::Clock attack_clock4;
	static sf::Clock anim_clock4;
	static Enemy_Struct Skeleton4;



	static bool active;


	//attack
	static sf::Texture skeleton_attack_texture;

	static sf::Sprite skeleton_attack;

	//idle
	static sf::Texture skeleton_idle_texture;

	static sf::Sprite skeleton_idle;

	//hit
	static sf::Texture skeleton_hit_texture;

	static sf::Sprite skeleton_hit;

	//dead
	static sf::Texture skeleton_dead_texture;

	static sf::Sprite skeleton_dead;






	static void Enemy_Level1();

	static void Enemy_Level2();

	static void Enemy_Deal_Damage(int damage, int hp);

	static void Enemy_Skeleton_Textures();

	static void Enemy_Skeleton(sf::RenderWindow& x_window, int x, int y, int& anim_x, int& position_x, int& position_y, int& dead, int& hp, int& damage, int& attack_begin, bool& right, int& alerted, bool& hit, sf::Clock& attack, sf::Clock& anim, bool& is_alive);
	
};

