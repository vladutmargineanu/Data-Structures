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
    std::vector<Node> nodes;
    int size;

public:
    // Constructor
    ListGraph(int size) {
        // TODO: TASK 1
        this->size = size;
        nodes.resize(size);
        //size = 0;
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
       // size++;
    }

    /**
     * Removes an existing edge from the graph.
     *
     * @param src Source node of the edge to be removed.
     * @param dst Destination node of the edge to be removed.
     */
    void removeEdge(int src, int dst) {
        // TODO: TASK 1
        for(auto it = nodes[src].neighbors.begin(); it != nodes[src].neighbors.end(); ++it){
            if(*it == dst){
                nodes[src].neighbors.erase(it);
                //size--;
                return ;
            }
        }
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
        for(auto elem:nodes[src].neighbors)
            if(elem == dst)
            return true;

        
        return false;
    }

    /**
     * Gets the vector of neighbors associated with the given node.
     *.
     * @param node Node whose neighbors will get returned.
     * @return A vector containing the neighbors of the given node.
     */
    std::vector<int> getNeighbors(int node) {
        // TODO: TASK 1
      //
        std::vector<int> v;
       
        /*for(int i = 0; i < getSize(); i++)
            if(hasEdge(node,i) == true){
                v.push_back(i);
               
            }*/
        return nodes[node].neighbors;
       // return std::vector<int>();
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

#endif // __LISTGRAPH_H__
