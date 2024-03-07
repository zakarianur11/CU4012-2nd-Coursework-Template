#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	// initialise game objects
	p1.setPosition(100, 100);
	p1.setInput(input);


	e1.setPosition(500, 100);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
	p1.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	p1.update(dt);
	e1.update(dt);

	if (p1.checkCollision(e1.getCollisionBox()))
	{
		p1.collisionResponse(&e1);
	}
	else
	{
		p1.setColliding(false);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(p1);
	window->draw(p1.getDebugCollisionBox());


	window->draw(e1);
	window->draw(e1.getDebugCollisionBox());


	window->draw(ground.getDebugCollisionBox());

	endDraw();
}
