#include "SaveLoad.h"
#include "iostream"
#include "SFML/Graphics.hpp"
#include "fstream"
#include "Player.h"
#include "Movement.h"

using namespace std;




void SaveLoad::Save()
{
	ofstream SaveFile;
	SaveFile.open("Data/VGe1.dat", std::ofstream::trunc);

	SaveFile << Player::gold << " " << Player::player_health << " " << Player::player_current_health << " " << Player::player_stamina << " " << Player::player_current_stamina << " " << Player::player_energy <<  " " << Player::player_current_energy << " " << 
	Player::player_exp << " " << Player::souls << " " << Player::player_damage << " " << Player::visibility << " " << Player::back_item << " " << Player::sling_item << " " << Walk::right << " " << Walk::player_position << " " << Walk::player_position_y << " " <<
	Walk::tired << " " << Player::Armor;


	SaveFile.close();
}

void SaveLoad::Load()
{
	int pou = 2;
	ifstream LoadFile;
	LoadFile.open("Data/VGe1.dat", std::ofstream::in);

	LoadFile >> Player::gold >> Player::player_health >> Player::player_current_health >> Player::player_stamina >> Player::player_current_stamina >> Player::player_energy >> Player::player_current_energy >>
	Player::player_exp >> Player::souls >> Player::player_damage >> Player::visibility >> Player::back_item >> Player::sling_item >> Walk::right >> Walk::player_position >> Walk::player_position_y >>
	Walk::tired >> Player::Armor;

	LoadFile.close();
}
