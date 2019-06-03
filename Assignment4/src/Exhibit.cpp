/*
 * Exhibit.cpp
 *
 *  Created on: 19 May 2019
 *      Author: nikolay
 */

#include "Exhibit.h"
#include <sstream>

Exhibit::Exhibit(): n(), cn(), wght(), hght(), wdth(), year(), toggle(false) {}

Exhibit::Exhibit(std::string name, std::string cName, float weight, float height,
		float width, int year):
				n(name), cn(cName), wght(weight), hght(height),
				wdth(width), year(year), toggle(true) {}

Exhibit::~Exhibit() {}

void Exhibit::setFields(std::string name, std::string cName, float weight, float height,
		float width, int year) {
	if (!toggle) {
			setName(name);
			setCName(cName);
			setWeight(weight);
			setHeight(height);
			setWidth(width);
			setYear(year);
			toggle = true;
		}
}

std::string Exhibit::className() const {
	return "Exhibit";
}

float Exhibit::floorArea() const {
	return 0;
}

float Exhibit::wallArea() const {
	return 0;
}

std::string Exhibit::about(std::string str) const {
	if ( str.length() == 0 ) {
		std::stringstream ss;
		ss << n << " by " << cn << std::endl;
		ss << "Weight/Width/Height: " << wght << "/" << hght << "/" << wdth;
		ss << std::endl << "Made in the year " << year;
		return ss.str();
	}
	return str;
}

std::string Exhibit::Serialize(std::string str) const {
	if ( str.length() == 0) {
		std::stringstream ss;
		ss << ";" << className();
		ss << ";" << n;
		ss << ";" << cn;
		ss << ";" << wght;
		ss << ";" << hght;
		ss << ";" << wdth;
		ss << ";" << year;
		ss << ";";
		return ss.str();
	}
	return str;
}
