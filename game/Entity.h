#pragma once

#include "vec2.h"

struct Entity
{
	vec2 pos; // 16
	vec2 speed; // 16
	vec2 accel; // 16
	float angle; // 4
	float alpha; // 4
	bool alive; // 1
};