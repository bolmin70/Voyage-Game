#include "sfml/graphics.hpp"
#include "sfml/audio.hpp"
#include "Movement.h"
#include "iostream"
#include "Combat.h"
#include "Player.h"
#include "Collision.h"
#include "Level.h"

using namespace std;


 
//walkin/running
bool Walk::is_running = 0;
bool Walk::tutorial_moving = 1;
bool Walk::right = 1;

sf::Clock Walk::anim_clock;
sf::Clock Walk::move_clock;

int Walk::anim_x = 0;
int Walk::player_position = 150;
int Walk::player_position_y = 300;
int Walk::x_plx = 0;

int Walk::Run_Anim = 0;

int Walk::tired = 0;

bool Walk::right_clicked = 0;
bool Walk::left_clicked = 0;

sf::Texture Walk::character_run_texture;

sf::Sprite Walk::character_run;



sf::Texture Walk::character_idle_sword_texture;

sf::Texture Walk::character_idle_texture;

sf::Sprite Walk::character_idle;





//equiping sword
sf::Clock Equipment::anim_clock;
sf::Clock Equipment::move_clock;




int Equipment::anim_x = 0;

bool Equipment::sword_equipped = 0;

bool Equipment::sword_equip_start = 0;

sf::Texture Equipment::character_equip_sword_texture;

sf::Texture Equipment::character_unequip_sword_texture;

sf::Sprite Equipment::character_equip_sword;


sf::Texture Equipment::character_drink_texture;

sf::Sprite Equipment::character_drink;


//combat roll
sf::Clock Rolling::anim_clock;
sf::Clock Rolling::move_clock;


int Rolling::anim_x;
bool Rolling::roll_begin;


sf::Texture Rolling::character_roll_texture;

sf::Sprite Rolling::character_roll;


sf::Texture Walk::character_walk_texture;

sf::Sprite Walk::character_walk;





//jumping - experimental
sf::Clock Jumping::anim_clock;
sf::Clock Jumping::move_clock;




int Jumping::anim_x;
bool Jumping::jump_begin;
int Jumping::jump_y = 0;

sf::Texture Jumping::character_jump_texture;

sf::Sprite Jumping::character_jump;

int Jumping::double_jump = 2;

//gravity
int Physics::G;
bool Physics::on_platform = true;


//Sit

sf::Clock Sitting::anim_clock;
sf::Clock Sitting::move_clock;

sf::Sprite Sitting::character_sit;

sf::Texture Sitting::character_sit_texture;


sf::Sprite Sitting::character_sit_start;

sf::Texture Sitting::character_sit_start_texture;


sf::Sprite Sitting::character_sit_end;

sf::Texture Sitting::character_sit_end_texture;

int Sitting::sit = 0;
int Sitting::sit_begin = 0;
int Sitting::sit_end = 0;
int Sitting::anim_x = 0;

//hit
sf::Clock Hit::anim_clock;
sf::Clock Hit::move_clock;

int Hit::anim_x;


sf::Sprite Hit::character_hit_right;

sf::Texture Hit::character_hit_right_texture;


sf::Sprite Hit::character_hit_left;

sf::Texture Hit::character_hit_left_texture;

bool Hit::hit = 0;

//sounds
sf::SoundBuffer Movement_SFX::sword_unsheath_buffer;

sf::Sound  Movement_SFX::sword_unsheath;

//hitbox
sf::Texture Physics::character_hitbox_texture;
sf::Texture Physics::character_hitbox_full_texture;

sf::Sprite Physics::character_hitbox;
bool Physics::cycle_f12 = 0;



void Walk::Run_Textures() {
	cout << "loading - player" << endl << endl;

	cout << "player - Movement..." << endl;
	Collision::CreateTextureAndBitmask(Walk::character_run_texture, "Assets/Textures/Player/Daemon/Run/run_right.png");
	character_run_texture.loadFromFile("Assets/Textures/Player/Daemon/Run/run_right.png");
	Collision::CreateTextureAndBitmask(Walk::character_run_texture, "Assets/Textures/Player/Daemon/Run/run_right.png");


	character_run.setTexture(character_run_texture);
	character_run.setScale(3.8f, 4.0f);



	character_walk_texture.loadFromFile("Assets/Textures/Player/Daemon/Run/walk_right.png");
	Collision::CreateTextureAndBitmask(Walk::character_walk_texture, "Assets/Textures/Player/Daemon/Run/walk_right.png");


	character_walk.setTexture(character_walk_texture);
	character_walk.setScale(3.8f, 4.0f);



	character_idle_texture.loadFromFile("Assets/Textures/Player/Daemon/Idle/idle_right.png");
	Collision::CreateTextureAndBitmask(Walk::character_idle_texture, "Assets/Textures/Player/Daemon/Idle/idle_right.png");

	character_idle_sword_texture.loadFromFile("Assets/Textures/Player/Daemon/Idle/idle_weapon_right.png");
	Collision::CreateTextureAndBitmask(Walk::character_idle_sword_texture, "Assets/Textures/Player/Daemon/Idle/idle_weapon_right.png");


	character_idle.setTexture(character_idle_texture);
	character_idle.setScale(3.8f, 4.0f);

}

