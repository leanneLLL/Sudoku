//
//  Graph.cpp
//  Word-Ladder
//
//  Created by Bing Lin on 10/4/20.
//

#include "Graph.hpp"
#include <iostream>

Graph::Graph(vector<string> dict){
    dictionary = dict;
    this->V = dictionary.size();
}
int Graph::index(string value){
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i] == value)
            return i;
    }
    exit(1);
}
string Graph::value(int location)
{
    if (location <= dictionary.size()) {
        return dictionary[location];
    } else {
        exit(1);
    }
}

list<string> Graph::shortestPath(string s, string d)
{
    BFS(s, d);
    list<Node>::iterator it;
    list<string> myPath;
    
    for (it = path.begin(); it->data != d; ++it) {}
    string num = it->data;
    myPath.push_front(num);
    
    while (it != path.begin()) {
        num = it->parent;
        myPath.push_front(num);
        for (it=it; it->data != num; --it) {}
    }
    return myPath;
}

list<Node> Graph::BFS(string s, string d)
{
    int start = index(s);
    int destination = index(d);
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[start] = true;
    queue.push_back(start);
    list<int> wordsVaryByOneLetter;
    Node n;
    n.data = s;
    n.parent = s;
    path.push_back(n);
    while(start != destination && !queue.empty()){
        start = queue.front();
        queue.pop_front();
        n.parent = value(start);
        wordsVaryByOneLetter.clear();
        for (int i = 0; i < dictionary.size(); i++)
        {
            if (dictionary[i][0] != dictionary[start][0] && dictionary[i][1] == dictionary[start][1] && dictionary[i][2] == dictionary[start][2] && dictionary[i][3] == dictionary[start][3])
            {
                wordsVaryByOneLetter.push_back(i);
            } else if (dictionary[i][0] == dictionary[start][0] && dictionary[i][1] != dictionary[start][1] && dictionary[i][2] == dictionary[start][2] && dictionary[i][3] == dictionary[start][3])
            {
                wordsVaryByOneLetter.push_back(i);
            } else if (dictionary[i][0] == dictionary[start][0] && dictionary[i][1] == dictionary[start][1] && dictionary[i][2] != dictionary[start][2] && dictionary[i][3] == dictionary[start][3])
            {
                wordsVaryByOneLetter.push_back(i);
            }
            else if (dictionary[i][0] == dictionary[start][0] && dictionary[i][1] == dictionary[start][1] && dictionary[i][2] == dictionary[start][2] && dictionary[i][3] != dictionary[start][3])
            {
                wordsVaryByOneLetter.push_back(i);
            }
        }
        list<int>::iterator it;
        for (it = wordsVaryByOneLetter.begin(); it != wordsVaryByOneLetter.end(); ++it){
            if(!visited[*it] ){
                visited[*it] = true;
                queue.push_back(*it);
                n.data = dictionary[*it];
                path.push_back(n);
            }
        }
    }
    return path;
}
