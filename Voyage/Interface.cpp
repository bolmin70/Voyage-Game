#include "Interface.h"
#include "SFML/Graphics.hpp"
#include "iostream"
#include "Player.h"
#include "Movement.h"
#include "Items.h"
#include "Text.h"
#include "Enemy.h"




sf::Shader UI::blur;


//inventory cycle clock
sf::Clock UI::cycle_clock;

//inventory selector clock
sf::Clock UI::selector_clock;

//bag item selected
int UI::fx1; //future x
int UI::fy1; //future y

int UI::x1;
int UI::x2;
int UI::x3;

int UI::y1;
int UI::y2;
int UI::y3;

int UI::selected_item;


//x; y; position
int UI::bag_x;
int UI::bag_y;

//low health anim
sf::Clock UI::anim_clock;
sf::Clock UI::move_clock;

int UI::anim_x;

//awareness anim
sf::Clock UI::anim_clock2;
sf::Clock UI::move_clock2;

int UI::anim_x2;


int UI::control = 0;

int UI::using_item = 0;

sf::Clock Buttons::anim_clock;
sf::Clock Buttons::move_clock;

int Buttons::anim_x;


//health and stamina bar empty
sf::Texture UI::hud_texture;

sf::Sprite UI::hud;


sf::Texture UI::health_bar_texture;

sf::Sprite UI::health_bar;


sf::Texture UI::stamina_bar_empty_texture;

sf::Sprite UI::stamina_bar_empty;

sf::Texture UI::stamina_bar_texture;

sf::Sprite UI::stamina_bar;



sf::Texture UI::durability_texture;

sf::Texture UI::durability_full_texture;

sf::Texture UI::durability_empty_texture;

sf::Sprite UI::durability;


int UI::hud_show = 1;

//low hp red screen
sf::Texture UI::blood_texture;

sf::Sprite UI::blood;


//low hp animation
sf::Texture UI::low_hp_texture;

sf::Sprite UI::low_hp;


//inventory/selector
sf::Texture UI::inv_texture;

sf::Sprite UI::inv;


//selector left
sf::Texture UI::sel_left_texture;

sf::Sprite  UI::sel_left;

//selector right
sf::Texture  UI::sel_right_texture;

sf::Sprite  UI::sel_right;

//selector down
sf::Texture  UI::sel_down_texture;

sf::Sprite  UI::sel_down;

//selector up
sf::Texture  UI::sel_up_texture;

sf::Sprite  UI::sel_up;



//select right (outline)
sf::Texture UI::outline_right_texture;

sf::Sprite UI::outline_right;

//select left (outline)
sf::Texture UI::outline_left_texture;

sf::Sprite UI::outline_left;

//select down1 (outline)
sf::Texture UI::outline_down1_texture;

sf::Sprite UI::outline_down1;

//select down2 (outline)
sf::Texture UI::outline_down2_texture;

sf::Sprite UI::outline_down2;

//select down3 (outline)
sf::Texture UI::outline_down3_texture;

sf::Sprite UI::outline_down3;

//analog R
sf::Texture UI::analog_texture;

sf::Sprite UI::analog;

//analog L
sf::Texture UI::analog2_texture;

sf::Sprite UI::analog2;


//x
sf::Texture Buttons::x_texture;

sf::Sprite Buttons::x;

//tri
sf::Texture Buttons::tri_texture;

sf::Sprite Buttons::tri;

//quadrat
sf::Texture Buttons::quad_texture;

sf::Sprite Buttons::quad;

//circle
sf::Texture Buttons::circle_texture;

sf::Sprite Buttons::circle;

//r1
sf::Texture Buttons::r1_texture;

sf::Sprite Buttons::r1;

//l1
sf::Texture Buttons::l1_texture;

sf::Sprite Buttons::l1;


//bag inventory selector
 sf::Texture UI::bag_selector_texture;

sf::Sprite UI::bag_selector;


//bag inventory
sf::Texture UI::bag_texture;

sf::Sprite UI::bag;


