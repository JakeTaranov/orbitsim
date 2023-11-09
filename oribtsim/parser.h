#include "json/json.h"
#pragma once
class parser
{
	const char* filename;
public:
	parser(const char* filename);
	Json::Value parse();
};

