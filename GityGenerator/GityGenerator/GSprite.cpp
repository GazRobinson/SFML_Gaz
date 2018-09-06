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
