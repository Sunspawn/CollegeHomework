/*
 * Standing.h
 *
 *  Created on: 22 May 2019
 *      Author: nikolay
 */

#ifndef SRC_STANDING_H_
#define SRC_STANDING_H_

#include "Painting.h"

class Standing: public Painting {
public:
	Standing(std::string,std::string,float,float,float,int,std::string);
	virtual ~Standing();
	float floorArea() const;
};

#endif /* SRC_STANDING_H_ */
