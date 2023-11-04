#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void dfs(int node, vector<bool> &visited, vector<vector<int>> &adjMatrix, vector<int> &component){
    
    
    component.push_back(node);
    visited[node] = true;
    
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[node][i] && !visited[i]) {
            dfs(i, visited, adjMatrix, component);
        }
    }
}

int main() {
    srand(time(0));
    int num_nodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> num_nodes;

    int start_node;
    cout << "Enter the starting node: ";
    cin >> start_node;

  vector<vector<int>> graph(num_nodes, vector<int>(num_nodes, 0));
  for (int i = 0; i < num_nodes; ++i) {
        int num_neighbors = rand() % (num_nodes / 2) + 1;
        for (int j = 0; j < num_neighbors; ++j) {
            int neighbor = rand() % num_nodes;
            if (i != neighbor) { // Ensure not connecting a node to itself
                graph[i][neighbor] = 1;
                graph[neighbor][i] = 1; // Create a mutual connection
            }
        }
    }
     for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nDepth First Search (DFS) starting from node " << start_node << ": ";
    int V = graph.size();
    
    vector<int> ans;
    vector<bool> visited(V, false);
    
    dfs(start_node, visited, graph, ans);
    
    for(int i=0;i<num_nodes;i++)
    {
        cout<<ans[i]<<endl;
    }
    
    
    return 0;
}
