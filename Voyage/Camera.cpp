#include "Camera.h"
#include "SFML/Graphics.hpp"
#include "Movement.h"
#include "Interface.h"
#include "Player.h"

sf::View Camera::Main_Camera(sf::FloatRect(Walk::player_position - 140, Walk::player_position_y - 320, 1920.f, 1080.f));

sf::View Camera::Base_Camera(sf::FloatRect(Walk::player_position - 140, Walk::player_position_y - 420, 1920.f, 1080.f));

sf::View Camera::UI_Camera(sf::FloatRect(0, 0, 1920.f, 1080.f));

int Camera::last_spot;

sf::Clock Camera::anim_clock;

sf::RectangleShape Camera::fade_rect;

int Camera::fade;

int Camera::goto_place = 0;

void Camera::Camera_Operator(sf::RenderWindow& x_window)
{

	if (Walk::player_position < 720 || Walk::player_position > 1140) {	
			if (sf::Joystick::isButtonPressed(0, 11)) {
				Base_Camera.setViewport(sf::FloatRect(0.f - 0.3f, 0.f - 0.3f, 1.f + 0.5f, 1.f + 0.5f));
			}
			else {
				Base_Camera.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
			}
	}
	else {	
			Base_Camera.setCenter(Walk::player_position + 240 + sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z), Walk::player_position_y + 120 + sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R));			
			if (sf::Joystick::isButtonPressed(0, 11)) {
				Base_Camera.setViewport(sf::FloatRect(0.f - 0.3f, 0.f - 0.3f, 1.f + 0.5f, 1.f + 0.5f));
			}
			else {
				Base_Camera.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
			}
	}

	if (Walk::player_position < 720 || Walk::player_position > 6240) {
			if (Walk::player_position < 720) {
				Main_Camera.setCenter(960, Walk::player_position_y + 120 + sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R));
			}
			if (Walk::player_position > 6240) {
				Main_Camera.setCenter(6480, Walk::player_position_y + 120 + sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R));
			}

			if (sf::Joystick::isButtonPressed(0, 11)) {
				Main_Camera.setViewport(sf::FloatRect(0.f - 0.3f, 0.f - 0.3f, 1.f + 0.5f, 1.f + 0.5f));

			}
			else {
				Main_Camera.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

			}		
	}
	else {
		if (Walk::player_position > 830) {			
				Main_Camera.setCenter(Walk::player_position + 240 + sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z), Walk::player_position_y + 120 + sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R));		
		}
		else {
				Main_Camera.setCenter(Walk::player_position + 240, Walk::player_position_y + 120);
		}
		
			if (sf::Joystick::isButtonPressed(0, 11)) {
				Main_Camera.setViewport(sf::FloatRect(0.f - 0.3f, 0.f - 0.3f, 1.f + 0.5f, 1.f + 0.5f));
			}
			else {
				Main_Camera.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

			}
	
	}
	
	if (Walk::player_position_y > 2800 && Walk::player_position_y < 2900) {
		Camera::last_spot = Walk::player_position;

	}
	if (Walk::player_position_y > 2900) {
		Main_Camera.setCenter(Camera::last_spot + 240, 2900);
		Player::player_current_health = 0;
	}
}

void Camera::Load_Cameras()
{
	//Camera::fade_rect.setFillColor(sf::Color(0, 0, 0, fadeint));
	Camera::fade_rect.setPosition(sf::Vector2f(0, 0));
	Camera::fade_rect.setFillColor(sf::Color(0, 0, 0, 0));
	Camera::fade_rect.setSize(sf::Vector2f(2020, 1580));

	UI_Camera.setViewport(sf::FloatRect(0.f, 0.f, 1.5f, 1.5f));

	Main_Camera.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	UI_Camera.zoom(1.5);
}

void Camera::Fade_In(sf::RenderWindow& x_window) {
	if (anim_clock.getElapsedTime().asMilliseconds() > 40) {
		Camera::fade_rect.setFillColor(sf::Color(0, 0, 0, fade));

	}
	if (Player::player_current_health <= 0) {
		if (fade <= 254) {
			fade = fade + 2;
		}
		else {
			fade = 255;
		}
		fade_rect.setPosition(-500, -500);
		x_window.draw(fade_rect);

	}
	if (Walk::player_position >= 7200 && Walk::player_position_y > 2300) {
		if (fade < 254) {
			fade = fade + 2;
		}
		else {
			fade = 255;
			goto_place = 1;
		}
		fade_rect.setPosition(-500, -500);
		x_window.draw(fade_rect);

	}
}