//awareness marker anim
sf::Texture UI::marker_anim_texture;

sf::Sprite UI::marker_anim;

//awareness marker
sf::Texture UI::marker_texture;

sf::Sprite UI::marker;

//inventory pages
sf::Texture UI::page1_texture;
sf::Texture UI::page2_texture;

sf::Sprite UI::page;


int UI::inventory_show = 0;

bool UI::dpad_input = 0;

//selector direction
int UI::selector_dir = 0;

bool UI::inventory_cycle = 0;

//bag item selected
sf::Texture UI::bag_selected_texture;

sf::Sprite UI::bag_selected;

sf::Texture UI::cyberhud_texture;
sf::Sprite UI::cyberhud;

sf::Texture UI::cyberhud_vig_texture;
sf::Sprite UI::cyberhud_vig;

sf::Clock UI::hud_anim;

int UI::hud_animint = 0;

void UI::UI_Textures()
{
	

	// load only the fragment shader
	if (!blur.loadFromFile("Assets/Shaders/GuassianBlur.frag", sf::Shader::Fragment))
	{
		// error...
	}



	std::cout << std::endl << std::endl << "loading - User Interface" << std::endl << std::endl;
	
	std::cout << "User Interface - Blood Background" << std::endl;
	blood_texture.loadFromFile("Assets/Textures/UI/HUD/wound.png");

	blood.setTexture(blood_texture);
	blood.setScale(1.0f, 1.0f);
	
	std::cout << "User Interface - Health Bar" << std::endl;
	hud_texture.loadFromFile("Assets/Textures/UI/HUD/health_empty.png");

	hud.setTexture(hud_texture);
	hud.setScale(3.0f, 3.0f);



	health_bar_texture.loadFromFile("Assets/Textures/UI/HUD/health_full.png");

	health_bar.setTexture(health_bar_texture);
	health_bar.setScale(5.0f, 3.0f);


	std::cout << "User Interface - Stamina Bar" << std::endl;
	stamina_bar_texture.loadFromFile("Assets/Textures/UI/HUD/stamina_full.png");

	stamina_bar.setTexture(stamina_bar_texture);
	stamina_bar.setScale(3.0f, 3.0f);

	stamina_bar_empty_texture.loadFromFile("Assets/Textures/UI/HUD/stamina_empty.png");

	stamina_bar_empty.setTexture(stamina_bar_empty_texture);
	stamina_bar_empty.setScale(3.0f, 3.0f);

	std::cout << "User Interface - Durability Bar" << std::endl;
	durability_empty_texture.loadFromFile("Assets/Textures/UI/HUD/durability_empty.png");
	durability_texture.loadFromFile("Assets/Textures/UI/HUD/durability.png");
	durability_full_texture.loadFromFile("Assets/Textures/UI/HUD/durability_full.png");

	durability.setTexture(durability_empty_texture);
	durability.setScale(4.0f, 4.0f);

	std::cout << "User Interface - Low Health Animation" << std::endl;
	low_hp_texture.loadFromFile("Assets/Textures/UI/HUD/low_hp.png");

	low_hp.setTexture(low_hp_texture);
	low_hp.setScale(4.0f, 4.0f);

	std::cout << "User Interface - Awareness Marker Animation" << std::endl;
	marker_anim_texture.loadFromFile("Assets/Textures/UI/HUD/aware.png");

	marker_anim.setTexture(marker_anim_texture);
	marker_anim.setScale(10.0f, 10.0f);

	std::cout << "User Interface - Awareness Marker" << std::endl;
	marker_texture.loadFromFile("Assets/Textures/UI/HUD/triggered.png");

	marker.setTexture(marker_texture);
	marker.setScale(10.0f, 10.0f);




	std::cout << "User Interface - Inventory/Selector" << std::endl;
	inv_texture.loadFromFile("Assets/Textures/UI/HUD/selector.png");

	inv.setTexture(inv_texture);
	inv.setScale(10.0f, 10.0f);



	//selector
	sel_left_texture.loadFromFile("Assets/Textures/UI/HUD/selector_left.png");

	sel_left.setTexture(sel_left_texture);
	sel_left.setScale(10.0f, 10.0f);

	sel_right_texture.loadFromFile("Assets/Textures/UI/HUD/selector_right.png");

	sel_right.setTexture(sel_right_texture);
	sel_right.setScale(10.0f, 10.0f);

	sel_down_texture.loadFromFile("Assets/Textures/UI/HUD/selector_down.png");

	sel_down.setTexture(sel_down_texture);
	sel_down.setScale(10.0f, 10.0f);

	sel_up_texture.loadFromFile("Assets/Textures/UI/HUD/selector_up.png");

	sel_up.setTexture(sel_up_texture);
	sel_up.setScale(10.0f, 10.0f);


	//selection outlines
	outline_right_texture.loadFromFile("Assets/Textures/UI/HUD/select_right.png");

	outline_right.setTexture(outline_right_texture);
	outline_right.setScale(10.0f, 10.0f);

	outline_left_texture.loadFromFile("Assets/Textures/UI/HUD/select_left.png");

	outline_left.setTexture(outline_left_texture);
	outline_left.setScale(10.0f, 10.0f);

	outline_down1_texture.loadFromFile("Assets/Textures/UI/HUD/select_down1.png");
	
	outline_down1.setTexture(outline_down1_texture);
	outline_down1.setScale(10.0f, 10.0f);

	outline_down2_texture.loadFromFile("Assets/Textures/UI/HUD/select_down2.png");

	outline_down2.setTexture(outline_down2_texture);
	outline_down2.setScale(10.0f, 10.0f);

	outline_down3_texture.loadFromFile("Assets/Textures/UI/HUD/select_down3.png");

	outline_down3.setTexture(outline_down3_texture);
	outline_down3.setScale(10.0f, 10.0f);

	//analog choice tex
	analog_texture.loadFromFile("Assets/Textures/UI/HUD/selector_alt.png");

	analog.setTexture(analog_texture);
	analog.setScale(4.0f, 4.0f);

	analog2_texture.loadFromFile("Assets/Textures/UI/HUD/l.png");

	analog2.setTexture(analog2_texture);
	analog2.setScale(4.0f, 4.0f);

	//Bag
	bag_texture.loadFromFile("Assets/Textures/UI/HUD/inventory.png");

	bag.setTexture(bag_texture);
	bag.setScale(10.0f, 10.0f);

	//Bag selector
	bag_selector_texture.loadFromFile("Assets/Textures/UI/HUD/inventory_sel.png");

	bag_selector.setTexture(bag_selector_texture);
	bag_selector.setScale(10.0f, 10.0f);

	//Bag selected
	bag_selected_texture.loadFromFile("Assets/Textures/UI/HUD/item_select.png");

	bag_selected.setTexture(bag_selected_texture);
	bag_selected.setScale(10.0f, 10.0f);


	page1_texture.loadFromFile("Assets/Textures/UI/HUD/inv_1.png");
	page2_texture.loadFromFile("Assets/Textures/UI/HUD/inv_2.png");

	page.setTexture(page1_texture);
	page.setScale(8.0f, 8.0f);





	cyberhud_texture.loadFromFile("Assets/Textures/UI/HUD/hud_cyber.png");

	cyberhud.setTexture(cyberhud_texture);
	cyberhud.setScale(4.0f, 4.0f);

	cyberhud_vig_texture.loadFromFile("Assets/Textures/UI/HUD/vig.png");

	cyberhud_vig.setTexture(cyberhud_vig_texture);
	cyberhud_vig.setScale(2.0f, 2.0f);



}



