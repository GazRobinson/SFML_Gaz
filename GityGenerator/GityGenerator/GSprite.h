#pragma once

#include <SFML\Graphics.hpp>
#include "Input.h"
#include "structs.h"

class GSprite : public sf::RectangleShape
{
public:
	GSprite();
	~GSprite();

	virtual void Update(float dt);

	sf::Vector2f GetLastPosition() { return lastPosition; };

	void SetVelocity(sf::Vector2f vel);
	void SetVelocity(float vx, float vy);
	sf::Vector2f GetVelocity();

	void SetCollider(bool colliderActive) { collider = colliderActive; };
	void SetCollisionBox(float x, float y, float w, float h) { SetCollisionBox(sf::FloatRect(x, y, w, h)); };
	void SetCollisionBox(sf::FloatRect newSize) { collisionBox = newSize; };
	sf::FloatRect GetCollisionBox() { 
		return sf::FloatRect(collisionBox.left + getPosition().x, collisionBox.top + getPosition().y, collisionBox.width, collisionBox.height);
	};
	bool IsCollider() { return collider; };
	virtual void CollisionResponse(GSprite* sp);

	void SetInput(Input* in) { input = in; };
	Line GetEdge(int edge);

	void SetGravity(bool active) { useGravity = active; };

protected:
	sf::Vector2f lastPosition;

	sf::Vector2f velocity;
	bool active;

	sf::FloatRect collisionBox;
	bool collider;

	bool useGravity = true;

	Input* input;

	sf::Vector2f GetCenter() { return getPosition(); };
	sf::Vector2f GetColCenter() { return  sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top) + sf::Vector2f(GetCollisionBox().width*0.5f, GetCollisionBox().height * 0.5f); };
};

