#include <Windows.h>
#include <tchar.h>
#include <SFML\Graphics.hpp>

#include "Level.h"
#include "Input.h"

int WinMain( HINSTANCE hInstance,
	 HINSTANCE hPrevInstance,
	 LPSTR     lpCmdLine,
	 int       nCmdShow) {


	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Input input;
	Level level(&window, &input);

	//Delta time calculation
	sf::Clock clock;
	float deltaTime;

	while (window.isOpen())
	{
		//Reset the clock
		deltaTime = clock.restart().asSeconds();

		//Reset the Input and log the last tick's input
		input.Update();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					else
						input.SetKeyDown(event.key.code);
					break;

				case sf::Event::KeyReleased:
						input.SetKeyUp(event.key.code);
					break;
				case sf::Event::MouseMoved:
					input.SetMousePosition(event.mouseMove.x, event.mouseMove.y);
					break;
				case sf::Event::MouseButtonPressed:
					input.SetMouseButtonDown(event.mouseButton.button);
					break;
				case sf::Event::MouseButtonReleased:
					input.SetMouseButtonUp(event.mouseButton.button);
					break;
			}
		}
		
		level.HandleInput();
		level.Update(deltaTime);
		level.Render();
	}

	return 0;
}