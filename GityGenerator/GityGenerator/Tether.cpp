#include "Tether.h"



Tether::Tether(GSprite* a, GSprite* s)
{
	anchor = a;
	swing = s;
}


Tether::~Tether()
{
}

void Tether::Update(float dt)
{
	sf::Vector2f dist = swing->getPosition() - anchor->getPosition();
	float l = Length(dist);
	if (l > tetherLength) {
		sf::Vector2f pos = Normalise(dist) * tetherLength;
		swing->setPosition(anchor->getPosition() + pos);
		swing->SetVelocity((swing->getPosition() - swing->GetLastPosition()) / dt);
		//constrain
	}
}
