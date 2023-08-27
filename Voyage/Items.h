#pragma once
#include "SFML/Graphics.hpp"

/*
Equipment types

Potions
stamina potion - restores stamina and some durability
health potion - restores some health
anti-posion - removes poison effect
rage potion - buffs damage and attack speeds
invisibility potion - visibility = 10


Swords
basic sword - basic attack speeds and damage
broad sword - slower attack speeds, higher damage
balanced sword - higher attack speeds, lower damage, lower stamina consumtion

Shields
basic shield - basic defense and stamina consumtion
heavy shield - high defense, high stamina consumtion
ballistic shield - low defense, low stamina consumtion

Armor
Daemonic Armor - basic defense, basic stamina, basic durability, base visibility = 100
Light Armor - low defense, high stamina, low durability, base visbility = 95
Heavy Armor - High defense, low stamina, high durablity, base visibility = 110
Stealth Suit - no defense, very high stamina, basic durability, base visibility = 55


*/
class Items
{
public:
	static sf::Clock anim_clock;
	static sf::Clock move_clock;

	static int anim_x;

	//stamina potion
	static sf::Texture potion_texture;

	static sf::Sprite potion;

	//anti-poison potion
	static sf::Texture antipotion_texture;

	static sf::Sprite antipotion;

	//health potion
	static sf::Texture health_potion_texture;

	static sf::Sprite health_potion;


	//empty potion (no animation)
	static sf::Texture empty_potion_texture;

	static sf::Sprite empty_potion;





	//basic sword
	static sf::Texture basic_sword_texture;

	static sf::Sprite basic_sword;





	static void Items_Textures();

	static void Potion_Anim(sf::RenderWindow& x_window, int x, int y, sf::Sprite x_sprite, sf::Texture x_texture);



};

