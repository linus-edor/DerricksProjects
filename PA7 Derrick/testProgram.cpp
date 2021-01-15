/*
 * testProgram.cpp
 *  Created on: Nov 2, 2018
 */
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Insertion sort method
template<class elemType>
void insertionSort(elemType list[], int length);

//Selection sort method
template<class elemType>
void selectionSort(elemType list[], int length);

//Method to swap two array elements during selection sort
template<class elemType>
void swap(elemType list[], int first, int second);

//Method to return the index of the smaller of the current item and the previous in selection sort iteration
template<class elemType>
int minLocation(elemType list[], int first, int last);

//Binary search method
template<class Type>
int binarySearch(Type arr[], int l, int r, int x);

//Variables to hold the number of swaps and key comparisons in
int insertSwaps, insertComps, selectSwaps, selectComps, binarySearchComps = 0;

int main() {

	//Seed the random number generator with current system time and PID
	srand(getpid() + time(NULL));

	int numOfRuns; //holds the number of times user wants sorting and searching to be run.

	cout << "SORTING AND SEARCHING ALGORITHMS TEST PROGRAM"
		 << endl << endl
		 << "The program creates and array of 1000 randomly generated numbers for a "
		 << endl <<	 "user entered number of times, makes a copy of the array, runs selection "
		 << endl <<	 "sort on one copy and insertion sort on the other and then allows the "
		 << endl <<  "user to continually enter an item to search from the list. The user can "
		 << endl <<  "enter -1 to exit the search loop and continue with the next sort operations"
		 << endl <<	 "or 0 to exit the application."
		 << endl <<  "On each sort and search, the program displays the number of key comparisons "
		 << endl <<	 "and swaps(where applicable). Before the programs exits after a successful run,"
		 << endl <<  "it displays the name of the programmer." << endl;

	cout << endl << "Enter the number of times to run the algorithms" << endl;
	cin >> numOfRuns;

	//For the preferred number of times, generate 1000 random numbers, sort the
	//numbers and allow user to search for as many items as possible.
	//When user enters -1 for search item, exit the loop and run the next sorting
	//operations and allow user to run searches again.....
	for (int k = 0; k < numOfRuns; k++) {
		int numbers[1000];

		//generate and store the various random number
		for (int i = 0; i < 1000; i++) {
			numbers[i] = rand();
		}

		//make a copy of the array
		int numbers1[1000];
		for (int i = 0; i < 1000; i++) {
			numbers1[i] = numbers[i];
		}

		//print the generated random numbers unsorted;
		cout << "Array unsorted:" << endl;
		for (int j = 0; j < 1000; j++) {
			cout << numbers[j] << " " << endl;
		}

		//Run insertion sort on one of the arrays
		insertSwaps = 0;
		insertComps = 0;
		insertionSort(numbers, 1000);
		cout << "Insertion sort number of swaps:" << insertSwaps << endl
				<< "Insertion sort key comparisons:" << insertComps << endl;

		//run selection sort on the other array
		selectSwaps = 0;
		selectComps = 0;
		selectionSort(numbers1, 1000);
		cout << "Selection sort number of swaps:" << selectSwaps << endl
				<< "Selection sort key comparisons:" << selectComps << endl;

		//Print the sorted array
		cout << "Array sorted with insertion sort:"
				<< endl << "Index   Element" << endl << "-----   -------" << endl;
		for (int j = 0; j < 1000; j++) {
			cout << j << "\t" << numbers[j] << endl;
		}

		int searchInp = 0;
		int binarySeaarchResult; //Holds binary search result
		while (true) {
			cout << "Enter a value to search" << endl;
			cin.clear();
			cin >> searchInp;
			if (searchInp == -1) {
				//exit this loop and continue with the next sorting instance.
				break;
			} else if (searchInp == 0) {

				//The program cannot search for 0. Display your name and exit the application
				cout << "----DERRICK ANNOR----";
				exit(0);
			} else {

				//Display the number of comparisons while searching for the item.
				binarySearchComps = 0;
				binarySeaarchResult = binarySearch(numbers, 0, 1000, searchInp);
				printf("Number of comparisons while searching for %d : %d \n",
						searchInp, binarySearchComps);

				//Display the postion of the item in the array if found.
				(binarySeaarchResult == -1) ?
						printf("Search item not found in array") :
						printf("Search item found at index %d", binarySeaarchResult);
				cout << endl;

			}
		}
		cout << "----DERRICK ANNOR----";
	}
	return 0;
}

//Insertion sort implementation
template<class elemType>
void insertionSort(elemType list[], int length) {
	for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++) {
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1]) {
			insertSwaps++;
			elemType temp = list[firstOutOfOrder];
			int location = firstOutOfOrder;
			do {
				list[location] = list[location - 1];
				location--;
				insertComps++;
			} while (location > 0 && list[location - 1] > temp);
			list[location] = temp;
		}
	}
} //end insertionSort


//Selection sort implementation
template<class elemType>
void selectionSort(elemType list[], int length) {
	int minIndex, loc;

	for (int loc = 0; loc < length; loc++) {
		minIndex = minLocation(list, loc, length - 1);
		swap(list, loc, minIndex);
	}
} //end selectionSort

//minLocation implementation
template<class elemType>
int minLocation(elemType list[], int first, int last) {
	int loc, minIndex;
	minIndex = first;
	for (loc = first + 1; loc <= last; loc++) {
		selectComps++;
		if (list[loc] < list[minIndex])
			minIndex = loc;
	}
	return minIndex;
} //end minLocation

//swap implementation
template<class elemType>
void swap(elemType list[], int first, int second) {
	elemType temp;
	temp = list[first];
	list[first] = list[second];
	list[second] = temp;
	selectSwaps++;
} //end swap

//Recursive binary search implementation
template<class Type>
int binarySearch(Type arr[], int l, int r, int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		binarySearchComps++;
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		binarySearchComps++;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

// We reach here when element is not
// present in array
	return -1;
}

