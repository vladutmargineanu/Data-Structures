#include "Graph.h"

#include <climits>
#include <algorithm>
/*
	Constructor
*/
Graph::Graph(int n, bool oriented) {
	this->numNodes = n;
	this->oriented = oriented;
	for (int i = 0; i < numNodes; i++) {
		neigh.push_back(vector<int>());
	}
}

/* 
	Adds an edge to the graph (both ways if unoriented)
*/
void Graph::addEdge(int i, int j) {
	neigh[i].push_back(j);
	if (!oriented) {
		// graf neorientat
		neigh[j].push_back(i);
	}
}

/*
	Checks if two nodes are connected by an edge
*/
bool Graph::isEdge(int i, int j) {
	vector<int> v = neigh[i];
	return std::find(v.begin(), v.end(), j) != v.end();
}

void Graph::connectedComponents() {

	/* TODO 1 Initializations */
	std::vector<bool> visited = std::vector<bool>(this->numNodes, false);
	/* 
		TODO 1 Call dfs for all unvisited nodes
		
		Use: components.push_back(vector<int>());
			to create new component
	*/

	for (int i = 0; i < this->numNodes; i++) {
		if (!visited[i]) {
			this->components.push_back(vector<int>());
			dfs(i, visited);
			this->numConnectedComp++;
		}
	}
}

void Graph::dfs(int node, vector<bool>& visited) {
	/*
		TODO 1 Perform dfs
			To add node to component use:
			components[numConnectedComp].push_back(node);
	*/
	visited[node] = true;
	this->components[this->numConnectedComp].push_back(node);
    // dfs recursiv
	for (auto v : this->neigh[node]) {
		if (!visited[v]) {
			dfs(v, visited);
		}
	}
}

stack<int> Graph::minPath(int source, int dest) {
	int currNode;
	vector<bool> visited;
	std::queue<int> q;
	vector<int> dist;
	vector<int> parent(numNodes);
	
	/* TODO 2 Initializations */
	// Initializam toate distantele cu inf (INT_MAX)
	dist.resize(this->numNodes, INT_MAX);
	visited.resize(this->numNodes, false);
	parent.resize(this->numNodes, -1);

	/*
		TODO 2 Perform BFS from source, keeping track of distance and parent
	*/
	q.push(source);
	dist[source] = 0;
	visited[source] = true;

	while (!q.empty()) {
		currNode = q.front();
		q.pop();

		for (auto v : this->neigh[currNode]) {
			if (!visited[v]) {
				// daca nu a fost vizitat
				dist[v] = dist[currNode] + 1;
				parent[v] = currNode;
				visited[v] = true;
				q.push(v);
			}
		}
	}

	stack<int> path;
	// There is no path from source to destination
	if (parent[dest] == -1) return path;
	if (dist[dest] == INT_MAX) return path;

	/*
		TODO 2 Start from destination, node becomes its parent and gets
		pushed onto the stack while source is not reached
	*/

	currNode = dest;

	while(currNode != source) {
		path.push(currNode);
		currNode = parent[currNode];
	}

	path.push(source);

	return path;
}

/*
	Comparator for finTime used in topologicalSort
*/
struct comp {
	vector<int> finTime;
	comp(vector<int>& finTime) {
		this->finTime = finTime;
	}
	bool operator()(int i, int j) const {
		return finTime[i] > finTime[j];
	}
};

vector<int> Graph::topSort() {
	vector<bool> visited;
	vector<int> topSortOrder;

	finTime.resize(numNodes);
	visited.resize(this->numNodes);

	for (int i = 0; i < numNodes; i++) {
		/*
			TODO 3 Initialize visited
		*/

		visited[i] = false;
		finTime[i] = 0;
		topSortOrder.push_back(i);
	}
	
	this->time = 0;
	/*
		TODO 3 Call dfsTopSort for each unvisited node
	*/

	for (int i = 0; i < numNodes; i++) {
		if (!visited[i]) {
			dfsTopSort(i, visited);
		}
	}
	
	comp c(finTime);
	
	// Nodes sorted in descending order by finTime
	sort(topSortOrder.begin(), topSortOrder.end(), c);
	return topSortOrder;
}

void Graph::dfsTopSort(int n, vector<bool>& visited) {
	/* 
		TODO 3 Perform DFS keeping track of finTime
	*/

	std::stack<int> s;
	
	visited[n] = true;
	s.push(n);

	while (!s.empty()) {
		int currNode = s.top();

		int unvisited_neigh = -1;
		for (auto v : this->neigh[currNode]) {
			if (!visited[v]) {
				unvisited_neigh = v;
				break;
			}
		}

		if (unvisited_neigh != -1) {
			visited[unvisited_neigh] = true;
			s.push(unvisited_neigh);
		} else {
			this->time++;
			this->finTime[currNode] = this->time;
			s.pop();
		}
	}
}

bool Graph::isBipartite(pair<vector<int>, vector<int> >& p) {
	vector<int> sides[2];
	vector<Tag> tag(numNodes);
	queue<int> q;

	/*
		TODO 4 Initialize all tags with UNDEFINED
	*/

	std::fill(tag.begin(), tag.end(), UNDEFINED);
	
	tag[0] = PAR;
	q.push(0);
	
	/*
		TODO 4 Perform BFS, marking the tags accordingly
	*/
	
	while (!q.empty()) {
		int currNode = q.front();
		q.pop();

		for (auto v : this->neigh[currNode]) {
			if (tag[v] == UNDEFINED) {
				tag[v] = (tag[currNode] == PAR ? IMPAR : PAR);
				q.push(v);
			} else if (tag[v] == tag[currNode]) {
				return false;
			}
		}
	}
	/*
		TODO 4 sides[0] will contain nodes with PAR tag and sides[1]
		the nodes with IMPAR tag
		
		To add node to one side: sides[x].push_back(node);
	*/

	for (int i = 0; i < this->numNodes; i++) {
		if (tag[i] == PAR) {
			sides[0].push_back(i);
		}

		if (tag[i] == IMPAR) {
			sides[1].push_back(i);
		}
	}

	p = make_pair(sides[0], sides[1]);
	return true;
}
void Graph::hamiltonianCycles() {
	vector<bool> included(numNodes, false);
	vector<int> path(numNodes, -1);

	/*
		TODO BONUS Start constructing path from node 0
	*/
	included[0] = true;
	path[0] = 0;
	buildPath(path, included, 1);
}

bool Graph::buildPath(vector<int>& path, vector<bool>& included, int length) {
	/*
		TODO BONUS Check if path represents a hamiltonian cycle and add it to the list:
				hamCycles.push_back(path);
		
			Otherwise try to include each node to the path.
			
			Path already has the right size, use [] operator not push_back!
	*/
	if (length == this->numNodes) {
		int start = path[0];
		int end = path[length - 1];

		if (this->isEdge(start, end)) {
			this->hamCycles.push_back(path);
			return true;
		}
	} else {
		int end = path [length - 1];
		for (auto v : this->neigh[end]) {
			if (!included[v]) {
				path[length] = v;
				included[v] = true;
				buildPath(path, included, length + 1);
				path[length] = -1;
				included[v] = false;
			}
		}
	}

	return false;
}
