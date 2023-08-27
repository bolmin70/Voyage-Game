#include "Enemy.h"
#include "sfml/graphics.hpp"
#include "Movement.h"
#include "iostream"
#include "Collision.h"
#include "Player.h"
#include "Combat.h"
#include "Interface.h"

sf::Clock Enemy::attack_clock;
sf::Clock Enemy::anim_clock;
sf::Clock Enemy::move_clock;

sf::Clock Enemy::attack_clock2;
sf::Clock Enemy::anim_clock2;

sf::Clock Enemy::attack_clock3;
sf::Clock Enemy::anim_clock3;

sf::Clock Enemy::attack_clock4;
sf::Clock Enemy::anim_clock4;


bool Enemy::active = 0;

bool Enemy::level_alerted = 0;

//Enemy::Enemy_Struct Skeleton1;

Enemy::Enemy_Struct Enemy::Skeleton1 = { 0, 1300, 1670, 0, 150, 0, 0, 1, 0, 0, 1 };
Enemy::Enemy_Struct Enemy::Skeleton2 = { 0, 1800, 170, 0, 150, 0, 0, 1, 0, 0, 1 };
Enemy::Enemy_Struct Enemy::Skeleton3 = { 0, 2850, 170, 0, 150, 0, 0, 1, 0, 0, 1 };
Enemy::Enemy_Struct Enemy::Skeleton4 = { 0, 550, -10, 0, 150, 0, 0, 1, 0, 0, 1 };


//attack
sf::Texture Enemy::skeleton_attack_texture;

sf::Sprite Enemy::skeleton_attack;

//idle
sf::Texture Enemy::skeleton_idle_texture;

sf::Sprite Enemy::skeleton_idle;

//hit
sf::Texture Enemy::skeleton_hit_texture;

sf::Sprite Enemy::skeleton_hit;

//dead
sf::Texture Enemy::skeleton_dead_texture;

sf::Sprite Enemy::skeleton_dead;

/////////////////////////circa dwa tygodnie wczeœniej - Marta chce siê spotkaæ :)))))))  ///////////////////////////////////////////////////////////////////////////////////

/////////////////////////17.02.2020 circa. 16 - Hej jak by³o na wyjeŸdzie//// :[ - nie odpisa³a  ///////////////////////////////////////////////////////////////////////////////////

/////////////////////////19.02.2020 21:11 - W sensie fajnie by³oby siê spotkaæ a ju¿ koñcz¹ siê ferie, wiêc przyda³oby siê ¿ebyœ odpisa³a xD (rekonstrukcja wiadomoœci)////  //////////

////////////////////////19.02.2020 22:30 - odpisa³a ¿e nie ma czasu itp. :''[ (ewidentny brak zainteresowania... :[[[[) ////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////// :'[ koniec :'[///////////////////////////////////////////////////////////////////////////////////////////////
//:[ :[

///////////////////////////////////////////////////////////// Przynajmniej zaprzyjaŸni³em siê z Nor¹ :] ///////////////////////////////////////////////////////////////////////////////////////////////


void Enemy::Enemy_Skeleton_Textures() {
	std::cout << "Loading - Enemies" << std::endl << std::endl;

	std::cout << "Enemies - Skeleton..." << std::endl << std::endl;

	std::cout << "Skeleton - Attack" << std::endl;
	skeleton_attack_texture.loadFromFile("Assets/Textures/Enemies/Skeleton/Attack/attack1.png");
	Collision::CreateTextureAndBitmask(skeleton_attack_texture, "Assets/Textures/Enemies/Skeleton/Attack/attack1.png");

	skeleton_attack.setTexture(skeleton_attack_texture);
	skeleton_attack.setScale(3.8f, 4.0f);

	std::cout << "Skeleton - Idle" << std::endl;
	skeleton_idle_texture.loadFromFile("Assets/Textures/Enemies/Skeleton/Idle/idle.png");
	Collision::CreateTextureAndBitmask(skeleton_idle_texture, "Assets/Textures/Enemies/Skeleton/Idle/idle.png");

	skeleton_idle.setTexture(skeleton_idle_texture);
	skeleton_idle.setScale(3.8f, 4.0f);

	std::cout << "Skeleton - Hit" << std::endl;
	skeleton_hit_texture.loadFromFile("Assets/Textures/Enemies/Skeleton/Hit/hit.png");
	Collision::CreateTextureAndBitmask(skeleton_hit_texture, "Assets/Textures/Enemies/Skeleton/Hit/hit.png");

	skeleton_hit.setTexture(skeleton_hit_texture);
	skeleton_hit.setScale(3.8f, 4.0f);

	std::cout << "Skeleton - Dead" << std::endl;
	skeleton_dead_texture.loadFromFile("Assets/Textures/Enemies/Skeleton/Dead/dead.png");
	Collision::CreateTextureAndBitmask(skeleton_dead_texture, "Assets/Textures/Enemies/Skeleton/Dead/dead.png");

	skeleton_dead.setTexture(skeleton_idle_texture);
	skeleton_dead.setScale(3.8f, 4.0f);

	
}

