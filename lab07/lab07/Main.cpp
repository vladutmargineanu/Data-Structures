#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "Graph.h"
using namespace std;
int main() {

	int nNodes, nEdges, u, v;
	std::ifstream in1, in2, in3, in4, inb;
	std::ofstream file1, file2, file3, file4, fileb;

	in1.open("Input/Lab7/task1.in");
#ifdef DEBUG
	std::ostream& out1 = std::cout;
#else
	file1.open("Out/Lab7/task1.out");
	std::ostream& out1 = file1;
#endif
	
	in1 >> nNodes >> nEdges;

	Graph g1(nNodes, false);
	
	for (int i = 0; i < nEdges; i++) {
		in1 >> u >> v;
		g1.addEdge(u, v);
	}
	g1.connectedComponents();
	vector<vector<int> > comp = g1.components;
	out1 << g1.numConnectedComp << std::endl;
	
	for (int i = 0; i < g1.numConnectedComp; i++) {
		vector<int> v = comp[i];
		std::sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); j++) {
			out1 << v[j] << " ";
		}
		out1 << std::endl;
	}

	in1.close();
#ifndef DEBUG
	file1.close();
#endif
	
	in2.open("Input/Lab7/task2.in");
#ifdef DEBUG
	std::ostream& out2 = std::cout;
#else
	file2.open("Out/Lab7/task2.out");
	std::ostream& out2 = file2;
#endif
	
	int nTests;
	
	in2 >> nNodes >> nEdges >> nTests;

	Graph g2(nNodes, false);
	
	for (int i = 0; i < nEdges; i++) {
		in2 >> u >> v;
		g2.addEdge(u, v);
	}
	for (int i = 0; i < nTests; i++) {
		int source, dest;
		in2 >> source >> dest;
		stack<int> s = g2.minPath(source, dest);
		if (s.empty()) {
			out2 << "Impossible";
		}
		while(!s.empty()) {
			int x = s.top();
			out2 << x << " ";
			s.pop();
		}
		out2 << endl;
	}

	in2.close();
#ifndef DEBUG
	file2.close();
#endif
	
	in3.open("Input/Lab7/task3.in");
#ifdef DEBUG
	std::ostream& out3 = std::cout;
#else
	file3.open("Out/Lab7/task3.out");
	std::ostream& out3 = file3;
#endif
	
	in3 >> nNodes >> nEdges;

	Graph g3(nNodes, true);
	
	unordered_map<string, int> namesToNodes;
	vector<string> nodesToNames;
	nodesToNames.resize(nNodes + 1);
	int nodeCount = 0;
	for (int i = 0; i < nEdges; i++) {
		std::string s1, s2;
		in3 >> s1 >> s2;
		auto hasS1 = namesToNodes.find(s1);
		if (hasS1 == namesToNodes.end()) {
			namesToNodes[s1] = nodeCount;
			nodesToNames[nodeCount] = s1;
			nodeCount++;
		}
		auto hasS2 = namesToNodes.find(s2);
		if (hasS2 == namesToNodes.end()) {
			namesToNodes[s2] = nodeCount;
			nodesToNames[nodeCount] = s2;
			nodeCount++;
		}
		int u, v;
		u = namesToNodes[s1];
		v = namesToNodes[s2];
		g3.addEdge(u, v);
	}
	
	vector<int> topSort = g3.topSort();
	for (int i = 0; i < nNodes; i++) {
		int x = topSort[i];
		out3 << nodesToNames[x] << endl;
	}

	in3.close();
#ifndef DEBUG
	file3.close();
#endif
	
	in4.open("Input/Lab7/task4.in");
#ifdef DEBUG
	std::ostream& out4 = std::cout;
#else
	file4.open("Out/Lab7/task4.out");
	std::ostream& out4 = file4;
#endif
	
	in4 >> nNodes >> nEdges;

	Graph g4(nNodes, false);
	
	for (int i = 0; i < nEdges; i++) {
		in4 >> u >> v;
		g4.addEdge(u, v);
	}
	pair<vector<int>, vector<int> > p;
	vector<int> sides[2];
	bool bipartite = g4.isBipartite(p);
	sides[0] = p.first;
	sides[1] = p.second;
	
	if (!bipartite) {
		out4 << "Not bipartite\n";
	} else {
		for (int i = 0; i < sides[0].size(); i++) {
			out4 << sides[0][i] << " ";
		}
		out4 << endl;
		for (int i = 0; i < sides[1].size(); i++) {
			out4 << sides[1][i] << " ";
		}
	}

	in4.close();
#ifndef DEBUG
	file4.close();
#endif
	
	inb.open("Input/Lab7/bonus1.in");
#ifdef DEBUG
	std::ostream& outb = std::cout;
#else
	fileb.open("Out/Lab7/bonus1.out");
	std::ostream& outb = fileb;
#endif

	inb >> nTests;
	
	for (int i = 0; i < nTests; i++) {
		inb >> nNodes >> nEdges;

		Graph gb(nNodes, false);

		for (int i = 0; i < nEdges; i++) {
			inb >> u >> v;
			gb.addEdge(u, v);
		}
		vector<vector<int> > hamCycle;
		gb.hamiltonianCycles();
		if (gb.hamCycles.size() == 0) {
			outb << "There is no hamiltonian cycle";
		} else {
			for (int i = 0; i < gb.hamCycles.size(); i++) {
				for (int j = 0; j < nNodes; j++) {
					outb << gb.hamCycles[i][j] << " ";
				}
				outb << endl;
			}
		}
		outb << endl;
	}

	inb.close();
#ifndef DEBUG
	fileb.close();
#endif

	return 0;
}
