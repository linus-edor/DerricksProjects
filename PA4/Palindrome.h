/*
 * Palindrome.h
 */

#ifndef PALINDROME_H_
#define PALINDROME_H_

#include <iostream>
#include<string>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

class Palindrome {
public:
	Palindrome(){};
	virtual ~Palindrome(){};

	bool isPalindrome(string s) {
		// if length is 0 or 1 then the string is palindrome
		if (s.length() == 0 || s.length() == 1)
			return true;
		//convert the phrase to lower case.
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		if ((isalpha(s.at(0)) && isalpha(s.at(s.length() - 1)))
				&& s.at(0) != s.at(s.length() - 1))
			/* check first and last alphabets of the phrase for equality:
			 * If they are not the same return false.
			 */
			return false;
		else
			/*recursive call on a substring of the current phrase excluding both
			 *alphabets on either ends.
			 */
			return isPalindrome(s.substr(1, s.length() - 2));

	};

};

#endif /* PALINDROME_H_ */
