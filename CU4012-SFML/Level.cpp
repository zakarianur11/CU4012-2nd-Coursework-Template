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


	world->AddGameObject(p1);

	tileManager.setInput(input);
	tileManager.setWindow(window);
	tileManager.setWorld(world);

	if (!tileManager.loadTiles())
	{
		std::cout << "Tiles not found\n";
	}
	else
	{
		std::cout << "Tiles loaded\n";
	}
	mapBackground.setWindow(window);
	mapBackground.setInput(input);



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

	tileManager.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	if(p1.CollisionWithTag("Enemy"))
	{ 
		
	}
	mapBackground.update(dt, p1.getPosition());
	tileManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(mapBackground);


	window->draw(p1);
	window->draw(p1.getDebugCollisionBox());


	tileManager.render();
	endDraw();
}
