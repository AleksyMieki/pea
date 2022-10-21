//
// Created by aleks on 20.10.22.
//

#include "Graph.h"

Graph::Graph() {

    /**
     * constructor for Graph class, reading data from file into adjacenty matrix
     */
    std::fstream indata;

    indata.open("data.txt");

    if(!indata)
    {
        std::cerr << "ERROR: FILE COULD NOT BE OPENED";

    }else
    {
        indata >> verticles;

        adjacenty_matrix = new int *[verticles];

        while(indata.is_open())
        {

            for(int i = 0 ; i < verticles ; i++)
            {
                adjacenty_matrix[i] = new int [verticles];

                for(int j = 0 ; j < verticles ; j++)
                {
                    int weight;
                    indata >> weight;
                    adjacenty_matrix[i][j] = weight;
                }
            }
            indata.close();
        }
    }

}

Graph::~Graph() {

    for(int i = 0 ; i < verticles ; i++)
    {
        delete[] adjacenty_matrix[i];
    }
    delete[] adjacenty_matrix;
}

void Graph::print_graph() {

    for(int i = 0 ; i < verticles ; i++)
    {
        for(int j = 0 ; j < verticles ; j++)
        {
            std::cout << adjacenty_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

int Graph::brute_force() {

    int source = 0 ;
    int shortest_path = 9999;
    std::vector<int> nodes;

    //push all verticles inside a graph into
    for(int i = 0 ; i < verticles ; i++)
    {
        if(i != source)
            nodes.push_back(i);
    }

    int n = nodes.size();

    do
    {
        //set inital path to 0
        int path_weight = 0;
        std::vector<int> temp;
        //temp.push_back(source);
        int j = source;

        for(int i = 0 ; i < n; i++)
        {
            //add weights of next paths
            path_weight += adjacenty_matrix[j][nodes[i]];
            //temp.emplace_back(nodes[i]);
            j = nodes[i];
        }

        //temp.emplace_back(nodes[j]);
        path_weight += adjacenty_matrix[j][source];

        //path.emplace_back(temp,path_weight);

        //if new path is shorter than previous one replace it
        shortest_path = std::min(shortest_path,path_weight);

        //calculate permutations of nodes inside a vector
    }while(std::next_permutation(nodes.begin(),nodes.end()));

    return shortest_path;

}

void Graph::print_weights() {

    int value = brute_force();

    for(auto itr: path){

        if(itr.second == value) {
            for (auto it: itr.first) {
                std::cout << it << " ";
            }

            std::cout << "weight = " << itr.second << std::endl;
        }
    }

}


