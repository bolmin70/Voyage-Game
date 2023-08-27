#include "Combat.h"
#include "Movement.h"
#include "sfml/graphics.hpp"
#include "sfml/audio.hpp"
#include "cstdlib"
#include "time.h"
#include "iostream"
#include "Player.h"
#include "Collision.h"

using namespace std;



sf::Clock Combat::anim_clock;
sf::Clock Combat::move_clock;
int Combat::anim_x;

int Combat::choose_attack;

sf::Sprite Combat::character_attack1;

sf::Texture Combat::character_attack1_texture;

sf::Texture Combat::character_attack2_texture;

sf::Texture Combat::character_attack3_texture;

int Combat::attack1_start = 0;

//sfx
sf::SoundBuffer Combat_SFX::sword_attack1_buffer;

sf::Sound Combat_SFX::sword_attack1;


void Combat::Attack(int& x_parralax, sf::RenderWindow& x_window)
{
	if (attack1_start == 1 && Rolling::roll_begin != 1 && Equipment::sword_equip_start == 0) {

			if (Walk::is_running == true) {
				Walk::is_running = false;

			}
			
			if (choose_attack == 0) {
				if (Walk::right == true) {
					if (anim_clock.getElapsedTime().asMilliseconds() > 60) {
						if (anim_x < 512) {
							anim_x += 128;
							//Walk::player_position += 5;
						}
						else {
							attack1_start = 0;

							if (Walk::tired < 3) {
								Walk::tired++;
							}
						}

						anim_clock.restart();
					}
					character_attack1.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
					character_attack1.setPosition(Walk::player_position, Walk::player_position_y);
					character_attack1.setTexture(character_attack1_texture);
					character_attack1.setScale(3.8f, 4.0f);
					x_window.draw(character_attack1);
				}
				else {

					if (anim_clock.getElapsedTime().asMilliseconds() > 50) {
						if (anim_x < 512) {
							anim_x += 128;
							//Walk::player_position -= 35;
						}
						else {
							attack1_start = 0;
							if (Walk::tired < 3) {
								Walk::tired++;
							}
						}
						anim_clock.restart();
					}
					character_attack1.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
					character_attack1.setPosition(Walk::player_position + 300, Walk::player_position_y);
					character_attack1.setTexture(character_attack1_texture);
					character_attack1.setScale(-3.8f, 4.0f);
					x_window.draw(character_attack1);
				}
			}

			if (choose_attack == 1) {
				if (Walk::right == true) {
					if (anim_clock.getElapsedTime().asMilliseconds() > 60) {
						if (anim_x < 640) {
							anim_x += 128;
							//Walk::player_position += 5;
						}
						else {
							attack1_start = 0;

							if (Walk::tired < 3) {
								Walk::tired++;
							}
						}

						anim_clock.restart();
					}
					character_attack1.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
					character_attack1.setPosition(Walk::player_position, Walk::player_position_y);
					character_attack1.setTexture(character_attack2_texture);
					character_attack1.setScale(3.8f, 4.0f);
					x_window.draw(character_attack1);
				}
				else {

					if (anim_clock.getElapsedTime().asMilliseconds() > 60) {
						if (anim_x < 640) {
							anim_x += 128;
							//Walk::player_position -= 35;
						}
						else {
							attack1_start = 0;
							if (Walk::tired < 3) {
								Walk::tired++;
							}
						}
						anim_clock.restart();
					}
					character_attack1.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
					character_attack1.setPosition(Walk::player_position + 300, Walk::player_position_y);
					character_attack1.setTexture(character_attack2_texture);
					character_attack1.setScale(-3.8f, 4.0f);
					x_window.draw(character_attack1);
				}
			}

			if (choose_attack == 2) {
				if (Walk::right == true) {
					if (anim_clock.getElapsedTime().asMilliseconds() > 60) {
						if (anim_x < 1024) {
							anim_x += 128;
							//Walk::player_position += 5;
						}
						else {
							attack1_start = 0;

							if (Walk::tired < 3) {
								Walk::tired++;
							}
						}

						anim_clock.restart();
					}
					character_attack1.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
					character_attack1.setPosition(Walk::player_position, Walk::player_position_y);
					character_attack1.setTexture(character_attack3_texture);
					character_attack1.setScale(3.8f, 4.0f);
					x_window.draw(character_attack1);
				}
				else {

					if (anim_clock.getElapsedTime().asMilliseconds() > 60) {
						if (anim_x < 1024) {
							anim_x += 128;
							//Walk::player_position -= 35;
						}
						else {
							attack1_start = 0;
							if (Walk::tired < 3) {
								Walk::tired++;
							}
						}
						anim_clock.restart();
					}
					character_attack1.setTextureRect(sf::IntRect(anim_x, 0, 100, 80));
					character_attack1.setPosition(Walk::player_position + 300, Walk::player_position_y);
					character_attack1.setTexture(character_attack3_texture);
					character_attack1.setScale(-3.8f, 4.0f);
					x_window.draw(character_attack1);
				}
			}


	}
}

void Combat::Attack_Textures()
{
	character_attack1_texture.loadFromFile("Assets/Textures/Player/Daemon/Attacks/attack1.png");
	Collision::CreateTextureAndBitmask(character_attack1_texture, "Assets/Textures/Player/Daemon/Attacks/attack1.png");

	character_attack2_texture.loadFromFile("Assets/Textures/Player/Daemon/Attacks/attack2.png");
	Collision::CreateTextureAndBitmask(character_attack2_texture, "Assets/Textures/Player/Daemon/Attacks/attack2.png");

	character_attack3_texture.loadFromFile("Assets/Textures/Player/Daemon/Attacks/attack3.png");
	Collision::CreateTextureAndBitmask(character_attack3_texture, "Assets/Textures/Player/Daemon/Attacks/attack3.png");

	character_attack1.setTexture(character_attack1_texture);
	character_attack1.setScale(3.8f, 4.0f);
	cout << "player - Combat..." << endl;
}

void Combat::Attack_Events(sf::Event& x_event)
{
	if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::LShift) {
		if (attack1_start == 0 && Equipment::sword_equipped == 1 && Walk::is_running == false) {
			if (Player::player_current_stamina >= 100) {
				Player::player_current_stamina -= 100;
				attack1_start = 1;
				anim_x = 0;
				choose_attack = rand() % 3;
			}
		}
	}
	if (sf::Joystick::isConnected(0) == 1) {
		if (sf::Joystick::isButtonPressed(0, 5)) {
			if (attack1_start == 0 && Walk::is_running == false) {
				if (Player::player_current_stamina >= 100) {
					Player::player_current_stamina -= 100;
					attack1_start = 1;
					anim_x = 0;
					choose_attack = rand() % 3;
					if (choose_attack == 0) {
						Combat_SFX::sword_attack1.play();
					}
					if (choose_attack == 1) {

					}
					if (choose_attack == 2) {

					}
				}
			}
		}

	}

}

void Combat_SFX::Load_SFX()
{
	sword_attack1_buffer.loadFromFile("Assets/Audio/Effects/sword1.flac");
	sword_attack1.setBuffer(sword_attack1_buffer);
}
