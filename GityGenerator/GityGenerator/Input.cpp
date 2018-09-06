#include "Input.h"



Input::Input()
{
}


Input::~Input()
{
}

void Input::SetKeyDown(int key) {
	keys[key] = true;
}

void Input::SetKeyUp(int key) {
	keys[key] = false;
}

bool Input::GetKeyDown(int key) {
	return !lastKeys[key] && keys[key];
}

bool Input::GetKeyUp(int key) {
	return lastKeys[key] && !keys[key];
}

bool Input::GetKey(int key) {
	return keys[key];
}

void Input::SetMouseX(int lx) {
	mouse.x = lx;
}

void Input::SetMouseY(int ly) {
	mouse.y = ly;
}

void Input::SetMousePosition(int lx, int ly) {
	mouse.x = lx; mouse.y = ly;
}

void Input::SetMouseButtonDown(int button) {
	mouse.buttons[button] = true;
}

void Input::SetMouseButtonUp(int button) {
	mouse.buttons[button] = false;
}

bool Input::GetMouseButton(int button) {
	return mouse.buttons[button];
}

bool Input::GetMouseButtonDown(int button) {
	return !mouse.lastButtons[button] && mouse.buttons[button];
}

bool Input::GetMouseButtonUp(int button) {
	return mouse.lastButtons[button] && !mouse.buttons[button];
}

int Input::GetMouseX() {
	return mouse.x;
}

int Input::GetMouseY() {
	return mouse.y;
}

sf::Vector2f Input::GetInput()
{
	sf::Vector2f input = sf::Vector2f(0, 0);
	input.x += GetKey(sf::Keyboard::A) ? -1 : 0;
	input.x += GetKey(sf::Keyboard::D) ? 1 : 0;

	input.y += GetKey(sf::Keyboard::W) ? 1 : 0;
	input.y += GetKey(sf::Keyboard::S) ? -1 : 0;
	return input;
}

void Input::Update() {
	lastKeys = keys;
	mouse.lastButtons = mouse.buttons;
}