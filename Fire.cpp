#include "Fire.h"



Fire::Fire(int w, int h, Vector2f _motion)
{
	fire = new RectangleShape(Vector2f(140, 140));
	motion = _motion;
	fire->setPosition(w, h);
	fire->setFillColor(Color::Magenta);
}

void Fire::update()
{
	fire->move(motion);
}

void Fire::drow(RenderWindow* win)
{
	win->draw(*fire);
}
