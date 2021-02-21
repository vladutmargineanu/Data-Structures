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

#include "ListGraph.h"
#include "MatrixGraph.h"
#include <queue>

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
    std::vector<bool> visited = std::vector<bool> (listGraph.getSize(),false);
    int s = 0;
    visited[s] = true;
    std::queue<int> q;
    q.push(s);
    std::vector<int> ex;
    while(!q.empty()){
        int v;
        v = q.front();
        ex.push_back(v);

      for(auto node:listGraph.getNeighbors(v)){
        if(visited[node] == false){
            visited[node] = true;
            q.push(node);
        }
      }
      q.pop();
    }
    return ex;
        
        //return std::vector<int>();
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
        return std::vector<int>();
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
    static void rDFS(ListGraph& listGraph, std::vector<bool>& visited, std::vector<int>& nodeList, int node) {
        // TODO: BONUS 1
    }

    /**
     * Applies Floyd-Warshall on the given graph.
     *
     * @param matrixGraph Matrix representation of a graph.
     * @return A matrix where A[i][j] contains the shortest path from node i to node j.
     */
    static std::vector<std::vector<int>> Floyd_Warshall(MatrixGraph matrixGraph) {
        // TODO: BONUS 2
        return std::vector<std::vector<int>>();
    }

    /**
     * Applies Kruskal on the given graph.
     *
     * @param matrixGraph Matrix representation of a graph.
     * @return A vector of edges (described by the two adjacent nodes) which compose the minimum spanning tree.
     */
    static std::vector<std::pair<int, int>> Kruskal(MatrixGraph matrixGraph) {
        // TODO: BONUS 3
        return std::vector<std::pair<int, int>>();
    }
};

#endif // __ALGORITHMS_H__
