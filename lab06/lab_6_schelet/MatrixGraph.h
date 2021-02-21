/**
 * LabSD 6
 * MatrixGraph.h
 * Purpose: Skeleton code for the matrix graph.
 *
 * @author Gabriel Bercaru
 */

#ifndef __MATRIXGRAPH_H__
#define __MATRIXGRAPH_H__

#include <vector>

/**
 * Matrix implementation.
 */
class MatrixGraph {
private:
    std::vector<std::vector<int>> adjacency_matrix;
    int size;

public:
    // Constructor
    MatrixGraph(int size) {
        // TODO: TASK 1
    }

    // Destructor
    ~MatrixGraph() {}

    /**
     * Adds an edge between two existing nodes.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     */
    void addEdge(int src, int dst) {
        // TODO: TASK 1
        adjacency_matrix[src][dst] = 1;
        adjacency_matrix[dst][src] = 1;
    }

    /**
     * Adds an edge between two existing nodes, with given cost.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     * @param cost The cost associated with the new edge.
     */
    void addEdgeWithCost(int src, int dst, int cost) {
        // TODO: BONUS 2

        adjacency_matrix[src][dst] = cost;
    }

    /**
     * Removes an existing edge from the graph.
     *
     * @param src Source node of the edge to be removed.
     * @param dst Destination node of the edge to be removed.
     */
    void removeEdge(int src, int dst) {
        // TODO: TASK 1
        adjacency_matrix[src][dst] = 0;
        adjacency_matrix[dst][src] = 0;
    }

    /**
     * Checks if there is an edge between two existing nodes.
     *
     * @param src Source node of the edge.
     * @param dst Destination node of the edge.
     * @return True if there is and edge between src and dst, False otherwise.
     */
    bool hasEdge(int src, int dst) {
        // TODO: TASK 1
        if(adjacency_matrix[src][dst] == 1)return true;
        return false;
    }

    /**
     * Returns the cost of the edge described by src and dst.
     *
     * @param src Source node of the edge.
     * @param dst Destination node of the edge.
     * @return Cost of the edge between src and dst.
     */
    int edgeCost(int src, int dst) {
        // TODO: BONUS 2
        return 0;
    }

    /**
     * Gets the vector of neighbors associated with the given node.
     *
     * @param node Node whose neighbors will get returned.
     * @return A vector containing the neighbors of the given node.
     */
    std::vector<int> getNeighbors(int node) {
        // TODO: TASK 1
        std::vector<int> v;
        int k = 0;
        for(int i = 0; i < getSize(); i++)
            if(adjacency_matrix[node][i] == 1){
                v[k] = i;
                k++;
            }
        return std::vector<int>();
    }

    /**
     * Gets the graph size.
     *
     * @return Number of nodes in the graph.
     */
    int getSize() {
        return size;
    }
};

#endif // __MATRIXGRAPH_H__
