# CU4012-2nd-Coursework-Template

 I have added a basic Physics Engine which handles collisions for us, to check if you are colliding with something, just use the CompareWithTag("Name of the object you wanna compare")
 For example you wanna check if player is colliding with enemy 
 
```c++
  void Level::update(float dt)
{
	if(p1.CollisionWithTag("Enemy"))
	{ 
		//Decrease player health 
	}
}
```

 To make ground or objects that shouldn't be affected by gravity you can turn on isStatic when initialising the constructor 
 for example you create a class called Ground that is derived from GameObject 
 inside the constructor 
 
 ```c++
    Ground::Ground()
{
	setPosition(100, 500);
	setSize(sf::Vector2f(1000, 100));
	setOrigin(getSize() / 2.f);
	setCollisionBox(getPosition(), getSize());
	setTag("Ground");
	setStatic(true);
} 
```

For making dynamic objects which move you have to set a mass 

```c++

  Player::Player()
{
	if (!texture.loadFromFile("gfx/Mushroom.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	
	setCollisionBox(getPosition(), getSize());
	setMass(100.f);
	setTag("Player");
}
```
## Things to add
 -Trigger collisions boxes: which detects collision but aren't blocking objects
 -Improve collision detection from AABB to SAT(more complex)
 

