/*
 * GCD.h
 */

#ifndef GCD_H_
#define GCD_H_

class GCD {
public:

	GCD(){};

	virtual ~GCD(){};

	//returns the greatest common devisor of p and q
	int gcd(int p, int q) {
		//if one value is zero, then return the other.
		if (q == 0)
			return p;
		else if(p==0)
			return q;
		else
			//continuously repeat the above process until one value is zero
			return abs(gcd(q, p % q));
	}

};

#endif /* GCD_H_ */
