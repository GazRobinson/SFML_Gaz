#pragma once
#include "GSprite.h"
#include "Animation.h"
#include "structs.h"
#include "MapTile.h"
#include "Collision.h"
#include <array>

class PlayerInput;

class Player : public GSprite 
{
public:
	Player();
	~Player();
	

	void Update(float dt, std::vector<MapTile>* world, PlayerInput currentInput, bool isActive);
	void CollisionResponse(GSprite* sp, sf::Vector2f Overlap);
	void SetPosition(sf::Vector2f pos);Line groundSensor;
	Line headSensor;
	Line forwardSensor;
	bool active = false;
	void ForceJump(float f);
	void SaveLast();

private:
	Animation* currentAnimation;
	Animation idle;
	Animation walk;
	Animation jump;


	float bufferT		= 0.0f;
	bool facingRight	= true;
	bool isGrounded		= false;
	bool wasGrounded	= false;
};