void UI::Use_Item(int x_pocket) {
	if (sf::Joystick::isButtonPressed(0, 2)) {
		if (Player::item_type_table[x_pocket] == 1) {
			Player::item_amount_table[x_pocket]--;
			if (Player::item_amount_table[x_pocket] < 0 || Player::item_amount_table[x_pocket] == 0) {
				Player::item_amount_table[x_pocket] = 0;
			}
			Player::player_current_stamina = Player::player_stamina;
		}
		if (Player::item_type_table[x_pocket] == 2) {
			Player::item_amount_table[x_pocket]--;
			if (Player::item_amount_table[x_pocket] < 0 || Player::item_amount_table[x_pocket] == 0) {
				Player::item_amount_table[x_pocket] = 0;
			}
			//Player::player_current_stamina = Player::player_stamina;
		}
		if (Player::item_type_table[x_pocket] == 3) {
			Player::item_amount_table[x_pocket]--;
			inventory_show = 0;
			if (Player::item_amount_table[x_pocket] < 0 || Player::item_amount_table[x_pocket] == 0) {
				Player::item_amount_table[x_pocket] = 0;

			}
			Player::player_current_health = Player::player_current_health + Player::player_health * 0.5;
			if (Player::player_current_health > Player::player_health) {
				Player::player_current_health = Player::player_health;
			}
		}
	}
}
void UI::Item_Slot(int x_slot, sf::RenderWindow& x_window, int x, int y, int extra_x, int extra_y) {
	if (Player::item_type_table[x_slot] > 0 && Player::item_amount_table[x_slot] > 0) {
		if (Player::item_type_table[x_slot] == 1) {
			Items::Potion_Anim(x_window, x + extra_x, y + extra_y, Items::potion, Items::potion_texture);
		}
		if (Player::item_type_table[x_slot] == 2) {
			Items::Potion_Anim(x_window, x + extra_x, y + extra_y, Items::antipotion, Items::antipotion_texture);
		}
		if (Player::item_type_table[x_slot] == 3) {
			Items::Potion_Anim(x_window, x + extra_x, y + extra_y, Items::health_potion, Items::health_potion_texture);
		}
	}
}




