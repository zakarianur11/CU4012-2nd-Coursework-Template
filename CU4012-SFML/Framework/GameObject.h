// Game Object Class
// A class representing a single renderable game object.
// Game Object extend sf::RectangleShape, and added functionailty for collision, sprite states (alive/dead), velocity for movement, input component
// Most elements of your game will extend game object to create larger more complex elements such as player, enemies, bullets etc.

#pragma once
#include "SFML\Graphics.hpp"
#include "Input.h"

class GameObject : public sf::RectangleShape
{
public:
	GameObject();
	~GameObject();

	// Virtual update function. Base function does nothing (for static objects). Inheritted version will most likely override this function.
	virtual void handleInput(float dt);
	virtual void update(float dt);

	// Control sprite speed and direction
	void setVelocity(sf::Vector2f vel);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity();

	// Sprite state
	bool isAlive() { return alive; };
	void setAlive(bool b) { alive = b; };

	// For sprite collision, set collider box, get collider box, and dedicated virtual function for collision response
	bool isColliding() { return Colliding; };
	void setColliding(bool b) { Colliding = b; };
	sf::FloatRect getCollisionBox();

	void setCollisionBox(float x, float y, float width, float height) 
	{ 
		collisionBox = sf::FloatRect(x, y, width, height);
		setDebugCollisionBox(x, y, width, height);
	};
	
	void setCollisionBox(sf::Vector2f pos, sf::Vector2f size)
	{
		collisionBox = sf::FloatRect(pos.x, pos.y, size.x, size.y);
		setDebugCollisionBox(pos.x, pos.y, size.x, size.y);

	}

	void setCollisionBox(sf::FloatRect fr)
	{ 
		collisionBox = fr;
		setDebugCollisionBox(fr.left, fr.top, fr.width, fr.height);
	};

	sf::RectangleShape getDebugCollisionBox() { return collisionBoxDebug; }

	bool checkCollision(sf::FloatRect collisionBox);

	virtual void collisionResponse(GameObject* collider);

	// Set the input component
	void setInput(Input* in) { input = in; };
	void setWindow(sf::RenderWindow* win) { window = win; };
	


protected:

	void setDebugCollisionBox(float x, float y, float w, float h);


	// Sprite properties
	sf::Vector2f velocity;
	bool alive;

	// Collision vars
	sf::FloatRect collisionBox;
	sf::RectangleShape collisionBoxDebug;
	bool Colliding;

	// input component
	Input* input;
	sf::RenderWindow* window;
};