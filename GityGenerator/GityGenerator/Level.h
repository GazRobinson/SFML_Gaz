#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "Player.h"

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

	//Level variables
	sf::RectangleShape rect;
	sf::CircleShape circle;
	sf::Color squareColor;
	
	//Test Sprite
	Player gSprite;
	sf::Texture gSpriteTex;

};

