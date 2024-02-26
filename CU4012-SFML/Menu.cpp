#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;

	Level level(window, input, gameState);
	level1 = new Level(window, input, gameState);


	font.loadFromFile("font/ZOMBIES REBORN.ttf");
	title.loadFromFile("font/BloodBlocks Project.ttf");


	menu_texture.loadFromFile("gfx/menu.png");
	menu_sprite.setTexture(menu_texture);
	menu_sprite.setScale(0.35, 0.32);


	Title.setFont(title);
	Title.setFillColor(sf::Color::Magenta);
	Title.setString("My Game");
	Title.setOutlineColor(sf::Color::Black);
	Title.setCharacterSize(70);
	Title.setPosition(500, 50);


	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(600,120));


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(600,150));


	selectedItem = 0;



}
Menu::~Menu()
{
}

void Menu::update(float dt)
{

}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}
void Menu::MoveDown()
{
	if (selectedItem + 1 < 2)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}

}
int Menu::handleInput(float dt)
{




	if (input->isKeyDown(sf::Keyboard::Up))

	{
		MoveUp();
		input->setKeyUp(sf::Keyboard::Up);
		return 0;
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		MoveDown();
		input->setKeyUp(sf::Keyboard::Down);
		return 0;
	}

	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		switch (GetPressedItem())
		{
			//static bool runOnce = true;
		case 0:
			std::cout << "Play Button has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::LEVEL);
			break;
		case 1:
			exit(0);
		}

		return 0;
	}
}

void Menu::render()
{
	beginDraw();
	window->draw(menu_sprite);
	window->draw(Title);
	for (int i = 0; i < 2; i++)
	{
		window->draw(menu[i]);
	}

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