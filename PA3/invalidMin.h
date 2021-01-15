/*
 * invalidHr.h
 */

#ifndef INVALIDMIN_H_
#define INVALIDMIN_H_

#include <iostream>
#include <exception>
using namespace std;
class invalidMin : public exception {
public:
	virtual const char* what() const throw()
	{
		return "\nInvalid minute. Enter minute in range 1 - 59 inclusive.";
	}

	invalidMin(){};
};

#endif /* INVALIDMIN_H_ */
