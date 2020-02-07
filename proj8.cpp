/*
Utah McEntire
CSCI 3110-001
Project #8
Due: 12/3/19
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <limits>
#include "graph.h"
using namespace std;

int main(){
	// Set variables
	string direct;
	bool directed;
	int numOfVertices=0, numOfEdges=0, startVertex=0, fromVertex=0, toVertex=0;
	float weight=0.0;
	
	// Open file
	ifstream myIn;
	myIn.open("graph.txt");
	assert(myIn);
	
	// Graph details
	myIn>>numOfVertices>>numOfEdges>>startVertex;
	// Instantiate graph
	Graph myGraph(numOfVertices);
	
	// Read in all vertices
	while(myIn){
		myIn>>fromVertex>>toVertex>>weight>>direct;
		if(direct=="false")
			directed=false;
		else
			directed=true;
		myGraph.addEdge(fromVertex, toVertex, weight, directed);
	}
	
	// Run Dijkstras Algorithm on my graph, send start vertex
	cout<<"\nShortest paths:\n";
	myGraph.DijkstraPaths(startVertex);
	
	// Close file and end
	myIn.close();
	return 0;
}