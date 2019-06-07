#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sorts.hpp"

/** Bubble Sort
 *  O(n^2), Omega(n)
 */
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

/** Selection Sort
 * O(?), Omega(?), Theta(?)
 */
 void selection_sort(int *arr, int n){
     int temp, min, swap;
     for(int i = 0; i < n; i++){
         for(int j = (i+1); j < n; j++){
             if(arr[j] < arr[i]){
                 min = arr[j];

             }
         }
     }
 }

/** Insertion Sort
 * O(?), Omega(?), Theta(?)
 */
void insertion_sort(int *arr, int n)
{
  int swap;
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = i; j > 0; j--)
    {
      if (arr[j - 1] > arr[j])
      {
        swap = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = swap;
      }
      else
      {
        break;
      }
    }
  }
}

