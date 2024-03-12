#include "Background.h"
#include "Framework/utilities.h"

Background::Background()
{
	if (!backgroundTexture.loadFromFile("gfx/stage.png")) //Loading background texture
	{
		std::cout << "Texture not found\n";
	}

	setTexture(&backgroundTexture);
	setSize(sf::Vector2f(3672, 1204));
	
	setScale(3.4, 3.4);
	setPosition(0, -getSize().y*2);
	view.setSize(WINDOWWIDTH, WINDOWHEIGHT);
	view.setCenter(WINDOWWIDTH / 2, WINDOWHEIGHT / 2);
}

void Background::update(float dt, sf::Vector2f playerPos)
{
	//view.setCenter(playerPos);
	if (input->isKeyDown(sf::Keyboard::E))
	{
		view.move(-400 * dt, 0);

	}
	if (input->isKeyDown(sf::Keyboard::R))
	{
		view.move(400 * dt, 0);
	}
	//if (input->isKeyDown(sf::Keyboard::W))
	//{
	//	view.move(0, -400 * dt);
	//}
	window->setView(view);

}
