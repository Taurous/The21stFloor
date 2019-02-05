#pragma once

#include "vector.h"

class rect
{
public:
	rect(float x, float y, float w, float h);
	~rect();

	vector2f calculateCenter();
	void draw();
	void rotate(float angle, int point = rect::CENTER);
	void rotate(float angle, vector2f point);

	enum
	{
		CENTER,
		TOPLEFT,
		TOPRIGHT,
		BOTTOMLEFT,
		BOTTOMRIGHT
	};

private:
	vector2f topLeft;
	vector2f topRight;
	vector2f botLeft;
	vector2f botRight;
};

