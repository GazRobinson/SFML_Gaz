#pragma once
#include "GSprite.h"
#include "Animation.h"
class Player : public GSprite 
{
public:
	Player();
	~Player();

	void Update(float dt);

private:
	Animation* currentAnimation;
	Animation idle;
	Animation walk;
	bool facingRight = true;
};

