//
// Created by aleks on 20.10.22.
//

#ifndef PEA_1_GRAPH_H
#define PEA_1_GRAPH_H
#include "fstream"
#include "iostream"
#include "algorithm"
#include "vector"
#include "utility"

class Graph {

private:

    int **adjacenty_matrix;
    int verticles;

    std::vector<std::pair<std::vector<int>,int>> path;

public:

    Graph();
    ~Graph();
    void print_graph();

    int brute_force();
    void print_weights();
};


#endif //PEA_1_GRAPH_H
