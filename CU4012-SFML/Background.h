#pragma once
#include "Framework/GameObject.h"
class Background :
    public GameObject
{

	sf::View view;
	sf::Texture backgroundTexture;

public:
	Background();
	void update(float dt, sf::Vector2f playerPos);
};

