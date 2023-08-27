#include "Items.h"
#include "iostream"

sf::Clock Items::anim_clock;
sf::Clock Items::move_clock;

int Items::anim_x;

/*
damage
penetration
firerate
magazine capacity
mobility
changeinspeed
accuracy


*/

sf::Texture Items::potion_texture;

sf::Sprite Items::potion;




sf::Texture Items::antipotion_texture;

sf::Sprite Items::antipotion;



sf::Texture Items::health_potion_texture;

sf::Sprite Items::health_potion;


//empty potion (no animation)
sf::Texture  Items::empty_potion_texture;

sf::Sprite  Items::empty_potion;


//basic sword
sf::Texture Items::basic_sword_texture;

sf::Sprite Items::basic_sword;


void Items::Items_Textures()
{
	std::cout << std::endl << std::endl << "loading - Items";

	std::cout << std::endl << std::endl << "Items - Potions" << std::endl << std::endl;




	std::cout << std::endl << std::endl << "Potions - Agility" << std::endl;
	potion_texture.loadFromFile("Assets/Textures/UI/Items/Potions/potion_agility.png");

	potion.setTexture(potion_texture);
	potion.setScale(10.0f, 10.0f);



	std::cout <<"Potions - Antidote" << std::endl;
	antipotion_texture.loadFromFile("Assets/Textures/UI/Items/Potions/potion_antidot.png");

	antipotion.setTexture(antipotion_texture);
	antipotion.setScale(10.0f, 10.0f);

	std::cout << "Potions - Health" << std::endl;
	health_potion_texture.loadFromFile("Assets/Textures/UI/Items/Potions/potion_health.png");

	health_potion.setTexture(health_potion_texture);
	health_potion.setScale(10.0f, 10.0f);

	std::cout << "Potions - Empty" << std::endl;
	empty_potion_texture.loadFromFile("Assets/Textures/UI/Items/Potions/potion_empty.png");

	empty_potion.setTexture(empty_potion_texture);
	empty_potion.setScale(10.0f, 10.0f);



}

void Items::Potion_Anim(sf::RenderWindow& x_window, int x, int y, sf::Sprite x_sprite, sf::Texture x_texture)
{
	
		if (anim_clock.getElapsedTime().asMilliseconds() > 100) {
			if (anim_x < 80) {
				anim_x += 16;
			}
			else {
				anim_x = 0;
			}

			anim_clock.restart();
		}


		x_sprite.setTextureRect(sf::IntRect(anim_x, 0, 16, 16));
		x_sprite.setPosition(x, y);
		x_window.draw(x_sprite);
	
}
