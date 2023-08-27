#pragma once
#include "SFML/Graphics.hpp"

class UI
{

public:
	static sf::Shader blur;

	//static uniform float myvar;



	//inventory cycle clock
	static sf::Clock cycle_clock;

	//inventory selector clock
	static sf::Clock selector_clock;

	//x; y; position
	static int bag_x;
	static int bag_y; 

	//bag item selected
	static int fx1; //future x
	static int fy1; //future y

	static int x1;
	static int x2;
	static int x3;

	static int y1;
	static int y2;
	static int y3;

	static int selected_item;

	//low hp animation
	static sf::Clock anim_clock;
	static sf::Clock move_clock;

	static int anim_x;

	//low hp animation
	static sf::Clock anim_clock2;
	static sf::Clock move_clock2;

	static int anim_x2;

	
	//control scheme (problem with DS4)
	static int control;

	//type of hud shown (normal/mgs4/none)
	static int hud_show;

	static int using_item;

	//bars
	static sf::Texture hud_texture;

	static sf::Sprite hud;


	
	static sf::Texture health_bar_texture;

	static sf::Sprite health_bar;


	static sf::Texture stamina_bar_empty_texture;

	static sf::Sprite stamina_bar_empty;

	static sf::Texture stamina_bar_texture;

	static sf::Sprite stamina_bar;


	static sf::Texture durability_texture;

	static sf::Texture durability_full_texture;

	static sf::Texture durability_empty_texture;

	static sf::Sprite durability;


	//red background (mgsV critical injury screen imitation)
	static sf::Texture blood_texture;

	static sf::Sprite blood;


	



	static sf::Texture low_hp_texture;

	static sf::Sprite low_hp;


	static sf::Texture inv_texture;

	static sf::Sprite inv;


	//selector left
	static sf::Texture sel_left_texture;

	static sf::Sprite sel_left;

	//selector right
	static sf::Texture sel_right_texture;

	static sf::Sprite sel_right;

	//selector down
	static sf::Texture sel_down_texture;

	static sf::Sprite sel_down;

	//selector up
	static sf::Texture sel_up_texture;

	static sf::Sprite sel_up;

	//select right (outline)
	static sf::Texture outline_right_texture;

	static sf::Sprite outline_right;

	//select left (outline)
	static sf::Texture outline_left_texture;

	static sf::Sprite outline_left;


	//select down1 (outline)
	static sf::Texture outline_down1_texture;

	static sf::Sprite outline_down1;


	//select down2 (outline)
	static sf::Texture outline_down2_texture;

	static sf::Sprite outline_down2;

	//select down3 (outline)
	static sf::Texture outline_down3_texture;

	static sf::Sprite outline_down3;

	//analog
	static sf::Texture analog_texture;

	static sf::Sprite analog;

	//analog
	static sf::Texture analog2_texture;

	static sf::Sprite analog2;



	//bag inventory
	static sf::Texture bag_texture;

	static sf::Sprite bag;

	//bag inventory selector
	static sf::Texture bag_selector_texture;

	static sf::Sprite bag_selector;

	//bag item selected
	static sf::Texture bag_selected_texture;

	static sf::Sprite bag_selected;


	//awareness marker anim
	static sf::Texture marker_anim_texture;

	static sf::Sprite marker_anim;

	//awareness marker
	static sf::Texture marker_texture;

	static sf::Sprite marker;

	//inventory pages
	static sf::Texture page1_texture;
	static sf::Texture page2_texture;

	static sf::Sprite page;


	static sf::Texture cyberhud_texture;
	static sf::Sprite cyberhud;

	static sf::Texture cyberhud_vig_texture;
	static sf::Sprite cyberhud_vig;

	static sf::Clock hud_anim;

	static int hud_animint;

	//selector direction
	static int selector_dir;


	//dpad input
	static bool dpad_input;

	static int inventory_show;

	static bool inventory_cycle;



	static void UI_Textures();

	static void Use_Item(int x_pocket);

	static void Item_Slot(int x_slot, sf::RenderWindow& x_window, int x, int y, int extra_x, int extra_y);


	static void Inventory(sf::RenderWindow& x_window, int extra_x, int extra_y);

	static void Inventory_Cyber(sf::RenderWindow& x_window, int extra_x, int extra_y);

	static void Currency(sf::RenderWindow& x_window);

	static void FPS(sf::RenderWindow& x_window);



	static void Health_Bar(sf::RenderWindow& x_window);

	static void Durability_Bar(sf::RenderWindow& x_window);

	static void Low_Health_Anim(sf::RenderWindow& x_window);

	static void Aware_Anim(sf::RenderWindow& x_window, int alert, int x, int y);

	static void UI_Events(sf::Event& x_event);

	




};

class Buttons {
public:
	static sf::Clock anim_clock;
	static sf::Clock move_clock;

	static int anim_x;

	//x
	static sf::Texture x_texture;

	static sf::Sprite x;

	//triangle
	static sf::Texture tri_texture;

	static sf::Sprite tri;

	//quadrat
	static sf::Texture quad_texture;

	static sf::Sprite quad;

	//circle
	static sf::Texture circle_texture;

	static sf::Sprite circle;

	//l1
	static sf::Texture l1_texture;

	static sf::Sprite l1;

	//r1
	static sf::Texture r1_texture;

	static sf::Sprite r1;

	static void Button_Textures();

	static void Button_Anim(sf::RenderWindow& x_window, sf::Sprite& sprite, int x, int y);

};