void UI::Inventory(sf::RenderWindow& x_window, int extra_x, int extra_y)
{

	if (inventory_show == 1 && using_item == 0) {
		//Walk::is_running = 0;
		inv.setPosition(-100 + extra_x, -300 + extra_y);
		x_window.draw(inv);
		page.setTexture(page1_texture);
		

		Item_Slot(0, x_window, 210, 360, extra_x, extra_y);
		Item_Slot(1, x_window, 440, 360, extra_x, extra_y);
		Item_Slot(2, x_window, 670, 360, extra_x, extra_y);

		if (Player::item_type_table[0] == 1 || Player::item_type_table[0] == 2 || Player::item_type_table[0] == 3) {
			if (Player::item_amount_table[0] == 0) {
				Items::empty_potion.setPosition(210 + extra_x, 360 + extra_y);
				x_window.draw(Items::empty_potion);
			}
		}
		if (Player::item_type_table[1] == 1 || Player::item_type_table[1] == 2 || Player::item_type_table[1] == 3) {
			if (Player::item_amount_table[1] == 0) {
				Items::empty_potion.setPosition(440 + extra_x, 360 + extra_y);
				x_window.draw(Items::empty_potion);
			}
		}
		if (Player::item_type_table[2] == 1 || Player::item_type_table[2] == 2 || Player::item_type_table[2] == 3) {
			if (Player::item_amount_table[2] == 0) {
				Items::empty_potion.setPosition(670 + extra_x, 360 + extra_y);
				x_window.draw(Items::empty_potion);
			}
		}


		if (dpad_input == 1) {
			if (selector_dir == 1) {
				sel_right.setScale(10.0f, 10.0f);
				sel_right.setPosition(-100 + extra_x, -300 + extra_y);
				x_window.draw(sel_right);

				outline_right.setPosition(-100 + extra_x, -300 + extra_y);
				x_window.draw(outline_right);
			}

			if (selector_dir == 2) {
				sel_left.setPosition(-100 + extra_x, -300 + extra_y);
				x_window.draw(sel_left);

				outline_left.setPosition(-100 + extra_x, -300 + extra_y);
				x_window.draw(outline_left);
			}
			if (selector_dir == 3) {
				sel_up.setPosition(-100 + extra_x, -300 + extra_y);
				x_window.draw(sel_up);


			}
			
			if (selector_dir >= 4 && selector_dir <= 6) {
				sel_down.setPosition(-100 + extra_x, -300 + extra_y);
				x_window.draw(sel_down);
				if (selector_dir == 4) {
					outline_down1.setPosition(-100 + extra_x, -300 + extra_y);
					x_window.draw(outline_down1);
				}
				if (selector_dir == 5) {
					outline_down2.setPosition(-100 + extra_x, -300 + extra_y);
					x_window.draw(outline_down2);
				}
				if (selector_dir == 6) {
					outline_down3.setPosition(-100 + extra_x, -300 + extra_y);
					x_window.draw(outline_down3);
				}
			}

		}



	}
	
	if (inventory_show == 2 && using_item == 0) {

		
		
		//blur.setParameter("offsetFactor", 5.5f, 5.5f);

		bag.setPosition(-50 + extra_x, -250 + extra_y);

		x_window.draw(bag, &blur);
		page.setTexture(page2_texture);


		Item_Slot(0, x_window, 63, -180, extra_x, extra_y);
		Item_Slot(1, x_window, 293, -180, extra_x, extra_y);
		Item_Slot(2, x_window, 523, -180, extra_x, extra_y);
		Item_Slot(3, x_window, 753, -180, extra_x, extra_y);

		Item_Slot(4, x_window, 63, 60, extra_x, extra_y);
		Item_Slot(5, x_window, 293, 60, extra_x, extra_y);
		Item_Slot(6, x_window, 523, 60, extra_x, extra_y);
		Item_Slot(7, x_window, 753, 60, extra_x, extra_y);

		Item_Slot(8, x_window, 63, 300, extra_x, extra_y);
		Item_Slot(9, x_window, 293, 300, extra_x, extra_y);
		Item_Slot(10, x_window, 523, 300, extra_x, extra_y);
		Item_Slot(11, x_window, 753, 300, extra_x, extra_y);

		Item_Slot(12, x_window, 63, 540, extra_x, extra_y);
		Item_Slot(13, x_window, 293, 540, extra_x, extra_y);
		Item_Slot(14, x_window, 523, 540, extra_x, extra_y);
		Item_Slot(15, x_window, 753, 540, extra_x, extra_y);

		bag_selected.setPosition(x1, y1);
		x_window.draw(bag_selected);

		bag_selected.setPosition(x2, y2);
		x_window.draw(bag_selected);

		bag_selected.setPosition(x3, y3);
		x_window.draw(bag_selected);

		bag_selector.setPosition(-50 + extra_x + bag_x * 230, -250 + extra_y + bag_y * 240);
		x_window.draw(bag_selector);



	}
	
	if (inventory_show == 1 || inventory_show == 2) {
		Buttons::Button_Anim(x_window, Buttons::r1, 940, 250);

		page.setPosition(940, 350);
		x_window.draw(page);
	}

}


