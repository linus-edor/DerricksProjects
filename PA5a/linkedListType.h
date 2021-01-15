#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node

template<class Type>
struct nodeType {
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class linkedListIterator {
public:
	linkedListIterator();
	//Default constructor
	//Postcondition: current = nullptr;

	linkedListIterator(nodeType<Type> *ptr);
	//Constructor with a parameter.
	//Postcondition: current = ptr;

	Type operator*();
	//Function to overload the dereferencing operator *.
	//Postcondition: Returns the info contained in the node.

	linkedListIterator<Type> operator++();
	//Overload the pre-increment operator.
	//Postcondition: The iterator is advanced to the next
	//               node.

	bool operator==(const linkedListIterator<Type>& right) const;
	//Overload the equality operator.
	//Postcondition: Returns true if this iterator is equal to
	//               the iterator specified by right,
	//               otherwise it returns the value false.

	bool operator!=(const linkedListIterator<Type>& right) const;
	//Overload the not equal to operator.
	//Postcondition: Returns true if this iterator is not
	//               equal to the iterator specified by
	//               right; otherwise it returns the value
	//               false.

private:
	nodeType<Type> *current; //pointer to point to the current
							 //node in the linked list
};

template<class Type>
linkedListIterator<Type>::linkedListIterator() {
	current = nullptr;
}

template<class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr) {
	current = ptr;
}

template<class Type>
Type linkedListIterator<Type>::operator*() {
	return current->info;
}

template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
	current = current->link;

	return *this;
}

template<class Type>
bool linkedListIterator<Type>::operator==(
		const linkedListIterator<Type>& right) const {
	return (current == right.current);
}

template<class Type>
bool linkedListIterator<Type>::operator!=(
		const linkedListIterator<Type>& right) const {
	return (current != right.current);
}

//*****************  class linkedListType   ****************

template<class Type>
class linkedListType {
public:
	const linkedListType<Type>& operator=(const linkedListType<Type>&);
	//Overload the assignment operator.

	void initializeList();
	//Initialize the list to an empty state.
	//Postcondition: first = nullptr, last = nullptr,
	//               count = 0;

	bool isEmptyList() const;
	//Function to determine whether the list is empty.
	//Postcondition: Returns true if the list is empty,
	//               otherwise it returns false.

	void print() const;
	//Function to output the data contained in each node.
	//Postcondition: none

	void reversePrint() const;
	//Function to print the list data in reverse order
	//Postcondition: none

	void recursiveReversePrint(nodeType<Type> *node) const;
	//Function to print the list data in reverse order using recursion
	//Postcondition: none

	int length() const;
	//Function to return the number of nodes in the list.
	//Postcondition: The value of count is returned.

	void destroyList();
	//Function to delete all the nodes from the list.
	//Postcondition: first = nullptr, last = nullptr,
	//               count = 0;

	Type front() const;
	//Function to return the first element of the list.
	//Precondition: The list must exist and must not be
	//              empty.
	//Postcondition: If the list is empty, the program
	//               terminates; otherwise, the first
	//               element of the list is returned.

	Type back() const;
	//Function to return the last element of the list.
	//Precondition: The list must exist and must not be
	//              empty.
	//Postcondition: If the list is empty, the program
	//               terminates; otherwise, the last
	//               element of the list is returned.

	virtual bool search(const Type& searchItem) const = 0;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the
	//               list, otherwise the value false is
	//               returned.

	virtual void insertFirst(const Type& newItem) = 0;
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	//               inserted at the beginning of the list,
	//               last points to the last node in the list,
	//               and count is incremented by 1.

	virtual void insertLast(const Type& newItem) = 0;
	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem
	//               is inserted at the end of the list,
	//               last points to the last node in the
	//               list, and count is incremented by 1.

	virtual void deleteNode(const Type& deleteItem) = 0;
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing
	//               deleteItem is deleted from the list.
	//               first points to the first node, last
	//               points to the last node of the updated
	//               list, and count is decremented by 1.

