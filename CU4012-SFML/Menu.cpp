#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;


	UIfont.loadFromFile("font/ZOMBIES REBORN.ttf");
	titleFont.loadFromFile("font/BloodBlocks Project.ttf");


	menu_texture.loadFromFile("gfx/menu.png");
	menu_sprite.setTexture(menu_texture);
	menu_sprite.setScale(0.5, 0.5);


	Title.setFont(titleFont);
	Title.setFillColor(sf::Color::Magenta);
	Title.setString("My Game");
	Title.setOutlineColor(sf::Color::Black);
	Title.setCharacterSize(70);
	Title.setPosition(500, 50);


	UIText[0].text.setFont(UIfont);
	UIText[0].text.setFillColor(sf::Color::Red);
	UIText[0].text.setString("Play");
	UIText[0].text.setPosition(sf::Vector2f(600,120));
	UIText[0].setCollisionBox(sf::FloatRect(UIText[0].text.getPosition().x, UIText[0].text.getPosition().y+15, 35, 15));



	UIText[1].text.setFont(UIfont);
	UIText[1].text.setFillColor(sf::Color::White);
	UIText[1].text.setString("Exit");
	UIText[1].text.setPosition(sf::Vector2f(600,150));
	UIText[1].setCollisionBox(sf::FloatRect(UIText[1].text.getPosition().x, UIText[1].text.getPosition().y + 15, 35, 15));



	selectedItem = 0;

	mouseOverAnyItem = false;

}
Menu::~Menu()
{
}

void Menu::update(float dt)
{
	mouseOverAnyItem = false; // Reset this flag each frame

	// Update mouse position
	MousePos.x = input->getMouseX();
	MousePos.y = input->getMouseY();

	for (int i = 0; i < 2; i++) {
		if (Collision::checkBoundingBox(UIText[i].getCollisionBox(), MousePos)) {
			if (!mouseOverAnyItem) { // Only change if the mouse wasn't already over an item
				selectedItem = i;
				mouseOverAnyItem = true;
			}
		}
	}

	updateVisualFeedback(); // Update visual feedback at the end to reflect any changes
}

void Menu::updateVisualFeedback()
{
    for (int i = 0; i < 2; i++) {
        if (i == selectedItem) {
			UIText[i].text.setFillColor(sf::Color::Red); // Highlight selected item
        } else {
            UIText[i].text.setFillColor(sf::Color::White); // Default color for non-selected items
        }
    }
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		UIText[selectedItem].text.setFillColor(sf::Color::White);
		selectedItem--;
		UIText[selectedItem].text.setFillColor(sf::Color::Red);
	}
}
void Menu::MoveDown()
{
	if (selectedItem + 1 < 2)
	{
		UIText[selectedItem].text.setFillColor(sf::Color::White);
		selectedItem++;
		UIText[selectedItem].text.setFillColor(sf::Color::Red);
	}

}
int Menu::handleInput(float dt)
{
	// Keyboard handling for menu navigation
	if (input->isKeyDown(sf::Keyboard::Up)) {
		MoveUp();
		input->setKeyUp(sf::Keyboard::Up);
	}

	if (input->isKeyDown(sf::Keyboard::Down)) {
		MoveDown();
		input->setKeyUp(sf::Keyboard::Down);
	}

	// Execute action for the current selected item
	if (input->isKeyDown(sf::Keyboard::Enter) || (input->isLeftMouseDown() && mouseOverAnyItem)) {
		switch (selectedItem) {
		case 0:
			std::cout << "Play Button has been pressed" << std::endl;
			gameState->setCurrentState(State::LEVEL);
			break;
		case 1:
			std::cout << "Exit Button has been pressed" << std::endl;
			exit(0);
			break;
		}

		// Reset input states
		if (input->isKeyDown(sf::Keyboard::Enter)) {
			input->setKeyUp(sf::Keyboard::Enter);
		}
		if (input->isLeftMouseDown()) {
			input->setLeftMouse(Input::MouseState::UP); // Assuming you have a method to reset the mouse state
		}
	}

	return 0; // Return value can be used if needed for further input handling logic

}

void Menu::render()
{
	beginDraw();
	window->draw(menu_sprite);
	window->draw(Title);
	for (int i = 0; i < 2; i++)
	{
		window->draw(UIText[i].text);
	}

	//Uncomment so debug shapes for the menu text
	//for (int i = 0; i < 2; i++)
	//{
	//	window->draw(UIText[i].getDebugShape());
	//}

	endDraw();
}




void Menu::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}
void Menu::endDraw()
{
	window->display();
}