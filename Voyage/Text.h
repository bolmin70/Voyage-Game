#pragma once
#include "sfml/graphics.hpp"
#include "sstream"

using namespace std;

class Text
{
public:
	static sf::Font mfont;
	static sf::Font font2;
	static sf::Font cfont; //CyberpunkFONT

	static stringstream blankss;

	static string Integer;
	static sf::Text int_text;


	static string playerInput;
	static sf::Text playerText;


	static sf::Clock fps_clock;
	static int fps;
	static int fps_hide;

	static void Fps_Counter();

	static void Int_Text(sf::RenderWindow& x_window, int x, sf::Font x_font, int x_size, int x_cord, int y_cord, sf::Color x_color);

	static void Enter_Text(sf::RenderWindow& x_window);
	static void Enter_Text_Event(sf::Event& x_event);

	static void Texts();

};