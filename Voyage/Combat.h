#pragma once
#include "sfml/graphics.hpp"
#include "sfml/audio.hpp"
class Combat
{
public:

	static sf::Clock anim_clock;
	static sf::Clock move_clock;
	static int anim_x;

	static int attack1_start;

	static sf::Sprite character_attack1;

	static sf::Texture character_attack1_texture;

	static sf::Texture character_attack2_texture;

	static sf::Texture character_attack3_texture;

	static int choose_attack;

	static void Attack(int& x_parralax, sf::RenderWindow& x_window);
	static void Attack_Textures();
	static void Attack_Events(sf::Event& x_event);

};

class Combat_SFX {
public:
	static sf::SoundBuffer sword_attack1_buffer;

	static sf::Sound sword_attack1;

	static void Load_SFX();


};

