#include "Level.h"
#include "Movement.h"
#include "iostream"
#include "Text.h"
#include "Collision.h"
#include "Combat.h"
#include "Interface.h"

sf::Texture Level1::background_texture;

sf::Sprite Level1::background;


sf::Texture Level1::door_texture;

sf::Sprite Level1::door;

sf::Texture Level1::crate_texture;

sf::Sprite Level1::crate;


sf::Texture Level1::platform_texture;

sf::Sprite Level1::platform;



sf::Texture Level10::cyber_platform_texture;

sf::Sprite Level10::cyber_platform;



sf::Text Level1::tutorial_movement;
sf::Text Level1::tutorial_camera;
sf::Text Level1::tutorial_rolling;
sf::Text Level1::tutorial_jump;
sf::Text Level1::tutorial_sword;
sf::Text Level1::tutorial_end;


sf::Texture Level0::background_texture;

sf::Sprite Level0::background;


sf::Texture Level10::cyber_background_texture;

sf::Sprite Level10::cyber_background;

sf::Texture Level10::cyber_background_near_texture;

sf::Sprite Level10::cyber_background_near;

sf::Texture Level10::cyber_background_far_texture;

sf::Sprite Level10::cyber_background_far;



int Levels::level_code = 1;

int Levels::x_near_bound = 7200;
int Levels::x_far_bound = -50;






void Levels::Level_Textures()
{



	Level1::tutorial_movement.setString("Move around with  ");
	Level1::tutorial_movement.setCharacterSize(50);
	Level1::tutorial_movement.setFont(Text::font2);

	Level1::tutorial_camera.setString("Move the camera with  ");
	Level1::tutorial_camera.setCharacterSize(50);
	Level1::tutorial_camera.setFont(Text::font2);

	Level1::tutorial_rolling.setString("You can do a roll with  ");
	Level1::tutorial_rolling.setCharacterSize(50);
	Level1::tutorial_rolling.setFont(Text::font2);

	Level1::tutorial_jump.setString("You can jump with  ");
	Level1::tutorial_jump.setCharacterSize(50);
	Level1::tutorial_jump.setFont(Text::font2);

	Level1::tutorial_sword.setString("\n\nAttack with ");
	Level1::tutorial_sword.setCharacterSize(50);
	Level1::tutorial_sword.setFont(Text::font2);

	Level1::tutorial_end.setString("Make the legend come to life!");
	Level1::tutorial_end.setCharacterSize(50);
	Level1::tutorial_end.setFont(Text::font2);





	std::cout << std::endl << std::endl << "loading - levels" << std::endl << std::endl;
	

	Level0::background_texture.loadFromFile("Assets/Textures/Level/Base/base.png");

	Level0::background.setTexture(Level0::background_texture);
	Level0::background.setScale(4.0f, 4.0f);
	
	

	Level1::background_texture.loadFromFile("Assets/Textures/Level/Tutorial/tutorial.png");

	Level1::background.setTexture(Level1::background_texture);
	Level1::background.setScale(9.0f, 9.0f);

	Level1::door_texture.loadFromFile("Assets/Textures/Level/Tutorial/door.png");

	Level1::door.setTexture(Level1::door_texture);
	Level1::door.setScale(9.0f, 9.0f);


	Level1::crate_texture.loadFromFile("Assets/Textures/Level/Tutorial/BigCrate.png");

	Level1::crate.setTexture(Level1::crate_texture);
	Level1::crate.setScale(9.0f, 9.0f);


	Level1::platform_texture.loadFromFile("Assets/Textures/Level/Tutorial/platform.png");
	Collision::CreateTextureAndBitmask(Level1::platform_texture, "Assets/Textures/Level/Tutorial/platform.png");

	Level1::platform.setTexture(Level1::platform_texture);
	Level1::platform.setScale(9.0f, 9.0f);

	std::cout << "levels - level 1..." << std::endl;










	static sf::Texture cyber_background_far_texture;

	static sf::Texture cyber_background_far;


	Level10::cyber_background_texture.loadFromFile("Assets/Textures/Level/Cyber/back.png");
	Collision::CreateTextureAndBitmask(Level10::cyber_background_texture, "Assets/Textures/Level/Cyber/back.png");

	Level10::cyber_background.setTexture(Level10::cyber_background_texture);
	



	Level10::cyber_background_near_texture.loadFromFile("Assets/Textures/Level/Cyber/near.png");
	Collision::CreateTextureAndBitmask(Level10::cyber_background_near_texture, "Assets/Textures/Level/Cyber/near.png");

	Level10::cyber_background_near.setTexture(Level10::cyber_background_near_texture);
	



	Level10::cyber_background_far_texture.loadFromFile("Assets/Textures/Level/Cyber/far.png");
	Collision::CreateTextureAndBitmask(Level10::cyber_background_far_texture, "Assets/Textures/Level/Cyber/far.png");

	Level10::cyber_background_far.setTexture(Level10::cyber_background_far_texture);
	









	Level10::cyber_platform_texture.loadFromFile("Assets/Textures/Level/Cyber/platform.png");
	Collision::CreateTextureAndBitmask(Level10::cyber_platform_texture, "Assets/Textures/Level/Cyber/platform.png");

	Level10::cyber_platform.setTexture(Level10::cyber_platform_texture);
	Level10::cyber_platform.setScale(9.0f, 9.0f);


	std::cout << "levels - level 10..." << std::endl;



}

