/*
 * WallArt.h
 *
 *  Created on: 22 May 2019
 *      Author: nikolay
 */

#ifndef SRC_WALLART_H_
#define SRC_WALLART_H_

#include "Painting.h"
#include "Statue.h"
#include <iostream>

class WallArt: public Painting, public Statue {
	std::string className() const { return "WallArt"; }
public:
	/*
	 * Constructor.
	 *
	 * @param name 			The name of the creation.
	 * @param cname 		The name of the creator.
	 * @param weight 		The weight of the creation.
	 * @param height 		The height of the creation.
	 * @param width 		The width of the creation.
	 * @param year 			The year of the creation's making.
	 * @param style 		The style of the creation's make.
	 * @param material 		The material the creation is made from.
	 * @param depth 		The depth of the creation.
	 */
	WallArt(std::string,std::string,float,float,float,int,std::string,std::string,float);
	virtual ~WallArt();
	float priceToBring() const;
	float wallArea() const { return Painting::wallArea(); }
	float floorArea() const { return Statue::floorArea(); }
	std::string about(std::string = std::string()) const;
	std::string Serialize(std::string = std::string()) const;
};

#endif /* SRC_WALLART_H_ */
