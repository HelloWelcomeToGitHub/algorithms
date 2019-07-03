#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sorts.hpp"
#include <sstream>
#include "../Functions/functions.hpp"
#include "../Trees/BST.hpp"

/* Helper Functions */

// O(n)
void copy_arr(int* arr, int* temp, int n) {
  for (int i = 0; i < n; i++) {
    temp[i] = arr[i];
  }
}

/*Strand Sort

 Pseudocode
First, check if the array is empty
If so, throw an error
Else, pop the first element into a second array
For all subsequent elements of the second array,
	Check if they are greater or equal to first element
	If so, pop them into the second array
    Check if the third, final array is sorted, and if so place contents in order into third array
	Else append them to the partially filled third array
	Repeat operation for remaining elements in the first array


Analysis:
O(n^2)
o(n) (if array already sorted)
theta(1)
*/

bool empty(int n){
	if (n == 0){
		return false;
	}
	else{
		return true;
	}
}

void strandSort(int *arr, int n){
	if(empty(n)){
		throw "Error: empty array";
	}

	const int len = n;
	int finArr[len];

    bool first = false;

	int newArr[n];
	newArr[0] = arr[0];

	for(int i = 0; i < n; i++){
		if(arr[i] > newArr[i]){
			newArr[i+1] = arr[i];
		}
	}

	if (first){
		for(int i = 0; i < n; i++){
			finArr[i] = newArr[i];
			first = false;
		}
	}
	else{
		int end = n - 1;
		int start = 0;
		while(!empty(n)){
			if(newArr[end] > finArr[start]){
				start++;
			}
			else{
				finArr[start] = newArr[end];
				end--;
				start = 0;
			}
		}
	}
}

// O(1)
void swap(int* y, int* x) {
  int temp;
  temp = *y;
  *y = *x;
  *x = temp;
}

// Worst Case: O(n^2)
// Best Case: O(n)
void bubble_sort(int* arr, int n) {
  for (int i = 0; i < (n - 1); i++) {
    if (arr[i] > arr[i + 1]) {
      arr[i] = arr[i] xor arr[i + 1];
      arr[i + 1] = arr[i] xor arr[i + 1];
      arr[i] = arr[i] xor arr[i + 1];
    }
  }
  if (n != 1) {
    bubble_sort(arr, n - 1);
  }
}

// Worst Case: O(n^2)
// Best Case: O(n^2)
void selection_sort(int* arr, int n) {
  for (int i = 0; i < (n - 1); i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    swap(&arr[min], &arr[i]);
  }
}

// Worst Case: O(n^2)
// Best Case: O(n)
void insertion_sort(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      swap(&arr[j], &arr[j - 1]);
    }
  }
}

// O(n log n)
void mergesort(int* arr, int n) {
  if (n > 1) {
    mergesort(arr, n / 2);
    mergesort(arr + (n / 2), n - n / 2);
    merge(arr, n, n / 2);
  }
}

// O(n)
void merge(int* arr, int n, int mid) {
  int* temp = new int[n];
  copy_arr(arr, temp, n);

  int j = 0;
  int k = mid;
  for (int i = 0; i < n; i++) {
    // If k is consumed, or the element at j is better, take j.
    if (k >= n || (j < mid && temp[j] <= temp[k]))
      arr[i] = temp[j++];
    // Otherwise take k.
    else
      arr[i] = temp[k++];
  }
  delete[] temp;
}

// Best Case: O(n log n)
// Worst Case: O(n^2)
void quicksort(int* arr, int lo, int hi) {
  if (lo < hi) {
    int p = partition(arr, lo, hi);
    quicksort(arr, lo, p - 1);
    quicksort(arr, p + 1, hi);
  }
}
// Wrapper function to normalize sorts API.
void quicksort(int* arr, int n) {
  quicksort(arr, 0, n - 1);
}

// O(n)
int partition(int* arr, int lo, int hi) {
  int i = lo + 1, j = hi;
  while (true) {
    while (i < hi && arr[i] <= arr[lo])
      i++;
    while (j > lo && arr[j] >= arr[lo])
      j--;
    if (j <= i) {
      break;
    }
    swap(&arr[i], &arr[j]);
  }

  swap(&arr[lo], &arr[j]);
  return j;
}

/** Hybrid Quick + Bubble
 * Worst Case: O(n^2)
 * Best Case: O(n log n)
 * Partitions the arrays into small chunks,
 * which are then sorted with bubble sort.
 * This does not avoid the worst case for quicksort.
 */
void hybridsort_quick(int* arr, int lo, int hi) {
  if (hi - lo <= 10) {
    // Insertion sort small segments
    bubble_sort(arr + lo, hi - lo + 1);
  } else {
    // Otherwise partition and call further.
    // This drives towards insertion sorts' best case O(kn).
    // But, doesn't actually save us from the worst case of quicksort.
    int p = partition(arr, lo, hi);
    hybridsort_quick(arr, lo, p - 1);
    hybridsort_quick(arr, p + 1, hi);
  }
}

/** Hybrid Merge + Insertion
 * All Cases: O(n log n)
 * Splits arrays down into small chunks,
 * runs insertion sort on those chunks,
 * then merges the results.
 */
void hyrbidsort_merge(int* arr, int n) {
  // Run insertion sort on small arrays.
  if (n <= 10) {
    insertion_sort(arr, n);
    // Otherwise, break it up more.
  } else {
    hyrbidsort_merge(arr, n / 2);
    hyrbidsort_merge(arr + (n / 2), n - (n / 2));
    merge(arr, n, n / 2);
  }
}
void hybridsort(int* arr, int n) {
  hybridsort_quick(arr, 0, n - 1);
  // hyrbidsort_merge(arr, n);
}

bool validnum(char c) {
  return c == '-' || ('0' <= c && c <= '9');
}
void treesort(int* arr, int n) {
  std::ostringstream oss;
  BST tree;
  for (int i = 0; i < n; ++i)
    tree.insert(arr[i]);

  tree.inorder(oss, true);
  int j = 0;
  for (int i = 0; i < n; ++i) {
    char num[50] = {0};
    int n = 0;
    // Skip irrelevant characters.
    while (!validnum(oss.str()[j]))
      ++j;
    // Get a number
    while (validnum(oss.str()[j])) {
      num[n++] = oss.str()[j++];
    }
    // Save it.
    arr[i] = stringtoint(num);
  }
}