#include "TileMap.h"



TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

void TileMap::LoadTexture(const char* filename) {
	texture.loadFromFile(filename);
}
void TileMap::SetTileSet(std::vector<MapTile> ts) {
	tileSet = ts;
}
void TileMap::SetTileMap(std::vector<int> tm, sf::Vector2u mapDimensions) {
	tileMap = tm;
	mapSize = mapDimensions;
}
void TileMap::BuildLevel() {
	if (tileSet.size() > 0 && tileMap.size() > 0)
	{
		int x, y = 0;
		sf::Vector2f tileSize(tileSet[0].getSize().x, tileSet[0].getSize().y);
		for (int i = 0; i < (int)tileMap.size(); i++)
		{
			x = i % mapSize.x;
			y = (int)floor(i / mapSize.x);
			tileSet[tileMap[i]].setPosition(position.x + (x * tileSize.x), position.y + (y *
				tileSize.y));
			level.push_back(tileSet[tileMap[i]]);
			level[i].setTexture(&texture);
		}

		for (int i = 0; i < (int)tileMap.size(); i++)
		{
			if (tileMap[i] > 0) {
				x = i % mapSize.x;
				y = (int)floor(i / mapSize.x);

				MapTile::EdgeType u , d, l, r;
				u = d = l = r = MapTile::EdgeType::OFF;
				if (i - 1 >= 0 && tileMap[i - 1] < 1)
					l = MapTile::EdgeType::SOLID;
				if (i + 1 < level.size() && tileMap[i + 1] < 1)
					r = MapTile::EdgeType::SOLID;

				int p = i - mapSize.x;
				if (p >= 0 && tileMap[p] < 1) {
						u = MapTile::EdgeType::SOLID;
				}
				p = i + mapSize.x;
				if (p < level.size() && tileMap[p] < 1) {
					d = MapTile::EdgeType::SOLID;
				}

				level[i].SetEdges(u, d, l, r);
			}
		}
	}

}

void TileMap::Render(sf::RenderWindow* window) {
	for (int i = 0; i < (int)level.size(); i++) {
		window->draw(level[i]);
	}
}