void Walk::Run(int& x_parralax, sf::RenderWindow& x_window) {
	character_idle.setPosition(player_position, player_position_y);
	character_run.setPosition(player_position, player_position_y);
	//cout << player_position << endl;
	
	if (is_running == true && Equipment::sword_equip_start == 0 && Rolling::roll_begin == 0 && Sitting::sit_begin == 0 && Sitting::sit == 0 && Sitting::sit_end == 0 && Combat::attack1_start == 0 && Hit::hit == 0 && Physics::on_platform == 1 && Jumping::jump_begin == 0) {
		
		if (Equipment::sword_equipped == 0) {
			if (anim_clock.getElapsedTime().asMilliseconds() > 40) {
				if (anim_x < 1408) {
					anim_x += 128;
				}
				else {
					if (tired < 3) {
						tired++;
					}
					anim_x = 0;
				}


				anim_clock.restart();
			}




			if (right == true) {
				if (Walk::player_position > Levels::x_far_bound) {

				}
				else {
					player_position += 20;
				}
				character_run.setPosition(player_position, player_position_y);
				character_run.setTexture(character_run_texture);
				character_run.setScale(3.8f, 4.0f);
				character_run.setTextureRect(sf::IntRect(anim_x, 0, 60, 80));
				x_window.draw(character_run);

				


			}
			else {
				if (player_position < Levels::x_near_bound) {
				}
				else {
					player_position -= 20;
				}
				character_run.setPosition(player_position + 300, player_position_y);
				character_run.setTexture(character_run_texture);
				character_run.setScale(-3.8f, 4.0f);
				character_run.setTextureRect(sf::IntRect(anim_x, 0, 60, 80));
				x_window.draw(character_run);
				
			}

		}
		else {
			if (anim_clock.getElapsedTime().asMilliseconds() > 40) {
				if (anim_x < 1280) {
					anim_x += 128;
				}
				else {
					anim_x = 0;
				}


				anim_clock.restart();
			}

			if (right == true) {
				if (Walk::player_position > Levels::x_far_bound) {
					
				}
				else {
					player_position += 10;
				}
				character_walk.setPosition(player_position, player_position_y);
				character_walk.setTexture(character_walk_texture);
				character_walk.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
				character_walk.setScale(3.8f, 4.0f);
				x_window.draw(character_walk);

				if (move_clock.getElapsedTime().asMilliseconds() > 60) {
					

					move_clock.restart();
				}


			}
			else {
				if (player_position < Levels::x_near_bound) {
				}
				else {
					player_position -= 10;
				}
				character_walk.setPosition(player_position + 300, player_position_y);
				character_walk.setTexture(character_walk_texture);
				character_walk.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
				character_walk.setScale(-3.8f, 4.0f);
				x_window.draw(character_walk);
				if (move_clock.getElapsedTime().asMilliseconds() > 60) {

					


					move_clock.restart();


				}
			}

		}


	}
	else {
		if (tired == 0) {
			if (anim_clock.getElapsedTime().asMilliseconds() > 500) {
				if (anim_x < 576) {
					anim_x += 128;
				}
				else {
					anim_x = 0;
					
				}

				anim_clock.restart();
			}
		}
		if (tired == 1) {
			if (anim_clock.getElapsedTime().asMilliseconds() > 300) {
				if (anim_x < 576) {
					anim_x += 128;
				}
				else {
					anim_x = 0;
					tired--;
				}

				anim_clock.restart();
			}
		}
		if (tired == 2) {
			if (anim_clock.getElapsedTime().asMilliseconds() > 250) {
				if (anim_x < 576) {
					anim_x += 128;
				}
				else {
					anim_x = 0;
					tired--;
				}

				anim_clock.restart();
			}
		}
		if (tired == 3) {
			if (anim_clock.getElapsedTime().asMilliseconds() > 150) {
				if (anim_x < 576) {
					anim_x += 128;
				}
				else {
					anim_x = 0;
					tired--;
				}

				anim_clock.restart();
			}
		}

		if (Equipment::sword_equip_start == 0 && Rolling::roll_begin == 0 && Combat::attack1_start == 0 && Jumping::jump_begin == 0 && Sitting::sit_begin == 0 && Sitting::sit == 0 && Sitting::sit_end == 0 && Hit::hit == 0 && Physics::on_platform == 1) {
			if (Equipment::sword_equipped == 0) {
				if (right == true) {

					character_idle.setTextureRect(sf::IntRect(anim_x, 0, 60, 80));
					character_idle.setPosition(player_position, player_position_y);
					character_idle.setTexture(character_idle_texture);
					character_idle.setScale(3.8f, 4.0f);
					x_window.draw(character_idle);
				}
				else {
					character_idle.setTextureRect(sf::IntRect(anim_x, 0, 60, 80));
					character_idle.setPosition(player_position + 300, player_position_y);
					character_idle.setTexture(character_idle_texture);
					character_idle.setScale(-3.8f, 4.0f);
					x_window.draw(character_idle);
				}
			}
			else {
				if (right == true) {

					character_idle.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
					character_idle.setPosition(player_position, player_position_y);
					character_idle.setTexture(character_idle_sword_texture);
					character_idle.setScale(3.8f, 4.0f);
					x_window.draw(character_idle);
				}
				else {
					character_idle.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
					character_idle.setPosition(player_position + 300, player_position_y);
					character_idle.setTexture(character_idle_sword_texture);
					character_idle.setScale(-3.8f, 4.0f);
					x_window.draw(character_idle);
				}
			}
		}
	
	}


}

