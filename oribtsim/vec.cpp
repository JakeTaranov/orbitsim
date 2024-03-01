#include "vec.h"
#include <math.h> 
#include <iostream>

Vec::Vec()
{
	this->x = 0;
	this->y = 0;
}

Vec::Vec(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vec::print()
{
	std::cout << "x: " << x << "y: " << y << std::endl;
}


Vec Vec::sum(Vec other)
{
	return Vec((other.x + x), (other.y + y));
}

Vec Vec::subtract(Vec other)
{
	return Vec((other.x - x), (other.y - y));
}

void Vec::multiplty_scalar(float value)
{
	x = x * value;
	y = y * value;
}

void Vec::normalize()
{
	x = x / get_magnitude();
	y = y / get_magnitude();
}

float Vec::get_angle()
{
	return atan2(y, x);
}

float Vec::get_magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Vec::get_x()
{
	return x;
}

float Vec::get_y()
{
	return y;
}

void Vec::add_to_x(float val)
{
	x += val;
}

void Vec::add_to_y(float val)
{
	y += val;
}


void Vec::set_x(float new_x)
{
	x = new_x;
}

void Vec::set_y(float new_y)
{
	y = new_y;
}

void Vec::reset(float new_x, float new_y)
{
	x = new_x;
	y = new_y;
}
