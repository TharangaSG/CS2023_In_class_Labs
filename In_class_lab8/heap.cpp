#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
    int largest = root; // root is largest one
    int right = 2*root + 2; // right child index
    int left = 2*root + 1; // left child index
    

    
    if (left < n && arr[left] > arr[largest])
        largest = left;

    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != root)
    {
        swap(arr[root], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // Build heap 
    for (int a = n / 2 - 1; a >= 0; a--)
        heapify(arr, n, a);

  
    for (int a=n-1; a>=0; a--)
    {
        // Move current root to end
        swap(arr[0], arr[a]);

        // call max heapify on the reduced heap
        heapify(arr, a, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int a = 0; a < n; ++a)
        cout << arr[a] << " ";
    cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}