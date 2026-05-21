#ifndef GRAPH_H
#define GRAPH_H
#pragma once
// Minimal header-only templated Graph implementation
// Provides basic undirected weighted graph operations and traversals

#include <iostream>
#include <map>
#include <unordered_map>
#include <cassert>
#include <vector>
#include <stack>
#include <set>
#include <utility>
#include <string>
#include <fstream>
#include <queue>
#include <sstream>
#include <algorithm>

inline std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


inline std::string removeParentheses(const std::string& input) {
    std::string result;
    for (char ch : input) {
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
    // adjacency: vertex -> (neighbor -> weight)
    std::unordered_map<T, std::unordered_map<T, int>> g;
    std::vector<std::pair<int, std::string>> paths; // unused helper kept for compatibility

public:
    Graph();
    const std::unordered_map<T,std::unordered_map<T, int>>& getGraph() const;

    bool addVertex(T vertex);
    bool addEdge(T v1, T v2, int weight);
    void displayGraph();
    void removeEdge(T v1, T v2);
    std::string bfsTraversal(T startVertex);
    std::string DFS(const T& startVertex);
    void displayWidthDistances();
    void removeVertex(T vertex);
    std::string dijkstraShortestPath(T start, T end);
    std::string bellmanFordShortestPath(T start, T end);
    void saveGraph();
    bool loadGraph();
};

// Implementation (header-only templates)
template<typename T>
Graph<T>::Graph() {}

template<typename T>
const std::unordered_map<T, std::unordered_map<T, int>>& Graph<T>::getGraph() const {
    return g;
}

template<typename T>
bool Graph<T>::addVertex(T vertex) {
    if (g.find(vertex) != g.end()) {
        return false;
    }
    g[vertex] = {};
    return true;
}

template<typename T>
bool Graph<T>::addEdge(T v1, T v2, int weight) {
    // undirected Graph
    if (g.find(v1) == g.end() || g.find(v2) == g.end()) {
        return false;
    }
    g[v1][v2] = weight;
    g[v2][v1] = weight;
    return true;
}

template<typename T>
void Graph<T>::displayGraph() {
    for (const auto& element : g) {
        std::cout << element.first << " : ";
        for (const auto& innerMap : element.second) {
            std::cout << innerMap.first << " ";
        }
        std::cout << "\n";
    }
}

template<typename T>
void Graph<T>::removeEdge(T v1, T v2) {
    if (g.find(v1) == g.end() || g.find(v2) == g.end()) {
        std::cout << "Invalid Vertex Name \n";
        return;
    }

    g[v1].erase(v2);
    g[v2].erase(v1);
}

template<typename T>
std::string Graph<T>::bfsTraversal(T startVertex) {
    if (g.find(startVertex) == g.end()) {
        return "The start city doesn't exist in the graph.\n";
    }

    std::unordered_map<T, bool> visited;
    std::queue<T> q;
    std::stringstream ss;

    visited[startVertex] = true;
    q.push(startVertex);

    ss << "BFS Traversal starting from " << startVertex  << ":\n";

    while (!q.empty()) {
        T current = q.front();
        q.pop();
        ss << current << " ";

        for (const auto& neighbor : g[current]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }

    return ss.str();
}

template<typename T>
std::string Graph<T>::DFS(const T& startVertex) {
    std::set<T> visited;
    std::stack<T> s;
    std::stringstream ss;

    s.push(startVertex);
    ss << "DFS traversal from " << startVertex << ": ";

    while (!s.empty()) {
        T current = s.top();
        s.pop();

        if (visited.find(current) == visited.end()) {
            ss << current << " ";
            visited.insert(current);

            for (const auto& neighbor : g[current]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    s.push(neighbor.first);
                }
            }
        }
    }

    return ss.str();
}

template<typename T>
void Graph<T>::displayWidthDistances() {
    std::unordered_map<T, bool> visitedMap;

    for (const auto& outerMap : g) {
        for (const auto& innerMap : outerMap.second) {
            if (visitedMap[innerMap.first] == true) {
                continue;
            }
            std::cout << "( " << outerMap.first << " - " << innerMap.first << " )" << " -> " << innerMap.second;
            std::cout << std::endl;
        }
        visitedMap[outerMap.first] = true;
    }
}

template<typename T>
void Graph<T>::removeVertex(T vertex) {
    if (g.find(vertex) == g.end()) {
        std::cout << "Vertex Doesn't Exist\n";
        return;
    }
    for (const auto& node : g) {
        removeEdge(node.first, vertex);
    }
    g.erase(vertex);
}

template<typename T>
std::string Graph<T>::dijkstraShortestPath(T start, T end) {
    std::stringstream ss;
    if (g.find(start) == g.end() || g.find(end) == g.end()) {
        ss<< "Invalid Vertex Name\n";
        return ss.str();
    }

    std::unordered_map<T, int> distances;
    std::unordered_map<T, T> previous;
    std::unordered_map<T, bool> visited;

    for (const auto& node : g) {
        distances[node.first] = INT_MAX;
        visited[node.first] = false;
    }

    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<>> pq;

    distances[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        T current = pq.top().second;
        pq.pop();

        if (visited[current])
            continue;

        visited[current] = true;

        for (const auto& neighbor : g[current]) {
            int newDistance = distances[current] + neighbor.second;
            if (newDistance < distances[neighbor.first]) {
                distances[neighbor.first] = newDistance;
                previous[neighbor.first] = current;
                pq.push({ newDistance, neighbor.first });
            }
        }
    }

    if (distances[end] == INT_MAX) {
       ss << "There is no connection between " << start << " and " << end << "\n";
        return ss.str();

    }

    std::vector<T> path;
    for (T at = end; at != start; at = previous[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        ss << path[i];
        if (i != path.size() - 1)
            ss << " - ";
    }
    ss << " : " << distances[end] << std::endl;
    return ss.str();
}

template<typename T>
std::string Graph<T>::bellmanFordShortestPath(T start, T end) {
    std::stringstream ss;
    if (g.find(start) == g.end() || g.find(end) == g.end()) {
        ss << "Invalid Vertex Name\n";
        return ss.str();
    }
    std::unordered_map<T, int> distances;
    std::unordered_map<T, T> previous;

    for (const auto& node : g) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;

    int V = g.size();

    for (int i = 0; i < V - 1; i++) {
        for (const auto& u : g) {
            for (const auto& v : u.second) {
                if (distances[u.first] != INT_MAX && distances[u.first] + v.second < distances[v.first]) {
                    distances[v.first] = distances[u.first] + v.second;
                    previous[v.first] = u.first;
                }
            }
        }
    }

    for (const auto& u : g) {
        for (const auto& v : u.second) {
            if (distances[u.first] != INT_MAX && distances[u.first] + v.second < distances[v.first]) {
                ss << "Graph contains a negative weight cycle\n";
                return ss.str();
            }
        }
    }

    if (distances[end] == INT_MAX) {
        ss<< "There is no connection between " << start << " and " << end << "\n";
        return ss.str();
    }

    std::vector<T> path;
    for (T at = end; at != start; at = previous[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        ss << path[i];
        if (i != path.size() - 1)
            ss << " - ";
    }
    ss << " : " << distances[end] << std::endl;
    return ss.str();
}

template<typename T>
void Graph<T>::saveGraph() {
    std::ofstream File("Graph_DB.txt");
    for (const auto& m1 : g) {
        File << m1.first << " : ";
        for (const auto& m2 : m1.second) {
            File << "(" << m2.first << "," << m2.second << ")" << ",";
        }
        File << std::endl;
    }
    File.close();
}

template<typename T>
bool Graph<T>::loadGraph() {
    std::ifstream File("Graph_DB.txt");
    std::string line;
    std::vector<std::string> lines;
    std::queue<std::string> vertices;
    if (File.is_open()) {
        while (getline(File, line)) {
            lines.push_back(line);
            std::string vertex = line.substr(0, line.find(" "));
            vertices.push(vertex);
            addVertex(vertex);
        }


        for (int i = 0; i < (int)lines.size(); i++) {
           std::string vectorLine = lines[i];
            std::string restLine = vectorLine.substr(vectorLine.find(":") + 2);
            std::vector<std::string> splitted = split(restLine, ',');

            for (int j = 0; j < (int)splitted.size() - 1; j++) {
                std::string otherVertex = removeParentheses(splitted[j]);
                int EdgeWeight = stoi(removeParentheses(splitted[j + 1]));
                addEdge(vertices.front(), otherVertex, EdgeWeight);
                j++;
            }
            vertices.pop();
        }

        File.close();
    }
    else {
        return false;
    }
    return true;
}

#endif // GRAPH_H
