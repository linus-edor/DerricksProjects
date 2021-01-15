/*
 * TestProgram.cpp
 */

#include<iostream>
#include"invalidHr.h"
#include"invalidMin.h"
#include"invalidSec.h"
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

vector<string> split(const char *str, char c);

int main() {
	cout << "Time printer program\n----------------------\n\nThe program accepts a 12-hr formatted time and displays it in 24-hr format\n";
	do {
		cout<< "\n\nEnter 12-hour format time (e.g. 11:00:00 am) and hit Enter.\n";
		string timeInput = "";
		string meridiem;
		cin >> timeInput >> meridiem;
		cout << "\nTime entered: " << timeInput << " " << meridiem << "\n";
		int hr, min, sec;
		try {
			//extract the time components for validation.
			vector<string> timeTokens = split(timeInput.c_str(), ':');
			if (!timeTokens.empty()) {
				sec = atoi(timeTokens.back().c_str());
				timeTokens.pop_back();
			}
			if (!timeTokens.empty()) {
				min = atoi(timeTokens.back().c_str());
				timeTokens.pop_back();
			}
			if (!timeTokens.empty()) {
				hr = atoi(timeTokens.back().c_str());
				timeTokens.pop_back();
			}

			//validate input time
			if (hr > 12 || hr < 1) {
				throw invalidHr();
			} else if (min > 59 || min < 1) {
				throw invalidMin();
			} else if (sec > 59 || sec < 1) {
				throw invalidSec();
			}

			if (meridiem.compare("pm") == 0) {
				if (hr != 12)
					hr = hr + 12;
				else
					hr = 0; //midnight
			}
			cout << "\n24-hr format of time: \n";
			if (hr < 10)
				cout << "0" << hr << ":";
			else
				cout << hr << ":";

			if (min < 10)
				cout << "0" << min << ":";
			else
				cout << min << ":";

			if (sec < 10)
				cout << "0" << sec << "\n";
			else
				cout << sec << "\n";


		} catch (invalidHr e) {
			//User entered invalid hour
			cout << e.what() << "!";
		} catch (invalidMin e) {
			//User entered invalid minute
			cout << e.what() << "!";
		} catch (invalidSec e) {
			//User entered invalid second
			cout << e.what() << "!";
		} catch (exception e) {
			//An unspecified error occured.
			cout << "An error occurred. Please ensure your time"
					" format is hh:mm:ss am/pm";
		}
	} while (true);
	return 0;
}

vector<string> split(const char *str, char c) {
	vector<string> result;
	do {
		const char *begin = str;

		while (*str != c && *str)
			str++;
		result.push_back(string(begin, str));
	} while (0 != *str++);
	return result;
}
