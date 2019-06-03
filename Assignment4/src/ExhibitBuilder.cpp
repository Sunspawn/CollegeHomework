/*
 * ExhibitBuilder.cpp
 *
 *  Created on: 22 May 2019
 *      Author: nikolay
 */

#include "Painting.h"
#include "Statue.h"
#include "Standing.h"
#include "WallArt.h"

#include "BadDataException.h"
#include "ExhibitBuilder.h"
#include <vector>
#include <sstream>

Painting * buildPainting(std::vector<std::string> &);
Statue * buildStatue(std::vector<std::string> &);
Standing * buildStanding(std::vector<std::string> &);
WallArt * buildWallArt(std::vector<std::string> &);
float mystof(std::string str);
int mystoi(std::string str);

std::vector<std::string> & tokenize(std::string str, std::vector<std::string> & result, char delim = ' ');

Exhibit * ExhibitBuilder::buiildExhibitFromString(std::string str) {
	std::vector<std::string> data;
	tokenize(str,data,';');
	if ( 0 == data[0].compare("Painting"))
		return buildPainting(data);
	else if ( 0 == data[0].compare("Statue"))
		return buildStatue(data);
	else if ( 0 == data[0].compare("Standing"))
		return buildStanding(data);
	else if ( 0 == data[0].compare("WallArt"))
		return buildWallArt(data);
	else
		throw BadDataException("Invalid data provided.");
}

std::vector<std::string> & tokenize(std::string str, std::vector<std::string> & result, char delim) {
	std::stringstream ss(str);
	std::string buf;
	while( getline(ss,buf,delim) ) {
		if ( 0 == buf.length() )
			continue;
		result.push_back(buf);
	}
	return result;
}

Painting * buildPainting(std::vector<std::string> & data) {
	// name,cname,weight,height,width,year,style
	std::string name = data[1];
	std::string cname = data[2];
	float weight = mystof(data[3]);
	float height = mystof(data[4]);
	float width = mystof(data[5]);
	int year = mystoi(data[6]);
	std::string style = data[7];
	return new Painting(name,cname,weight,height,width,year,style);
}

Statue * buildStatue(std::vector<std::string> & data) {
	// name,cname,weight,height,width,year,material,depth
	std::string name = data[1];
	std::string cname = data[2];
	float weight = mystof(data[3]);
	float height = mystof(data[4]);
	float width = mystof(data[5]);
	int year = mystoi(data[6]);
	std::string material = data[7];
	float depth = mystof(data[8]);
	return new Statue(name,cname,weight,height,width,year,material,depth);
}

Standing * buildStanding(std::vector<std::string> & data) {
	// name,cname,weight,height,width,year,style
	std::string name = data[1];
	std::string cname = data[2];
	float weight = mystof(data[3]);
	float height = mystof(data[4]);
	float width = mystof(data[5]);
	int year = mystoi(data[6]);
	std::string style = data[7];
	return new Standing(name,cname,weight,height,width,year,style);
}

WallArt * buildWallArt(std::vector<std::string> & data) {
	// name,cname,weight,height,width,year,style,material,depth
	std::string name = data[1];
	std::string cname = data[2];
	float weight = mystof(data[3]);
	float height = mystof(data[4]);
	float width = mystof(data[5]);
	int year = mystoi(data[6]);
	std::string style = data[7];
	std::string material = data[8];
	float depth = mystof(data[9]);
	return new WallArt(name,cname,weight,height,width,year,style,material,depth);

}

float mystof(std::string str) {
	std::stringstream ss;
	ss << str;
	float num;
	ss >> num;
	return num;
}
int mystoi(std::string str) {
	std::stringstream ss;
	ss << str;
	int num;
	ss >> num;
	return num;
}
