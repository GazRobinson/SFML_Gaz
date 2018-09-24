#pragma once
#include "GSprite.h"
#include <SFML\Graphics.hpp>
#include <math.h>
class Tether
{
public:
	Tether(GSprite* a, GSprite* s);
	~Tether();
	void Update(float dt);

private:
	GSprite * anchor, *swing;
	float tetherLength = 32.0f;

	float Length(sf::Vector2f vec) {
		return sqrtf((vec.x * vec.x) + (vec.y * vec.y));
	}
	sf::Vector2f Normalise(sf::Vector2f vec) {
		float l = Length(vec);
		return vec / l;
	}
};