void Level0::render_backround(int& x_parralax, sf::RenderWindow& x_window)
{
	background.setPosition(x_parralax, -600);
	x_window.draw(background);

	//Level1::render_platform(x_window, 400, 300);

	//Level1::render_platform(x_window, 800, 300);

}

void Level0::render_upground(int& x_parralax, sf::RenderWindow& x_window)
{

}


void Level1::render_platform(sf::RenderWindow& x_window, int x, int y)
{

	platform.setPosition(x, y); //455
	x_window.draw(platform);
	//if (Collision::PixelPerfectTest(platform, Walk::character_idle) || Collision::PixelPerfectTest(platform, Walk::character_run) || Collision::PixelPerfectTest(platform, Jumping::character_jump) || Collision::PixelPerfectTest(platform, Rolling::character_roll)) {
	//	if (Walk::player_position_y < y - 280) {
	//		Physics::on_platform = true;
	//	}
	//}
	if (Walk::right == 1) {
		Physics::character_hitbox.setPosition(Walk::player_position, Walk::player_position_y);
	}
	else {
		Physics::character_hitbox.setPosition(Walk::player_position - 40, Walk::player_position_y);
	}


	x_window.draw(Physics::character_hitbox);

	if (Collision::PixelPerfectTest(platform, Physics::character_hitbox)) {

		if (Walk::player_position_y < y - 280) {
			Jumping::double_jump = 1;
			Physics::on_platform = true;
		}
	}

	//if (Walk::player_position > x - 100) {

		//if (Walk::player_position_y < y - 280) {
		//	Physics::on_platform = true;
		//}

	//}
	
}

