#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define inf 99999
using namespace std; 

void shortestDist(vector<vector<int> > distance, int V){ 
	cout<<"Distance Matrix" << endl; 
	for (int i = 0; i < V; i++)
	{ 
		for (int j = 0; j < V; j++)
		{ 
            if (distance[i][j] == inf){   
                cout<<"inf"<<"     ";  
			} else {
				cout << distance[i][j] << "	 "; 	
			}
		} 
		cout<<endl; 
	} 
} 

void floydWarshall (vector<vector<int> > Matrix, int V) { 
	vector<vector<int> > distance;
	int i, j, k; 

	for (int i = 0; i < V; i++){
		vector<int> distanceI;
		for (int j = 0; j < V; j++){
				distanceI.push_back(Matrix[i][j]);	
		} 		 
		distance.push_back(distanceI);
	} 
		

	for (int k = 0; k < V; k++){ 
		for (int i = 0; i < V; i++){ 
			for (int j = 0; j < V; j++){  
				if (distance[i][k] + distance[k][j] < distance[i][j]){
					distance[i][j] = distance[i][k] + distance[k][j];	
				} 
			} 
		} 
	} 

	shortestDist(distance, V); 
} 

int main() { 
	int V;
	cout << "Enter the total vertices in the graph" << endl;
	cin >> V;
	
	vector<vector<int> > Matrix;
	for(int i = 0; i<V; i++){
		vector<int> VertexI;
		for(int j = 0; j<V; j++){
			int e;
			cin >> e;
			VertexI.push_back(e);
		}
		Matrix.push_back(VertexI);
	}
	
	for(int i = 0; i<V; i++){
		for(int j = 0; j<V; j++){
			if(Matrix[i][j] == 0 && i!=j){
				Matrix[i][j] = inf;
			}
		}
	}

	floydWarshall(Matrix, V); 
	return 0; 
} 

