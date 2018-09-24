#include "MapTile.h"



MapTile::MapTile()
{
}


MapTile::~MapTile()
{
}

Line MapTile::GetEdge(Edge edge)
{
	switch (edge) {
		case Edge::UP:
			return Line(sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top), sf::Vector2f(GetCollisionBox().left + GetCollisionBox().width, GetCollisionBox().top));
			break;
		case Edge::RIGHT:
			return Line(sf::Vector2f(GetCollisionBox().left + GetCollisionBox().width, GetCollisionBox().top), sf::Vector2f(GetCollisionBox().left + GetCollisionBox().width, GetCollisionBox().top + GetCollisionBox().height));
			break;
		case Edge::DOWN:
			return Line(sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top + GetCollisionBox().height), sf::Vector2f(GetCollisionBox().left + GetCollisionBox().width, GetCollisionBox().top + GetCollisionBox().height));
			break;
		case Edge::LEFT:
			return Line(sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top), sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top + GetCollisionBox().height));
			break;
		}
}
