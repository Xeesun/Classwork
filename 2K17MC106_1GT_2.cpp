#include<iostream>
#include<vector>
using namespace std;

int main(){
	int vertices, totalEdges, edgeCount = 0;
	cout << "Enter number of vertices and edges consecutively: ";
	cin >> vertices >> totalEdges;
	
	vector<vector<int> > matrix;
	for(int i = 0; i<vertices; i++){
		vector<int> singleVertice;
		for(int j = 0; j<totalEdges; j++){
			singleVertice.push_back(0);
		}
		matrix.push_back(singleVertice);
	}
	
	
	
	cout << "Enter start and end vertex of each edge" << endl;
	for(int i = 0; i<totalEdges; i++){
		int start, end;
		cin >> start >> end;
		matrix[start][edgeCount] = 1;
		matrix[end][edgeCount] = 1;
		edgeCount++;
	}	
		
	vector<int> edges;
	for(int i = 0; i<vertices; i++){
		int count = 0;
		for(int j = 0; j<totalEdges; j++){
			if(matrix[i][j] == 1)
				count++;
		}
		edges.push_back(count);		
	}
	
	int countVerticeEven = 0, countVerticeOdd = 0;
	vector<int> evenIndex, oddIndex;
	
	for(int i = 0; i<vertices; i++){
		if(edges[i] % 2 == 0){
			countVerticeEven++;
			evenIndex.push_back(i);
		} else {
			countVerticeOdd++;
			oddIndex.push_back(i);
		}
	}
	
	cout << "Total vertices: " << vertices << endl;
	cout << "Total edges: " << totalEdges << endl;
	cout << "Total even vertices: " << countVerticeEven << endl;
	cout << "List of indices of even vertices: " << endl;
	
	for(int i = 0; i<evenIndex.size(); i++){
		cout << evenIndex[i] << endl;
	}

	cout << "Total odd vertices: " << countVerticeOdd << endl;
	cout << "List of indices of odd vertices: " << endl;
	
	for(int i = 0; i<oddIndex.size(); i++){
		cout << oddIndex[i] << endl;
	}	
}
