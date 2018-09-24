#pragma once
#include <math.h>
#include "MapTile.h"

class TileMap
{
public:
	TileMap();
	~TileMap();

	void LoadTexture(const char* filename);
	void SetTileSet(std::vector<MapTile> ts);
	void SetTileMap(std::vector<int> tm, sf::Vector2u mapDimensions);
	void BuildLevel();

	void Render(sf::RenderWindow* window);
	std::vector<MapTile>* GetLevel() { return &level; };

	void SetPosition(sf::Vector2f pos) { position = pos; };

protected:
	std::vector<MapTile>	tileSet;
	std::vector<int>		tileMap;
	std::vector<MapTile>	level;
	sf::Texture				texture;
	sf::Vector2u			mapSize;
	sf::Vector2f			position;
};