void Walk::Run_Events(sf::Event& x_event) {
	
		if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::D) {
			if (Rolling::roll_begin == 0) {
				Walk::right_clicked = 1;
				Walk::is_running = true;
				Walk::right = true;
			}
		}
		if (x_event.type == sf::Event::KeyReleased && x_event.key.code == sf::Keyboard::D) {
			Walk::Run_Anim = 1;
			Walk::right_clicked = 0;
			Walk::anim_x = 0;
			Walk::is_running = false;
		}

		if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::Right) {
			if (Rolling::roll_begin == 0) {
				Walk::right_clicked = 1;
				Walk::is_running = true;
				Walk::right = true;
			}
		}
		if (x_event.type == sf::Event::KeyReleased && x_event.key.code == sf::Keyboard::Right) {
			Walk::right_clicked = 0;
			Walk::Run_Anim = 1;
			Walk::anim_x = 0;
			Walk::is_running = false;
		}
		
		if (sf::Joystick::isConnected(0) == 1) {
			if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) > 20) {
				if (Rolling::roll_begin == 0 && Equipment::sword_equip_start == 0) {
					Walk::right_clicked = 1;
					if (Jumping::jump_begin == 0) {
						Walk::is_running = true;
						Walk::right = true;
					}
				}
			}
			if (Walk::right_clicked == 1) {
				if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) < 20 && sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) >= 0) {
					Walk::right_clicked = 0;
					Walk::Run_Anim = 1;
					Walk::anim_x = 0;
					Walk::is_running = false;
				}
			}

			if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) < -20) {
				if (Rolling::roll_begin == 0 && Equipment::sword_equip_start == 0) {
					Walk::left_clicked = 1;
					if (Jumping::jump_begin == 0) {
						Walk::is_running = true;
						Walk::right = false;
					}
				}
			}
			if (Walk::left_clicked == 1) {
				if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) > -20 && sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) >= 0) {
					Walk::left_clicked = 0;
					Walk::Run_Anim = 1;
					Walk::anim_x = 0;
					Walk::is_running = false;
				}
			}

		}
		if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::A) {
			if (Rolling::roll_begin == 0) {
				Walk::left_clicked = 1;
				Walk::is_running = true;
				Walk::right = false;
			}
		}
		if (x_event.type == sf::Event::KeyReleased && x_event.key.code == sf::Keyboard::A) {
			Walk::left_clicked = 0;
			Walk::Run_Anim = 1;
			Walk::anim_x = 0;
			Walk::is_running = false;
		}


		if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::Left) {
			if (Rolling::roll_begin == 0) {
				Walk::left_clicked = 1;
				Walk::is_running = true;
				Walk::right = false;
			}
		}
		if (x_event.type == sf::Event::KeyReleased && x_event.key.code == sf::Keyboard::Left) {
			Walk::left_clicked = 0;
			Walk::Run_Anim = 1;
			Walk::anim_x = 0;
			Walk::is_running = false;
		}

		if (x_event.type == sf::Event::KeyReleased && x_event.key.code == sf::Keyboard::F12) {
			Physics::cycle_f12 != Physics::cycle_f12;
			if (Physics::cycle_f12 == 0) {
				Physics::character_hitbox.setTexture(Physics::character_hitbox_texture);
			}
			if (Physics::cycle_f12 == 1) {
				Physics::character_hitbox.setTexture(Physics::character_hitbox_full_texture);
			}

		}

	}


