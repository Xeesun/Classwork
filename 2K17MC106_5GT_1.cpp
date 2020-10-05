#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int helperDjikstra(int pathLength[], bool check[], int V) { 
	
	int minHere = INT_MAX;
	int index; 
	for (int i = 0; i < V; i++){
		if (check[i] == false && pathLength[i] <= minHere){
			minHere = pathLength[i];
			index = i;
		}
							
	} 
		
	return index; 
} 

void Path(int parent[], int j){ 
	
	if (parent[j] == - 1) 
		return; 

	Path(parent, parent[j]); 
	cout << j;
} 

int Solution(int pathLength[], int V, int parent[], int src){ 
	cout << "Vertex		Distance 	Path";
	for (int i = 0; i < V; i++) { 
		if(i==src){
			continue;
		}
		cout << endl << src << " -> " << i << " 		 " << pathLength[i] << "		" << src;
		Path(parent, i); 
	} 
} 

void dijkstraAlgo(int V, vector<vector<int> > graph, int src){ 
	
	int pathLength[V]; 
	bool check[V]; 
	int parent[V]; 

	for (int i = 0; i < V; i++) { 
		parent[src] = -1; 
		pathLength[i] = INT_MAX; 
		check[i] = false; 
	} 
	
	pathLength[src] = 0;  
	for (int i = 0; i < V - 1; i++) { 
		int u = helperDjikstra(pathLength, check, V); 
		check[u] = true; 

		for (int v = 0; v < V; v++) 
			if (!check[v] && graph[u][v] && pathLength[u] + graph[u][v] < pathLength[v]) { 
				parent[v] = u; 
				pathLength[v] = pathLength[u] + graph[u][v]; 
			} 
	} 

	Solution(pathLength, V, parent, src); 
} 

int main() { 
	int V, source;
	cout << "Enter total vertices" << endl;
	cin >> V;
	cout << "Enter the source vertex" << endl;
	cin >> source;
	vector<vector<int> > graph;
	for(int i = 0; i<V; i++){
		vector<int> smallGraph;
		for(int j = 0; j<V; j++){
			int e;
			cin >> e;
			smallGraph.push_back(e);
		}
		graph.push_back(smallGraph);
	}

    dijkstraAlgo(V, graph, source); 
  
    return 0; 

} 

