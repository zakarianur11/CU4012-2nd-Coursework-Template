#pragma once
#include "GameObject.h"
class Tiles :
    public GameObject
{
    bool editing; // To track editing mode
    bool addedToWorld = false;
    float rotationSpeed = 100.0f; // This is the rotation speed in degrees per second.

public:
    Tiles();

    void handleInput(float dt) override;
    void update(float dt) override;
    void markAddedToWorld() { addedToWorld = true; }

    bool isAddedToWorld() const {
        return addedToWorld;
    }

    bool isEditing() {
		return editing;
	}
};

