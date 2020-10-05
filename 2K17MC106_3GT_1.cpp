#include<iostream>

int a,b,u,v,n,i,j,ne=1;
int dist[10][10];
int m, mdist=0;
using namespace std;
int main(){
	cout << "Total nodes are: " << endl;
	cin >> n;
	
	int visited[10];
	for(i = 0; i<10; i++){
		visited[i] = 0;
	}
	
	cout << "Enter complete weight matrix: " << endl;
	
	for(i = 1; i<=n; i++){
		for(j = 1; j<=n; j++){
			cin >> dist[i][j];
			if(dist[i][j] == 0){
				dist[i][j] = 999;
			}
		}
	}

	visited[1] = 1;
	while(ne < n){
		for(i = 1, m = 999; i<=n; i++)
			for(j = 1; j<=n; j++)
				if(dist[i][j] < m)
					if(visited[i] != 0){
						m = dist[i][j];
						a = u = i;
						b = v = j;		
					}
					
			if(visited[u] == 0 || visited[v] == 0) {
				cout << endl << "Edge " << ne++ << ": (" << a << " " << b << ")dist: " << m;
				mdist += m;
				visited[b] = 1;
			}
			dist[a][b] = 999;
			dist[b][a] = 999;
    }
    cout << endl << "minimum dist = " << mdist;

}
