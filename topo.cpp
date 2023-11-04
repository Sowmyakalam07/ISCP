#include <bits/stdc++.h>

using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
	{
	  vector<int>indegree(V,0);
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
		

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) 
				{
				    q.push(it);
				}
			}
		}

		return topo;
	}
void addEdge(int u,int v,vector<int>adj[]){
    adj[u].push_back(v);
}


int main() {

    int V = 6;
	vector<int> adj[V];
	addEdge(2,3,adj);
	addEdge(3,1,adj);
	addEdge(4,0,adj);
	addEdge(4,1,adj);
	addEdge(5,0,adj);
	addEdge(5,2,adj);

	vector<int> res = topoSort(V, adj);
    cout<<"Topological order:"<<endl;
	for (auto i: res) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}