// Voyage Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Main / Test Module

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Movement.h"
#include "Text.h"
#include "Combat.h"
#include "Level.h"
#include "Textures.h"
#include "Menus.h"
#include "Interface.h"
#include "Player.h"
#include "Camera.h"
#include "Collision.h"
#include "Enemy.h"
#include "Items.h"
#include "Shaders.h"

using namespace std;

int parralax = 0;
int zero = 0;



/*
Voyage Engine

	Character Movement
	-Walk/Run
	-Roll
	-Jump
	TODO Wall Cling
	-Attack
	-TODO Block

	Physics
	-Character physics
	TODO Mob physics
	-Level collisions
	
	Level
	-Floor creator
	-Exit creator
	-Enemy placement
	TODO Stealth
	TODO defining level area

	Enemy AI
	-Attack
	-Turn
	-Alert
	TODO Health bar
	TODO Walk

	Engine
	-Seperate texture loading
	-Seperate text loading
	TODO Save/Load

	Interface
	-Icon animation
	-Quick inventory
	-TODO inventory
	-Status Bars

	Camera
	-tracking
	-zoom
	-external movement
	TODO blocking at the end and the start of the level

	Menus
	TODO Main menu
	TODO Menu ingame



*/



int main()
{
	
	static sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Voyage Engine");
	sf::RenderTexture window_texture;
	window_texture.create(1920, 1080);

	window.setFramerateLimit(60); //framerate

	
	//blur4.setParameter("source", sf::Shader::CurrentTexture);
	//blur4.setParameter("offsetFactor", 2.f, 2.f);


	sf::Image image; //icon
	image.loadFromFile("Assets/Textures/Engine/icon.png"); //icon
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr()); //icon

	


	srand(time(NULL));

	window.clear();
	window.display();

	Level1::render_backround(parralax, window);

	

	Movement_SFX::Load_SFX();
	Combat_SFX::Load_SFX();
	
	Textures::Load_Textures();
	Camera::Load_Cameras();
	Shaders::Load_Shaders();


	Player::item_type_table[0] = 1;
	Player::item_type_table[1] = 2;
	Player::item_type_table[2] = 3;
	Player::item_type_table[3] = 1;
	Player::item_type_table[4] = 2;
	Player::item_type_table[5] = 3;
	Player::item_type_table[6] = 2;
	Player::item_type_table[7] = 3;
	Player::item_type_table[8] = 1;
	Player::item_type_table[9] = 2;
	Player::item_type_table[10] = 3;
	Player::item_type_table[11] = 1;
	Player::item_type_table[12] = 2;
	Player::item_type_table[13] = 3;
	Player::item_type_table[14] = 2;
	Player::item_type_table[15] = 3;

	Player::item_amount_table[0] = 1;
	Player::item_amount_table[1] = 1;
	Player::item_amount_table[2] = 1;
	Player::item_amount_table[3] = 1;
	Player::item_amount_table[4] = 1;
	Player::item_amount_table[5] = 1;
	Player::item_amount_table[6] = 1;
	Player::item_amount_table[7] = 1;
	Player::item_amount_table[8] = 1;
	Player::item_amount_table[9] = 1;
	Player::item_amount_table[10] = 1;
	Player::item_amount_table[11] = 1;
	Player::item_amount_table[12] = 1;
	Player::item_amount_table[13] = 1;
	Player::item_amount_table[14] = 1;
	Player::item_amount_table[15] = 1;

	Effects::effect_start = 1;

	int tutorial_phase = 0;




	//matma

	//int a;
	//int a2;
	//int b;
	//int b2;
	//int c;
	//int c2;


	//cin >> a >> a2 >> b >> b2 >> c >> c2;
	//a = a / a2;
	//b = b / b2;
	//c = c / c2;


	//int wynik = b * b;
	//wynik = wynik - 4 * a * c;
	//cout << endl << endl << wynik << endl;


	//matma



	//goto Base;
	//Enemy::Enemy_Level1();
	//goto Tutorial;





	//Enemy::Enemy_Level2();
	//goto Dungeon;


	//int h = true + true + true;
	//cout << h << endl;
	Enemy::Enemy_Level1();
	//goto Tutorial;
	
	sf::Texture huj;
	
	sf::Sprite huj2;
	huj2.setTexture(huj);
	//Levels::level_code = 0;
	goto Tutorial;


