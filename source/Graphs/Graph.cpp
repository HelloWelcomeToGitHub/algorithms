#include "Graph.hpp"
#include <vector>

Graph::Graph(unsigned int n){
    for(int i = 0; i < n; i++){
            vec.push_back(0);
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }

    size = n;
}

Graph::~Graph(){
}

unsigned int Graph::node_count(){
    return size;
}

unsigned int Graph::edge_count(){
    int count = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(matrix[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}

int Graph::get_value(unsigned int v){
    return vec.at(v);
}

void Graph::set_value(unsigned int v, int val){
    vec[v] = val;
}

int Graph::weight(unsigned int v, unsigned int w){
    return 0;
}

bool Graph::has_edge(unsigned int v, unsigned int w){
    return matrix[v][w];
}

void Graph::add_edge(unsigned int v, unsigned int w, int weight){
    matrix[v][w] = 1;
}

void Graph::remove_edge(unsigned int v, unsigned int w){
    matrix[v][w] = 0;
}

std::vector<int> Graph::neighbors(unsigned int v){
    std::vector<int> x;
    return x;
}




