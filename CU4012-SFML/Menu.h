#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include"Framework/Collision.h"
#include "Framework/UICollsion.h"
#include <string>
#include <iostream>
#include"Level.h"


class Menu
{
public:
	Menu(sf::RenderWindow* hwnd, Input* in, GameState* game);
	~Menu();


	int handleInput(float dt);
	void update(float dt);
	void render();
	void MoveUp();
	void MoveDown();
	void updateVisualFeedback();
	int GetPressedItem() { return selectedItem; }


	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;

	Level* level1;

	int selectedItem;
	sf::Font font;
	sf::Font title;
	sf::Text Title;
	sf::Text menu[2];
	UICollisionBox UICollisionBox[2];
	
	void beginDraw();
	void endDraw();



	sf::Sprite menu_sprite;
	sf::Texture menu_texture;

	sf::Vector2i MousePos;

	bool mouseOverAnyItem;
};

