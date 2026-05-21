#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include "assert.h"
#include <vector>
#include <stack>
#include <set>
#include <utility>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
inline vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


inline string removeParentheses(const string& input) {
    string result;
    for (char ch : input) {
        // Append characters to result if they are NOT '(' or ')'
        if (ch != '(' && ch != ')') {
            result += ch;
        }
    }
    return result;
}


template <typename T>
class Graph
{
private:
    // parent vertex , -> children vertix and his weight
    unordered_map<T, unordered_map<T, int>> g;
    vector<pair<int, string>> paths;
    Graph<std::string>* cityGraph;
    //void findMinimalDistanceHelper(T start, T end, int MinimalDistance, string path, unordered_map<T, bool> visited);
public:
    Graph();
    const unordered_map<T,unordered_map<T, int>>& getGraph() const;

   bool addVertex(T vertex);
    bool addEdge(T v1, T v2, int weight);
    void displayGraph();
    void removeEdge(T v1, T v2);
    std::string bfsTraversal(T startVertex);
   std::string DFS(const T& startVertex);
   void displayWidthDistances();
    void removeVertex(T vertex);
   // void renameVertex(T oldVertexName, T newVertexName);
   // void findMinimalDistance(T start, T end);
   std::string dijkstraShortestPath(T start, T end);
   std::string bellmanFordShortestPath(T start, T end);
   // int heuristic(const T& a, const T& b);
   // void aStarShortestPath(T start, T end);
    void saveGraph();
    bool loadGraph();
};
// template <typename T>
// Graph<T>::Graph() {
// }
template<typename T>
const unordered_map<T, unordered_map<T, int>>& Graph<T>::getGraph() const {
    return g;
}

#endif // GRAPH_H
