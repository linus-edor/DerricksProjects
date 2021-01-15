/*
 * invalidHr.h
 */

#ifndef INVALIDHR_H_
#define INVALIDHR_H_

#include <iostream>
#include <exception>
using namespace std;
class invalidHr : public exception {
public:
	virtual const char* what() const throw()
	{
		return "\nInvalid hour. Enter hour in range 1 - 12 inclusive.";
	}

	invalidHr(){};
};

#endif /* INVALIDHR_H_ */