Menu:for (;; ) {
	window.clear();

	Level1::render_backround(parralax, window);

	Menus::Menu_Main(window);


	sf::Event menu;
	while (window.pollEvent(menu)) {
		if (menu.type == sf::Event::Closed) {
			window.close();
			return 0;
		}

	}
	window.display();
}

Tutorial:for (;; ) {
	window.clear();
	//cout << Walk::player_position << endl;



	Camera::Camera_Operator(window);
	window.setView(Camera::Main_Camera);



	Levels::x_near_bound = -50;
	Levels::x_far_bound = 7200;

	Player::Regeneration();

	Physics::on_platform = false;

	Levels::level_code = 1;



	if (Levels::level_code == 1) {

		Level2::render_backround(parralax, window);
		

		Enemy::Enemy_Skeleton(window, 0, 0, Enemy::Skeleton1.anim_x, Enemy::Skeleton1.enemy_position_x, Enemy::Skeleton1.enemy_position_y, Enemy::Skeleton1.enemy_dead, Enemy::Skeleton1.enemy_hp,
			Enemy::Skeleton1.enemy_damage, Enemy::Skeleton1.enemy_attack_begin, Enemy::Skeleton1.enemy_right, Enemy::Skeleton1.enemy_alerted, Enemy::Skeleton1.enemy_hit, Enemy::attack_clock, Enemy::anim_clock, Enemy::Skeleton1.enemy_exists);

	}





	Walk::Run(parralax, window);

	Equipment::Equip(parralax, window);

	Rolling::Roll(parralax, window);

	Jumping::Jump(parralax, window);


	Hit::Hitt(parralax, window);


	Combat::Attack(parralax, window);





	//Sitting::Sit(parralax, window);

	Physics::Gravity(parralax, window);






	window.setView(Camera::UI_Camera);
	//UI::Durability_Bar(window);

	UI::Health_Bar(window);

	UI::Low_Health_Anim(window);

	//UI::Currency(window);

	//UI::Inventory(window, 0, 0);

	UI::FPS(window);

	Camera::Fade_In(window);

	if (Camera::goto_place == 1) {
		Camera::fade = 0;
		Camera::goto_place = 0;
		Enemy::Enemy_Level2();
		Walk::player_position = 150;
		Walk::player_position_y = 300;
		goto Dungeon;
	}

sf::Event global;
while (window.pollEvent(global)) {
	if (global.type == sf::Event::Closed) {
		window.close();
		return 0;
	}

	if (Player::player_current_health > 0) {
		Walk::Run_Events(global);

		if (UI::inventory_show == 0) {

			Equipment::Equip_Events(global);

			Rolling::Roll_Events(global);

			Combat::Attack_Events(global);

			Jumping::Jump_Events(global);

			//Sitting::Sit_Events(global);

		}

		UI::UI_Events(global);
	}
}

window.display();


}

