/*
 * unorderedSetType.h
 */

#ifndef UNORDEREDSETTYPE_H_
#define UNORDEREDSETTYPE_H_
#include <iostream>
#include "unorderedArrayListType.h"
using namespace std;

class unorderedSetType : public unorderedArrayListType {
public:

	void insertAt(int location, int item) {

		if (location < 0 || location >= maxSize) {
			cout << "\nPosition is invalid. "
					<< "Position should be a positive number." << endl;
			return;
		}
		if(length == 0 || length < location){
			for(int i = length; i <= location; i++){
				list[i] = 0;
				length++;
			}
		}
		if (length >= maxSize) {  //the list is full.
			cout << "The list is full" << endl;
			return;
		}

		if (list[location] == 0)
			list[location] = item; //array index not initialized, insert item.
		else {
			for (int i = length; i > location; i--) {
				list[i] = list[i - 1];	//shift items up the array
				list[location] = item; //insert the item at the position
			}
		}
		return;
	}

	void insertEnd(int item) {
		if (length >= maxSize)  //the list is full
			cout << "The list is full. You can't insert anymore items." << endl;
		else {
			list[length] = item; //insert the item at the end
			length++; //provide room for next element
		}
	}

	void replaceAt(int location, int repItem) {
		if (location < 0 || location >= length)
			cout << "Invalid location. Enter a location in the range 0 - "
					<< maxSize << endl;
		else
			list[location] = repItem;
	} //end replaceAt

	void printList(){
		cout << "Current list items \n--------------------------\n";
		for(int i = 0; i < length; i++){
			cout << list[i] << " ";
		}
	}

	~unorderedSetType();


};

#endif /* UNORDEREDSETTYPE_H_ */
