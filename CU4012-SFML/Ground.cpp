#include "Ground.h"

Ground::Ground()
{
	setPosition(0, 500);
	setSize(sf::Vector2f(1200, 100));
	setCollisionBox(getPosition(), getSize());
}
