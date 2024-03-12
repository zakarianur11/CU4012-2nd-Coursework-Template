#include "Tiles.h"

Tiles::Tiles()
{
	setSize(sf::Vector2f(50, 50));
	setStatic(true);
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
	if (input->isKeyDown(sf::Keyboard::Return) && editing) {
		editing = false;
		std::cout << "Editing: " << editing << std::endl;

	}


	if(editing)
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


		//Resize the tile
		if (input->isKeyDown(sf::Keyboard::J))
		{
			setSize(sf::Vector2f(getSize().x - 1, getSize().y));
		}
		if (input->isKeyDown(sf::Keyboard::L))
		{
			setSize(sf::Vector2f(getSize().x + 1, getSize().y));
		}
		if (input->isKeyDown(sf::Keyboard::I))
		{
			setSize(sf::Vector2f(getSize().x, getSize().y - 1));
		}
		if (input->isKeyDown(sf::Keyboard::K))
		{
			setSize(sf::Vector2f(getSize().x, getSize().y + 1));
		}

		if (input->isKeyDown(sf::Keyboard::O))
		{
			// Rotate counterclockwise
			float currentRotation = getRotation(); // Assume getRotation() retrieves the current rotation
			currentRotation -= rotationSpeed; // Decrease the rotation based on the time and speed
			rotate(currentRotation); // Set the new rotation
		}
		if (input->isKeyDown(sf::Keyboard::P))
		{
			// Rotate clockwise
			float currentRotation = getRotation(); // Assume getRotation() retrieves the current rotation
			currentRotation += rotationSpeed * dt; // Increase the rotation based on the time and speed
			rotate(currentRotation); // Set the new rotation
		}
	}

}
