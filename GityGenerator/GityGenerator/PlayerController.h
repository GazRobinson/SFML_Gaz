#pragma once
#include "Player.h"
#include "structs.h"
#include "Tether.h"
class PlayerController
{
public:
	PlayerController();
	~PlayerController();

	void Update(float dt, std::vector<MapTile>* world, Input* input);
	void SetPlayers(Player* popo, Player* nana) { 
		Popo = popo; Nana = nana; 
		active = Popo; 
		sub = Nana;	}
	/*void SetCurrentInput(PlayerInput pInput);
	PlayerInput GetInput() { return currentInput; };
	PlayerInput GetLastInput() { return positionBuffer[positionBuffer.size() - 1]; };*/


private:
	Player * active;
	Player * sub;
	Player* Popo;
	Player* Nana;

	Tether* tether;

	std::array<PlayerInput, 60> positionBuffer{ PlayerInput() };
	PlayerInput currentInput;

	void Throw();
};

