#include "PlayerController.h"
#include "Input.h"
#include "Collision.h"
#include <SFML\Graphics.hpp>

PlayerController::PlayerController():
	tether(NULL)
{
	Popo = Nana = active = sub = NULL;
}


PlayerController::~PlayerController()
{
}

void PlayerController::Update(float dt, std::vector<MapTile>* world, Input* input)
{
	if (active != NULL && sub != NULL) {
		active->SaveLast();
		sub->SaveLast();
		currentInput.direction = input->GetInput();
		currentInput.jump = input->GetKeyDown(sf::Keyboard::Space);
		if (input->GetKeyDown(sf::Keyboard::LControl)) {
			Throw();
		}
		if (input->GetKeyDown(sf::Keyboard::LShift)) {
			if (tether == NULL) {
				tether = new Tether(active, sub);
				active->SetGravity(false);
				active->SetVelocity(0.0f, 0.0f);
				Player* temp = active;
				active = sub;
				sub = temp;
			}
			else {
				delete(tether);
				active->SetGravity(true);
				tether = NULL;
			}
		}
		active->Update(dt, world, currentInput, true);
		sub->Update(dt, world, positionBuffer[positionBuffer.size() - 1], false);
		if (tether != NULL) {
			tether->Update(dt);
		}

		for (int i = positionBuffer.size() - 1; i > 0; i--) {
			positionBuffer[i] = positionBuffer[i - 1];
		}
		positionBuffer[0] = currentInput;
	}
}

void PlayerController::Throw() {
	sf::Vector2f vec = sub->getPosition() - active->getPosition();
	if (((vec.x * vec.x) + (vec.y * vec.y)) < (32.0f*32.0f)) {
		sub->setPosition(active->getPosition());
		sub->ForceJump(-100.0f);
		//active->setPosition(sub->getPosition() + vec);
		Player* temp = sub;
		sub = active;
		active = temp;
		temp = NULL;
	}
}