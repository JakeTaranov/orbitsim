#include "Parser.h"
#include <json/json.h>
#include <fstream>
#include <iostream>

sf::Color generate_random_color()
{
	float r = rand() * 255;
	float g = rand() * 255;
	float b = rand() * 255;

	return sf::Color(r, g, b);
}

Parser::Parser(const char* filename)
{
	this->filename = filename;
}

Json::Value Parser::parse()
{
	Json::Value root;
	std::ifstream ifs;
	ifs.open(filename);


	Json::CharReaderBuilder builder;
	builder["collectComments"] = true;
	JSONCPP_STRING errs;
	if (!parseFromStream(builder, ifs, &root, &errs)) {
		std::cout << errs << std::endl;
		return -1;
	}

	return root;
}

std::vector<Body> Parser::genereate_bodies_vector(Json::Value parsed_json_bodies, std::vector<Body> bodies)
{
	srand(time(NULL));

	if (parsed_json_bodies)
	{
		for (int i = 0; i < parsed_json_bodies["bodies"].size(); i++)
		{
			bodies.push_back(
				Body(
					parsed_json_bodies["bodies"][i]["mass"].asFloat(),
					parsed_json_bodies["bodies"][i]["radius"].asFloat(),
					generate_random_color(),
					parsed_json_bodies["bodies"][i]["pos_x"].asFloat(),
					parsed_json_bodies["bodies"][i]["pos_y"].asFloat(),
					parsed_json_bodies["bodies"][i]["vel_x"].asFloat(),
					parsed_json_bodies["bodies"][i]["vel_y"].asFloat(),
					parsed_json_bodies["bodies"][i]["drawline"].asFloat()));
		}
	}
	else
	{
		std::cout << "FAILED TO READ JSON FILE" << std::endl;
	}
	return bodies;
}