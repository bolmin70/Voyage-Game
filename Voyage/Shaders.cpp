#include "Shaders.h"


sf::Shader Shaders::blur;


void Shaders::Load_Shaders() {
	
	if (!Shaders::blur.loadFromFile("Assets/Shaders/GuassianBlur.frag", sf::Shader::Fragment))
	{
		// error...
	}



	sf::Vector2f i(0.01f, 0.03f);
	//blur.
	blur.setUniform("source", sf::Shader::CurrentTexture);
	blur.setUniform("offsetFactor", i);


}