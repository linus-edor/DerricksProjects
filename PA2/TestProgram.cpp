#include <iostream>
#include "unorderedSetType.h"
#include<bits/stdc++.h>
using namespace std;

int main() {
	unorderedSetType * uSet = new unorderedSetType;
	uSet->list = new int[uSet->maxSize];
	cout << "Max list size: " << uSet->maxSize;
	cout
			<< "\n\nStarting program.............\ndone! \n\n Program menu\n ------------\n";
	cout
			<< " 1. Insert \n 2. Remove\n 3. InsertAt\n 4. InsertEnd\n 5. ReplaceAt\n 6. SeqSearch\n 7. PrintList\n 8. Quit\n ------------\n\nEnter an option to continue........";
	int userInput = 0;
	string optionList[8] = { "1. Insert", "2. Remove", "3. InsertAt",
			"4. InsertEnd", "5. ReplaceAt", "6. SeqSearch", "7. PrintList",
			"8. Quit" };
	do {
		cin >> userInput;
		cout << "User input: " << optionList[userInput - 1] << "\n";
		if (userInput > 0 && userInput < 9) {
			switch (userInput) {
			case 3: {
				cout << "Enter a value to insert.\n";
				int insertValue = 0;
				cin >> insertValue;
				cout << "\nValue entered: " << insertValue << "\n";
				int insertPosition = 0;
				cout << "\nEnter position: ";
				cin >> insertPosition;
				cout << "Postion: " << insertPosition << "\n";
				uSet->insertAt(insertPosition, insertValue);
				uSet->printList();
				break;
			}
			case 4: {
				cout << "\nEnter value to insert at end of list......\n";
				int insertValue = 0;
				cin >> insertValue;
				cout << "\nValue entered: " << insertValue << "\n";
				uSet->insertEnd(insertValue);
				uSet->printList();
				break;
			}
			case 5: {
				int insertPosition = 0;
				cout << "\nEnter position to replace: ";
				cin >> insertPosition;
				cout << "Postion: " << insertPosition << "\n";
				cout << "Enter a value to insert.\n";
				int repValue = 0;
				cin >> repValue;
				cout << "\repValue entered: " << repValue << "\n";
				uSet->insertAt(insertPosition, repValue);
				uSet->printList();
				break;
			}
			case 8: {
				cout << "Thanks for using the program. Exiting in a second"
						<< "\nBye.......";
				exit(0);
				break;
			}
			default:
				cout << "Operation will be made available soon.";
			}
		} else {
			cout << "Invalid input. Enter a value between 1 and 8 inclusive.";
		}

		cout << "\nProceed with a new operation...";
		cout
				<< "\n 1. Insert \n 2. Remove\n 3. InsertAt\n 4. InsertEnd\n 5. ReplaceAt\n 6. SeqSearch\n 7. PrintList\n 8. Quit\n ------------\n\nEnter an option to continue........";
	} while (true);
}
