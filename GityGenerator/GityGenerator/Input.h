#pragma once
#include <SFML/Graphics.hpp>
#include <array>
class Input
{
private:
	struct Mouse {
		int x, y;
		std::array<bool, 5> buttons{ false };
		std::array<bool, 5> lastButtons{ false };
	};

public:
	
	Input();
	~Input();

	//Keyboard
	void SetKeyDown(int key);
	void SetKeyUp(int key);
	bool GetKeyDown(int key);
	bool GetKeyUp(int key);
	bool GetKey(int key);

	//Mouse
	void SetMouseX(int lx);
	void SetMouseY(int ly);
	void SetMousePosition(int lx, int ly);
	void SetMouseButtonDown(int button);
	void SetMouseButtonUp(int button);
	int GetMouseX();
	int GetMouseY();
	bool GetMouseButtonDown(int button);
	bool GetMouseButtonUp(int button);
	bool GetMouseButton(int button);

	//Controls
	sf::Vector2f GetInput();

	void Update();

private:
	std::array<bool, 256> keys{ false };
	std::array<bool, 256> lastKeys{ false };

	Mouse mouse;
};