void Level1::render_backround(int& x_parralax, sf::RenderWindow& x_window)
{
	


	background.setPosition(x_parralax, -2000);
	x_window.draw(background);

	//tutorial_movement.setPosition(300, 150);
	//x_window.draw(tutorial_movement);



	Level1::render_platform(x_window, -150, 810);

	Level1::render_platform(x_window, 400, 300);

	Level1::render_platform(x_window, 1200, 300);


	Level1::render_platform(x_window, 1800, 480);

	Level1::render_platform(x_window, 2800, 480);

	Level1::render_platform(x_window, 600, 1280);




	Level1::render_platform(x_window, 0, 1980);

	Level1::render_platform(x_window, 400, 1980);
	
	Level1::render_platform(x_window, 800, 1980);

	Level1::render_platform(x_window, 1200, 1980);

	Level1::render_platform(x_window, 1600, 1980);

	Level1::render_platform(x_window, 2000, 1980);

	Level1::render_platform(x_window, 2400, 1980);

	Level1::render_platform(x_window, 2800, 1980);

	Level1::render_platform(x_window, 3200, 1980);

	Level1::render_platform(x_window, 3600, 1980);

	Level1::render_platform(x_window, 4000, 1980);

	//render_platform(x_window, 0, 455);

	//render_platform(x_window, 300, 455);

	// render_platform(x_window, 600, 455);

	//render_platform(x_window, 900, 455);

	//render_platform(x_window, 1200, 455);

	//platform.setPosition(100, 500);
	//x_window.draw(platform);

	//platform.setPosition(200, 800);
	//x_window.draw(platform);


	//tutorial_movement.setPosition(500, 400);
	//x_window.draw(tutorial_movement);
}

void Level1::render_upground(int& x_parralax, sf::RenderWindow& x_window)
{

	//crate.setPosition(x_parralax + 500, 700);
	//x_window.draw(crate);

	door.setPosition(x_parralax, -610);
	x_window.draw(door);

	door.setScale(-9.0f, 9.0f);
	door.setPosition(x_parralax + 4445, -605);
	x_window.draw(door);

}


void Level2::render_backround(int& x_parralax, sf::RenderWindow& x_window)
{



	Level1::background.setPosition(x_parralax, -2000);
	x_window.draw(Level1::background);

	Level1::tutorial_movement.setPosition(300, 150);
    x_window.draw(Level1::tutorial_movement);

	UI::analog.setPosition(470, 0);
	x_window.draw(UI::analog);



	Level1::tutorial_camera.setPosition(2300, 150);
	x_window.draw(Level1::tutorial_camera);

	UI::analog2.setPosition(2550, 0);
	x_window.draw(UI::analog2);


	Level1::tutorial_rolling.setPosition(4300, 150);
	x_window.draw(Level1::tutorial_rolling);

	Buttons::quad.setPosition(4790, 160);
	x_window.draw(Buttons::quad);


	Level1::tutorial_jump.setPosition(4300, 1150);
	x_window.draw(Level1::tutorial_jump);

	Buttons::x.setPosition(4700, 1160);
	x_window.draw(Buttons::x);

	Level1::tutorial_sword.setPosition(2300, 1150);
	x_window.draw(Level1::tutorial_sword);

	Buttons::r1.setScale(5.0f, 5.0f);
	Buttons::r1.setTextureRect(sf::IntRect(0, 0, 12, 9));
	Buttons::r1.setPosition(2550, 1265);
	x_window.draw(Buttons::r1);

	


	Level1::render_platform(x_window, -150, 700);

	Level1::render_platform(x_window, 400, 700);

	Level1::render_platform(x_window, 800, 700);

	Level1::render_platform(x_window, 1200, 700);

	Level1::render_platform(x_window, 1600, 700);

	Level1::render_platform(x_window, 2000, 700);

	Level1::render_platform(x_window, 2400, 700);

	Level1::render_platform(x_window, 2800, 700);

	Level1::render_platform(x_window, 3200, 700);

	Level1::render_platform(x_window, 3600, 700);

	Level1::render_platform(x_window, 4000, 700);

	Level1::render_platform(x_window, 4400, 700);

	Level1::render_platform(x_window, 4800, 700);

	Level1::render_platform(x_window, 5200, 700);

	Level1::render_platform(x_window, 5600, 700);

	Level1::render_platform(x_window, 6000, 700);

	Level1::render_platform(x_window, 6400, 700);



	

	Level1::render_platform(x_window, 400, 1700);

	Level1::render_platform(x_window, 800, 1700);

	Level1::render_platform(x_window, 1200, 1700);

	Level1::render_platform(x_window, 1600, 1700);

	Level1::render_platform(x_window, 2000, 1700);

	Level1::render_platform(x_window, 2400, 1700);

	Level1::render_platform(x_window, 2800, 1700);

	Level1::render_platform(x_window, 3200, 1700);

	Level1::render_platform(x_window, 3600, 1700);

	Level1::render_platform(x_window, 4000, 1700);

	Level1::render_platform(x_window, 4400, 1700);

	Level1::render_platform(x_window, 4800, 1700);

	Level1::render_platform(x_window, 5200, 1700);

	Level1::render_platform(x_window, 5600, 1700);

	Level1::render_platform(x_window, 6000, 1700);

	Level1::render_platform(x_window, 6400, 1700);

	Level1::render_platform(x_window, 6800, 1700);

	Level1::render_platform(x_window, 7200, 1700);


	Level1::render_platform(x_window, -150, 2700);

	Level1::render_platform(x_window, 400, 2700);

	Level1::render_platform(x_window, 800, 2700);

	Level1::render_platform(x_window, 1200, 2700);

	Level1::render_platform(x_window, 1600, 2700);

	Level1::render_platform(x_window, 2000, 2700);

	Level1::render_platform(x_window, 2400, 2700);

	Level1::render_platform(x_window, 2800, 2700);

	Level1::render_platform(x_window, 3200, 2700);

	Level1::render_platform(x_window, 3600, 2700);

	Level1::render_platform(x_window, 4000, 2700);

	Level1::render_platform(x_window, 4400, 2700);

	Level1::render_platform(x_window, 4800, 2700);

	Level1::render_platform(x_window, 5200, 2700);

	Level1::render_platform(x_window, 5600, 2700);

	Level1::render_platform(x_window, 6000, 2700);

	Level1::render_platform(x_window, 6400, 2700);

	Level1::render_platform(x_window, 6800, 2700);

	Level1::render_platform(x_window, 7200, 2700);

	Level1::render_platform(x_window, 7600, 2700);


}









