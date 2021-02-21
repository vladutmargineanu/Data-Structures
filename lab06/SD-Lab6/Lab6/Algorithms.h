/**
 * Lab6 SD
 * Algorithms.h
 * Purpose: Wrapper class for Lab6 algorithms.
 *
 * @author Gabriel Bercaru
 */

#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#include "ListGraph.h"
#include "MatrixGraph.h"

class Algorithms {
public:
    /**
     * Returns a breadth-first traversal of the given matrix graph.
     *
     * @param matrixGraph Matrix representation of a graph.
     * @return A vector containing indexes of the nodes, visited using BFS.
     */
    static std::vector<int> BFS(MatrixGraph matrixGraph) {
        // TODO: TASK 2
        return std::vector<int>();
    }

    /**
     * Returns a breadth-first traversal of the given list graph.
     *
     * @param listGraph Neighbors list representation of a graph.
     * @return A vector containing indexes of the nodes, visited using BFS.
     */
    static std::vector<int> BFS(ListGraph listGraph) {
        // TODO: TASK 2
        int size = listGraph.getSize();
        // initializam vectorul bool cu false (toate elementele)
        std::vector<bool> visited = std::vector<bool>(size, false);
        std::vector<int> bfs = std::vector<int>();

        std::queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            bfs.push_back(node);
            q.pop();
            std::cout << "new call\n";

            for (auto neigh : listGraph.getNeighbors(node)) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                } 
            }
        }

        return bfs;
    }

    /**
     * Returns a depth-first traversal of the given matrix graph.
     *
     * @param matrixGraph Matrix representation of a graph.
     * @return A vector containing indexes of the nodes, visited using DFS.
     */
    static std::vector<int> DFS(MatrixGraph matrixGraph) {
        // TODO: TASK 3
        return std::vector<int>();
    }

    /**
     * Returns a depth-first traversal if the given graph.
     *
     * @param listGraph Neighbors list representation of a graph.
     * @return A vector containing indexes of the nodes, visited using DFS.
     */
    static std::vector<int> DFS(ListGraph listGraph) {
        // TODO: TASK 3
        int size = listGraph.getSize();
        std::vector<bool> visited = std::vector<bool>(size, false);
        std::vector<int> dfs = std::vector<int>();

        std::stack<int> s;
        s.push(0);
        visited[0] = true;

        while (!s.empty()) {
            int node = s.top();
            dfs.push_back(node);
            s.pop();

            for (auto neigh : listGraph.getNeighbors(node)) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    s.push(neigh);
                } 
            }
        }

        return dfs;
    }

    /**
     * Applies recursive DFS on the given graph.
     * The result of the traversal must be placed in nodeList.
     *
     * @param listGraph Neighbors list representation of a graph.
     * @param visited Vector containing the visit status of each node.
     * @param nodeList Vector which must contain the result of the traversal.
     * @param node The starting point of the traversal.
     */
    static void rDFS(ListGraph& listGraph, std::vector<bool>& visited, 
    	std::vector<int>& nodeList, int node) {
        // TODO: BONUS 1
        visited[node] = true;
        nodeList.push_back(node);

        for (auto neigh : listGraph.getNeighbors(node)) {
            if (!visited[neigh]) {
                rDFS(listGraph, visited, nodeList, neigh);
            }
        }
    }

    /**
     * Applies Floyd-Warshall on the given graph.
     *
     * @param matrixGraph Matrix representation of a graph.
     * @return A matrix where A[i][j] contains the shortest path from node i to node j.
     */
    static std::vector<std::vector<int>> Floyd_Warshall(MatrixGraph matrixGraph) {
        // TODO: BONUS 2
        int size = matrixGraph.getSize();
        std::vector<std::vector<int>> dist;

        dist.resize(size, std::vector<int>(size, 0));

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                dist[i][j] = matrixGraph.edgeCost(i, j);
            }
        }

        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (dist[i][k] + dist[k][j] <= dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }

    static int getParent(int node, std::vector<int> parents) {
        if (parents[node] == node) {
            return node;
        }

        return getParent(parents[node], parents);
    }

    static void unite(int node1, int node2, std::vector<int> &parents, 
        std::vector<int> ranks) {
        if (ranks[node1] < ranks[node2]) {
            parents[node1] = node2;
            return;
        }

        if (ranks[node2] < ranks[node1]) {
            parents[node2] = node1;
            return;
        }

        parents[node2] = node1;
        ranks[node1]++;
    }

    /**
     * Applies Kruskal on the given graph.
     *
     * @param matrixGraph Matrix representation of a graph.
     * @return A vector of edges (described by the two adjacent nodes) which 
     compose the minimum spanning tree.
     */
    static std::vector<std::pair<int, int>> Kruskal(MatrixGraph matrixGraph) {
        // TODO: BONUS 3
        int size = matrixGraph.getSize();
        std::vector<std::pair<int, int>> tree = std::vector<std::pair<int, int>>();
        
        std::vector<std::pair<int, std::pair<int, int>>> initial;
        
        std::vector<int> parents = std::vector<int>(size, 0);
        std::vector<int> ranks = std::vector<int>(size, 0);

        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int cost = matrixGraph.edgeCost(i, j);

                if (cost != 0) {
                    initial.push_back({cost, {i, j}});
                }
            }
        }

        sort(initial.begin(), initial.end());

        for (unsigned int i = 0; i < initial.size(); i++) {
            std::pair<int, std::pair<int, int>> currPair = initial[i];
            int node1 = currPair.second.first,
                node2 = currPair.second.second;
                //cost = currPair.first;

            int parent1 = getParent(node1, parents),
                parent2 = getParent(node2, parents);

            if (parent1 != parent2) {
                unite(parent1, parent2, parents, ranks);
                tree.push_back({node1, node2});
            }
        }


        return tree;
    }
};

#endif // __ALGORITHMS_H__
