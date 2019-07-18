#include "Graph.hpp"
<<<<<<< HEAD
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




=======
#include <iostream>

Graph::Graph(unsigned int n) {
  if (!n)
    throw "Graph cannot contain zero vertices";
  matrix = new int*[n];
  // Note: new int[n]() initializes values to zero
  for (unsigned int i = 0; i < n; ++i) {
    matrix[i] = new int[n]();
  }
  node_values = new int[n]();
  num_nodes = n;
  num_edges = 0;
}

Graph::~Graph() {
  delete[] node_values;
  for (unsigned int i = 0; i < num_nodes; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

unsigned int Graph::node_count() {
  return num_nodes;
}

unsigned int Graph::edge_count() {
  return num_edges;
}

int Graph::get_value(unsigned int v) {
  if (v >= num_nodes)
    throw "Vertex out of bounds";
  return node_values[v];
}

void Graph::set_value(unsigned int v, int val) {
  if (v >= num_nodes)
    throw "Vertex out of bounds";
  node_values[v] = val;
}

bool Graph::has_edge(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes)
    throw "Vertex out of bounds";
  return matrix[v][w];
}

int Graph::weight(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes)
    throw "Vertex out of bounds";
  return matrix[v][w];
}

void Graph::add_edge(unsigned int v, unsigned int w, int weight) {
  if (v >= num_nodes || w >= num_nodes)
    throw "Vertex out of bounds";
  if (!weight)
    throw "Weight cannot be zero";
  if (v == w)
    throw "Self-connected edges are not permitted";
  matrix[v][w] = weight;
  ++num_edges;
}

void Graph::remove_edge(unsigned int v, unsigned int w) {
  if (v >= num_nodes || w >= num_nodes)
    throw "Vertex out of bounds";
  if (!matrix[v][w])
    throw "Edge does not exist";
  matrix[v][w] = 0;
  --num_edges;
}

std::vector<int> Graph::neighbors(unsigned int v) {
  if (v >= num_nodes)
    throw "Vertex out of bounds";
  std::vector<int> neighbor_nodes;
  for (unsigned int i = 0; i < num_nodes; ++i) {
    if (matrix[v][i])
      neighbor_nodes.push_back(i);
  }
  return neighbor_nodes;
}
>>>>>>> upstream/master
