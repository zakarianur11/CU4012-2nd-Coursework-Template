#include "Stage.h"

Stage::Stage()
{
	if (!stageTexture.loadFromFile("gfx/stage.png")) //Loading stage texture
	{
		std::cout << "Texture not found\n";
	}

	setTexture(&stageTexture);
	setSize(sf::Vector2f(10288, 1204));


}
