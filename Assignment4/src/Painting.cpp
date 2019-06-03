/*
 * Painting.cpp
 *
 *  Created on: 22 May 2019
 *      Author: nikolay
 */

#include "Painting.h"
#include <sstream>

Painting::Painting(std::string name, std::string cName,
		float weight, float height, float width, int year, std::string style): st(style) {
	setFields(name,cName,weight,height,width,year);
}

Painting::~Painting() {}

float Painting::wallArea() const {
	return width() + 0.5;
}

float Painting::priceToBring() const {
	return width() * height() * 100;
}

std::string Painting::about(std::string str) const {
	std::stringstream ss;
	ss << Exhibit::about(str) << std::endl;
	ss << "Made in the " <<  st << " style.";
	return ss.str();
}

std::string Painting::Serialize(std::string str) const {
	std::stringstream ss;
	ss << Exhibit::Serialize(str) << st << ";";
	return ss.str();
}
