/**
 * LabSD 6
 * ListGraph.h
 * Purpose: Skeleton code for the neighbors list graph.
 *
 * @author Gabriel Bercaru
 */

#ifndef __LISTGRAPH_H__
#define __LISTGRAPH_H__

#include <vector>

/**
 * Node structure is useful only for the neighbors list implementation.
 */
struct Node {
    std::vector<int> neighbors;
};

/**
 * Neighbors list implementation.
 */
class ListGraph {
private:
    // vector de tip vector (fiecare nod are cate un vector => lista de adiacenta)
    std::vector<Node> nodes;
    int size;

public:
    // Constructor
    ListGraph(int size) {
        // TODO: TASK 1
        this->size = size;
        this->nodes.resize(size);
    }

    // Destructor
    ~ListGraph() {}

    /**
     * Adds an edge between two existing nodes.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     */
    void addEdge(int src, int dst) {
        // TODO: TASK 1
        nodes[src].neighbors.push_back(dst);
        //nodes[dst].neighbors.push_back(src);
    }

    /**
     * Removes an existing edge from the graph.
     *
     * @param src Source node of the edge to be removed.
     * @param dst Destination node of the edge to be removed.
     */
    void removeEdge(int src, int dst) {
        // TODO: TASK 1
        // cautam in lista de adiacenta pe dst pentru a-l sterge
        for (auto it = nodes[src].neighbors.begin(); 
            it != nodes[src].neighbors.end(); ++it) {
            if (*it == dst) {
                nodes[src].neighbors.erase(it);
                return;
            }
        }
        //nodes[dst].neighbors.erase(nodes[dst].neighbors.begin() + src);
    }

    /**
     * Checks if there is an edge between two existing nodes.
     * 
     * @param src Source node of the edge.
     * @param dst Destination node of the edge.
     * @return True if there is an edge between src and dst, False otherwise.
     */
    bool hasEdge(int src, int dst) {
        // TODO: TASK 1
        for (auto elem : nodes[src].neighbors) {
            if (elem == dst) {
                return true;
            }
        }

        return false;
    }

    /**
     * Gets the vector of neighbors associated with the given node.
     *
     * @param node Node whose neighbors will get returned.
     * @return A vector containing the neighbors of the given node.
     */
    std::vector<int> getNeighbors(int node) const {
        // TODO: TASK 1

        return nodes[node].neighbors;
    }

    /**
     * Gets the graph size.
     *
     * @return Number of nodes in the graph.
     */
    int getSize() const {
        return size;
    }

    friend std::ostream& operator<<(std::ostream& os, const ListGraph& adjList);
};

std::ostream& operator<<(std::ostream& os, const ListGraph& adjList) {
    os << "Adjacency List: \n";

    for (int i = 0; i < adjList.getSize(); i++) {
        os << "Printing adj list for node " << i << ": ";

        for (auto node : adjList.getNeighbors(i)) {
            os << node << " ";
        }

        os << "\n";
    }

    return os;
}


#endif // __LISTGRAPH_H__
