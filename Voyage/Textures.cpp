#include "Textures.h"
#include "SFML/Graphics.hpp"
#include "Movement.h"
#include "Text.h"
#include "Combat.h"
#include "Level.h"
#include "Menus.h"
#include "Interface.h"
#include "Enemy.h"
#include "Items.h"
#include "Player.h"

void Textures::Load_Textures() {
	Walk::Run_Textures();

	Equipment::Equip_Textures();

	Rolling::Roll_Textures();

	Combat::Attack_Textures();

	Jumping::Jump_Textures();

	Sitting::Sit_Textures();

	Hit::Hitt_Textures();


	Effects::Effect_Textures();


	Levels::Level_Textures();


	Physics::Hitbox_Textures();




	Menus::Menu_Textures();

	UI::UI_Textures();

	Buttons::Button_Textures();

	Items::Items_Textures();


	Enemy::Enemy_Skeleton_Textures();



	Text::Texts();

}
