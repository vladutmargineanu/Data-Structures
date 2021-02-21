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
        this->size = size;
        // resize(marimea, tipul de element pentru initializare)
        this->adjacency_matrix.resize(size, std::vector<int>(size));
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
        this->adjacency_matrix[src][dst] = 
            this->adjacency_matrix[dst][src] = 1;
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
         this->adjacency_matrix[src][dst] = cost;
    }

    /**
     * Removes an existing edge from the graph.
     *
     * @param src Source node of the edge to be removed.
     * @param dst Destination node of the edge to be removed.
     */
    void removeEdge(int src, int dst) {
        // TODO: TASK 1
        this->adjacency_matrix[src][dst] = 0;
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
        return this->adjacency_matrix[src][dst] == 1;
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
        return this->adjacency_matrix[src][dst];
    }

    /**
     * Gets the vector of neighbors associated with the given node.
     *
     * @param node Node whose neighbors will get returned.
     * @return A vector containing the neighbors of the given node.
     */
    std::vector<int> getNeighbors(int node) const {
        // TODO: TASK 1
        std::vector<int> neighbors;

        for (int i = 0; i < this->size; i++) {
            if (this->adjacency_matrix[node][i] == 1) {
                neighbors.push_back(i);
            }
        }

        return neighbors;
    }

    /**
     * Gets the graph size.
     *
     * @return Number of nodes in the graph.
     */
    int getSize() const {
        return this->size;
    }

    friend std::ostream& operator<<(std::ostream& os, 
        const MatrixGraph& matrix);
};

std::ostream& operator<<(std::ostream& os, const MatrixGraph& matrix) {
    os << "Adjacency Matrix: \n";

    for (int i = 0; i < matrix.getSize(); i++) {
        int counter = 0;
        auto neighbors = matrix.getNeighbors(i);

        for (int j = 0; j < matrix.getSize(); j++) {
            if (!neighbors.empty() && j == neighbors[counter]) {
                os << "1 ";
                counter++;
            } else {
                os << "0 ";
            }
        }

        os << "\n";
    }

    return os;
}

#endif // __MATRIXGRAPH_H__
