#include "RBTree.hpp"

Node* RBTree::insert(int data, Node* n){
    return 0;
}

Node* RBTree::rotateRight(Node* node){
    Node* x = node->left;
	node->left = x->right;
	x->right = node;
	x->color = x->right->color;
	node->color = 1; //red

	return x;
}

Node* RBTree::rotateLeft(Node* node){
    Node* x = node->right;
    node->right= x->left;
    x->left = node;
    x->color = x->left->color;
    node->color = 1; //red

    return x;
}

void RBTree::flipColors(Node* node){
    node->color = !node->color;
    node->left->color = !node->left->color; //black
    node->right->color = !node->right->color; //black
}

Node* RBTree::fix(Node* temp){
    return 0;
}

Node* RBTree::moveRedLeft(Node* temp){
    return 0;
}

Node* RBTree::moveRedRight(Node* temp){
    return 0;
}

bool RBTree::search(int data, Node* n){
    if(!n)
        return false;
    else if(data == n->data)
        return true;
    else if(data < n->data)
        return search(data, n->left);
    else
        return search(data, n->right);
}

Node* RBTree::remove(int data, Node* n){
    return 0;
}

int RBTree::height(Node* n){
    return height(root);
}

void RBTree::clear(Node* n){
    return;
}

void RBTree::preorder(Node* n, std::ostream& oss){
    return;
}

void RBTree::inorder(Node* n, std::ostream& oss){
    return;
}

void RBTree::postorder(Node* n, std::ostream& oss){
    return;
}

Node* RBTree::deleteMax(Node* temp){
    return 0;
}

Node* RBTree::deleteMin(Node* temp){
    if(temp->left == nullptr)
    delete temp;
    return nullptr;

    if(temp->left && temp->left->color && temp->left->left && temp->left->left->color){

    }
}

int RBTree::min(Node* subtree, bool first){
    return 0;
}

RBTree::~RBTree(){
    return;
}

void RBTree::insert(int data){
    return;
}

int RBTree::height(){
    return 0;
}

void RBTree::clear(){
    return;
}

void RBTree::preorder(std::ostream& oss = std::cout){
    return;
}

void RBTree::inorder(std::ostream& oss = std::cout){
    return;
}

void RBTree::postorder(std::ostream& oss = std::cout){
    return;
}

void RBTree::deleteMax(){
    return;
}

void RBTree::deleteMin(){
    return;
}