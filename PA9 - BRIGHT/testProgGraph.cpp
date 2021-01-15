/*
 * testProgramGraph.cpp
 */

#include <iostream>
#include <fstream>
#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include "weightedGraph.h"
#include "minimalSpanTreeType.h"
using namespace std;

int main() {
	weightedGraphType weightedGraph;
	weightedGraph.createWeightedGraph();

	cout << "PA9 - GRAPH PROJECCT" << endl << endl;
	cout << "The program repeatedly prompts the user to operations to perform" << endl
			<< "on graph created form the file AdjListFile.txt." << endl << endl;
			cout << "----------Menu----------" << endl
			<< "1. Print shortest distance from a vertex" << endl
			<< "2. Print the edges in the minimal spanning tree of the graph." << endl
			<< "3. Exit" << endl << endl;

	for (;;) {
		cout << "Enter a menu option" << endl;
		int option;
		cin >> option;
		if (option == 1) {
			cout << "Enter a vertex number to print shortest distance" << endl;
			int vertex;
			cin >> vertex;
			weightedGraph.printShortestDistance(vertex);
		} else if (option == 2) {
			cout << "Available soon" << endl;
		} else if (option == 3) {
			cout << "------BRIGHT OWUSU------" << endl << "Bye...." << endl;
			return 0;
		}
	}
	return 0;
}
