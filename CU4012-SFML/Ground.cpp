#include "Ground.h"

Ground::Ground()
{
	setPosition(0, 500);
	setSize(sf::Vector2f(1500, 100));
	setCollisionBox(getPosition(), getSize());
	setTag("Ground");
	setStatic(true);
}
