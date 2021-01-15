/*
 * Palindrome.cpp
 */

#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include <algorithm>
#include "Palindrome.h"
#include "GCD.h"
using namespace std;

int main() {
	//program description
	cout<< "\nProject Assignment 4\n-----------------------\n\nThe program presents a menu of two operations to perform and an exit option.";
	string phrase;
	int option;
	GCD obj = GCD();
	Palindrome pal = Palindrome();
	do {
		cout << "\nPlease chose an option to continue:";
		cout << "\n1. Palindrome\n2. GCD\n99. Exit\n"; //program menu
		cin >> option; //read menu option
		switch (option) {

		case 1:
			cout << "\nEnter a phrase\n";
			//close previous input session before attempting to read the phrase
			std::cin.ignore();
			//read the phrase
			std::getline(std::cin, phrase);
			//check and display palindrome result
			if (pal.isPalindrome(phrase))
				cout << "\"" << phrase << "\" is a palindrome";
			else
				cout << "\"" << phrase << "\" is a not palindrome";
			break;

		case 2:
			int p, q, d;
			cout << "\nEnter first non-decimal number\n";
			cin >> p;
			cout << "Enter second non-decimal number\n";
			cin >> q;
			//compute greatest common devisor
			d= obj.gcd(p, q);
			cout << "gcd(" << p << ", " << q << ") = " << d << "\n";
			break;

		case 99:
			//user chose exit option
			cout << "Exiting program.....";
			exit(0);
			break;

		default:
			//invalid option input
			cout << "Invalid option chosen";
			break;

		}
	} while (true);

}

