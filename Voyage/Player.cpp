#include "Player.h"
#include "Movement.h"
#include "iostream"
#include "SFML/Graphics.hpp"

sf::Clock Effects::anim_clock;
sf::Clock Effects::move_clock;

int Effects::anim_x;

bool Effects::effect_start = 0;

//player stats
int Player::player_health = 550;
int Player::player_current_health = 550;

int Player::player_stamina = 550;
int Player::player_current_stamina = 550;

int Player::player_energy = 1000;
int Player::player_current_energy = 1000;

int Player::durability_table[5] = { 3, 3, 3, 0, 0 };


int Player::player_exp = 0;

int Player::player_damage = 50;

int Player::gold = 0;

int Player::souls = 0;

int Player::visibility = 100;

int Player::item_type_table[16];
int Player::item_amount_table[16];

int Player::select_item_table_x[4];
int Player::select_item_table_y[4];


int Player::back_item = 0;
int Player::sling_item = 0;
int Player::Armor = 0;


sf::Texture Effects::soul_texture;

sf::Sprite Effects::soul;


sf::Texture Effects::poison_texture;

sf::Sprite Effects::poison;


sf::Texture Effects::heal_texture;

sf::Sprite Effects::heal;



//stamina regeneration
void Player::Regeneration()
{
		
	if (player_current_stamina < 150 && Walk::tired == 3) {
		player_current_energy--;

		if (player_current_energy < 900) {
			durability_table[2] = 2;
		}
		if (player_current_energy < 800) {
			durability_table[2] = 1;
		}
		if (player_current_energy < 700) {
			durability_table[1] = 2;
		}
		if (player_current_energy < 600) {
			durability_table[1] = 1;
		}
		if (player_current_energy < 500) {
			durability_table[0] = 2;
		}
		if (player_current_energy < 400) {
			durability_table[0] = 1;
		}

		std::cout << player_current_energy << std::endl;
	}

	if (Walk::tired <= 1 && player_current_stamina < player_stamina) {
		player_current_stamina += 2;
	}

}

void Effects::Effect_Textures()
{
	//soul harvesting effect
	soul_texture.loadFromFile("Assets/Textures/Player/Effects/soul.png");

	soul.setTexture(soul_texture);
	soul.setScale(6.0f, 6.0f);

	//posion effect
	poison_texture.loadFromFile("Assets/Textures/Player/Effects/poison.png");

	poison.setTexture(poison_texture);
	poison.setScale(6.0f, 6.0f);

	//heal effect
	heal_texture.loadFromFile("Assets/Textures/Player/Effects/heal.png");

	heal.setTexture(heal_texture);
	heal.setScale(5.0f, 5.0f);


}

void Effects::Effect_Manager(sf::RenderWindow& x_window, sf::Sprite& sprite, int x, int y, int fps, int frame_x, int frame_y, int max)
{

	if (effect_start == 1) {
		if (anim_clock.getElapsedTime().asMilliseconds() > fps) {
			if (anim_x < max) {
				anim_x += frame_x;
			}
			else {
				effect_start = 0;
				//anim_x = 0;
			}

			anim_clock.restart();
		}


		sprite.setTextureRect(sf::IntRect(anim_x, 0, frame_x, frame_y));
		sprite.setPosition(x, y);
		x_window.draw(sprite);
	}
}