void Enemy::Enemy_Level1()
{
	Enemy::Skeleton1 = { 0, 2000, 2380, 0, 150, 0, 0, 1, 0, 0, 1 };

}

void Enemy::Enemy_Level2()
{
	Enemy::Skeleton1 = { 0, 1300, 1670, 0, 150, 0, 0, 1, 0, 0, 1 };
	Enemy::Skeleton2 = { 0, 1800, 170, 0, 150, 0, 0, 1, 0, 0, 1 };
	Enemy::Skeleton3 = { 0, 2850, 170, 0, 150, 0, 0, 1, 0, 0, 1 };
	Enemy::Skeleton4 = { 0, 550, -10, 0, 150, 0, 0, 1, 0, 0, 1 };
	
}

void Enemy::Enemy_Deal_Damage(int damage, int hp) {
	
	if (Collision::PixelPerfectTest(skeleton_attack, Physics::character_hitbox) && Rolling::roll_begin != 1) {

		if (Player::player_current_energy > 800) {
			Player::player_current_health = Player::player_current_health - damage * 0.7;
		}
		if (Player::player_current_energy < 700) {
			Player::player_current_health = Player::player_current_health - damage * 0.7;
		}
		if (Player::player_current_energy < 600) {
			Player::player_current_health = Player::player_current_health - damage * 0.8;
		}
		if (Player::player_current_energy < 450) {
			Player::player_current_health = Player::player_current_health - damage * 0.8;
		}
		if (Player::player_current_energy < 300) {
			Player::player_current_health = Player::player_current_health - damage * 0.9;
		}
		if (Player::player_current_energy < 200) {
			Player::player_current_health = Player::player_current_health - damage * 1.0;
		}



		Hit::hit = 1;
	}

}

