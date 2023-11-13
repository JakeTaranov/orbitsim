#include "json/json.h"
#include "body.h"
#include <SFML/Graphics.hpp>
#pragma once
class Parser
{
	const char* filename;
public:
	Parser(const char* filename);
	Json::Value parse();
	std::vector<Body> genereate_bodies_vector(Json::Value parsed_json_bodies, std::vector<Body> bodies);
};

