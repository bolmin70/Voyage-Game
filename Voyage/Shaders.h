
#include <iostream>
#include "SFML/Graphics.hpp"
#pragma once

class Shaders
{
public:
	static sf::Shader blur;
	// load only the fragment shader


	static void Load_Shaders();

};


