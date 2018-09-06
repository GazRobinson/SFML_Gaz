#include "Player.h"



Player::Player()
{
	//Idle
	idle.AddFrame(sf::IntRect(0, 0, 32, 32));
	
	//Walk
	walk.AddFrame(sf::IntRect(96, 0, 32, 32));
	walk.AddFrame(sf::IntRect(128, 0, 32, 32));
	walk.AddFrame(sf::IntRect(160, 0, 32, 32));
	walk.AddFrame(sf::IntRect(128, 0, 32, 32));
	walk.SetFrameSpeed(0.128f);

	currentAnimation = &idle;
}


Player::~Player()
{
}

void Player::Update(float dt) {

	currentAnimation = &idle;

	sf::Vector2f Input = input->GetInput();

	if (Input.x != 0) {
		currentAnimation = &walk;
		if (Input.x > 0) {
			facingRight = true;
		}
		else if (Input.x < 0) {
			facingRight = false;
		}
	}
	currentAnimation->SetFlipped(facingRight);

	currentAnimation->Animate(dt);
	setTextureRect(currentAnimation->GetCurrentFrame());
	setOrigin(-6 * (facingRight ? 1 : -1), 0);
	SetVelocity(Input.x * 100.0f, 0.0f);

	move(velocity * dt);
}