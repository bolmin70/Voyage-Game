#pragma once
#include "SFML/Graphics.hpp"
class Menus
{
public:
	static sf::Texture title_texture;
	static sf::Sprite title;

	static sf::Texture ve_texture; //voyage engine intro
	static sf::Sprite ve; //voyage engine intro

	static void Menu_Textures();

	static void Menu_Main(sf::RenderWindow& x_window);
};

