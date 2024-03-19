#include "Level.h"
#include "Player.h"


Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, World* w)
{
	window = hwnd;
	input = in;
	gameState = gs;
	world = w;


	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "error loading font" << std::endl;
	};

	TileEditorText.setFont(font);
	TileEditorText.setCharacterSize(24);
	TileEditorText.setFillColor(sf::Color::Red);




	TileEditorText.setString(" Press E to edit tiles");
	TileEditorText.setPosition(0, 0);

	// initialise game objects
	p1.setPosition(100, 100);
	p1.setInput(input);

	RingsCollectedText.setFont(font);
	RingsCollectedText.setCharacterSize(24);
	RingsCollectedText.setFillColor(sf::Color::Black);
	RingsCollectedText.setPosition(window->getSize().x, 0);
	RingsCollectedText.setString("Rings Collected:");


	world->AddGameObject(p1);

	tileManager.setCollectableTexture("gfx/Ring.png");
	tileManager.setPlatformTexture("gfx/Platform.png");
	tileManager.setInput(input);
	tileManager.setWindow(window);
	tileManager.setWorld(world);
	tileManager.ShowDebugCollisionBox(true);

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

	sf::Vector2f viewSize = sf::Vector2f(window->getSize().x, window->getSize().y);
	view.setSize(viewSize.x, viewSize.y);
	view.setCenter(viewSize.x / 2, viewSize.y / 2);


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
	// Check if 'E' is pressed to toggle editing mode
	if (input->isKeyDown(sf::Keyboard::E))
	{
		// First, if we're in edit mode, we save the tiles
		if (editMode)
		{
			std::cout << "Exiting edit mode. Saving tiles...\n";
			tileManager.saveTiles(tileManager.getTiles(), tileManager.getFilePath());
		}
		// Then toggle the edit mode
		editMode = !editMode;
		input->setKeyUp(sf::Keyboard::E); // Acknowledge the key press
	}

	if (editMode)
	{
		// Handle moving the view or other edit-mode-specific logic
		moveView(dt);
		//tileManager.handleInput(dt); // tileManager might have its own logic for when editing is true
	}
	else
	{
		// Handle game logic when not in edit mode
		p1.handleInput(dt);
	}
}

// Update game objects
void Level::update(float dt)
{

	sf::Vector2f viewSize = sf::Vector2f(window->getSize().x, window->getSize().y);
	RingsCollectedText.setPosition(view.getCenter().x - viewSize.x / 14, view.getCenter().y - viewSize.y / 2);
	
	if(p1.CollisionWithTag("Enemy"))
	{ 
		
	}
	if (p1.CollisionWithTag("Ring"))
	{
		// Player is Colliding with Ring
		p1.addRingCollected(1); // Increment ring count
		tileManager.RemoveCollectableTile(); // Remove the collectable tile
		p1.updatePlayerAttributes();

		// Update the RingsCollectedText to display the new number of rings collected
		int ringCount = p1.getRingCount(); // Assume p1 is the player object and has the getRingCount method
		RingsCollectedText.setString("Rings Collected: " + std::to_string(ringCount));
	}


	if (editMode)
	{
		TileEditorText.setPosition(view.getCenter().x - viewSize.x / 2, view.getCenter().y - viewSize.y / 2);
		TileEditorText.setString("Editing mode\nLeft Mouse Button to place tile\nPress B to set collider as a wall (allows bouncing)\n Press C to make it a collectable\n Press P to make it a Platform\nPress E to exit and Save");
		tileManager.handleInput(dt);
		tileManager.update(dt);
	}
	else
	{
		TileEditorText.setString("Press E to edit tiles");
		mapBackground.update(dt, p1.getPosition());
		//sf::View view = window->getView();
		view.setCenter(view.getCenter().x, 360);

		sf::Vector2f playerPosition = p1.getPosition();
		float newX = std::max(playerPosition.x, view.getSize().x / 2.0f);
		view.setCenter(newX, view.getCenter().y);
		window->setView(view);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(mapBackground);


	window->draw(p1);
	window->draw(p1.getDebugCollisionBox());


	tileManager.render();
	if(editMode) window->draw(TileEditorText);
	window->draw(RingsCollectedText);


	endDraw();
}
void Level::moveView(float dt)
{
	float speed = 500;
	if (input->isKeyDown(sf::Keyboard::W))
	{
		view.move(0, -speed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		view.move(0, speed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		view.move(-speed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		view.move(speed * dt, 0);
	}

	window->setView(view);

}

void Level::adjustViewToWindowSize(unsigned int width, unsigned int height)
{
	sf::FloatRect visibleArea(0, 0, static_cast<float>(width), static_cast<float>(height));
	view.setSize(static_cast<float>(width), static_cast<float>(height));
	view.setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}