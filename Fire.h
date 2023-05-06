#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Fire
{
	RectangleShape* fire;
	Texture texture;

	Vector2f motion;



public:
	Fire(int w, int h, Vector2f _motion);
	void update();
	

	void drow(RenderWindow* win);

};