void Equipment::Equip_Textures() {
	character_equip_sword_texture.loadFromFile("Assets/Textures/Player/Daemon/Equip/sword_right.png");
	Collision::CreateTextureAndBitmask(character_equip_sword_texture, "Assets/Textures/Player/Daemon/Equip/sword_right.png");

	character_unequip_sword_texture.loadFromFile("Assets/Textures/Player/Daemon/Equip/un_sword_right.png");
	Collision::CreateTextureAndBitmask(character_unequip_sword_texture, "Assets/Textures/Player/Daemon/Equip/un_sword_right.png");

	character_equip_sword.setTexture(character_equip_sword_texture);
	character_equip_sword.setScale(3.8f, 4.0f);


	character_drink_texture.loadFromFile("Assets/Textures/Player/Daemon/Equip/drink.png");
	Collision::CreateTextureAndBitmask(character_drink_texture, "Assets/Textures/Player/Daemon/Equip/drink.png");


	character_drink.setTexture(character_drink_texture);
	character_drink.setScale(3.8f, 4.0f);
	cout << "player - Equiping..." << endl;
}

void Equipment::Equip(int& x_parralax, sf::RenderWindow& x_window) {
	if (sword_equip_start == 1 && Rolling::roll_begin != 1 && Physics::on_platform == 1) {
		if (Walk::is_running == true) {
			Walk::is_running = false;

		}
		else {
			if (sword_equipped == false) {

				if (anim_clock.getElapsedTime().asMilliseconds() > 50) {
					if (anim_x < 384) {
						anim_x += 128;
					}
					else {
						sword_equip_start = 0;
						sword_equipped = 1;
						anim_x = 0;
					}

					anim_clock.restart();
				}

				if (Walk::right == true) {
					character_equip_sword.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
					character_equip_sword.setPosition(Walk::player_position, Walk::player_position_y);
					character_equip_sword.setTexture(character_equip_sword_texture);
					character_equip_sword.setScale(3.8f, 4.0f);
					x_window.draw(character_equip_sword);
				}
				else {
					character_equip_sword.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
					character_equip_sword.setPosition(Walk::player_position + 300, Walk::player_position_y);
					character_equip_sword.setTexture(character_equip_sword_texture);
					character_equip_sword.setScale(-3.8f, 4.0f);
					x_window.draw(character_equip_sword);
				}
			}
			else {

				if (anim_clock.getElapsedTime().asMilliseconds() > 50) {
					if (anim_x < 384) {
						anim_x += 128;
					}
					else {
						sword_equip_start = 0;
						sword_equipped = 0;
						//anim_x = 0;
					}

					anim_clock.restart();
				}

				if (Walk::right == true) {
					character_equip_sword.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
					character_equip_sword.setPosition(Walk::player_position, Walk::player_position_y);
					character_equip_sword.setTexture(character_unequip_sword_texture);
					character_equip_sword.setScale(3.8f, 4.0f);
					x_window.draw(character_equip_sword);
				}
				else {
					character_equip_sword.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
					character_equip_sword.setPosition(Walk::player_position + 300, Walk::player_position_y);
					character_equip_sword.setTexture(character_unequip_sword_texture);
					character_equip_sword.setScale(-3.8f, 4.0f);
					x_window.draw(character_equip_sword);
				}
			}

		}
	}

}

