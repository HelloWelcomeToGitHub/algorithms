#include "LinkedList.hpp"
#include "Stack.hpp"

Stack::Stack(){
    head = nullptr;
    len = 0;

}
Stack::~Stack(){
    clear();
}

unsigned int Stack::size(){
    int count = 0;
    Node* n = head->next;
    while(n!=nullptr){
        n = n->next;
        count++;
    }

    return count;
}

  /** push(int data)
   * Pushes a node containing the given data to the top of the stack.
   */
void Stack::push(int data){
    Node* n = head->next;
    n->data = data;
    n->next = nullptr;
    Node* m = head->next;
    while(m!=n){
        m = m->next;
    }
    m->next = n;
}

  /** pop()
   * Removes and returns the data at the top of the stack.
   */
  int Stack::pop(){
    Node* n = head->next;
      while(head->next!=nullptr){
          n = n->next;
      }
    Node* m = head->next;
    while(m!=n){
        m = m->next;
    }
    m->next = nullptr;
    int temp = n->data;
    delete n;
    return temp;
}

  /** top()
   * Returns the data at the top of the stack without changing the stack.
   */
  int Stack::top(){
      return 0;
  }

  /** empty()
   * Returns whether or not the stack is empty.
   */
  bool Stack::empty(){
      if(len == 0){
          return true;
      }
      else{
          return false;
      }
  }

  /** clear()
   * Clears the entire stack.
   */
  void Stack::clear(){

  }