	virtual void deleteLeastInfo() = 0;
	//Function to delete the node with the smallest info from the list.
	//Postcondition: If found, the first occurrence of the node with the smallest info
	//               is deleted from the list.
	//               first points to the first node, last
	//               points to the last node of the updated
	//               list, and count is decremented by 1.

	virtual void deleteAllOccurrencesOfInfo(const Type& deleteItem) = 0;
	//Function to delete all occurrences of an given info deleteItem from the list.
	//Postcondition: If found, all nodes containing
	//               deleteItem are deleted from the list.
	//               first points to the first node, last
	//               points to the last node of the updated
	//               list, and count is decremented by 1.

	Type getKthNode(const int k);
	//Function to return the info of the kth element of the list. If no such element, return nullptr
	//Postcondition: the kth element if found is returned and state of the list is preserved.

	bool deleteKthNode(const int k);
	//Function to delete the kth element of the list.
	//Postcondition: If found, the kth element of the list is deleted and last
	//node points to the last node of the update list whilst the first node
	//points to the first node of the updated list and also count is decreased by 1.

	linkedListIterator<Type> begin();
	//Function to return an iterator at the begining of
	//the linked list.
	//Postcondition: Returns an iterator such that current
	//               is set to first.

	linkedListIterator<Type> end();
	//Function to return an iterator one element past the
	//last element of the linked list.
	//Postcondition: Returns an iterator such that current
	//               is set to nullptr.

	linkedListType();
	//Default constructor
	//Initializes the list to an empty state.
	//Postcondition: first = nullptr, last = nullptr,
	//               count = 0;

	linkedListType(const linkedListType<Type>& otherList);
	//copy constructor

	~linkedListType();
	//Destructor
	//Deletes all the nodes from the list.
	//Postcondition: The list object is destroyed.

protected:
	int count;   //variable to store the number of
				 //elements in the list
	nodeType<Type> *first; //pointer to the first node of the list
	nodeType<Type> *last;  //pointer to the last node of the list

private:
	void copyList(const linkedListType<Type>& otherList);
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and
	//               assigned to this list.
};

template<class Type>
bool linkedListType<Type>::isEmptyList() const {
	return (first == nullptr);
}

template<class Type>
linkedListType<Type>::linkedListType() //default constructor
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<class Type>
void linkedListType<Type>::destroyList() {
	nodeType<Type> *temp;   //pointer to deallocate the memory
							//occupied by the node
	while (first != nullptr)   //while there are nodes in
	{                          //the list
		temp = first;        //set temp to the current node
		first = first->link; //advance first to the next node
		delete temp;   //deallocate the memory occupied by temp
	}
	last = nullptr; //initialize last to nullptr; first has
	//already been set to nullptr by the while loop
	count = 0;
}

template<class Type>
void linkedListType<Type>::initializeList() {
	destroyList(); //if the list has any nodes, delete them
}

template<class Type>
void linkedListType<Type>::print() const {
	nodeType<Type> *current; //pointer to traverse the list

	current = first;    //set current so that it points to
						//the first node
	while (current != nullptr) //while more data to print
	{
		cout << current->info << "  ";
		current = current->link;
	}
} //end print

//reverse rrint
template<class Type>
void linkedListType<Type>::reversePrint() const {
	//print the list in reverse using recursion
	recursiveReversePrint(first);
} //end reverse print

//Recursive reverse print
template<class Type>
void linkedListType<Type>::recursiveReversePrint(
		nodeType<Type> * current) const {

	//Call this function while current node is not last
	if (current != nullptr) {
		recursiveReversePrint(current->link); //print the tail
		cout << current->info << "  "; //print the node
	}
} //end recursiveReversePrint

