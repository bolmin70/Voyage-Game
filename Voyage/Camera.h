#pragma once
#include "SFML/Graphics.hpp"

class Camera
{
public:
	static sf::View Main_Camera;
	static sf::View Base_Camera;

	static sf::View UI_Camera;


	static sf::Clock anim_clock;

	static int last_spot;


	static sf::RectangleShape fade_rect;

	static int fade;
	//static rect

	static int goto_place;

	static void Camera_Operator(sf::RenderWindow& x_window);

	static void Load_Cameras();

	static void Fade_In(sf::RenderWindow& x_window);

	//static void Fade_Out();

};

