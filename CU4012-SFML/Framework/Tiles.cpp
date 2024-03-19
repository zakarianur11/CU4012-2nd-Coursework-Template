#include "Tiles.h"

Tiles::Tiles()
{
	setSize(sf::Vector2f(50, 50));


	setStatic(true);
	setTile(true);
	//setMass(50.f);
	editing = true;
}

void Tiles::update(float dt)
{
	// Set the collision box to be the same as the sprite
	updateCollisionBox(dt);
}

void Tiles::handleInput(float dt)
{

	if (editing)
	{
		// Move the tile
		float moveSpeed = 50.0f; // Speed of movement

		if (input->isKeyDown(sf::Keyboard::Left)) {
			setPosition(getPosition().x - moveSpeed * dt, getPosition().y);
		}
		if (input->isKeyDown(sf::Keyboard::Right)) {
			setPosition(getPosition().x + moveSpeed * dt, getPosition().y);
		}
		if (input->isKeyDown(sf::Keyboard::Up)) {
			setPosition(getPosition().x, getPosition().y - moveSpeed * dt);
		}
		if (input->isKeyDown(sf::Keyboard::Down)) {
			setPosition(getPosition().x, getPosition().y + moveSpeed * dt);
		}

		float resizeSpeed = 0.1f; // Speed of resizing	
		//Resize the tile
		if (input->isKeyDown(sf::Keyboard::J))
		{
			setSize(sf::Vector2f(getSize().x - resizeSpeed, getSize().y));
		}


		if (input->isKeyDown(sf::Keyboard::L))
		{
			setSize(sf::Vector2f(getSize().x + resizeSpeed, getSize().y));
		}

		if (input->isKeyDown(sf::Keyboard::I))
		{
			setSize(sf::Vector2f(getSize().x, getSize().y - resizeSpeed));
		}

		if (input->isKeyDown(sf::Keyboard::K))
		{
			setSize(sf::Vector2f(getSize().x, getSize().y + resizeSpeed));
		}

		if (input->isKeyDown(sf::Keyboard::B))
		{
			input->setKeyUp(sf::Keyboard::B);
			setTag("Wall");
			std::cout << "Tile set as Wall\n";
		}
		if (input->isKeyDown(sf::Keyboard::C))
		{
			input->setKeyUp(sf::Keyboard::C);
			setTag("Ring");
			std::cout << "Tile set as Ring\n";
		}

		if (input->isKeyDown(sf::Keyboard::P))
		{
			input->setKeyUp(sf::Keyboard::P);
			setTag("Platform");
			std::cout << "Tile set as Platform\n";
		}
	}
}
