#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
};

class Graph {
private:
    int V; 
    vector<Edge> edgeList;

public:
    Graph(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v, int w = 0) {
        if (u >= 1 && u <= V && v >= 1 && v <= V) {
            edgeList.push_back({u, v, w});
        }
    }

    vector<Edge> outgoingEdges(int u) const {
        vector<Edge> result;
        for (auto e : edgeList) {
            if (e.src == u) result.push_back(e);
        }
        return result;
    }

    void printGraph() const {
        for (int i = 1; i <= V; i++) {
            cout << i << ": ";
            for (auto e : edgeList) {
                if (e.src == i) {
                    cout << "{" << e.dest << "} ";
                }
            }
            cout << endl;
        }
    }
};

vector<int> DFS(const Graph &G, int start) {
    stack<int> st;
    set<int> visited;
    vector<int> order;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            order.push_back(node);

            for (auto e : G.outgoingEdges(node)) {
                if (visited.find(e.dest) == visited.end()) {
                    st.push(e.dest);
                }
            }
        }
    }
    return order;
}

Graph createGraph() {
    Graph G(8);
    map<int, vector<int>> edges = {
        {1, {2, 5}},
        {2, {1, 5, 4}},
        {3, {4, 7}},
        {4, {2, 3, 5, 6, 8}},
        {5, {1, 2, 4, 8}},
        {6, {4, 7, 8}},
        {7, {3, 6}},
        {8, {4, 5, 6}}
    };

    for (auto &p : edges) {
        for (auto v : p.second) {
            G.addEdge(p.first, v);
        }
    }
    return G;
}

int main() {
    Graph G = createGraph();

    cout << "Graph adjacency list:" << endl;
    G.printGraph();
    cout << endl;

    cout << "DFS Order of vertices:" << endl;
    vector<int> dfsOrder = DFS(G, 1);
    for (int v : dfsOrder) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}