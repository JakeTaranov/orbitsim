#include "vec.h"
#include <math.h> 
#include <iostream>
using namespace std;

vec::vec()
{
	this->x = 0;
	this->y = 0;
}

vec::vec(float x, float y)
{
	this->x = x;
	this->y = y;
}

void vec::print()
{
	cout << "x: " << x << "y: " << y << endl;
}


vec vec::sum(vec other)
{
	return vec((other.x + x), (other.y + y));
}

vec vec::subtract(vec other)
{
	return vec((other.x - x), (other.y - y));
}

void vec::multiplty_scalar(float value)
{
	x = x * value;
	y = y * value;
}

void vec::normalize()
{
	x = x / get_magnitude();
	y = y / get_magnitude();
}

float vec::getAngle()
{
	return atan2(y, x);
}

float vec::get_magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float vec::get_x()
{
	return x;
}

float vec::get_y()
{
	return y;
}

void vec::add_to_x(float val)
{
	x += val;
}

void vec::add_to_y(float val)
{
	y += val;
}


void vec::set_x(float new_x)
{
	x = new_x;
}

void vec::set_y(float new_y)
{
	y = new_y;
}

void vec::reset(float new_x, float new_y)
{
	x = new_x;
	y = new_y;
}