void Equipment::Equip_Events(sf::Event& x_event) {
	if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::E) {
		if (sword_equip_start == 0 && Physics::on_platform == 1) {
			sword_equip_start = 1;
			Combat::attack1_start = 0;
			anim_x = 0;
			Movement_SFX::sword_unsheath.setVolume(100);
			Movement_SFX::sword_unsheath.play();
		}
	}

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > 80 || sf::Joystick::isButtonPressed(0, 3)) { //|| sf::Joystick::isButtonPressed(0, 5)
		if (sword_equip_start == 0 && Physics::on_platform == 1) {
			sword_equip_start = 1;
			Combat::attack1_start = 0;
			anim_x = 0;
			Movement_SFX::sword_unsheath.setVolume(100);
			Movement_SFX::sword_unsheath.play();
		}
	}
}


void Rolling::Roll_Textures() {
	character_roll_texture.loadFromFile("Assets/Textures/Player/Daemon/Roll/roll_right.png");
	Collision::CreateTextureAndBitmask(character_roll_texture, "Assets/Textures/Player/Daemon/Roll/roll_right.png");

	character_roll.setTexture(character_roll_texture);
	character_roll.setScale(3.8f, 4.0f);
	cout << "player - Rolling..." << endl;
}

void Rolling::Roll(int& x_parralax, sf::RenderWindow& x_window) {
	character_roll.setPosition(Walk::player_position, Walk::player_position_y);
	if (roll_begin == 1 ) {
		
		if (Walk::is_running == true) {
			Walk::is_running = false;

		}
			else {
				

				if (Walk::right == true) {
					if (Walk::player_position > Levels::x_far_bound) {

					}
					else {
						Walk::player_position += 20;
					}
					if (anim_clock.getElapsedTime().asMilliseconds() > 50) {
						if (anim_x < 1280) {
							anim_x += 128;
							
						}
						else {
							roll_begin = 0;
							if (Walk::right_clicked == 1 || Walk::left_clicked == 1) {
								Walk::is_running = 1;
							}
							if (Equipment::sword_equipped == 1) {
								Equipment::sword_equipped = 0;
								Equipment::sword_equip_start = 1;

							}
						}

						anim_clock.restart();
					}

					character_roll.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
					character_roll.setPosition(Walk::player_position, Walk::player_position_y);
					character_roll.setTexture(character_roll_texture);
					character_roll.setScale(3.8f, 4.0f);
					x_window.draw(character_roll);
				}
				else {
					if (Walk::player_position < Levels::x_near_bound) {

					}
					else {
						Walk::player_position -= 20;
					}
					if (anim_clock.getElapsedTime().asMilliseconds() > 50) {
						if (anim_x < 1280) {
							anim_x += 128;
							
						}
						else {
							
							roll_begin = 0;
							if (Walk::right_clicked == 1 || Walk::left_clicked == 1) {
								Walk::is_running = 1;
							}
							if (Equipment::sword_equipped == 1) {
								Equipment::sword_equipped = 0;
								Equipment::sword_equip_start = 1;

							}
						}



						anim_clock.restart();
					}

					character_roll.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
					character_roll.setPosition(Walk::player_position + 300, Walk::player_position_y);
					character_roll.setTexture(character_roll_texture);
					character_roll.setScale(-3.8f, 4.0f);
					x_window.draw(character_roll);
				}
			
			

		}
	}
}

void Rolling::Roll_Events(sf::Event& x_event) {
	if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::Space) {
		if (Equipment::sword_equipped == 2) {
			Equipment::sword_equip_start = 1;
			Combat::attack1_start = 0;
			anim_x = 0;
		}
		if (Jumping::jump_begin == 0 && roll_begin == 0 && Hit::hit == 0 && Physics::on_platform == 1) {
			if (Player::player_current_stamina >= 50) {
				roll_begin = 1;
				anim_x = 0;
				Player::player_current_stamina -= 50;
				if (Walk::tired < 3) {
					Walk::tired++;
				}
			}
		}
	}

	if (sf::Joystick::isButtonPressed(0, 0)) {
		if (Equipment::sword_equipped == 2) {
			Equipment::sword_equip_start = 1;
			Combat::attack1_start = 0;
			anim_x = 0;
		}
		if (Jumping::jump_begin == 0 && roll_begin == 0 && Hit::hit == 0 && Physics::on_platform == 1) {
			if (Player::player_current_stamina >= 50) {
				roll_begin = 1;
				anim_x = 0;
				Player::player_current_stamina -= 50;
				
				if (Walk::tired < 3) {
					Walk::tired++;
				}
			}
		}
	}

}


