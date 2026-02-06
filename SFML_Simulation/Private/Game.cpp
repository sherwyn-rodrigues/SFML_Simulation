#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game()
	: Window(sf::VideoMode({ 800, 800 }), "SFML Window")
{
	Window.setFramerateLimit(30);
}

Game::~Game()
{
}

void Game::Run()
{
	while (Window.isOpen())
	{
		if (!HasStarted)
		{
			Start();
			HasStarted = true;
		}

		sf::Time deltaTime = Clock.restart();

		ProcessEvents();
		Update(deltaTime);
		Render();
	}
}

void Game::Start()
{

}

void Game::Update(sf::Time DeltaTime)
{

}

void Game::ProcessEvents()
{

}

void Game::Render()
{
	Window.clear(sf::Color::Black);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Window.draw(shape);
	Window.display();

}