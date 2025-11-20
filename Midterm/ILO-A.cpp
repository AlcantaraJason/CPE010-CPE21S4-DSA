#include <iostream>
#include <vector>
#include <list>
using namespace std;


class GraphMatrix {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v, int weight = 1, bool directed = false) {
        adjMatrix[u][v] = weight;
        if (!directed) {
            adjMatrix[v][u] = weight; 
        }
    }

    void displayMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// ==========================
// Graph using Adjacency List
// ==========================
class GraphList {
private:
    int vertices;
    vector<list<int>> adjList;

public:
    GraphList(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, bool directed = false) {
        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    void displayList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

// ==========================
// Main Program
// ==========================
int main() {
    // Mapping: A=0, B=1, C=2, D=3, E=4
    int V = 5;

    //Undirected Graph
    cout << "UNDIRECTED GRAPH:" << endl;
    GraphMatrix g1(V);
    g1.addEdge(0, 1); // A-B
    g1.addEdge(0, 2); // A-C
    g1.addEdge(0, 3); // A-D
    g1.addEdge(1, 4); // B-E
    g1.addEdge(2, 3); // C-D
    g1.addEdge(3, 4); // D-E
    g1.displayMatrix();
    cout << endl;

    GraphList g2(V);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 4);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.displayList();
    cout << endl;

    //Directed Graph 
    cout << "DIRECTED GRAPH:" << endl;
    GraphMatrix g3(V);
    g3.addEdge(0, 1, 1, true); // A->B
    g3.addEdge(0, 2, 3, true); // A->C
    g3.addEdge(0, 3, 4, true); // A->D
    g3.addEdge(1, 4, 2, true); // B->E
    g3.addEdge(2, 3, 1, true); // C->D
    g3.addEdge(3, 4, 5, true); // D->E
    g3.displayMatrix();
    cout << endl;

    GraphList g4(V);
    g4.addEdge(0, 1, true);
    g4.addEdge(0, 2, true);
    g4.addEdge(0, 3, true);
    g4.addEdge(1, 4, true);
    g4.addEdge(2, 3, true);
    g4.addEdge(3, 4, true);
    g4.displayList();
    cout << endl;

    return 0;
}