//Cyberpunk
void Levels::Level_Background(sf::RenderWindow& x_window) {
	if (level_code == 10) {

		Level10::cyber_background_far.setScale(40.f, 10.f);
		Level10::cyber_background_far.setPosition(-Walk::player_position / 20 - 300, -200);
		x_window.draw(Level10::cyber_background_far);
		
		Level10::cyber_background.setScale(12.f, 12.f);
		Level10::cyber_background.setPosition(-Walk::player_position / 10, 0);
		x_window.draw(Level10::cyber_background);
		

		Level10::cyber_background_near.setScale(5.f, 5.f);
		Level10::cyber_background_near.setPosition(-Walk::player_position / 6, 200);
		x_window.draw(Level10::cyber_background_near);


	}
}

void Levels::Level_Boundries() {
	if (level_code == 10) {
		Levels::x_near_bound = -50;
		Levels::x_far_bound = 7200;
	}
}

void Level10::render_platform(sf::RenderWindow& x_window, int x, int y)
{
	cyber_platform.setScale(10.f, 5.f);
	cyber_platform.setPosition(x, y); //455
	x_window.draw(cyber_platform);

	if (Walk::right == 1) {
		Physics::character_hitbox.setPosition(Walk::player_position, Walk::player_position_y);
	}
	else {
		Physics::character_hitbox.setPosition(Walk::player_position - 40, Walk::player_position_y);
	}


	x_window.draw(Physics::character_hitbox);

	if (Collision::PixelPerfectTest(cyber_platform, Physics::character_hitbox)) {

		if (Walk::player_position_y < y - 280) {
			Jumping::double_jump = 1;
			Physics::on_platform = true;
		}
	}
}



void Level10::render_background(int& x_parralax, sf::RenderWindow& x_window)
{
	//background.setPosition(x_parralax, -2000);
	//x_window.draw(background);

	//tutorial_movement.setPosition(300, 150);
	//x_window.draw(tutorial_movement);


	Levels::Level_Background(x_window);


	Level10::render_platform(x_window, -150, 810);




}


