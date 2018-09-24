#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "PlayerController.h"
#include "Player.h"
#include "TileMap.h"
#include "MapTile.h"
#include "Collision.h"

class Level
{
public:
	Level(sf::RenderWindow* hwnd, Input* hinput);
	~Level();

	void HandleInput();
	void Update(float dt);
	void Render();

private:
	sf::RenderWindow* window;
	Input* input;
	void BeginDraw();
	void EndDraw();
		
	//Test Sprite
	PlayerController pController;
	Player gSprite;
	Player gSprite2;
	sf::Texture gSpriteTex;
	sf::Texture gSpriteTex2;
	Line a;
	Line b;

	//Map
	TileMap tileMap;
};

