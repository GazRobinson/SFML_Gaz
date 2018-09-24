#include "GSprite.h"



GSprite::GSprite()
{
	
}


GSprite::~GSprite()
{
}

void GSprite::Update(float dt)
{
}

void GSprite::SetVelocity(sf::Vector2f vel)
{
	velocity = vel;
}

void GSprite::SetVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

sf::Vector2f GSprite::GetVelocity()
{
	return velocity;
}

void GSprite::CollisionResponse(GSprite * sp)
{
}

Line GSprite::GetEdge(int edge)
{
	switch (edge) {
	case 0:
		return Line(sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top), sf::Vector2f(GetCollisionBox().left + GetCollisionBox().width, GetCollisionBox().top));
		break;
	case 1:
		return Line(sf::Vector2f(GetCollisionBox().left + GetCollisionBox().width, GetCollisionBox().top), sf::Vector2f(GetCollisionBox().left + GetCollisionBox().width, GetCollisionBox().top + GetCollisionBox().height));
		break;
	case 2:
		return Line(sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top + GetCollisionBox().height), sf::Vector2f(GetCollisionBox().left + GetCollisionBox().width, GetCollisionBox().top + GetCollisionBox().height));
		break;
	case 3:
		return Line(sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top), sf::Vector2f(GetCollisionBox().left, GetCollisionBox().top + GetCollisionBox().height));
		break;
	}
}
