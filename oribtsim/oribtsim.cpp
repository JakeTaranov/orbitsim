#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Vec.h"
#include "Constants.hpp"
#include "Parser.h"
#include "json/json.h"
#include <fstream>
#include <time.h>

bool is_file_exist(const char* file_name)
{
	std::ifstream infile(file_name);
	return infile.good();
}


int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(Constants::screen_width, Constants::screen_height), "Orbit Simulation");
	window.setFramerateLimit(60);


	const char* file_name = argv[1];

	if (!is_file_exist(file_name))
	{
		std::cout << "FILE NOT FOUND - EXITING";
		exit(1);
	}

	Parser input_parser = Parser(file_name);
	Json::Value parsed_input = input_parser.parse();

	std::vector<Body> bodies;
	bodies = input_parser.genereate_bodies_vector(parsed_input, bodies);

	bool stay_in_bounds = parsed_input["stay_in_bounds"].asBool();

	// if there are no bodies defined in json file then exit
	if (bodies.size() == 0)
	{
		std::cout << "EXITING" << std::endl;
		exit(1);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}


		window.clear();


		/* iterate over each body, creating a list of all other bodies except the current
		   then update physics relative to all other bodies and redner window again */
		for (int i = 0; i < bodies.size(); i++) {
			std::vector<Body> bodies_except_self;
			for (int j = 0; j < bodies.size(); j++) {
				if (i == j) continue;
				bodies_except_self.push_back(bodies[j]);
			}

			bodies[i].update_physics(bodies_except_self);

			// check if we want to bounce off the borders
			if (stay_in_bounds)
			{
				bodies[i].check_bounds();
			}

			// check if we want to draw a trailing line
			if (bodies[i].get_drawline())
			{
				bodies[i].update_line();
				bodies[i].draw_line(window);
			}
			bodies[i].render(window);

		}

		window.display();
	}
	return 0;
}

