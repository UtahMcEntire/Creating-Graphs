/*
Utah McEntire
CSCI 3110-001
Project #8
Due: 12/3/19
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <limits>
#include "graph.h"
using namespace std;

// Constructor
Graph::Graph(int numNodes){
	numVertices = numNodes;
};

void Graph::addEdge(int startvertex, int endvertex, double weight, bool directed){
	Edge e=Edge(startvertex, endvertex, weight);
	if (!(startvertex < adjacent.size())){
		adjacent.resize(startvertex + 1);
	}
	cout<<"Edge "<<startvertex<<", "<<endvertex<<", "<<weight<<endl;
	adjacent[startvertex].push_back(e);
	
	if(!directed){
		Edge e=Edge(endvertex, startvertex, weight);
		if (! (endvertex<adjacent.size())){
			adjacent.resize(endvertex+1);
		}
		cout<<"Edge "<<endvertex<<", "<<startvertex<<", "<<weight<<endl;
		adjacent[endvertex].push_back(e);
	}
	
	
	//Outputs adjacency list for testing
	/*
	for (size_t i = 0; i < adjacent.size(); ++i) {
        std::list<Edge>::iterator li;
		cout<<"i: ";
        for (li = adjacent[i].begin(); li != adjacent[i].end(); ++li)
			std::cout <<": "<< li->v1 << ", "<<li->v2<<", "<<li->weight<<" ";
		cout<<endl;
    }*/
}

// Computes/Outputs single source shortest paths - Param: source vertex
void Graph::DijkstraPaths(int src){
	PathNode pn;	  // Local data structure to hold cost and prev
	set<pair<double, int>> s; // Create openlist

    pn.cost = numeric_limits<double>::infinity(); //Set initial cost to infinity
	pn.prev = -1;	// Initial prev node to -1
    s.insert(make_pair(0,src)); //Initial openlist values
	while(!s.empty()){
		int i=0;
		auto p = *(s.begin());
		int nodeDist = p.first; //----------
        s.erase(s.begin());
		
		for(auto childPair: adjacent[p.second]){ //-----------
			if(nodeDist + childPair.weight < pn.cost){ //---------
				// Delete old and make new to update
				int dest = childPair.v1; //--------
				auto f = s.find(make_pair(pn.cost,dest));
				if(f!=s.end()){
					s.erase(f);
				}
				//Insert the new pair
				pn.cost = nodeDist + childPair.weight; //----------
				s.insert(make_pair(pn.cost,dest)); //----------
				for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it) {
					// 'it' is an iterator
					cout << i 
						 << " cost: " 
						 <<it->first		 
						 <<setw(10) <<right
						 <<" prev: " 
						 <<setw(5) << right 
						 << it->second
						 <<endl;
					i++;
				}
            }
		}
	}
}
