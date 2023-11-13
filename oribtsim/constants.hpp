#pragma once

namespace Constants
{
	// screen constants 
	const int screen_height = 1000;
	const int screen_width = 1600;

	// physics constants 
	const float pi = 3.14159265f;
	const float G = 7;	// Gravitational Constant (not true to reality)
	const float dt = 0.05;	// Incremenet of time in simulation
	const int constrain_lower = 50;	// Lower limit for constraining distance of bodies
	const int constrain_upper = 1000; // Upper limit for constraining distance of bodies

}