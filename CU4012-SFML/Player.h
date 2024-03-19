#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class Player : public GameObject
{
	int baseHealth;
	int baseSpeed;
	int baseJumpHeight;
	int health;
	float speed;
	int noOfRingsCollected;
	sf::Texture texture;
	int jumpHeight;

	float maxJumpHeight;
	float  maxSpeed;
public:
	Player();

	void handleInput(float dt);
	void update(float dt);
	void addRingCollected(int count) { noOfRingsCollected += count; }
	int getRingCount() { return noOfRingsCollected; }

	void updatePlayerAttributes();
};