void UI::Inventory_Cyber(sf::RenderWindow& x_window, int extra_x, int extra_y)
{

	if (inventory_show == 1 && using_item == 0) {
		cyberhud_vig.setPosition(-500, -500);

			cyberhud_vig.setColor(sf::Color(255, 255, 255, hud_animint));
		
		

		x_window.draw(cyberhud_vig);

		cyberhud.setPosition(-350 + extra_x, -250 + extra_y);
		cyberhud.setColor(sf::Color(255, 255, 255, hud_animint));

		x_window.draw(cyberhud);
		//page.setTexture(cyber);

		if (hud_anim.getElapsedTime().asMilliseconds() > 1) { //10 for cinematic 
			if (hud_animint < 255) {
				hud_animint = hud_animint + 5;
			}
			if (hud_animint > 255) {
				hud_animint = 255;
			}

			hud_anim.restart();
		}

	}
	else {
		cyberhud_vig.setPosition(-500, -500);

		cyberhud_vig.setColor(sf::Color(255, 255, 255, hud_animint));



		x_window.draw(cyberhud_vig);

		cyberhud.setPosition(-350 + extra_x, -250 + extra_y);
		cyberhud.setColor(sf::Color(255, 255, 255, hud_animint));

		x_window.draw(cyberhud);


		if (hud_anim.getElapsedTime().asMilliseconds() > 1) { //10 for cinematic 
			if (hud_animint > 0) {
				hud_animint = hud_animint - 15;
			}
			if (hud_animint < 0) {
				hud_animint = 0;
			}

			hud_anim.restart();
		}
	}




}