void Jumping::Jump_Textures() {
	character_jump_texture.loadFromFile("Assets/Textures/Player/Daemon/Jump/jump.png");
	Collision::CreateTextureAndBitmask(character_jump_texture, "Assets/Textures/Player/Daemon/Jump/jump.png");

	character_jump.setTexture(character_jump_texture);
	character_jump.setScale(3.8f, 4.0f);
	cout << "player - Jumping..." << endl;
}
void Jumping::Jump(int& x_parralax, sf::RenderWindow& x_window) {
	character_jump.setPosition(Walk::player_position, Walk::player_position_y);
	if (jump_begin == 1 && Rolling::roll_begin == 0 && Equipment::sword_equipped == 0) {
		if (Walk::is_running == true) {
			Walk::is_running = false;

		}
		else {


			if (Walk::right == true) {
				if (anim_x > 640) {
					//jump_begin = 0;
					//jump_y += 30;
					//Walk::player_position_y += 10;
					//if (Collision::PixelPerfectTest(Level1::platform, Walk::character_idle)) {
					//	Jumping::jump_begin = 0;
					//}
				}
				else {
					//jump_y -= 30;
					Walk::player_position_y -= 45;
				}

				if (Walk::right_clicked == 1) {
					if (Walk::player_position > Levels::x_far_bound) {

					}
					else {
						Walk::player_position += 20;
					}
				}
				if (anim_clock.getElapsedTime().asMilliseconds() > 25) {
					if (anim_x < 1280) {
						anim_x += 128;
						//Walk::player_position += 35;
						

						

					}
					else {
						if (Walk::tired < 3) {
							Walk::tired++;
						}
						jump_begin = 0;
						if (Walk::right_clicked == 1 || Walk::left_clicked == 1) {
							Walk::is_running = 1;
						}

					}

					anim_clock.restart();
				}

				character_jump.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
				character_jump.setPosition(Walk::player_position, Walk::player_position_y);
				character_jump.setTexture(character_jump_texture);
				character_jump.setScale(3.8f, 4.0f);
				x_window.draw(character_jump);
			}
			else {
				if (anim_x > 640) {

				}
				else {
					Walk::player_position_y -= 45;
					//jump_y -= 30;
				}

				if (Walk::left_clicked == 1) {
					if (Walk::player_position < Levels::x_near_bound) {

					}
					else {
						Walk::player_position -= 20;
					}
				}
				if (anim_clock.getElapsedTime().asMilliseconds() > 25) {
					if (anim_x < 1280) {
						anim_x += 128;

						

					}
					else {
						if (Walk::tired < 3) {
							Walk::tired++;
						}
						jump_begin = 0;
						if (Walk::right_clicked == 1 || Walk::left_clicked == 1) {
							Walk::is_running = 1;
						}
					}



					anim_clock.restart();
				}

				character_jump.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
				character_jump.setPosition(Walk::player_position + 300, Walk::player_position_y);
				character_jump.setTexture(character_jump_texture);
				character_jump.setScale(-3.8f, 4.0f);
				x_window.draw(character_jump);
			}



		}
	}
}
void Jumping::Jump_Events(sf::Event& x_event) {
	if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::W) {
		if (jump_begin == 0 && Equipment::sword_equipped == 0 && Rolling::roll_begin == 0 && Jumping::double_jump > 0) {
			double_jump--;
			jump_begin = 1;
			anim_x = 0;
		}

	}
	if (sf::Joystick::isButtonPressed(0, 1)) {
		if (jump_begin == 0 && Rolling::roll_begin == 0 && Jumping::double_jump > 0) {
			double_jump--;
			jump_begin = 1;
			anim_x = 0;
		}
	}
}


void Physics::Hitbox_Textures()
{
	character_hitbox_full_texture.loadFromFile("Assets/Textures/Player/Daemon/Run/hitbox_show.png");
	Collision::CreateTextureAndBitmask(character_hitbox_full_texture, "Assets/Textures/Player/Daemon/Run/hitbox_show.png");

	character_hitbox_texture.loadFromFile("Assets/Textures/Player/Daemon/Run/hitbox.png");
	Collision::CreateTextureAndBitmask(character_hitbox_texture, "Assets/Textures/Player/Daemon/Run/hitbox.png");

	character_hitbox.setTexture(character_hitbox_texture);
	character_hitbox.setScale(3.8f, 4.0f);
}

