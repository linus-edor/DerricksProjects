#include <iostream>
#include <string>
#include "linkedListType.h"
#include "unorderedLinkedListType.h"
//#include "orderedLinkedListType.h";
using namespace std;

bool is_numeric(const std::string& str);
int main() {

	//Program description and instructions.
	cout << "LINKED LIST TEST APPLICATION" << endl
			<< "=====================================";

	cout << endl << endl
			<< "This program presents a menu of tasks to perform on an unordered linked list."
			<< endl << endl << "--------------Program Menu--------------"
			<< endl << "1 Add a new item to the list" << endl
			<< "2 Delete the first occurrence of a given item from the list"
			<< endl << "3 Delete all occurrences of a given item from the list"
			<< endl << "4 Delete the smallest item from the list" << endl
			<< "5 Print the kth item in the list" << endl
			<< "6 Delete the kth item from the list" << endl
			<< "7 Print the list in reverse" << endl << "8 print the list"
			<< endl << "9 Quit";

	unorderedLinkedListType<string> unorderedLinkedList =
			unorderedLinkedListType<string>(); //Create UnorderedLinkedList object.

	//Prompt user for options to perform on the list and process input continually
	//till user enters option to quit the program.
	do {
		cout << endl << endl << "Choose an operation to perform:" << endl;
		string option; //holds the menu option input
		cin >> option; //read menu option entered
		int intOptionValue; //the integer version of the option input

		//validate the option input - check that it's a number
		if (!is_numeric(option)) {

			//Invalid input
			cout << "Invalid option. Option should be a positive integer";
		} else {

			//convert menu option input to an integer
			intOptionValue = atoi(option.c_str());
		}

		//Validate the option input - check that the option entered is within the range
		if (intOptionValue != -1
				&& (intOptionValue < 1 || intOptionValue > 9)) {
			//user entered an option that's not included in menu
			cout << "Invalid option. Enter option between 0 and 10";
		}

		switch (intOptionValue) {

		case 1: {

			//Option to add a value to the list
			cout << "Enter a value to add to the list" << endl;
			string input;
			std::cin.ignore();
			std::getline(std::cin, input);

			//Insert the value into the list
			unorderedLinkedList.insertLast(input);
			break;
		}

		case 2: {

			//Option to delete an info from the list
			cout << "Enter info to delete" << endl;
			string input;
			std::cin.ignore();
			std::getline(std::cin, input);

			//Delete the node whose info is entered (first occurrence)
			unorderedLinkedList.deleteNode(input);
			break;
		}
		case 3: {

			//option to delete all occurrences of a given info from the list
			cout << "Enter an info to delete" << endl;
			string input;
			std::cin.ignore();
			std::getline(std::cin, input);

			//Delete all occurrences of the given info
			unorderedLinkedList.deleteAllOccurrencesOfInfo(input);
			break;
		}
		case 4: {

			//Option to delete the node with the smallest info in the
			//list. (Just the first occurrence)
			unorderedLinkedList.deleteLeastInfo();
			break;
		}
		case 5: {

			//Option to print the kth item from the list
			cout << "Enter position of element to get info" << endl;

			string input;
			std::cin.ignore();
			std::getline(std::cin, input);
			if (!is_numeric(input)) {

				//user didn't enter a positive integer for list position
				cout << "Invalid input. Enter a positive number";
			} else {

				//Get the info in the given position
				string kthInfo = unorderedLinkedList.getKthNode(atoi(input.c_str()));
				if (kthInfo == "") {

					//That position doesn't exist
					cout << "No such element. Program is shutting down..."
							<< endl;
					//Exit the after destroying the list
					unorderedLinkedList.destroyList();
					exit(0);
				} else {

					//The position exists. Print info
					cout << input << "(th) element's info is '" << kthInfo
							<< "'" << endl;
				}
			}
			break;
		}

		case 6: {

			//Option to delete kth item from the list
			cout << "Enter position of element to delete " << endl;

			string input;
			std::cin.ignore();
			std::getline(std::cin, input);

			//Validate input
			if (!is_numeric(input)) {

				//Value entered is not a positive integer
				cout << "Invalid input. Enter a positive number" << endl;
			} else {

				//Does the position entered exist in the list and is deleted?
				bool isFound = unorderedLinkedList.deleteKthNode(atoi(input.c_str()));
				if (!isFound) {

					//Position doesn't exist. Exit the program.
					cout << "no such element. Program is shutting down....."
							<< endl;
					unorderedLinkedList.destroyList();
					exit(0);
				} else {

					//Position exists. Display the info
					cout << input << "th node has been deleted..." << endl;
				}
			}

			break;
		}
		case 7: {

			//Print the list in reverse
			unorderedLinkedList.reversePrint();
			break;
		}
		case 8: {

			//Print the list
			unorderedLinkedList.print();
			break;
		}
		case 9: {

			//Option to exit the program.
			unorderedLinkedList.destroyList();
			cout << "Program shutting down.......";
			exit(0);

			break;
		}
		default: {
			;
			break;
		}
		}

	} while (true);
}

//Function to determine of a string str is numeric
bool is_numeric(const string& str) {

	//Iterate the characters of the string and check if each character is a integer
	std::string::const_iterator i = str.begin();
	while (i != str.end() && std::isdigit(*i))
		++i;
	return !str.empty() && i == str.end(); //return false if it's not a number else true.
}