//getKthNode
template<class Type>
Type linkedListType<Type>::getKthNode(const int k) {
	bool found = false;
	nodeType<Type> *current; //pointer to the current node in the iteration.
	current = first;
	int counter = count;
	if (count == 0)
		//the list is empty
		return "";
	else if (k == count && first->link != nullptr)
		//the node is the first element of the list
		return first->info;
	else {
		//it's not the first element, traverse the given position is found
		while (current != nullptr && !found) {
			counter--;
			if (counter == k) {
				found = true;
			}
			current = current->link;
		}
	}
	return found ? current->info : ""; //return info or empty string if not found
}//end getKthNode

//deleteKthNode
template<class Type>
bool linkedListType<Type>::deleteKthNode(const int k) {
	bool found = false;
	nodeType<Type> *current; //points to the current node in the iteration
	nodeType<Type> *trailCurrent; //points to the previous node in the iteration
	current = first;
	trailCurrent = first;
	int counter = count;
	if (count == 0)
		//list is empty
		return false;
	else if (k == count && first->link != nullptr) {
		current = first;
		first = first->link;
		if (this->first == nullptr) //the list has only one node
			this->last = nullptr;
		delete current;
		this->count--;
		return true;
	} else {

		//continue searching through the rest of the list
		while (current != nullptr && !found) {
			counter--;
			trailCurrent = current;
			if (counter == k) {
				found = true;
			}
			current = current->link;
		}
	}
	if (found) {

		//node found
		if (current != last) {
			//not the last item
			trailCurrent->link = current->link;
			delete current;
			current = trailCurrent->link;
			count--;
		} else {
			//it's the last item of the list
			last = trailCurrent;
			last->link = nullptr;
			delete current;
			count--;
		}
		return true;
	} else {
		return false;
	}
} //end deleteKthNode

template<class Type>
int linkedListType<Type>::length() const {
	return count;
}  //end length

template<class Type>
Type linkedListType<Type>::front() const {
	assert(first != nullptr);

	return first->info; //return info of the first node
} //end front

template<class Type>
Type linkedListType<Type>::back() const {
	assert(last != nullptr);

	return last->info; //return info of the last node
} //end back

template<class Type>
linkedListIterator<Type> linkedListType<Type>::begin() {
	linkedListIterator<Type> temp(first);

	return temp;
}

template<class Type>
linkedListIterator<Type> linkedListType<Type>::end() {
	linkedListIterator<Type> temp(nullptr);

	return temp;
}

template<class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList) {
	nodeType<Type> *newNode; //pointer to create a node
	nodeType<Type> *current; //pointer to traverse the list

	if (first != nullptr) //if the list is nonempty, make it empty
		destroyList();

	if (otherList.first == nullptr) //otherList is empty
			{
		first = nullptr;
		last = nullptr;
		count = 0;
	} else {
		current = otherList.first; //current points to the
								   //list to be copied
		count = otherList.count;

		//copy the first node
		first = new nodeType<Type>;  //create the node

		first->info = current->info; //copy the info
		first->link = nullptr;        //set the link field of
									  //the node to nullptr
		last = first;              //make last point to the
								   //first node
		current = current->link;     //make current point to
									 //the next node

		//copy the remaining list
		while (current != nullptr) {
			newNode = new nodeType<Type>;  //create a node
			newNode->info = current->info; //copy the info
			newNode->link = nullptr;       //set the link of
										   //newNode to nullptr
			last->link = newNode;  //attach newNode after last
			last = newNode;        //make last point to
								   //the actual last node
			current = current->link;   //make current point
									   //to the next node
		}                                       //end while
	}                                       //end else
}                                       //end copyList

template<class Type>
linkedListType<Type>::~linkedListType() //destructor
{
	destroyList();
} //end destructor

template<class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) {
	first = nullptr;
	copyList(otherList);
} //end copy constructor

//overload the assignment operator
template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(
		const linkedListType<Type>& otherList) {
	if (this != &otherList) //avoid self-copy
			{
		copyList(otherList);
	} //end else

	return *this;
}

#endif
