#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

enum Tag {
	PAR, IMPAR, UNDEFINED
};
class Graph {
private:
	vector<vector<int> > neigh;
	int numNodes;	
	bool oriented;
	int time;
	vector<int> finTime;
public:
	int numConnectedComp;
	vector<vector<int> > components;
	vector<vector<int> > hamCycles;
	Graph(int n, bool oriented);
	void addEdge(int i, int j);
	bool isEdge(int i, int j);
	void connectedComponents();
	void dfs(int n, vector<bool>& visited);
	stack<int> minPath(int source, int dest);
	vector<int> topSort();
	bool finTimeRevComp (int i, int j);
	void dfsTopSort(int n, vector<bool>& visited);
	bool isBipartite(pair<vector<int>, vector<int> >& p);
	void hamiltonianCycles();
	bool buildPath(vector<int>& path, vector<bool>& included, int length);
};
