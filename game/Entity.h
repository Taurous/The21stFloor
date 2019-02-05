#pragma once

#include "vec2.h"

struct Entity
{
	vec2 pos;
	vec2 speed;
	vec2 accel;
	float angle;
	bool alive;
	float alpha;
};