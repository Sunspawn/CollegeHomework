/*
 * Painting.h
 *
 *  Created on: 22 May 2019
 *      Author: nikolay
 */

#ifndef SRC_PAINTING_H_
#define SRC_PAINTING_H_

#include "Exhibit.h"

class Painting: public virtual Exhibit {
	std::string st;
	std::string className() const { return "Painting"; }
public:
	Painting(std::string,std::string,float,float,float,int,std::string);
	virtual ~Painting();
	std::string style() const;
	float floorArea() const { return 0; }
	/*
	 * A painting takes up the width of the painting and an extra meter
	 * on the wall.
	 *
	 * @return 			The area taken on the yz plane(the wall).
	 */
	float wallArea() const;
	float priceToBring() const;
	std::string about(std::string = std::string()) const;
	std::string Serialize(std::string = std::string()) const;
};

#endif /* SRC_PAINTING_H_ */
