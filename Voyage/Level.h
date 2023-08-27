#pragma once
#include "SFML/Graphics.hpp"


class Levels {

public:
	static void Level_Textures();
	static void Level_Background(sf::RenderWindow& x_window);
	static void Level_Boundries();
	static int level_code;
	static int x_near_bound;
	static int x_far_bound;
	
};

class Level0
{
public:
	static sf::Texture background_texture;

	static sf::Sprite background;


	static void render_backround(int& x_parralax, sf::RenderWindow& x_window);

	static void render_upground(int& x_parralax, sf::RenderWindow& x_window);

};


class Level1
{
	public:
		static sf::Texture background_texture;

		static sf::Sprite background;

		static sf::Texture door_texture;

		static sf::Sprite door;

		static sf::Texture crate_texture;

		static sf::Sprite crate;


		static sf::Texture platform_texture;

		static sf::Sprite platform;


		static sf::Text tutorial_movement;
		static sf::Text tutorial_camera;
		static sf::Text tutorial_rolling;
		static sf::Text tutorial_jump;
		static sf::Text tutorial_sword;
		static sf::Text tutorial_end;




		static void render_platform(sf::RenderWindow& x_window, int x, int y);

		static void render_backround(int& x_parralax, sf::RenderWindow& x_window);

		static void render_upground(int& x_parralax, sf::RenderWindow& x_window);

		
		

};

class Level2
{
public:
	static void render_backround(int& x_parralax, sf::RenderWindow& x_window);

};



class Level10
{
public:
	static sf::Texture cyber_platform_texture;

	static sf::Sprite cyber_platform;


	static sf::Texture cyber_background_texture;

	static sf::Sprite cyber_background;

	static sf::Texture cyber_background_near_texture;

	static sf::Sprite cyber_background_near;

	static sf::Texture cyber_background_far_texture;

	static sf::Sprite cyber_background_far;



	static void render_background(int& x_parralax, sf::RenderWindow& x_window);

	static void render_platform(sf::RenderWindow& x_window, int x, int y);
};