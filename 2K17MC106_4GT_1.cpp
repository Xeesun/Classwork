#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Edge {
	int first, second, edgeWeight;
};

struct compare {
	inline bool operator() (Edge e1, Edge e2) {
		return (e1.edgeWeight > e2.edgeWeight);
	}
};

vector<Edge> getGraph(int e){
	vector<Edge> edges;
	cout << "Enter details for the edge";
	for(int i = 0; i<e; i++){
		Edge edge;
		cout  << endl << "Source: "; 
		cin >> edge.first;
		cout << endl << "Destination: ";
		cin >> edge.second;
		cout << endl << "Weight";
		cin >> edge.edgeWeight;
		edges.push_back(edge); 
	}
	cout << endl;
	sort(edges.begin(), edges.end(), compare());
	return edges;
}

class EdgeSet{
	public:
		unordered_map<int, int> m;
		void makeSet(int N){ 
			for (int i = 0; i < N; i++){
				m[i] = i;
			}
		}
	
		int search(int k) {
			if (m[k] == k){
				return k;	
			}
			return search(m[k]);
		}
	
		void join(int a, int b) {
			int x = search(a);
			int y = search(b);
			m[x] = y;
		}
};

vector<Edge> Kruskal(vector<Edge> edges, int N) {
	vector<Edge> graph;
	EdgeSet selectedEdges;
	selectedEdges.makeSet(N);
	
	while (graph.size() != N - 1){
		Edge next_edge = edges.back();
		edges.pop_back();
		int x = selectedEdges.search(next_edge.first);
		int y = selectedEdges.search(next_edge.second);

		if (x != y){
			graph.push_back(next_edge);
			selectedEdges.join(x, y);
		}
	}
	return graph;
}

int main(){
	vector<Edge> edges;
	int e, v;
	cout << "Enter number of edges and vertices" << endl;
	cin >> e >> v;
	edges = getGraph(e);
	vector<Edge> finalEdges = Kruskal(edges, v);

	for (Edge &edge: finalEdges){
		cout << "(" << edge.first << ", " << edge.second << ") -> " << edge.edgeWeight << endl;	
	}
	
	return 0;



}
