#include "parser.h"
#include <json/json.h>
#include <fstream>
#include <iostream>

parser::parser(const char* filename)
{
	this->filename = filename;
}

Json::Value parser::parse()
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