/*
 * Statue.cpp
 *
 *  Created on: 21 May 2019
 *      Author: nikolay
 */

#include "Statue.h"
#include <sstream>

Statue::Statue(std::string name, std::string cName, float weight, float height,
		float width, int year, std::string material, float depth): mat(material) {
	Exhibit::setName(name);
	Exhibit::setCName(cName);
	Exhibit::setWeight(weight);
	Exhibit::setHeight(height);
	Exhibit::setWidth(width);
	Exhibit::setYear(year);
	dpth = depth;
}

int Statue::volume() const {
	return dpth * height() * width();
}

float Statue::floorArea() const {
	return dpth * width() * 1.2;
}

float Statue::priceToBring() const {
	return volume() * 100;
}

std::string Statue::about(std::string str) const {
	std::stringstream ss;
	ss << Exhibit::about(str) << std::endl;
	ss << "Made from " << mat << std::endl;
	ss << "Volume: " << volume();
	return ss.str();
}

std::string Statue::Serialize(std::string str) const {
	std::stringstream ss;
	ss << Exhibit::Serialize(str) << mat << ";" << depth() << ";";
	return ss.str();
}
