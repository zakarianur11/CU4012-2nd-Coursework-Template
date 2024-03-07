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

void GameObject::updateCollisionBox(float dt)
{
	collisionBox = sf::FloatRect(getPosition().x, getPosition().y, getSize().x, getSize().y);
	setDebugCollisionBox(getPosition().x, getPosition().y, getSize().x, getSize().y);

}

// Sets the velocity of the sprite
void GameObject::setVelocity(sf::Vector2f vel)
{
	if(!isStatic)
	{ 
		velocity = vel;
	}
}
void GameObject::setVelocity(float vx, float vy)
{
	if (!isStatic)
	{
		velocity.x = vx;
		velocity.y = vy;
	}
}

void GameObject::applyImpulse(sf::Vector2f impulse)
{
	if (!isStatic)
	{
		velocity += impulse/mass;
	}
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



bool GameObject::checkCollision(GameObject* otherBox) {
	sf::Vector2f otherPos = otherBox->getPosition();
	sf::Vector2f otherHalfSize = otherBox->getHalfSize();

	sf::Vector2f thisPos = getPosition();
	sf::Vector2f thisHalfSize = getHalfSize();

	float deltaX = otherPos.x - thisPos.x;
	float deltaY = otherPos.y - thisPos.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		// Calculate the total inverse mass
		float totalInverseMass = getInverseMass() + otherBox->getInverseMass();

		// The push factor is the ratio of the other object's inverse mass to the total inverse mass
		float push = (totalInverseMass != 0) ? otherBox->getInverseMass() / totalInverseMass : 0.0f; // Avoid division by zero
		push = std::min(std::max(push, 0.0f), 1.0f); // Clamp push value between 0 and 1

		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				move(intersectX * (1.0f - push), 0.f);
				otherBox->move(-intersectX * push, 0.0f);
			}
			else {
				move(-intersectX * (1.0f - push), 0.0f);
				otherBox->move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				move(0.0f, intersectY * (1.f - push));
				otherBox->move(0.0f, -intersectY * push);
			}
			else {
				move(0.0f, -intersectY * (1.0f - push));
				otherBox->move(0.0f, intersectY * push);
			}
		}

		return true;
	}
	return false;
}
// Reponse function, what the sprite does based on collision
// Colliding object is passed in for information
// e.g. compare sprite positions to determine new velocity direction.
// e.g. checking sprite type (world, enemy, bullet etc) so response is based on that.
void GameObject::collisionResponse(GameObject * collider)
{
	collidingTag = collider->getTag();
	
	//std::cout<<"Collision is happening between "<<getTag()<<" and "<<collider->getTag()<<std::endl;
}