void Physics::Gravity(int& x_parralax, sf::RenderWindow& x_window)
{
	if (on_platform == false && Jumping::jump_begin == 0) {

		G = -20;
		Walk::player_position_y -= G;

		if (on_platform == false && Rolling::roll_begin == 0) {
			if (Walk::right == true) {
				if (Walk::right_clicked == 1) {
					if (Walk::player_position > Levels::x_far_bound) {

					}
					else {
						Walk::player_position += 15;
					}
				}
				if (Jumping::anim_clock.getElapsedTime().asMilliseconds() > 25) {
					
						Jumping::anim_x = 1280;
						if (Equipment::sword_equipped == 1) {
							Equipment::sword_equip_start = 1;
						}

						

					
					
					
					Jumping::anim_clock.restart();
				}

				Jumping::character_jump.setTextureRect(sf::IntRect(Jumping::anim_x, 0, 80, 80));
				Jumping::character_jump.setPosition(Walk::player_position, Walk::player_position_y);
				Jumping::character_jump.setTexture(Jumping::character_jump_texture);
				Jumping::character_jump.setScale(3.8f, 4.0f);
				x_window.draw(Jumping::character_jump);
			}
			else {
				if (Walk::left_clicked == 1) {
					if (Walk::player_position < Levels::x_near_bound) {

					}
					else {
						Walk::player_position -= 15;
					}
				}
				if (Jumping::anim_clock.getElapsedTime().asMilliseconds() > 25) {
					
						Jumping::anim_x = 1280;

						

					
					Jumping::anim_clock.restart();
				}

				Jumping::character_jump.setTextureRect(sf::IntRect(Jumping::anim_x, 0, 100, 80));
				Jumping::character_jump.setPosition(Walk::player_position + 300, Walk::player_position_y);
				Jumping::character_jump.setTexture(Jumping::character_jump_texture);
				Jumping::character_jump.setScale(-3.8f, 4.0f);
				x_window.draw(Jumping::character_jump);
			}


		}
	}
	else {
		
		G = 0;
	}
}


void Sitting::Sit(int& x_parralax, sf::RenderWindow& x_window)
{
	if (sit_begin == 1) {
		if (anim_clock.getElapsedTime().asMilliseconds() > 40) {
			if (anim_x < 256) {
				anim_x += 128;
			}
			else {
				sit_begin = 0;
				sit = 1;
				//anim_x = 0;
			}


			anim_clock.restart();
		}

		if (Walk::right == 1) {
			character_sit_start.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
			character_sit_start.setPosition(Walk::player_position, Walk::player_position_y);
			character_sit_start.setScale(3.8f, 4.0f);
			x_window.draw(character_sit_start);
		}
		else {
			character_sit_start.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
			character_sit_start.setPosition(Walk::player_position + 300, Walk::player_position_y);
			character_sit_start.setScale(-3.8f, 4.0f);
			x_window.draw(character_sit_start);
		}
	}
	if (sit == 1) {
		if (anim_clock.getElapsedTime().asMilliseconds() > 1000) {
			if (anim_x < 384) {
				anim_x += 128;
			}
			else {
				anim_x = 0;
			}


			anim_clock.restart();
		}

		if (Walk::right == 1) {
			character_sit.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
			character_sit.setPosition(Walk::player_position, Walk::player_position_y);
			character_sit.setScale(3.8f, 4.0f);
			x_window.draw(character_sit);
		}
		else {
			character_sit.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
			character_sit.setPosition(Walk::player_position + 300, Walk::player_position_y);
			character_sit.setScale(-3.8f, 4.0f);
			x_window.draw(character_sit);
		}
	}
	if (sit_end == 1) {
		if (anim_clock.getElapsedTime().asMilliseconds() > 40) {
			if (anim_x < 256) {
				anim_x += 128;
			}
			else {
				sit_end = 0;
				//sit = 0;
				//anim_x = 0;
			}


			anim_clock.restart();
		}

		if (Walk::right == 1) {
			character_sit_end.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
			character_sit_end.setPosition(Walk::player_position, Walk::player_position_y);
			character_sit_end.setScale(3.8f, 4.0f);
			x_window.draw(character_sit_end);
		}
		else {
			character_sit_end.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
			character_sit_end.setPosition(Walk::player_position + 300, Walk::player_position_y);
			character_sit_end.setScale(-3.8f, 4.0f);
			x_window.draw(character_sit_end);
		}


	}

}

