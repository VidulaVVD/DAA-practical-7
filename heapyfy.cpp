#include <bits/stdc++.h>
using namespace std;
 
void heap_sort(vector<int>& arr);
void build_heap(vector<int>& arr);
void heapify(vector<int>& arr, int i, int heap_size);
 
void heap_sort(vector<int>& arr){
    // Build a heap from the input array
    build_heap(arr);
 
    // Repeat until the heap contains only one element
    for (int i = arr.size() - 1; i > 0; i--){
        // Swap the root element with the last element
        swap(arr[0], arr[i]);
 
        // Remove the last element (which is now in the correct position)
        int heap_size = i;
        heapify(arr, 0, heap_size);
    }
    // Reverse the sorted array and return it
    reverse(arr.begin(), arr.end());
}
 
// building heap
void build_heap(vector<int>& arr){
    // Build a max heap from the input array
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, i, n);
    }
}
 
// function for heapify
void heapify(vector<int>& arr, int i, int heap_size){
    // Heapify the subtree rooted at i in the input array
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < heap_size && arr[left] > arr[largest])
        largest = left;
    if (right < heap_size && arr[right] > arr[largest])
        largest = right;
 
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, largest, heap_size);
    }
}

#include <iostream> 
using namespace std; 
  
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
} 