Dungeon:for (;; ) {
		window.clear();
		//cout << Walk::player_position_y << endl;

		//cout << UI::bag_x << endl << UI::bag_y << endl;

		Camera::Camera_Operator(window);
		window.setView(Camera::Main_Camera);


		

		

		Player::Regeneration();

		Physics::on_platform = false;



		Level1::render_backround(parralax, window);

		


		Enemy::Enemy_Skeleton(window, 0, 0, Enemy::Skeleton1.anim_x, Enemy::Skeleton1.enemy_position_x, Enemy::Skeleton1.enemy_position_y, Enemy::Skeleton1.enemy_dead, Enemy::Skeleton1.enemy_hp,
			Enemy::Skeleton1.enemy_damage, Enemy::Skeleton1.enemy_attack_begin, Enemy::Skeleton1.enemy_right, Enemy::Skeleton1.enemy_alerted, Enemy::Skeleton1.enemy_hit, Enemy::attack_clock, Enemy::anim_clock, Enemy::Skeleton1.enemy_exists);

		Enemy::Enemy_Skeleton(window, 0, 0, Enemy::Skeleton2.anim_x, Enemy::Skeleton2.enemy_position_x, Enemy::Skeleton2.enemy_position_y, Enemy::Skeleton2.enemy_dead, Enemy::Skeleton2.enemy_hp,
			Enemy::Skeleton2.enemy_damage, Enemy::Skeleton2.enemy_attack_begin, Enemy::Skeleton2.enemy_right, Enemy::Skeleton2.enemy_alerted, Enemy::Skeleton2.enemy_hit, Enemy::attack_clock2, Enemy::anim_clock2, Enemy::Skeleton2.enemy_exists);

		Enemy::Enemy_Skeleton(window, 0, 0, Enemy::Skeleton3.anim_x, Enemy::Skeleton3.enemy_position_x, Enemy::Skeleton3.enemy_position_y, Enemy::Skeleton3.enemy_dead, Enemy::Skeleton3.enemy_hp,
			Enemy::Skeleton3.enemy_damage, Enemy::Skeleton3.enemy_attack_begin, Enemy::Skeleton3.enemy_right, Enemy::Skeleton3.enemy_alerted, Enemy::Skeleton3.enemy_hit, Enemy::attack_clock3, Enemy::anim_clock3, Enemy::Skeleton3.enemy_exists);

		Enemy::Enemy_Skeleton(window, 0, 0, Enemy::Skeleton4.anim_x, Enemy::Skeleton4.enemy_position_x, Enemy::Skeleton4.enemy_position_y, Enemy::Skeleton4.enemy_dead, Enemy::Skeleton4.enemy_hp,
			Enemy::Skeleton4.enemy_damage, Enemy::Skeleton4.enemy_attack_begin, Enemy::Skeleton4.enemy_right, Enemy::Skeleton4.enemy_alerted, Enemy::Skeleton4.enemy_hit, Enemy::attack_clock4, Enemy::anim_clock4, Enemy::Skeleton4.enemy_exists);



		

		Walk::Run(parralax, window);
		
		Equipment::Equip(parralax, window);

		Rolling::Roll(parralax, window);

		Jumping::Jump(parralax, window);


		Hit::Hitt(parralax, window);


		Combat::Attack(parralax, window);





		Sitting::Sit(parralax, window);

		Physics::Gravity(parralax, window);



		
		//Effects::Effect_Manager(window, Effects::poison, Walk::player_position + 115, Walk::player_position_y + 130, 80, 16, 32, 112);

		//Effects::Effect_Manager(window, Effects::soul, Walk::player_position + 115, Walk::player_position_y + 130, 50, 16, 16, 128);
	
		//Effects::Effect_Manager(window, Effects::heal, Walk::player_position + 110, Walk::player_position_y - 80, 50, 22, 80, 154);

	


		//Level1::render_upground(parralax, window);


		window.setView(Camera::UI_Camera);
		//UI::Durability_Bar(window);
		
		UI::Health_Bar(window);

		UI::Low_Health_Anim(window);
		
		//UI::Currency(window);

		UI::Inventory(window, 0, 0);

		UI::FPS(window);

		Camera::Fade_In(window);

		sf::Event global;
		
		while (window.pollEvent(global)) {
			if (global.type == sf::Event::Closed) {
				window.close();
				return 0;
			}

			if (Player::player_current_health > 0) {
				Walk::Run_Events(global);

				if (UI::inventory_show == 0) {

					Equipment::Equip_Events(global);

					Rolling::Roll_Events(global);

					Combat::Attack_Events(global);

					Jumping::Jump_Events(global);

					Sitting::Sit_Events(global);

				}

				UI::UI_Events(global);
			}
		}

		window.display();

	}

