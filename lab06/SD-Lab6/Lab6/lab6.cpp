/**
 * LabSD 6
 * lab6.cpp
 * Purpose: Driver program to run lab6 tasks.
 *
 * @author Gabriel Bercaru
 */

#include <fstream>
#include <iostream>

#include "Algorithms.h"
#include "ListGraph.h"
#include "MatrixGraph.h"

void print(std::vector<int> vector) {
    for (auto it = vector.begin(); it != vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void printFile(std::vector<int> vector, const char *fileName) {
    std::ofstream outFile;
    outFile.open(fileName);

    for (auto it = vector.begin(); it != vector.end(); ++it) {
        outFile << *it << " ";
    }

    outFile << "\n";
    outFile.close();
}

ListGraph createListGraph(const char *inputFilename) {
    std::ifstream inFile;
    inFile.open(inputFilename);
    int n, m;

    inFile >> n >> m;
    ListGraph listGraph(n);

    for (int i = 0; i < m; ++i) {
        int x, y;

        inFile >> x >> y;
        listGraph.addEdge(x, y);
        listGraph.addEdge(y, x);
    }

    inFile.close();

    return listGraph;
}

MatrixGraph createMatrixGraph(const char *inputFilename) {
    std::ifstream inFile;
    inFile.open(inputFilename);
    int n, m;

    inFile >> n >> m;
    MatrixGraph matrixGraph(n);

    for (int i = 0; i < m; ++i) {
        int x, y;

        inFile >> x >> y;
        matrixGraph.addEdge(x, y);
        matrixGraph.addEdge(y, x);
    }

    inFile.close();

    return matrixGraph;
}

void checkBFS(const char *inputFilename) {
    std::vector<int> result;

    // TASK 2:
    ListGraph listGraph = createListGraph(inputFilename);
    result = Algorithms::BFS(listGraph);

    /* MatrixGraph matrixGraph = createMatrixGraph(inputFilename);
    result = BFS(matrixGraph); */

#ifdef DEBUG
    print(result);
#else
    printFile(result, "Out/Lab6/task2.out");
#endif
}

void checkDFS(const char *inputFilename) {
    std::vector<int> result;

    // TASK 3:
    ListGraph listGraph = createListGraph(inputFilename);
    result = Algorithms::DFS(listGraph);

    /* MatrixGraph matrixGraph = createMatrixGraph(inputFilename);
    result = BFS(matrixGraph); */

#ifdef DEBUG
    print(result);
#else
    printFile(result, "Out/Lab6/task3.out");
#endif
}

void checkRDFS(const char *inputFilename) {
    // BONUS 1:
    ListGraph listGraph = createListGraph(inputFilename);
    std::vector<int> nodeList;
    std::vector<bool> visited(listGraph.getSize(), false);

    Algorithms::rDFS(listGraph, visited, nodeList, 0);

#ifdef DEBUG
    print(nodeList);
#else
    printFile(nodeList, "Out/Lab6/bonus1.out");
#endif
}

void checkFloydWarshall(const char *inputFilename) {

#ifdef DEBUG
    std::ostream& bonus2 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab6/bonus2.out");
    std::ostream& bonus2 = file;
#endif

    std::ifstream inFile;
    inFile.open(inputFilename);
    int n;

    // BONUS 2:
    inFile >> n;

    MatrixGraph costMatrixGraph(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cost;
            inFile >> cost;
            costMatrixGraph.addEdgeWithCost(i, j, cost);
        }
    }

    std::vector<std::vector<int>> distanceMatrix = Algorithms::Floyd_Warshall(costMatrixGraph);

    for (unsigned int i = 0; i < distanceMatrix.size(); ++i) {
        for (unsigned int j = 0; j < distanceMatrix[i].size(); ++j) {
            bonus2 << distanceMatrix[i][j] << " "; 
        }

        bonus2 << "\n";
    }

    inFile.close();

#ifndef DEBUG
    file.close();
#endif
}

void checkKruskal(const char *inputFilename) {

#ifdef DEBUG
    std::ostream& bonus3 = std::cout;
#else
    std::ofstream file;
    file.open("Out/Lab6/bonus3.out");
    std::ostream& bonus3 = file;
#endif

    std::ifstream inFile;
    inFile.open(inputFilename);
    int n;

    // BONUS 3:
    inFile >> n;

    MatrixGraph costMatrixGraph(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            inFile >> cost;
            costMatrixGraph.addEdgeWithCost(i, j, cost);
        }  
    }

    std::vector<std::pair<int, int>> spanningTreeEdges = Algorithms::Kruskal(costMatrixGraph);

    for (unsigned int i = 0; i < spanningTreeEdges.size(); i++) {
        bonus3 << spanningTreeEdges[i].first << " " <<
            spanningTreeEdges[i].second << std::endl;
    }

    inFile.close();

#ifndef DEBUG
    file.close();
#endif
}

int main(int argc, char *argv[]) {
    std::cout << createListGraph("In/input_task_2.txt");
    std::cout << createMatrixGraph("In/input_task_2.txt");

    checkBFS("In/input_task_2.txt");
    checkDFS("In/input_task_3.txt");
    checkRDFS("In/input_bonus_1.txt");
    checkFloydWarshall("In/input_bonus_2.txt");
    checkKruskal("In/input_bonus_3.txt");

    return 0;
}
