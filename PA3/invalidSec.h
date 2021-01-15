/*
 * invalidHr.h
 */

#ifndef INVALIDSEC_H_
#define INVALIDSEC_H_

#include <iostream>
#include <exception>
using namespace std;
class invalidSec : public exception {
public:
	virtual const char* what() const throw()
	{
		return "\nInvalid second. Enter second in range 1 - 59 inclusive.";
	}

	invalidSec(){};
};

#endif /* INVALIDSEC_H_ */
