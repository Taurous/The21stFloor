#pragma once
#include <cmath>

class vec2
{
public:
	vec2() : x(0.f), y(0.f) { }
	vec2(double x, double y) : x(x), y(y) { }
	~vec2() { }

	vec2 operator+(const vec2 &other) { return vec2(this->x + other.x, this->y + other.y); }
	vec2& operator+=(const vec2 &rhs) { x += rhs.x; y += rhs.y; return *this; }

	vec2 operator-(const vec2 &other) { return vec2(this->x - other.x, this->y - other.y); }
	vec2& operator-=(const vec2 &rhs) { x -= rhs.x; y -= rhs.y; return *this; }

	vec2 operator*(const vec2 &other) { return vec2(this->x * other.x, this->y * other.y); }
	vec2& operator*=(const vec2 &rhs) { x *= rhs.x; y *= rhs.y; return *this; }

	vec2 operator/(const vec2 &other) { return vec2(this->x / other.x, this->y / other.y); }
	vec2& operator/=(const vec2 &rhs) { x /= rhs.x; y /= rhs.y; return *this; }

	vec2 operator/(double scalar) { return vec2(this->x / scalar, this->y / scalar); }
	vec2& operator/=(double scalar) { x /= scalar; y /= scalar; return *this; }
	vec2 operator*(double scalar) { return vec2(this->x * scalar, this->y * scalar); }
	vec2& operator*=(double scalar) { x += scalar; y += scalar; return *this; }

	double dot(const vec2 &other) { return (this->x * other.x) + (this->y * other.y); }
	double cross(const vec2 &other) { return (this->x * other.y) - (this->y * other.x); }

	double length() { return sqrtf((x * x) + (y * y)); }
	double squaredLength() { return (x*x) + (y*y); }
	double unit() { *this / length(); }
	double angle() { return atan2f(x, y); }

	vec2 turnRight() { return vec2(x, -y); }
	vec2 turnLeft() { return vec2(-x, y); }

	vec2 rotate(double angle) { return vec2(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle)); }

	double x;
	double y;
};

