#include "Menus.h"
#include "SFML/Graphics.hpp"

sf::Texture Menus::title_texture;
sf::Sprite Menus::title;

sf::Texture Menus::ve_texture; //voyage engine intro
sf::Sprite Menus::ve; //voyage engine intro


void Menus::Menu_Textures()
{
	title_texture.loadFromFile("Assets/Textures/UI/Menus/title.png");
	title.setTexture(title_texture);
	title.setScale(2.0f, 2.0f);

	ve_texture.loadFromFile("Assets/Textures/Engine/intro.png");
	ve.setTexture(ve_texture);
	ve.setScale(10.0f, 10.0f);
}

void Menus::Menu_Main(sf::RenderWindow& x_window)
{
	title.setPosition(300, 300);
	x_window.draw(title);

}
