#include "Trie.hpp"
<<<<<<< HEAD
#include "../String/String.hpp"

Node* Trie::remove(const char* word, Node* n){
    return 0;
}

void Trie::clear(Node* n){
    return;
}

void Trie::print(std::ostream& oss, Node* n, char* letters, int level){
    return;
}

Trie::Trie(){
    Node* root;
    int size = 0;
    int height_upper_bound = 0;
}

Trie::~Trie(){

}

void Trie::insert(const char* word, int val){
    if(!root){
        root = new Node(val,0);
    }





    while(!root->end_of_word){

    }

    return;
}

int Trie::count(){
    return 0;
}

bool Trie::search(const char* word){
    return 0;
}

int Trie::get(const char* word){
    return 0;
}

void Trie::remove(const char* word){
    return;
}

void Trie::clear(){
    return;
}

void Trie::print(std::ostream& oss){
    return;
=======
#include "../Functions/functions.hpp"

// O(1)
Trie::Trie() {
  root = new Node(0, false);
  size = 0;
}

// O(height)
Trie::~Trie() {
  clear(root);
}

// O(1) since we maintain size.
int Trie::count() {
  return size;
}

// O(word)
void Trie::put(const char* word, int val) {
  int idx;
  Node* n = root;
  for (int i = 0; word[i]; ++i) {  // O(word)
    idx = word[i] - 'a';
    if (n->children[idx]) {  // O(1)
      n = n->children[idx];
    } else {  // O(1)
      Node* next = new Node(0, false);
      n->children[idx] = next;
      n = n->children[idx];
    }
  }
  n->end_of_word = true;
  n->value = val;
  ++size;
}

// O(word) but is normally sublinear for a miss.
bool Trie::search(const char* word) {
  Node* n = root;
  for (int i = 0; word[i]; ++i) {
    if (!(n->children[word[i] - 'a']))
      return false;
    else
      n = n->children[word[i] - 'a'];
  }
  if (n->end_of_word)
    return true;
  else
    return false;
}

// O(word) but is normally sublinear for a miss.
int Trie::get(const char* word) {
  Node* n = root;
  for (int i = 0; word[i]; ++i) {
    if (n->children[word[i] - 'a'])
      n = n->children[word[i] - 'a'];
    else
      throw "Key not found.";
  }
  if (n->end_of_word)
    return n->value;
  else
    throw "Key not found.";
}

// O(word)
Node* Trie::remove(const char* word, Node* n) {
  if (!word[0]) {
    if (!n->end_of_word)
      throw "Key not found.";
    n->end_of_word = false;
    --size;
  } else {
    if (!n)
      throw "Key not found.";
    int idx = word[0] - 'a';
    n->children[idx] = remove(word + 1, n->children[idx]);
  }
  if (!n->end_of_word && !any(n->children, n->R)) {
    delete n;
    return nullptr;
  }
  return n;
}

void Trie::remove(const char* word) {
  root = remove(word, root);  // O(word)
  if (!root)
    root = new Node(0, false);  // O(1)
}

// O(R * height)
void Trie::clear(Node* n) {
  for (int i = 0; i < n->R; ++i) {
    if (n->children[i]) {
      clear(n->children[i]);
    }
  }
  delete n;
}

// O(R * height)
void Trie::clear() {
  clear(root);                // O(R * height)
  root = new Node(0, false);  // O(1)
  size = 0;                   // O(1)
}

// O(R * height)
void Trie::print(std::ostream& oss, Node* n, String& letters) {
  if (n->end_of_word) {
    oss << letters << ' ' << n->value << std::endl;
  }

  for (int i = 0; i < n->R; ++i) {  // O(R)
    if (n->children[i]) {
      letters.append('a' + i);
      print(oss, n->children[i], letters);  // O(height)
      letters.pop_back();
    }
  }
}

// O(R * height)
void Trie::print(std::ostream& oss) {
  String letters;
  print(oss, root, letters);
>>>>>>> upstream/master
}