#include "Player.h"
Player::Player()
{
    baseHealth = 100;
    baseSpeed = 500; // Base speed without any rings
    baseJumpHeight = 50; // Base jump height without any rings

    maxJumpHeight = 600.f;
    maxSpeed = 1000.f;
    health = baseHealth;
    speed = baseSpeed;
    jumpHeight = baseJumpHeight;

    if (!texture.loadFromFile("gfx/sonicCharacter.png"))
    {
        std::cout << "File not found\n";
    }
    setTexture(&texture);
    setSize(sf::Vector2f(100, 100));
    setCollisionBox(getPosition(), getSize());
    setMass(100.f);
    setTag("Player");
}

void Player::updatePlayerAttributes()
{
    // Reset attributes to their base values
    speed = baseSpeed;
    jumpHeight = baseJumpHeight;

    // Calculate the bonuses from rings collected
    float jumpHeightBonus = (noOfRingsCollected / 2) * 50.f; // Bonus for every 2 rings
    float speedBonus = (noOfRingsCollected / 2) * 20.f; // Bonus for every 2 rings

    // Apply bonuses with caps
    jumpHeight += std::min(jumpHeightBonus, maxJumpHeight);
    speed += std::min(speedBonus, maxSpeed);
}

void Player::handleInput(float dt)
{
	velocity.x = 0.f;

	// Update velocity based on input
	if (input->isKeyDown(sf::Keyboard::A))
	{
		// Update only the horizontal component, preserving vertical velocity
		velocity.x = -speed;
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		// Update only the horizontal component, preserving vertical velocity
		velocity.x = speed;
	}

	if (input->isKeyDown(sf::Keyboard::Space) && canJump)
	{
		Jump(jumpHeight);
	}
}

void Player::update(float dt)
{
}
