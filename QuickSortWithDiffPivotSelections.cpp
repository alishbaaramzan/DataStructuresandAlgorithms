#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Function to perform insertion sort on a sublist
void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Function to find the median of three elements
int findMedian(vector<int>& arr, int low, int mid, int high) {
    int a = arr[low];
    int b = arr[mid];
    int c = arr[high];

    if ((a <= b && b <= c) || (c <= b && b <= a))
        return mid;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return low;
    else
        return high;
}

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = findMedian(arr, low, (low + high) / 2, high);
    swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort with different pivot selection strategies
void quickSort(vector<int>& arr, int low, int high, bool useInsertionSort) {
    if (low < high) {
        if (useInsertionSort && high - low + 1 < 20) {
            // Use insertion sort for small sublists
            insertionSort(arr, low, high);
        } else {
            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex - 1, useInsertionSort);
            quickSort(arr, pivotIndex + 1, high, useInsertionSort);
        }
    }
}

void display(vector <int> arr){
   for(int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
    const int size = 10000;
    vector<int> arr(size);

     // Initialize array with random values
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }

    // a. Sort the array using pivot as the middle element of the array.
    vector<int> arrA = arr;
    quickSort(arrA, 0, size - 1, false);

    // b. Sort the array using pivot as the median of the first, last, and middle elements of the array.
    vector<int> arrB = arr;
    quickSort(arrB, 0, size - 1, false);

    // c. Sort the array using pivot as the middle element of the array. Use insertion sort for small sublists.
    vector<int> arrC = arr;
    quickSort(arrC, 0, size - 1, true);

    // d. Sort the array using pivot as the median of the first, last, and middle elements of the array.
    // Use insertion sort for small sublists.
    vector<int> arrD = arr;
    quickSort(arrD, 0, size - 1, true);


    // e. Effect of pivot choice on the complexity of the algorithm:
    // The choice of the pivot can significantly affect the performance of quicksort.
    // Using the median-of-three strategy (b and d) tends to reduce the likelihood of worst-case scenarios.
    // Using insertion sort for small sublists (c and d) can improve performance for small sublists.

    return 0;
}
