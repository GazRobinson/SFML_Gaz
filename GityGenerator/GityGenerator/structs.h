#pragma once
#include <SFML/Graphics.hpp>
struct Ray
{
public:
	sf::Vector2f startPoint;
	sf::Vector2f direction;
	float length;
	sf::Vector2f GetEndPoint() { return startPoint + (direction * length); };
};

struct Line
{
public:
	Line() {
		startPoint	= sf::Vector2f(0, 0);
		endPoint	= sf::Vector2f(1, 1);
	}
	Line(sf::Vector2f start, sf::Vector2f end) {
		startPoint = start;
		endPoint = end;
	}
	sf::Vector2f startPoint;
	sf::Vector2f endPoint;
	sf::Vector2f Vector() {
		return endPoint - startPoint;
	}
};

struct HitInfo
{
	HitInfo() {
		point = sf::Vector2f(0, 0);
	}
	sf::Vector2f point;
};

struct PlayerInput {
	PlayerInput() {
		direction = sf::Vector2f(0, 0);
		jump = false;
	}
	sf::Vector2f direction;
	bool jump;
};