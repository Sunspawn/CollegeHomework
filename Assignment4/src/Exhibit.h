/*
 * Exhibit.h
 *
 *  Created on: 19 May 2019
 *      Author: nikolay
 */

#ifndef SRC_EXHIBIT_H_
#define SRC_EXHIBIT_H_

#include <iostream>

class Exhibit {
	std::string n, cn;
	float wght, hght, wdth;
	int year;
	bool toggle;
	virtual std::string className() const;
protected:
	void setFields(std::string,std::string,float,float,float,int);
public:
	Exhibit();
	Exhibit(std::string,std::string,float,float,float,int);
	virtual ~Exhibit();
	std::string name() const { return n; }
	std::string crtrName() const { return cn; }
	float weight() const { return wght; }
	float height() const { return hght; }
	float width() const { return wdth; }
	int yearMade() const { return year; }
	void setName(std::string name) { n = name; }
	void setCName(std::string cname) { cn = cname; }
	void setWeight(float weight) { wght = weight; }
	void setHeight(float height) { hght = height; }
	void setWidth(float width) { wdth = width; }
	void setYear(int year) { this->year = year; }
	/*
	 * Checks how much of the floor the exhibit will take.
	 *
	 * @return 			The area taken.
	 */
	virtual float floorArea() const;
	/*
	 * Checks how much of the wall the exhibit will take.
	 *
	 * @return 			The area taken.
	 */
	virtual float wallArea() const;
	/*
	 * How much it will cost to bring the exhibit to the museum.
	 */
	virtual float priceToBring() const = 0;
	/*
	 * Appends extra details to prior details.
	 *
	 * @param str 		A prior about() string to append to.
	 * @return 			A block of information with the details of the exhibit.
	 */
	virtual std::string about(std::string = std::string()) const;
	/*
	 * Serializes the exhibit into a single line format for storage.
	 *
	 * @param str 		Previous serialization to append to. If empty,
	 * 					starts from scratch.
	 * @return 			A line with the information of the exhibit.
	 */
	virtual std::string Serialize(std::string = std::string()) const;
};

#endif /* SRC_EXHIBIT_H_ */
