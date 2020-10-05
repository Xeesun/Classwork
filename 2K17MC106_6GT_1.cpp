#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 99999 

void printSolution(int **cost, int V) { 
	cout<<"Pair wise shortest distance matrix" << endl; 
	for (int i = 0; i < V; i++) { 
		for (int j = 0; j < V; j++) { 
			if (cost[i][j] == MAX) 
				cout<<"inf"<<"	 "; 
			else
				cout<<cost[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 

void floydWarshall (int **graph, int V) { 
	int **cost = new int*[V];
	for(int i = 0; i<V; i++){
		cost[i] = new int[V];
		for(int j = 0; j<V; j++){
			cost[i][j] = 0;
		}
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if(graph[i][j] == 0 && i!=j){
				cost[i][j] = MAX;
			} else {
				cost[i][j] = graph[i][j];	
			}
		}
	}
			 

	for (int k = 0; k < V; k++) { 
		for (int i = 0; i < V; i++) { 
			for (int j = 0; j < V; j++) {  
				if (cost[i][k] + cost[k][j] < cost[i][j]) 
					cost[i][j] = cost[i][k] + cost[k][j]; 
			} 
		} 
	} 

	printSolution(cost, V); 
} 

int main() { 
	
	int V;
	cout << "Enter total number of vertices" << endl;
	cin >> V;
	int **graph = new int*[V];
	for(int i = 0; i<V; i++){
		graph[i] = new int[V];
		for(int j = 0; j<V; j++){
			cin >> graph[i][j];
		}
	}

	floydWarshall(graph, V); 
	return 0; 
} 


