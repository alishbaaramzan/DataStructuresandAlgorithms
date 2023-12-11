#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        // of their current position
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to choose the pivot element based on the chosen strategy
int choosePivot(int arr[], int start, int end, string pivotChoice) {
    if (pivotChoice == "middle") {
        // Choose the middle element as the pivot
        return arr[(start + end) / 2];
    } else if (pivotChoice == "median_of_three") {
        // Choose the median of first, middle, and last elements as the pivot
        int first = arr[start];
        int middle = arr[(start + end) / 2];
        int last = arr[end];

        // Find the median value among first, middle, and last
        if ((first < middle && middle < last) || (last < middle && middle < first)) {
            return middle;
        } else if ((middle < first && first < last) || (last < first && first < middle)) {
            return first;
        } else {
            return last;
        }
    }

    // Default: Use the middle element as the pivot
    return arr[(start + end) / 2];
}

// Function to perform quicksort with optional insertion sort for small sublists
void quicksort(int arr[], int start, int end, string pivotChoice, int insertionThreshold = 20) {
    if (start >= end) {
        return;
    }

    // Choose the pivot element
    int pivot = choosePivot(arr, start, end, pivotChoice);

    // Partition the array around the pivot
    int left = start, right = end;
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }

        // Swap elements and move pointers
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    // Recursively apply quicksort to the partitions
    if (start < right) {
        quicksort(arr, start, right, pivotChoice, insertionThreshold);
    }
    if (left < end) {
        quicksort(arr, left, end, pivotChoice, insertionThreshold);
    }

    // Switch to insertion sort for small sublists
    if (end - start + 1 <= insertionThreshold) {
        insertionSort(arr + start, end - start + 1);
    }
}

// Function to copy elements from source array to destination array
void arrayCopy(int source[], int destination[], int size) {
    for (int i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}

// Function to display the first few elements of an array
void displayArray(const int arr[], int size, string label) {
    cout << label << ": ";
    for (int i = 0; i < min(size, 100); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Initialize a random array
    const int size = 10000;
    int arr[size];

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }

    // Create new arrays for each sorting method
    int sortedArrayMiddle[size];
    arrayCopy(arr, sortedArrayMiddle, size);
    quicksort(sortedArrayMiddle, 0, size - 1, "middle");
    displayArray(sortedArrayMiddle, size, "Sorted Middle");

    int sortedArrayMedianOfThree[size];
    arrayCopy(arr, sortedArrayMedianOfThree, size);
    quicksort(sortedArrayMedianOfThree, 0, size - 1, "median_of_three");
    displayArray(sortedArrayMedianOfThree, size, "Sorted Median of Three");

    int sortedArrayMiddleWithInsertion[size];
    arrayCopy(arr, sortedArrayMiddleWithInsertion, size);
    quicksort(sortedArrayMiddleWithInsertion, 0, size - 1, "middle", 20);
    displayArray(sortedArrayMiddleWithInsertion, size, "Sorted Middle with Insertion");

    int sortedArrayMedianOfThreeWithInsertion[size];
    arrayCopy(arr, sortedArrayMedianOfThreeWithInsertion, size);
    quicksort(sortedArrayMedianOfThreeWithInsertion, 0, size - 1, "median_of_three", 20);
    displayArray(sortedArrayMedianOfThreeWithInsertion, size, "Sorted Median of Three with Insertion");

    return 0;
}