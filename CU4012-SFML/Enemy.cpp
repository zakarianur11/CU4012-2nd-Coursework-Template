#include "Enemy.h"

Enemy::Enemy()
{
	health = 100;
	speed = 150;
	velocity.x = -1;

	if (!texture.loadFromFile("gfx/Goomba.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollisionBox(getPosition(), getSize());

}

void Enemy::update(float dt)
{
	setCollisionBox(getPosition(), getSize());


	move(velocity * speed * dt);
}
