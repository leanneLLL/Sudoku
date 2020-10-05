//
//  Graph.hpp
//  Word-Ladder
//
//  Created by Bing Lin on 10/4/20.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Node{
    string data;
    string parent;
};
class Graph{//graph with list
private:
    unsigned long V;// Nvertice number
    vector<string> values;
    list<Node> path;//the words from begin to end
    vector<string> dictionary; // dictionary of words
    
    list<Node> BFS(string start ,string destination);
    int index(string value);//search vector
    string value(int location);//access vector
    
public:
    Graph(vector<string> dict);  // Constructor
    list<string> shortestPath(string s, string d);//shortest path
};




#endif /* Graph_hpp */
