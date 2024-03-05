#include "GameObject.h"

GameObject::GameObject()
{
	input = nullptr;
	window = nullptr;
	alive = true;
	Colliding = false;
}

GameObject::~GameObject()
{

}

// Override this function to provide input handling for the derived class
void GameObject::handleInput(float dt)
{
}

// override this function to provide functionality
void GameObject::update(float dt)
{
}

// Sets the velocity of the sprite
void GameObject::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}
void GameObject::setVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

// get sprite velocity
sf::Vector2f GameObject::getVelocity()
{
	return velocity;
}

// Returns collision box + position, giving the collision box in the correct position
sf::FloatRect GameObject::getCollisionBox() {
	
	return collisionBox;

}

void GameObject::setDebugCollisionBox(float x, float y, float w, float h)
{
	collisionBoxDebug.setPosition(sf::Vector2f(x, y));
	collisionBoxDebug.setSize(sf::Vector2f(w, h));
	collisionBoxDebug.setFillColor(sf::Color::Transparent);
	collisionBoxDebug.setOutlineColor(sf::Color::Red);
	collisionBoxDebug.setOutlineThickness(1.f);
}

bool GameObject::checkCollision(sf::FloatRect otherBox)
{
	return collisionBox.intersects(otherBox);
}

// Reponse function, what the sprite does based on collision
// Colliding object is passed in for information
// e.g. compare sprite positions to determine new velocity direction.
// e.g. checking sprite type (world, enemy, bullet etc) so response is based on that.
void GameObject::collisionResponse(GameObject * collider)
{

}
