/*
 * ExhibitBuilder.h
 *
 *  Created on: 22 May 2019
 *      Author: nikolay
 */

#ifndef SRC_EXHIBITBUILDER_H_
#define SRC_EXHIBITBUILDER_H_

#include "Exhibit.h"
#include <iostream>

class ExhibitBuilder {
public:
	ExhibitBuilder() {}
	virtual ~ExhibitBuilder() {}
	/*
	 * Turns a line of raw data into an exhibit.
	 *
	 * @param str 			A string containing a single line of serialized
	 * 						data.
	 * @return 				An exhibit matching the data given in the string.
	 */
	static Exhibit * buiildExhibitFromString(std::string);
};

#endif /* SRC_EXHIBITBUILDER_H_ */