void UI::Currency(sf::RenderWindow& x_window)
{
	if (hud_show == 0) {

	}
	if (hud_show == 1) {
		Text::Int_Text(x_window, Player::gold, Text::font2, 60, 1350, -250, sf::Color::White);
		Text::Int_Text(x_window, Player::souls, Text::font2, 60, 1350, -210, sf::Color::Magenta);


	}
	if (hud_show == 2) {
		Text::Int_Text(x_window, Player::gold, Text::font2, 60, 150, 100, sf::Color::White);
		Text::Int_Text(x_window, Player::souls, Text::font2, 60, 150, 140, sf::Color::Magenta);



	}

}

void UI::FPS(sf::RenderWindow& x_window)
{
	if (hud_show == 0) {

	}
	if (hud_show == 1 || hud_show == 2) {
		Text::Fps_Counter();
		Text::Int_Text(x_window, Text::fps, Text::font2, 60, -460, -290, sf::Color::White);

	}

}

void UI::Health_Bar(sf::RenderWindow& x_window)
{
	if (hud_show == 0) {

	}
	if (hud_show == 1) {


		

		hud.setScale(5.0f, 3.0f);
		hud.setPosition(-400, -200);
		x_window.draw(hud);

		health_bar.setTextureRect(sf::IntRect(0, 0, Player::player_current_health / 10, 80)); //55
		health_bar.setPosition(-400, -200); // -450 - 220
		x_window.draw(health_bar);

		

		hud.setScale(3.0f, 3.0f);
		hud.setPosition(-400, -165);
		x_window.draw(hud);

		stamina_bar_empty.setPosition(-400, -165);
		x_window.draw(stamina_bar_empty);

		stamina_bar.setTextureRect(sf::IntRect(0, 0, Player::player_current_stamina / 10, 80));
		stamina_bar.setPosition(-400, -165);
		x_window.draw(stamina_bar);
		if (Player::player_current_health < Player::player_health * 0.3) {
			blood.setPosition(-480, -270);
			//x_window.draw(blood);
		}
	}
	if (hud_show == 2) {




		hud.setScale(5.0f, 3.0f);
		hud.setPosition(150, 150);
		x_window.draw(hud);

		health_bar.setTextureRect(sf::IntRect(0, 0, Player::player_health / 10, 80)); //55
		health_bar.setPosition(150, 150);
		x_window.draw(health_bar);



		hud.setScale(3.0f, 3.0f);
		hud.setPosition(150, 185);
		x_window.draw(hud);

		stamina_bar_empty.setPosition(150, 185);
		x_window.draw(stamina_bar_empty);

		stamina_bar.setTextureRect(sf::IntRect(0, 0, Player::player_stamina / 10, 80));
		stamina_bar.setPosition(150, 185);
		x_window.draw(stamina_bar);

	}
}