void Sitting::Sit_Textures()
{
	character_sit_texture.loadFromFile("Assets/Textures/Player/Daemon/Sit/sit.png");
	Collision::CreateTextureAndBitmask(character_sit_texture, "Assets/Textures/Player/Daemon/Sit/sit.png");

	character_sit.setTexture(character_sit_texture);
	character_sit.setScale(3.8f, 4.0f);


	character_sit_start_texture.loadFromFile("Assets/Textures/Player/Daemon/Sit/sit_start.png");
	Collision::CreateTextureAndBitmask(character_sit_start_texture, "Assets/Textures/Player/Daemon/Sit/sit_start.png");

	character_sit_start.setTexture(character_sit_start_texture);
	character_sit_start.setScale(3.8f, 4.0f);


	character_sit_end_texture.loadFromFile("Assets/Textures/Player/Daemon/Sit/sit_end.png");
	Collision::CreateTextureAndBitmask(character_sit_end_texture, "Assets/Textures/Player/Daemon/Sit/sit_end.png");


	character_sit_end.setTexture(character_sit_start_texture);
	character_sit_end.setScale(3.8f, 4.0f);



	cout << "player - Sitting..." << endl;
}

void Sitting::Sit_Events(sf::Event& x_event)
{
	if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::C) {
		if (sit_begin == 0 && Equipment::sword_equipped == 0 && Rolling::roll_begin == 0 && sit == 0 && Physics::on_platform == 1) {
			sit_begin = 1;
			anim_x = 0;
		}
		if (sit_begin == 0 && sit == 1) {
			sit_end = 1;
			sit = 0;
			anim_x = 0;
		}
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < -80) {
		if (sit_begin == 0 && Equipment::sword_equipped == 0 && Rolling::roll_begin == 0 && sit == 0 && Physics::on_platform == 1) {
			sit_begin = 1;
			anim_x = 0;
		}
		if (sit_begin == 0 && sit == 1) {
			sit_end = 1;
			sit = 0;
			anim_x = 0;
		}
	}

}


void Hit::Hitt_Textures() {
	character_hit_left_texture.loadFromFile("Assets/Textures/Player/Daemon/Hit/hit1.png");
	Collision::CreateTextureAndBitmask(character_hit_left_texture, "Assets/Textures/Player/Daemon/Hit/hit1.png");

	character_hit_left.setTexture(character_hit_left_texture);
	character_hit_left.setScale(3.8f, 4.0f);

	character_hit_right_texture.loadFromFile("Assets/Textures/Player/Daemon/Hit/hit2.png");
	Collision::CreateTextureAndBitmask(character_hit_right_texture, "Assets/Textures/Player/Daemon/Hit/hit2.png");

	character_hit_right.setTexture(character_hit_right_texture);
	character_hit_right.setScale(3.8f, 4.0f);

	cout << "player - Hit..." << endl;
}

void Hit::Hitt(int& x_parralax, sf::RenderWindow& x_window) {
	if (hit == 1) {
		Sitting::sit = 0;
		Rolling::roll_begin = 0;
		Equipment::sword_equip_start = 0;
		Walk::is_running = false;

		if (Walk::is_running == true) {
			Walk::is_running = false;

		}
		else {


			if (Walk::right == true) {
				if (anim_clock.getElapsedTime().asMilliseconds() > 50) {
					if (anim_x < 384) {
						anim_x += 128;
						Walk::player_position -= 5;
					}
					else {
						hit = 0;
						anim_x = 0;
					}

					anim_clock.restart();
				}

				character_hit_right.setTextureRect(sf::IntRect(anim_x, 0, 80, 80));
				character_hit_right.setPosition(Walk::player_position, Walk::player_position_y);
				character_hit_right.setTexture(character_hit_right_texture);
				character_hit_right.setScale(3.8f, 4.0f);
				x_window.draw(character_hit_right);
			}
			else {

				if (anim_clock.getElapsedTime().asMilliseconds() > 50) {
					if (anim_x < 384) {
						anim_x += 128;
						Walk::player_position += 5;
					}
					else {
						anim_x = 0;
						hit = 0;
					
					}



					anim_clock.restart();
				}

				character_hit_left.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
				character_hit_left.setPosition(Walk::player_position + 300, Walk::player_position_y);
				character_hit_left.setTexture(character_hit_left_texture);
				character_hit_left.setScale(-3.8f, 4.0f);
				x_window.draw(character_hit_left);
			}



		}
	}
}


void Movement_SFX::Load_SFX()
{
	sword_unsheath_buffer.loadFromFile("Assets/Audio/Effects/sword2.wav");
	sword_unsheath.setBuffer(sword_unsheath_buffer);

}
