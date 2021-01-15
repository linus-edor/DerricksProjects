/**
 * This program tests a binary search tree implementation -
 * binarySearchTree header file to perform basic operations like
 * insert, search and delete node.
 */
#include<iostream>
#include<bits/stdc++.h>
#include "binarySearchTree.h"
#include <string>

using namespace std;

//Function to display the menu options
void displayMenu() {
	cout << endl << endl << "Choose an operation to perform:" << endl;
	cout << "1- Insert an item" << endl;
	cout << "2- Delete a given item" << endl;
	cout << "3- Delete node" << endl;
	cout << "4- Search for an item" << endl;
	cout << "5- Print postOrder traversal" << endl;
	cout << "6- Print preOrder traversal" << endl;
	cout << "7- Print inOrder traversal" << endl;
	cout << "8- Exit" << endl;
}

//Function to check of a string s is numeric
bool is_number(const string& s) {

	//Check if each character is a integer
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end(); //return false if it's not numeric else true.
}

int main() {

	//Print program description
	cout << endl << "BINARY SEARCH TEST PROGRAM - PA8" << endl << endl
			<< "*****************************************************************"
			<< endl
			<< "This program is a binary search tree implementation test program."
			<< endl
			<< "The program continuously presents a menu of operations to perform"
			<< endl
			<< "on a binary search tree instance until the user enters the option to"
			<< endl << "quit the program." << endl
			<< "*****************************************************************"
			<< endl;
	displayMenu();

	bSearchTreeType<string>* tree = new bSearchTreeType<string>; //the binary search tree instance

	string option; //holds the menu option entered
	int intOption = -1;
	while (true) {

		//read the input option
		std::getline(std::cin, option);
		if (!is_number(option)) {

			//Invalid option
			cout << "Invalid option. Option should be a positive integer";
		} else {

			//convert menu option input to an integer
			intOption = atoi(option.c_str());

			//validate menu option input
			if (intOption <= 8 && intOption >= 1) {

				//valid menu option chosen
				if (intOption == 8) {

					//option to quit the program
					delete &tree; //destroy the tree instance and release resources
					break;
				} else if (intOption == 1) {
					cout << "Enter a value to insert:" << endl;
					string phrase;

					//read the input phrase
					std::getline(std::cin, phrase);
					tree->insert(phrase); //insert the phrase in tree
				} else if (intOption == 2) {
					cout << "Enter a value to delete:" << endl;
					string phrase;

					//read the input phrase
					std::getline(std::cin, phrase);
					tree->deleteNode(phrase); //delete the phrase from tree
				} else if (intOption == 3) {
					cout << "Enter a value whose node you want to delete:"
							<< endl;
					string phrase;

					//read the input phrase
					std::getline(std::cin, phrase);
					tree->deleteNode(phrase);
				} else if (intOption == 4) {
					cout << "Enter a value to search for:" << endl;
					string phrase;

					//read the input phrase
					std::getline(std::cin, phrase);
					bool found = tree->search(phrase); //search for the input phrase from tree

					//display information about search result
					if (found)
						printf("%s was found in the tree", phrase.c_str());
					else
						printf("%s was not found in the tree", phrase.c_str());
				} else if (intOption == 5) {
					//Print the tree postOrder traversal
					cout << "Printing tree postOrder traversal........" << endl;
					tree->postorderTraversal();
				} else if (intOption == 6) {
					//Print the tree preOrder traversal
					cout << "Printing tree preOrder traversal........" << endl;
					tree->preorderTraversal();
				} else if (intOption == 7) {
					//Print the tree inOrder traversal
					cout << "Printing tree inOrder traversal........" << endl;
					tree->inorderTraversal();
				}

			} else {
				//invalid menu option entered
				cout << "Invalid menu option chosen. " << endl
						<< "Option should be in range 1 to 8";
			}
		}
		displayMenu(); //Display menu
	}

	//Exit program
	cout << endl << "Bye........";
	return 0;
}
