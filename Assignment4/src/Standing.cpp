/*
 * Standing.cpp
 *
 *  Created on: 22 May 2019
 *      Author: nikolay
 */

#include "Standing.h"

Standing::Standing(std::string name, std::string cName,
		float weight, float height, float width, int year, std::string style):
			Painting(name,cName,weight,height,width,year,style) {}

Standing::~Standing() {}

float Standing::floorArea() const {
	return Painting::wallArea() / 2;
}
