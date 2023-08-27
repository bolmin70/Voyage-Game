#include "sfml/graphics.hpp"
#include "Text.h"
#include "sstream"
#include "iostream"

using namespace std;

string Text::playerInput;
sf::Text Text::playerText;

sf::Font Text::mfont;
sf::Font Text::font2;
sf::Font Text::cfont;

string Text::Integer;
sf::Text Text::int_text;

stringstream Text::blankss;

sf::Clock Text::fps_clock;
int Text::fps;
int Text::fps_hide;

void Text::Texts() {

	mfont.loadFromFile("Assets/Fonts/Pixeled English Font.TTF");
	font2.loadFromFile("Assets/Fonts/InjuryPro.ttf");
	cfont.loadFromFile("Assets/Fonts/cyberninja.ttf");


	playerText.setCharacterSize(20);
	playerText.setFont(mfont);
	playerText.setString("sfg");




}

void Text::Int_Text(sf::RenderWindow& x_window, int x, sf::Font x_font, int x_size, int x_cord, int y_cord, sf::Color x_color) {
	blankss.str("");
	blankss << x;
	Integer = blankss.str();

	int_text.setString(Integer);
	int_text.setFont(x_font);
	int_text.setFillColor(x_color);
	int_text.setCharacterSize(x_size);

	int_text.setPosition(x_cord, y_cord);
	x_window.draw(int_text);


}

void Text::Fps_Counter() {
	
	fps_hide++;
	
	if (fps_clock.getElapsedTime().asMilliseconds() > 1000) {
		fps = fps_hide;
		fps_hide = 0;
		fps_clock.restart();
	}

}

void Text::Enter_Text(sf::RenderWindow& x_window) {
	playerText.setString(playerInput);
	playerText.setPosition(900, 200);
	x_window.draw(playerText);
}

void Text::Enter_Text_Event(sf::Event& x_event) {
	

	if (sf::Event::TextEntered) {
		if (x_event.text.unicode == '\b') {
			playerInput.erase(playerInput.size() - 1, 1);
			playerText.setString(playerInput);
		}
		else {
			if (playerInput.size() <= 8) {
				playerInput += static_cast<char>(x_event.text.unicode);
				playerText.setString(playerInput);
			}
		}
	}

}