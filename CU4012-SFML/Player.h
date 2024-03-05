#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class Player : public GameObject
{
	int health;
	float speed;
	sf::Texture texture;

	sf::Vector2f lastSafePosition;
public:
	Player();

	void handleInput(float dt);
	void update(float dt);


	void collisionResponse(GameObject* collider);

};

