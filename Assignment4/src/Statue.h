/*
 * Statue.h
 *
 *  Created on: 21 May 2019
 *      Author: nikolay
 */

#ifndef SRC_STATUE_H_
#define SRC_STATUE_H_

#include "Exhibit.h"

class Statue: public virtual Exhibit {
	std::string mat;
	float dpth;
	std::string className() const { return "Statue"; }
protected:
	int volume() const;
public:
	Statue(std::string,std::string,float,float,float,int,std::string,float);
	virtual ~Statue() {}
	std::string material() const { return mat; }
	float depth() const { return dpth; }
	float floorArea() const;
	float wallArea() const { return 0; }
	float priceToBring() const;
	std::string about(std::string = std::string()) const;
	std::string Serialize(std::string = std::string()) const;
};

#endif /* SRC_STATUE_H_ */
