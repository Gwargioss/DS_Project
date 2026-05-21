#include "Graph.h"
#include <algorithm>
#include <sstream>
template<typename T>
Graph<T>::Graph() {

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
        cout << element.first << " : ";
        for (const auto& innerMap : element.second) {
            cout << innerMap.first << " ";
        }
        cout << "\n";
    }

}
template<typename T>
void Graph<T>::removeEdge(T v1, T v2) {

    if (g.find(v1) == g.end() || g.find(v2) == g.end()) {
        cout << "Invalid Vertex Name \n";
        return;
    }


    // Access adjacency lists correctly by reference
    unordered_map<T, int>* innerM1 = &g[v1];
    unordered_map<T, int>* innerM2 = &g[v2];

    // Remove edge between the nodes
    innerM1->erase(v2);
    innerM2->erase(v1);



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
    unordered_map<T, bool> visitedMap;

    for (const auto& outerMap : g) {
        for (const auto& innerMap : outerMap.second) {
            if (visitedMap[innerMap.first] == true) {
                continue;
            }
            cout << "( " << outerMap.first << " - " << innerMap.first << " )" << " -> " << innerMap.second;
            cout << endl;
        }
        visitedMap[outerMap.first] = true;
    }
}






template<typename T>
void Graph<T>::removeVertex(T vertex) {
    // If not found
    if (g.find(vertex) == g.end()) {
        cout << "Vertex Doesn't Exist\n";
        return;
    }
    for (const auto node : g) {
        removeEdge(node.first, vertex);
    }
    g.erase(vertex);

}
/*template<typename T>
void Graph<T>::findMinimalDistanceHelper(T start, T end, int MinimalDistance, string path, unordered_map<T, bool> visited) {
    // base case
    if (start == end) { // reached
        path += "-";
        path += start;
        paths.push_back({ MinimalDistance, path });
        return;
    }
    visited[start] = true;
    for (auto& child : g[start]) {
        if (visited[child.first] == true) {
            continue;
        }
        MinimalDistance += child.second;

        path += "-";
        path += start;
        visited[child.first] = true;
        findMinimalDistanceHelper(child.first, end, MinimalDistance, path, visited);
        path = path.substr(0, path.rfind("-"));

        MinimalDistance -= child.second;
    }
    visited[start] = false;
}*/

/*template<typename T>
void Graph<T>::findMinimalDistance(T start, T end) {
    unordered_map<T, bool> visited;
    paths = {};
    findMinimalDistanceHelper(start, end, 0, "", visited);
    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i].second.substr(1, paths[i].second.length() - 1) << " : ";
        cout << paths[i].first << endl;
    }
}*/
template<typename T>
std::string Graph<T>::dijkstraShortestPath(T start, T end) {
    std::stringstream ss;
    if (g.find(start) == g.end() || g.find(end) == g.end()) {
        ss<< "Invalid Vertex Name\n";
        return ss.str();

    }

    unordered_map<T, int> distances;
    unordered_map<T, T> previous;
    unordered_map<T, bool> visited;

    for (const auto& node : g) {
        distances[node.first] = INT_MAX;
        visited[node.first] = false;
    }

    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<>> pq;

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

    vector<T> path;
    for (T at = end; at != start; at = previous[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        ss << path[i];
        if (i != path.size() - 1)
            ss << " - ";
    }
    ss << " : " << distances[end] << endl;
    return ss.str();
}
template<typename T>
std::string Graph<T>::bellmanFordShortestPath(T start, T end) {
    std::stringstream ss;
    if (g.find(start) == g.end() || g.find(end) == g.end()) {
        ss << "Invalid Vertex Name\n";
return ss.str();
    }
    unordered_map<T, int> distances;
    unordered_map<T, T> previous;

    // Step 1: Initialize distances
    for (const auto& node : g) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;

    int V = g.size();

    // Step 2: Relax all edges (V - 1) times
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

    // Step 3: Check for negative-weight cycles
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

    // Reconstruct path
    vector<T> path;
    for (T at = end; at != start; at = previous[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    // Print path
    for (int i = 0; i < path.size(); i++) {
        ss << path[i];
        if (i != path.size() - 1)
            ss << " - ";
    }
    ss << " : " << distances[end] << endl;
    return ss.str();
}

/*template<typename T>
int Graph<T>::heuristic(const T& a, const T& b) {
    return 0;
}*/
/*template<typename T>
void Graph<T>::aStarShortestPath(T start, T end) {
    if (g.find(start) == g.end() || g.find(end) == g.end()) {
        cout << "Invalid Vertex Name\n";
        return;
    }

    unordered_map<T, int> distances;
    unordered_map<T, T> previous;
    unordered_map<T, bool> visited;

    for (const auto& node : g) {
        distances[node.first] = INT_MAX;
        visited[node.first] = false;
    }

    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<>> pq;

    distances[start] = 0;
    int f_score = heuristic(start, end);
    pq.push({ f_score, start });

    while (!pq.empty()) {
        T current = pq.top().second;
        pq.pop();

        if (visited[current])
            continue;
        visited[current] = true;

        if (current == end)
            break;

        for (const auto& neighbor : g[current]) {
            int tentative_g = distances[current] + neighbor.second;
            if (tentative_g < distances[neighbor.first]) {
                distances[neighbor.first] = tentative_g;
                previous[neighbor.first] = current;
                int f = tentative_g + heuristic(neighbor.first, end);
                pq.push({ f, neighbor.first });
            }
        }
    }

    if (distances[end] == INT_MAX) {
        cout << "There is no connection between " << start << " and " << end << "\n";
        return;
    }

    vector<T> path;
    for (T at = end; at != start; at = previous[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1)
            cout << " - ";
    }
    cout << " : " << distances[end] << endl;
}*/

template<typename T>
void Graph<T>::saveGraph() {
    ofstream File("Graph_DB.txt");
    for (const auto& m1 : g) {
        File << m1.first << " : ";
        for (const auto& m2 : m1.second) {
            File << "(" << m2.first << "," << m2.second << ")" << ",";
        }
        File << endl;
    }
    File.close();
}
template<typename T>

bool  Graph<T>::loadGraph() {

    ifstream File("Graph_DB.txt");
    string line;
    vector<string> lines;
    queue<string> vertices;
    if (File.is_open()) {
        while (getline(File, line)) {
            lines.push_back(line);
            string vertex = line.substr(0, line.find(" "));
            vertices.push(vertex);
            addVertex(vertex);
        }


        for (int i = 0; i < lines.size(); i++) {
           string vectorLine = lines[i];
            string restLine = vectorLine.substr(vectorLine.find(":") + 2);
            vector<string> splitted = split(restLine, ',');

            for (int i = 0; i < splitted.size() - 1; i++) {
                string otherVertex = removeParentheses(splitted[i]);
                int EdgeWeight = stoi(removeParentheses(splitted[i + 1]));
                addEdge(vertices.front(), otherVertex, EdgeWeight);
                i++;
            }
            vertices.pop();
        }

        File.close();
    }
    else {
        // cerr << "Unable to open File!" << endl;
        return false;
    }
    return true;
}

