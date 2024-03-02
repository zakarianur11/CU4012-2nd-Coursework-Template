#pragma once


#include <SFML/Graphics.hpp>

class UICollisionBox 
{
    sf::FloatRect collisionBox;
    sf::RectangleShape debugShape;

    void updateDebugShape() {
        debugShape.setPosition(collisionBox.left, collisionBox.top);
        debugShape.setSize(sf::Vector2f(collisionBox.width, collisionBox.height));
    }
public:
    UICollisionBox() {
        debugShape.setFillColor(sf::Color::Transparent);
        debugShape.setOutlineColor(sf::Color::Red);
        debugShape.setOutlineThickness(1.0f);
    }

    void setCollisionBox(const sf::FloatRect& newBox) {
        collisionBox = newBox;
        updateDebugShape();
    }

    sf::FloatRect getCollisionBox() const {
        return collisionBox;
    }

    sf::RectangleShape getDebugShape() { return debugShape; }
};