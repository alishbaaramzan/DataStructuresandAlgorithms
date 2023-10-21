#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    srand(time(0)); // providing seed zero
    int arr[1000];

    // filling an array of 1000 random numbers
    for(int i = 0; i < 1000; i++){
        arr[i] = rand();
    }
    // sorting the array by bubble sort
    bubbleSort(arr, 1000);

    // displaying the sorted array
    for(int i = 0; i < 1000; i++){
        cout << arr[i] << " ";
    }
    return 0;
}