#ifndef UNORDEREDARRAYLISTTYPE_H_
#define UNORDEREDARRAYLISTTYPE_H_

#include <iostream>
#include "arrayListType.h"
using namespace std;

class unorderedArrayListType: public arrayListType {
public:
	void insertAt(int location, int insertItem)=0;
	void insertEnd(int insertItem)=0;
	void replaceAt(int location, int repItem)=0;
	int seqSearch(int searchItem){
	    int loc;
	    bool found = false;

	    loc = 0;

	    while (loc < length && !found)
	        if (list[loc] == searchItem)
	            found = true;
	        else
	            loc++;

	    if (found)
	        return loc;
	    else
	        return -1;
	}

	void remove(int removeItem){
		int loc;

		    if (length == 0)
		        cout << "Cannot delete from an empty list." << endl;
		    else
		    {
		        loc = seqSearch(removeItem);

		        if (loc != -1)
		            removeAt(loc);
		        else
		            cout << "The item to be deleted is not in the list."
		                 << endl;
		    }
	}

//	unorderedArrayListType(int size = 100);

//public:
//	unorderedArrayListType(){};
};

#endif
