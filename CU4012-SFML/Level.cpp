#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, World* w)
{
	window = hwnd;
	input = in;
	gameState = gs;
	world = w;
	// initialise game objects
	p1.setPosition(100, 100);
	p1.setInput(input);

	e1.setPosition(500, 100);
	world->AddGameObject(p1);
	world->AddGameObject(e1);
	world->AddGameObject(ground);
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
	if(p1.CollisionWithTag("Ground"))
	{ 
		std::cout<<"Player collided with Ground" << std::endl;
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
