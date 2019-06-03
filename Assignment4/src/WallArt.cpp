/*
 * WallArt.cpp
 *
 *  Created on: 22 May 2019
 *      Author: nikolay
 */

#include "WallArt.h"
#include <sstream>

WallArt::WallArt(std::string name, std::string cName, float weight, float height,
		float width, int year, std::string style, std::string material, float depth):
			Painting(name,cName,weight,height,width,year,style),
			Statue(name,cName,weight,height,width,year,material,depth) {}

WallArt::~WallArt() {}

float WallArt::priceToBring() const { return Statue::priceToBring(); }

std::string WallArt::about(std::string str) const {
	return Statue::about(Painting::about(str));
}

std::string WallArt::Serialize(std::string str) const {
	return Statue::Serialize(Painting::Serialize(str));
}