Base:for (;; ) {
	window.clear();

	Camera::Camera_Operator(window);
	window.setView(Camera::Base_Camera);


	Level0::render_backround(parralax, window);

	Walk::Run(parralax, window);

	//Equipment::Equip(parralax, window);

	Rolling::Roll(parralax, window);

	Jumping::Jump(parralax, window);


	//Hit::Hitt(parralax, window);


	//Combat::Attack(parralax, window);





	Sitting::Sit(parralax, window);


	Physics::Gravity(parralax, window);



	window.setView(Camera::UI_Camera);
	//UI::Durability_Bar(window);

	UI::Health_Bar(window);

	UI::Low_Health_Anim(window);

	//UI::Currency(window);

	//UI::Inventory(window, 0, 0);

	UI::FPS(window);

	sf::Event global;

	while (window.pollEvent(global)) {
		if (global.type == sf::Event::Closed) {
			window.close();
			return 0;
		}


		Walk::Run_Events(global);

		if (UI::inventory_show == 0) {

			//Equipment::Equip_Events(global);



			Rolling::Roll_Events(global);

			//Combat::Attack_Events(global);

			Jumping::Jump_Events(global);

			Sitting::Sit_Events(global);

		}

		UI::UI_Events(global);
	}



	window.display();
	}





Cyber:for (;; ) {


	window.clear();
	//cout << Walk::player_position_y << endl;

	//cout << UI::bag_x << endl << UI::bag_y << endl;
	Levels::level_code = 10;

	Levels::Level_Boundries();

	Camera::Camera_Operator(window);
	window.setView(Camera::Main_Camera);






	Player::Regeneration();

	Physics::on_platform = false;

	

	//Level10::render_background(parralax, window);

	Level2::render_backround(parralax, window);





	Walk::Run(parralax, window);

	Equipment::Equip(parralax, window);

	Rolling::Roll(parralax, window);

	Jumping::Jump(parralax, window);


	Hit::Hitt(parralax, window);


	Combat::Attack(parralax, window);





	Sitting::Sit(parralax, window);

	Physics::Gravity(parralax, window);




	//Effects::Effect_Manager(window, Effects::poison, Walk::player_position + 115, Walk::player_position_y + 130, 80, 16, 32, 112);

	//Effects::Effect_Manager(window, Effects::soul, Walk::player_position + 115, Walk::player_position_y + 130, 50, 16, 16, 128);

	//Effects::Effect_Manager(window, Effects::heal, Walk::player_position + 110, Walk::player_position_y - 80, 50, 22, 80, 154);




	//Level1::render_upground(parralax, window);






	//blur4.setParameter("my")

	


	window.setView(Camera::UI_Camera);
	//UI::Durability_Bar(window);

	//huj.create(1920, 1080);
	//huj.update(window);
	huj2.setTexture(huj);
	huj2.setPosition(200, 200);
	window.draw(huj2, &Shaders::blur);

	UI::Health_Bar(window);

	UI::Low_Health_Anim(window);

	//UI::Currency(window);

	//window_texture.clear();


	UI::Inventory_Cyber(window, 0, 0);

	//window_texture.display();

	//sf::Sprite sprite(window_texture.getTexture());
	//window.draw(sprite);

	UI::FPS(window);

	
	//window.draw(hudd, &blur4);
	//hudd.setPosition(300, 500);



	Camera::Fade_In(window);


	//window.draw(UI::blood, &Shaders::blur);

	sf::Event global;

while (window.pollEvent(global)) {
	if (global.type == sf::Event::Closed) {
		window.close();
		return 0;
	}

	if (Player::player_current_health > 0) {
		Walk::Run_Events(global);

		if (UI::inventory_show == 0) {

			Equipment::Equip_Events(global);

			Rolling::Roll_Events(global);

			Combat::Attack_Events(global);

			Jumping::Jump_Events(global);

			Sitting::Sit_Events(global);

		}

		UI::UI_Events(global);
	}
}

window.display();



}





}


