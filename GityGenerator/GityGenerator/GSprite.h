#pragma once

#include <SFML\Graphics.hpp>
#include "Input.h"

class GSprite : public sf::RectangleShape
{
public:
	GSprite();
	~GSprite();

	virtual void Update(float dt);

	void SetVelocity(sf::Vector2f vel);
	void SetVelocity(float vx, float vy);
	sf::Vector2f GetVelocity();
	
	void SetInput(Input* in) { input = in; };

protected:
	sf::Vector2f velocity;
	bool active;

	sf::FloatRect collisionBox;

	Input* input;
};