void UI::Durability_Bar(sf::RenderWindow& x_window)
{
	
	if (hud_show == 0) {

	}
	if (hud_show == 1) {
		if (Player::durability_table[0] >= 1) {
			if (Player::durability_table[0] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[0] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[0] == 3) {
				durability.setTexture(durability_full_texture);
			}


			durability.setPosition(-390, -130);
			x_window.draw(durability);
		}
		if (Player::durability_table[1] >= 1) {
			if (Player::durability_table[1] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[1] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[1] == 3) {
				durability.setTexture(durability_full_texture);
			}


			durability.setPosition(-360, -130);
			x_window.draw(durability);
		}
		if (Player::durability_table[2] >= 1) {
			if (Player::durability_table[2] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[2] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[2] == 3) {
				durability.setTexture(durability_full_texture);
			}


			durability.setPosition(-330, -130);
			x_window.draw(durability);
		}
		if (Player::durability_table[3] >= 1) {
			if (Player::durability_table[3] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[3] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[3] == 3) {
				durability.setTexture(durability_full_texture);
			}
		}
		if (Player::durability_table[4] >= 1) {
			if (Player::durability_table[4] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[4] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[4] == 3) {
				durability.setTexture(durability_full_texture);
			}
		}
	}
	if (hud_show == 2) {
		if (Player::durability_table[0] >= 1) {
			if (Player::durability_table[0] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[0] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[0] == 3) {
				durability.setTexture(durability_full_texture);
			}


			durability.setPosition(160, 220);
			x_window.draw(durability);
		}
		if (Player::durability_table[1] >= 1) {
			if (Player::durability_table[1] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[1] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[1] == 3) {
				durability.setTexture(durability_full_texture);
			}


			durability.setPosition(190, 220);
			x_window.draw(durability);
		}
		if (Player::durability_table[2] >= 1) {
			if (Player::durability_table[2] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[2] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[2] == 3) {
				durability.setTexture(durability_full_texture);
			}


			durability.setPosition(220, 220);
			x_window.draw(durability);
		}
		if (Player::durability_table[3] >= 1) {
			if (Player::durability_table[3] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[3] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[3] == 3) {
				durability.setTexture(durability_full_texture);
			}


			durability.setPosition(250, 220);
			x_window.draw(durability);
		}
		if (Player::durability_table[4] >= 1) {
			if (Player::durability_table[4] == 1) {
				durability.setTexture(durability_empty_texture);
			}
			if (Player::durability_table[4] == 2) {
				durability.setTexture(durability_texture);
			}
			if (Player::durability_table[4] == 3) {
				durability.setTexture(durability_full_texture);
			}


			durability.setPosition(280, 220);
			x_window.draw(durability);
		}
	}
	
}

void UI::Low_Health_Anim(sf::RenderWindow& x_window)
{
	if (Player::player_current_health < Player::player_health * 0.3) {
		if (anim_clock.getElapsedTime().asMilliseconds() > 50) {
			if (anim_x < 84) {
				anim_x += 12;
			}
			else {
				anim_x = 0;
			}

			anim_clock.restart();
		}


		low_hp.setTextureRect(sf::IntRect(anim_x, 0, 12, 12));
		low_hp.setPosition(-100, -200);
		x_window.draw(low_hp);
	}
}

void UI::Aware_Anim(sf::RenderWindow& x_window, int alert, int x, int y)
{
	if (alert == 0) {
		if (anim_clock2.getElapsedTime().asMilliseconds() > 50) {
			if (anim_x2 < 6) {
				anim_x2 += 2;
			}
			else {
				anim_x2 = 0;
			}

			anim_clock2.restart();
		}


		marker_anim.setTextureRect(sf::IntRect(anim_x2, 0, 2, 9));
		marker_anim.setPosition(x, y);
		x_window.draw(marker_anim);
	}
	else {
		marker.setPosition(x - 50, y);
		x_window.draw(marker);
	}
}

