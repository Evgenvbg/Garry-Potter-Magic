#pragma once

#include <SFML/Graphics.hpp>
#include "list"
#include "Fire.h"
using namespace sf;

class Game
{
	RenderWindow* win;
	std::list <Fire*> fire;

	

public:
	Game();
	void start();
	~Game();

};

