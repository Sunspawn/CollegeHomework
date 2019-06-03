/*
 * BadDataException.h
 *
 *  Created on: 25 May 2019
 *      Author: nikolay
 */

#ifndef SRC_BADDATAEXCEPTION_H_
#define SRC_BADDATAEXCEPTION_H_

#include <exception>
#include <iostream>

class BadDataException: public std::exception {
	std::string message;
public:
	BadDataException(std::string str): message(str) {}
	virtual ~BadDataException() {}
	const char * what() { return message.c_str(); }
};

#endif /* SRC_BADDATAEXCEPTION_H_ */
