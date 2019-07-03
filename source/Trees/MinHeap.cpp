#include "MinHeap.hpp"
#include "../Functions/functions.hpp"
#include <iostream>

int floor(int x)
{
  return (int)x;
}

MinHeap::MinHeap(unsigned int cap){
    array = new int[capacity];
    capacity = cap;
    size = 0;
}
MinHeap::~MinHeap(){
  delete [] array;
}

/** swim()
   * Restores the heap order property after an element is pushed. Assumes the
   * new element has been pushed at the end of the heap array (right-most node
   * in the bottom level of the tree), and swaps it upwards the tree until it's
   * greater than its parent.
   */
void MinHeap::swim()
{
  for(int i = size; i > 0; i--){
    if(array[i]<array[i/2]){
      swap(&array[i],&array[i/2]);
    }
  }

}

/** sink(int i)
   * Restores the heap order property after element removal. Assumes the element
   * at the end of the heap array has been swapped with the root, and the size
   * has been decremented (effectively removing the last element in the heap
   * array). It then swaps the element at the root down the tree until both
   * children are greater than it.
   */
void MinHeap::sink(int i){
    if(array[i] > array[2*i] && array[(2*i) +1]){
        return;
    }
    else if(array[i] > array[2*i]){
        int temp = array [i];
        array[i] = array[2*i];
        array[2*i]= temp;
    }
    else if(array[i] > array[(2*i)+1]){
        int temp = array[i];
        array[i] = array[(2*i)+1];
        array[(2*i)+1]= temp;
    }
}

/** search(int i, int data)
   * Recursively searches for data in the MinHeap's subtree rooted at i,
   * returning true if the data is found and false if i is greater than or
   * equal to size or data is less than the MinHeap's value at i.
   */
bool MinHeap::search(int i, int data)
{
    return 0;
}

/** erase(int i, int data)
   * Recursively searches for data in the MinHeap's subtree rooted at i,
   * calling remove on i if data is found in the tree.
   * Does nothing if data is not found in the subtree.
   */
void MinHeap::erase(int i, int data)
{
    if (array[i] == data)
    {
        if (array[i] == array[size])
        {
        }
        swap(&array[i], &array[size]);
    }
}

void MinHeap::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void MinHeap::moreBigger()
{
    int *bigArray = new int[capacity * 2];
    for (size_t i = 0; i < size; i++)
    {
        bigArray[i] = array[i];
    }
    array = bigArray;
    delete[] bigArray;
};

/** push(int data)
   * Inserts data into the MinHeap such that the heap order property is
   * preserved.
   * Assumes duplicate elements will not be pushed.
   */
void MinHeap::push(int data)
{
    if (size == capacity)
        moreBigger();
    size++;
    array[size] = data;
}

/** count()
   * Returns the number of elements in the MinHeap.
   */
int MinHeap::count()
{
    return size;
}

/** pop()
   * Removes and returns the minimum element in the MinHeap, preserving the
   * heap order property.
   * Throws an error if the heap is empty.
   */
int MinHeap::pop()
{
    if (size == 0)
    {
        throw "Empty heap";
    }
    size--;
    return array[1];
}

/** peek()
   * Returns the minimum element in the MinHeap without modifying its contents.
   * Throws an error if the heap is empty.
   */
int MinHeap::peek()
{
    if (size == 0)
    {
        throw "Empty Heap";
    }
    return array[1];
}

/** search(int data)
   * Searches the MinHeap for the given data, returning true if the data is
   * found and false otherwise.
   */
bool MinHeap::search(int data)
{
    return 0;
}

/** remove(int i)
   * Removes the element at index i in the MinHeap tree (indexed left-to-right,
   * top-to-bottom) and returns its value.
   * Throws an error if the heap is empty or the index is out of bounds.
   */
int MinHeap::remove(int i)
{
    if (i > size || i == 0 || size == 0)
        throw "Error";
    if (!search(i))
    {
        throw "Not Found";
    }
    //Then swap with root, delete root, trickleUp
    return i;
}

/** erase(int data)
   * Searches the MinHeap for the given data, and deletes it if it's found,
   * preserving the heap order property.
   * Does nothing if data is not found.
   */
void MinHeap::erase(int data)
{
    return;
}

/** print()
   * Prints the contents of the MinHeap tree to the ostream from left-to-right,
   * top-to-bottom.
   */
void MinHeap::print(std::ostream &oss)
{
    for(int i = 0; i < size; i++){
        oss << array[i] << ",";
    }
}