void UI::UI_Events(sf::Event& x_event)
{
		if (x_event.type == sf::Event::KeyPressed && x_event.key.code == sf::Keyboard::R) {
			inventory_show = 1;
	
		}
		else {
			inventory_show = 0;
		}

		if (sf::Joystick::isConnected(0) == 1)	{
			if (sf::Joystick::isButtonPressed(0, 4)) {
				if (cycle_clock.getElapsedTime().asMilliseconds() > 150) {
					if (sf::Joystick::isButtonPressed(0, 5)) {
						inventory_cycle = !inventory_cycle;
						cycle_clock.restart();
					}
				}
				if (inventory_cycle == 0) {
					inventory_show = 1;
				}
				else {
					inventory_show = 2;
				}

				

				dpad_input = 0;

				if (inventory_show == 1) {
				if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > 50) {
						dpad_input = 1;
						selector_dir = 1;
					}
				else {
						//dpad_input = 0;
					}
				if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < -50) {
					dpad_input = 1;
					selector_dir = 2;
				}
				else {
					//dpad_input = 0;
				}
				if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) > 50) {
					dpad_input = 1;
					selector_dir = 3;
				}
				else {
					//dpad_input = 0;
				}

				if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < -50 && sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < 50 && sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > -50) {
					dpad_input = 1;
					selector_dir = 5;
					Use_Item(1);
				}
				else {
					//dpad_input = 0;
				}


				if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > 50 && sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < -50) {
					selector_dir = 6;
					Use_Item(2);
				}
				if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < -50 && sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < -50) {
					selector_dir = 4;
					Use_Item(0);
				}
			}

				if (inventory_show == 2) {

					//blur.setParameter("myvar", 5.f);

					if (selector_clock.getElapsedTime().asMilliseconds() > 80) {
						if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > 50) {
							if (bag_x < 3) {
								bag_x++;
							}
						}

						if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < -50) {
							if (bag_x > 0) {
								bag_x--;
							}
						}

						if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) > 50) {
							if (bag_y > 0) {
								bag_y--;
							}
						}


						if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < -50) {

							if (bag_y < 3) {
								bag_y++;
							}
						}
						selector_clock.restart();
					}
					
					if (sf::Joystick::isButtonPressed(0, 1)) {
						if (selected_item == 0) {
							fx1 = -50 + bag_x * 230;
							fy1 = -50 + bag_x * 230;

							//if 
							x1 = -50 + bag_x * 230;
							y1 = -250 + bag_y * 240;

						}
						if (selected_item == 1) {
							x2 = -50 + bag_x * 230;
							y2 = -250 + bag_y * 240;
						}
						if (selected_item == 2) {
							x3 = -50 + bag_x * 230;
							y3 = -250 + bag_y * 240;
						}
						


						if (selected_item < 2) {
							selected_item++;
						}
						else {
							selected_item = 0;
						}
					}


					
				}
			}
			else {
				inventory_show = 0;
			}

		}

}


void Buttons::Button_Textures() {
	//circle pad
	circle_texture.loadFromFile("Assets/Textures/UI/HUD/cir.png");

	circle.setTexture(circle_texture);
	circle.setScale(5.0f, 5.0f);

	//quadrat pad
	quad_texture.loadFromFile("Assets/Textures/UI/HUD/quad.png");

	quad.setTexture(quad_texture);
	quad.setScale(5.0f, 5.0f);

	//x pad
	x_texture.loadFromFile("Assets/Textures/UI/HUD/x.png");

	x.setTexture(x_texture);
	x.setScale(5.0f, 5.0f);

	//triangle pad
	tri_texture.loadFromFile("Assets/Textures/UI/HUD/tri.png");

	tri.setTexture(x_texture);
	tri.setScale(5.0f, 5.0f);

	//l1 pad
	l1_texture.loadFromFile("Assets/Textures/UI/HUD/l1.png");

	l1.setTexture(l1_texture);
	l1.setScale(10.0f, 10.0f);

	//r1 pad
	r1_texture.loadFromFile("Assets/Textures/UI/HUD/r1.png");

	r1.setTexture(r1_texture);
	r1.setScale (10.0f, 10.0f);

}

void Buttons::Button_Anim(sf::RenderWindow& x_window, sf::Sprite& sprite, int x, int y)
{
		if (anim_clock.getElapsedTime().asMilliseconds() > 700) {
			if (anim_x < 12) {
				anim_x += 12;
			}
			else {
				anim_x = 0;
			}

			anim_clock.restart();
		}

		r1.setScale(10.0f, 10.0f);
		sprite.setTextureRect(sf::IntRect(anim_x, 0, 12, 9));
		sprite.setPosition(x, y);
		x_window.draw(sprite);
	
}

