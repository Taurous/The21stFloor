#include "rect.h"

#include <cstdio>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

rect::rect(float x, float y, float w, float h) :
	topLeft(x, y),
	topRight(x + w, y),
	botLeft(x, y + h),
	botRight(x + w, y + h)
{

}

rect::~rect()
{
}

vector2f rect::calculateCenter()
{
	vector2f diag = (topRight - topLeft) + (botRight - topRight);
	diag /= 2.f;

	//printf("diag.x = %.2f\ndiag.y = %.2f\n", diag.x, diag.y);

	//printf("topRight.x (%.2f) - botRight.x (%.2f) = %.2f\n", topRight.x, botRight.x, (topRight - botRight).x);
	//printf("topRight.y (%.2f) - botRight.y (%.2f) = %.2f\n", topRight.y, botRight.y, (topRight - botRight).y);

	return diag + topLeft;
}

void rect::draw()
{
	ALLEGRO_COLOR c = al_map_rgb(255, 0, 0);
	al_draw_line(topLeft.x, topLeft.y, topRight.x, topRight.y, c, 1);
	al_draw_line(topLeft.x, topLeft.y, botLeft.x, botLeft.y, c, 1);
	al_draw_line(botLeft.x, botLeft.y, botRight.x, botRight.y, c, 1);
	al_draw_line(topRight.x, topRight.y, botRight.x, botRight.y, c, 1);

	vector2f center = calculateCenter();

	al_draw_filled_circle(center.x, center.y, 2, c);
}

void rect::rotate(float angle, int point)
{
	switch (point)
	{
	case CENTER:
		rotate(angle, calculateCenter());
		break;
	case TOPLEFT:
		rotate(angle, topLeft);
		break;
	case TOPRIGHT:
		rotate(angle, topRight);
		break;
	case BOTTOMLEFT:
		rotate(angle, botLeft);
		break;
	case BOTTOMRIGHT:
		rotate(angle, botRight);
		break;
	default:
		rotate(angle, calculateCenter());
		break;
	}
}

void rect::rotate(float angle, vector2f rotation_point)
{
	topLeft = (topLeft - rotation_point).rotate(angle) + rotation_point;
	topRight = (topRight - rotation_point).rotate(angle) + rotation_point;
	botLeft = (botLeft - rotation_point).rotate(angle) + rotation_point;
	botRight = (botRight - rotation_point).rotate(angle) + rotation_point;
}