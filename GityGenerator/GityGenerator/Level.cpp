#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* hinput)
{
	window = hwnd;
	input = hinput;

	squareColor = sf::Color::Red;

	rect.setSize(sf::Vector2f(50.f, 50.f));
	rect.setPosition(100, 100);
	rect.setFillColor(squareColor);

	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2.f);

	gSpriteTex.loadFromFile("Images/MegaMan.png");
	gSprite.setTexture(&gSpriteTex);
	gSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	gSprite.setSize(sf::Vector2f(32, 32));
	gSprite.setPosition(200, 200);
	gSprite.SetInput(hinput);
}


Level::~Level()
{
}

void Level::HandleInput() {

	if (input->GetMouseButtonDown(sf::Mouse::Left)) {
		squareColor = sf::Color::Green;
	}

	if (input->GetMouseButtonUp(sf::Mouse::Left)) {
		squareColor = sf::Color::Magenta;
	}
	if (input->GetMouseButton(sf::Mouse::Right)) {
		circle.setFillColor(sf::Color::Cyan);
	}
	else {
		circle.setFillColor(sf::Color::Red);
	}
	rect.setFillColor(squareColor);
}

void Level::Update(float dt) {
	//circle.setPosition(circle.getPosition() + sf::Vector2f(2.f, 2.f) * dt);
	gSprite.Update(dt);
}

void Level::Render() {
	BeginDraw();

	window->draw(rect);
	window->draw(circle);
	window->draw(gSprite);

	EndDraw();
}

void Level::BeginDraw() {
	window->clear(sf::Color::Black);
}

void Level::EndDraw() {
	window->display();
}
