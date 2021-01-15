#ifndef H_weightedGraph
#define H_weightedGraph

#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <cfloat> 
#include "graphType.h"

using namespace std;

class weightedGraphType: public graphType {
public:
	void createWeightedGraph();
	//Function to create the graph and the weight matrix.
	//Postcondition: The graph using adjacency lists and
	//               its weight matrix is created.

	void shortestPath(int vertex);
	//Function to determine the weight of a shortest path
	//from vertex, that is, source, to every other vertex
	//in the graph.
	//Postcondition: The weight of the shortest path from
	//               vertex to every other vertex in the
	//               graph is determined.

	void printShortestDistance(int vertex);
	//Function to print the shortest weight from vertex
	//to the other vertex in the graph.
	//Postcondition: The weight of the shortest path from
	//               vertex to every other vertex in the
	//               graph is printed.

	weightedGraphType(int size = 0);
	//Constructor
	//Postcondition: gSize = 0; maxSize = size;
	//               graph is an array of pointers to linked
	//               lists.
	//               weights is a two-dimensional array to
	//               store the weights of the edges.
	//               smallestWeight is an array to store the
	//               smallest weight from source to vertices.

	~weightedGraphType();
	//Destructor
	//The storage occupied by the vertices and the arrays
	//weights and smallestWeight is deallocated.

	vector<string> split(const char *str, char c);
	//Utility function to split help extract the edges and weights from each line read from file.

protected:
	int **weights;   //pointer to create weight matrix
	int *smallestWeight;	//pointer to create the array to
							//store the smallest weight from
							//source to vertices
};

void weightedGraphType::createWeightedGraph() {
	ifstream in("AdjListFile.txt");

	if (!in) {
		cout << "Cannot open input file.\n";
	}

	int vertex = 0;
	string line;
	int weight;
	int adjacentVertex;
	graph = new unorderedLinkedList<int>;
	while (std::getline(in, line)) {
		vector<string> edgeTokens = split(line.c_str(), ' ');
		while (!edgeTokens.empty()) {
			vector<string> weightedNode = split(edgeTokens.back().c_str(), ',');
			edgeTokens.pop_back();
			weight = atoi(weightedNode.back().c_str());
			weightedNode.pop_back();
			adjacentVertex = atoi(weightedNode.back().c_str());
			weightedNode.pop_back();
			weights[vertex][adjacentVertex] = weight;
		}
		graph->insertLast(adjacentVertex);
		vertex++;
		gSize++;
	} //end while
	in.close();

} //createWeightedGraph

void weightedGraphType::shortestPath(int vertex) {
	for (int j = 0; j < gSize; j++)
		smallestWeight[j] = weights[vertex][j];

	bool *weightFound;
	weightFound = new bool[gSize];

	for (int j = 0; j < gSize; j++)
		weightFound[j] = false;

	weightFound[vertex] = true;
	smallestWeight[vertex] = 0;

	for (int i = 0; i < gSize - 1; i++) {
		double minWeight = DBL_MAX;
		int v;

		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (smallestWeight[j] < minWeight) {
					v = j;
					minWeight = smallestWeight[v];
				}

		weightFound[v] = true;

		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (minWeight + weights[v][j] < smallestWeight[j])
					smallestWeight[j] = minWeight + weights[v][j];
	} //end for
} //end shortestPath

void weightedGraphType::printShortestDistance(int vertex) {
	cout << "Source Vertex: " << vertex << endl;
	cout << "Shortest Distance from Source to each Vertex." << endl;
	cout << "Vertex  Shortest_Distance" << endl;

	for (int j = 0; j < gSize; j++)
		cout << setw(4) << j << setw(12) << smallestWeight[j] << endl;
	cout << endl;
} //end printShortestDistance

//Constructor
weightedGraphType::weightedGraphType(int size) :
		graphType(size) {
	weights = new int*[size];

	for (int i = 0; i < size; i++)
		weights[i] = new int[size];

	smallestWeight = new int[size];
}

//Destructor
weightedGraphType::~weightedGraphType() {
	for (int i = 0; i < gSize; i++)
		delete[] weights[i];

	delete[] weights;
	delete smallestWeight;
}

vector<string> weightedGraphType::split(const char *str, char c) {
	vector<string> result;
	do {
		const char *begin = str;

		while (*str != c && *str)
			str++;
		result.push_back(string(begin, str));
	} while (0 != *str++);
	return result;
} //split implementation


#endif