void Enemy::Enemy_Skeleton(sf::RenderWindow& x_window, int x, int y, int& anim_x, int& position_x, int& position_y, int& dead, int& hp, int& damage, int& attack_begin, bool& right, int& alerted, bool& hit, sf::Clock& attack, sf::Clock& anim, bool& is_alive)
{


	if (is_alive == 1) {
		if (dead == 0) {
			if (Walk::player_position > position_x - 600 && Walk::player_position < position_x + 500) {
				
					if (right == 0) {
						UI::Aware_Anim(x_window, alerted, position_x + 120, position_y - 50);
					}
					else {
						UI::Aware_Anim(x_window, alerted, position_x + 180, position_y - 50);
					}
					if (Jumping::jump_begin == 1 || Walk::tired > 2) {
						alerted = 1;
					}

			}
			if (anim.getElapsedTime().asMilliseconds() > 100) {
				if (Walk::player_position > position_x - 300 && Walk::player_position < position_x + 250) {
					if (Walk::player_position_y <= position_y + 15 && Walk::player_position_y >= position_y - 15) {



						if (Walk::player_position >= position_x - 100 && right == 1 && alerted != 1) {

							alerted = 1;
						

						}
						if (Walk::player_position < position_x + 100 && right == 0 && alerted != 1) {

							alerted = 1;
						
						}
						if (level_alerted == true) {
							alerted = 1;
						}
						if (alerted == 1) {
							//level_alerted = 1;
						}


						if (alerted == 1) {
							if (attack.getElapsedTime().asMilliseconds() > 2000) {
								attack_begin = 1;

								attack.restart();
							}

						}
						if (Collision::PixelPerfectTest(skeleton_idle, Combat::character_attack1) && Combat::attack1_start == 1) {
							hit = 1;
							alerted = 1;
							//std::cout << hit << std::endl;
						}

						if (Collision::PixelPerfectTest(skeleton_attack, Combat::character_attack1) && Combat::attack1_start == 1 && hit != 1) {
							hit = 1;
							alerted = 1;
						}
						if (hp <= 0) {
							anim_x = 0;
							dead = 1;
							hit = 0;
							attack_begin = 0;
						}

					}
					}
				
				}
			
		}
		if (hit == 1) {
			if (anim.getElapsedTime().asMilliseconds() > 100) {
				if (anim_x < 256) {
					anim_x += 128;
					attack_begin = 0;

				}
				else {
					attack.restart();
					hit = 0;
					anim_x = 0;
					hp = hp - Player::player_damage;


					

				}


				anim.restart();
			}

			if (right == true) {
				skeleton_hit.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
				skeleton_hit.setPosition(position_x + x, position_y);
				skeleton_hit.setTexture(skeleton_hit_texture);
				skeleton_hit.setScale(3.8f, 4.0f);
				x_window.draw(skeleton_hit);
			}
			else {
				skeleton_hit.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
				skeleton_hit.setPosition(position_x + 300 + x, position_y);
				skeleton_hit.setTexture(skeleton_hit_texture);
				skeleton_hit.setScale(-3.8f, 4.0f);
				x_window.draw(skeleton_hit);
			}



		}

		if (attack_begin == 1) {
			if (anim.getElapsedTime().asMilliseconds() > 100) {
				if (anim_x < 896) {
					anim_x += 128;

					Enemy_Deal_Damage(20, hp);
						
					
					
				}
				else {
					anim.restart();
					attack_begin = 0;
					anim_x = 0;

				}


				anim.restart();
			}

			if (right == true) {
				skeleton_attack.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
				skeleton_attack.setPosition(position_x + x, position_y);
				skeleton_attack.setTexture(skeleton_attack_texture);
				skeleton_attack.setScale(3.8f, 4.0f);
				x_window.draw(skeleton_attack);
			}
			else {
				skeleton_attack.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
				skeleton_attack.setPosition(position_x + 300 + x, position_y);
				skeleton_attack.setTexture(skeleton_attack_texture);
				skeleton_attack.setScale(-3.8f, 4.0f);
				x_window.draw(skeleton_attack);
			}




		}
		if (attack_begin == 0 && hit == 0 && dead == 0) {

			if (alerted == 1) {
				if (Walk::player_position >= position_x - 100) {
					right = 1;
				}
				if (Walk::player_position < position_x + 100) {
					right = 0;
				}
			}

			if (anim.getElapsedTime().asMilliseconds() > 100) {
				if (anim_x < 384) {
					anim_x += 128;
				}
				else {


					anim_x = 0;

				}


				anim.restart();
			}

			if (right == true) {
				skeleton_idle.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
				skeleton_idle.setPosition(position_x + x, position_y);
				skeleton_idle.setTexture(skeleton_idle_texture);
				skeleton_idle.setScale(3.8f, 4.0f);
				x_window.draw(skeleton_idle);
			}
			else {
				skeleton_idle.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
				skeleton_idle.setPosition(position_x + 300 + x, position_y);
				skeleton_idle.setTexture(skeleton_idle_texture);
				skeleton_idle.setScale(-3.8f, 4.0f);
				x_window.draw(skeleton_idle);
			}
		}

		if (dead == 1) {
			hit = 0;
			attack_begin = 0;
			if (anim.getElapsedTime().asMilliseconds() > 100) {
				if (anim_x < 384) {
					anim_x += 128;


				}
				else {
					is_alive = 0;
					Player::souls++;
					//attack.restart();
					//hit = 0;
					//anim_x = 0;

				}


				anim.restart();
			}

			if (right == true) {
				skeleton_dead.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
				skeleton_dead.setPosition(position_x + x, position_y);
				skeleton_dead.setTexture(skeleton_dead_texture);
				skeleton_dead.setScale(3.8f, 4.0f);
				x_window.draw(skeleton_dead);
			}
			else {
				skeleton_dead.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
				skeleton_dead.setPosition(position_x + 300 + x, position_y);
				skeleton_dead.setTexture(skeleton_dead_texture);
				skeleton_dead.setScale(-3.8f, 4.0f);
				x_window.draw(skeleton_dead);
			}
		}
	}
 else {


 
 if (right == true) {
	 skeleton_dead.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
	 skeleton_dead.setPosition(position_x + x, position_y);
	 skeleton_dead.setTexture(skeleton_dead_texture);
	 skeleton_dead.setScale(3.8f, 4.0f);
	 x_window.draw(skeleton_dead);
 }
 else {
	 skeleton_dead.setTextureRect(sf::IntRect(anim_x, 14, 120, 80));
	 skeleton_dead.setPosition(position_x + 300 + x, position_y);
	 skeleton_dead.setTexture(skeleton_dead_texture);
	 skeleton_dead.setScale(-3.8f, 4.0f);
	 x_window.draw(skeleton_dead);
 }


}



}


