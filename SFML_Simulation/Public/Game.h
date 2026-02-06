#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
//For Variables

public:
//avoid using public variables use getter setters for private variables instead

protected:

private:
	sf::RenderWindow Window;
	sf::Clock Clock;
	bool HasStarted = false;



//For Functions
public:

	//constructor
	Game();

	//virtual destructor
	//virtual because its going to have polymorphysm
	virtual ~Game();

	//Main Loop
	void Run();

protected:


private:

	void Start();
	void Update(sf::Time DeltaTime);
	void Render();
	void ProcessEvents();

};

