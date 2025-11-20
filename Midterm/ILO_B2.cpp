#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

template <typename T>
struct Edge {
    size_t src;
    size_t dest;
    T weight;

    bool operator<(const Edge<T> &e) const {
        return weight < e.weight;
    }
    bool operator>(const Edge<T> &e) const {
        return weight > e.weight;
    }
};

template <typename T>
class Graph {
public:
    Graph(size_t vertices) : V(vertices) {}

    void add_edge(size_t u, size_t v, T w) {
        if (u >= 1 && u <= V && v >= 1 && v <= V) {
            edge_list.push_back({u, v, w});
        } else {
            cerr << "Invalid edge!" << endl;
        }
    }

    vector<Edge<T>> outgoing_edges(size_t v) const {
        vector<Edge<T>> result;
        for (auto &e : edge_list) {
            if (e.src == v) result.push_back(e);
        }
        return result;
    }

    size_t vertices() const { return V; }

    void display() const {
        for (size_t i = 1; i <= V; i++) {
            cout << i << " -> ";
            auto adj = outgoing_edges(i);
            for (auto &e : adj) {
                cout << "{" << e.dest << ":" << e.weight << "} ";
            }
            cout << endl;
        }
    }

private:
    size_t V;
    vector<Edge<T>> edge_list;
};

template <typename T>
Graph<T> create_graph() {
    Graph<T> G(8);

    map<int, vector<pair<int, T>>> edges;
    edges[1] = {{2, 2}, {5, 3}};
    edges[2] = {{1, 2}, {5, 5}, {4, 1}};
    edges[3] = {{4, 2}, {7, 3}};
    edges[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    edges[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    edges[6] = {{4, 4}, {7, 4}, {8, 1}};
    edges[7] = {{3, 3}, {6, 4}};
    edges[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (auto &i : edges) {
        for (auto &j : i.second) {
            G.add_edge(i.first, j.first, j.second);
        }
    }

    return G;
}

template <typename T>
vector<size_t> breadth_first_search(const Graph<T>& G, size_t start) {
    queue<size_t> q;
    set<size_t> visited;
    vector<size_t> order;

    q.push(start);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            order.push_back(current);

            for (auto e : G.outgoing_edges(current)) {
                if (visited.find(e.dest) == visited.end()) {
                    q.push(e.dest);
                }
            }
        }
    }
    return order;
}

template <typename T>
void run_BFS() {
    auto G = create_graph<T>();
    cout << "Graph adjacency list:" << endl;
    G.display();

    cout << "BFS Order of vertices:" << endl;
    auto order = breadth_first_search(G, 1);
    for (auto v : order) {
        cout << v << endl;
    }
}

int main() {
    run_BFS<unsigned>();
    return 0;
}