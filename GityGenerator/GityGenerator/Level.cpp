#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* hinput):
a(sf::Vector2f(0, 0), sf::Vector2f(100, 100)),
b(sf::Vector2f(0, 0), sf::Vector2f(100, 100))
{
	window = hwnd;
	input = hinput;
	//Player1
	gSpriteTex.loadFromFile("Images/IceClimber.png");
	gSprite.setTexture(&gSpriteTex);
	gSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	gSprite.setSize(sf::Vector2f(32, 32));
	gSprite.setPosition(128, 120);
	gSprite.SetInput(hinput);
	gSprite.SetCollisionBox(11, 11, 10, 21);
	//Player2
	gSpriteTex2.loadFromFile("Images/IceClimber1.png");
	gSprite2.setTexture(&gSpriteTex2);
	gSprite2.setTextureRect(sf::IntRect(0, 0, 32, 32));
	gSprite2.setSize(sf::Vector2f(32, 32));
	gSprite2.setPosition(128, 120);
	gSprite2.SetInput(hinput);
	gSprite2.SetCollisionBox(11, 11, 10, 21);

	pController.SetPlayers(&gSprite, &gSprite2);

	tileMap.LoadTexture("Images/IceClimberLevel.png");

	MapTile tile;
	std::vector<MapTile> tiles;
	for (int i = 0; i < 5; i++)
	{
		tile.setSize(sf::Vector2f(8, 8));
		tile.SetCollisionBox(0.0f, 0.0f, 8.0f, 8.0f);
		tile.SetCollider(true);
		tiles.push_back(tile);
	}
	//blank tile
	tiles[0].setTextureRect(sf::IntRect(0, 0, 8, 8));
	tiles[0].SetCollider(false);

	tiles[1].setTextureRect(sf::IntRect(8, 0, 8, 8));
	tiles[2].setTextureRect(sf::IntRect(0, 8, 8, 8));
	tiles[3].setTextureRect(sf::IntRect(8, 8, 8, 8));
	tiles[4].setTextureRect(sf::IntRect(16, 8, 8, 8));

	tileMap.SetTileSet(tiles);

	//Map dimensions
	sf::Vector2u mapSize(32, 30);
	//build map
	std::vector<int> map = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
		1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};

	tileMap.SetTileMap(map, mapSize);
	tileMap.BuildLevel();
	
}


Level::~Level()
{
}

void Level::HandleInput() {

}

void Level::Update(float dt) {

	b = Line(sf::Vector2f(40, 150), sf::Vector2f(input->GetMouseX(), input->GetMouseY()));
	if (Collision::LineSpriteIntersect(&gSprite, b)) {

		printf("Cool!\n");
	}
	if (Collision::LineIntersect(a, b)) {
		printf("Wow!\n");
	}
	std::vector<MapTile>* world = tileMap.GetLevel();
	pController.Update(dt, world, input);

	for (int i = 0; i < (int)world->size(); i++)
	{
		// if collision check should occur
		if ((*world)[i].IsCollider())
		{
			if (Collision::LineMapIntersect(&(*world)[i], b)) {

				printf("Cool!");
			}
			/*if (Collision::CheckBoundingBox(&gSprite, &(*world)[i]))
			{
				gSprite.CollisionResponse(&(*world)[i], Collision::CheckBoundingBoxOverlap(&gSprite, &(*world)[i]));
			}*/
		}
	}

}

void Level::Render() {
	tileMap.Render(window);
	window->draw(gSprite);
	window->draw(gSprite2);
	
	sf::RectangleShape linea;
	linea.setPosition(sf::Vector2f(gSprite.forwardSensor.startPoint.x-2.0f, gSprite.forwardSensor.startPoint.y - 2.0f));
	linea.setSize( sf::Vector2f(gSprite.forwardSensor.endPoint.x - gSprite.forwardSensor.startPoint.x +2.0f, gSprite.forwardSensor.endPoint.y- gSprite.forwardSensor.startPoint.y+2.0f));
	linea.setFillColor(sf::Color::Red);

	sf::Vertex lineb[] =
	{
		sf::Vertex(b.startPoint),
		sf::Vertex(b.endPoint)
	};
	window->draw(linea);
	window->draw(lineb, 2, sf::Lines);
}

void Level::BeginDraw() {
	window->clear(sf::Color::Black);
}

void Level::EndDraw() {
	window->display();
}
