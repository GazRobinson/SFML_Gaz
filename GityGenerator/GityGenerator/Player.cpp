#include "Player.h"



Player::Player():
	groundSensor(),
	headSensor(),
	forwardSensor()
{
	//Idle
	idle.AddFrame(sf::IntRect(0, 0, 32, 32));
	
	//Walk
	walk.AddFrame(sf::IntRect(32, 0, 32, 32));
	walk.AddFrame(sf::IntRect(64, 0, 32, 32));
	walk.AddFrame(sf::IntRect(92, 0, 32, 32));
	walk.AddFrame(sf::IntRect(64, 0, 32, 32));
	walk.SetAnimationType(Animation::AnimationType::Loop);
	walk.SetFrameSpeed(0.096f);
	
	//Jump
	jump.AddFrame(sf::IntRect(32, 32, 32, 32));
	jump.AddFrame(sf::IntRect(64, 32, 32, 32));
	jump.SetAnimationType(Animation::AnimationType::Once);
	jump.SetFrameSpeed(0.5f);

	currentAnimation = &idle;
}


Player::~Player()
{
}

void Player::Update(float dt, std::vector<MapTile>* world, PlayerInput currentInput, bool isActive) {
	active = isActive;
	isGrounded = false;
	if (useGravity && !wasGrounded) {
		velocity.y += 200.0f * dt;
	}
	if (currentInput.direction.x != 0) {
		if(wasGrounded)
			currentAnimation = &walk;
		if (currentInput.direction.x > 0) {
			facingRight = true;
		}
		else if (currentInput.direction.x < 0) {
			facingRight = false;
		}
	}
	else
	{
		if(wasGrounded)
			currentAnimation = &idle;
	}
	if(wasGrounded)
	velocity.x = currentInput.direction.x * 75.0f;
	
	currentAnimation->SetFlipped(facingRight);

	currentAnimation->Animate(dt);
	setTextureRect(currentAnimation->GetCurrentFrame());
	
	sf::Vector2f waist(GetColCenter() + sf::Vector2f(0.0f, collisionBox.height*0.25f));

	groundSensor	= Line(GetColCenter(), GetColCenter() + sf::Vector2f(0.0f, GetCollisionBox().height*0.5f));
	headSensor		= Line(GetColCenter(), GetColCenter() + sf::Vector2f(0.0f, -GetCollisionBox().height*0.5f));
	if(wasGrounded)
		forwardSensor	= Line(waist, waist + sf::Vector2f((facingRight?1.0f:-1.0f)*GetCollisionBox().width*0.5f, 0.0f));
	else
		forwardSensor = Line(GetColCenter(), GetColCenter() + sf::Vector2f((facingRight ? 1.0f : -1.0f)*GetCollisionBox().width*0.5f, 0.0f));
	
	for (int i = 0; i < (int)world->size(); i++)
	{
		if ((*world)[i].IsCollider())
		{
			HitInfo info;
			if (Collision::LineMapIntersect(&(*world)[i], groundSensor, info)) {
				isGrounded = true;
				if (velocity.y > 0) {
					velocity.y = 0;
					setPosition(info.point - groundSensor.Vector() - (GetColCenter() - getPosition()));
				}
			}
			if (Collision::LineMapIntersect(&(*world)[i], headSensor, info)) {				
				if (velocity.y < 0) {
					velocity.y = 0;
					setPosition(info.point - headSensor.Vector() - (GetColCenter() - getPosition()));
				}
			}
			if (Collision::LineMapIntersect(&(*world)[i], forwardSensor)) {
				velocity.x = 0;
			}
		}
	}
	if (isGrounded) {
		if (currentInput.jump) {
			wasGrounded = false;
			isGrounded = false;
			velocity.y = -150.0f;
			currentAnimation = &jump;
			currentAnimation->Reset();
		}
	}

	move(velocity * dt);

	wasGrounded = isGrounded;

}

void Player::SaveLast() {
	lastPosition = getPosition();

}

void Player::CollisionResponse(GSprite * sp, sf::Vector2f Overlap)
{
	//Side col
	if ( abs(Overlap.y) > abs(Overlap.x)) {
		//velocity.x = 0;
		setPosition(getPosition().x - Overlap.x, getPosition().y);
	}
	else {
		if (getPosition().y < sp->getPosition().y) {
			setPosition(getPosition().x, getPosition().y - Overlap.y);
			velocity.y = 0;
			isGrounded = true;
		}
	}
}

void Player::SetPosition(sf::Vector2f pos)
{
	setPosition(pos);
}

void Player::ForceJump(float f)
{
	velocity.y = f;
	isGrounded = false;
}
