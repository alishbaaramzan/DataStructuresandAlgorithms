#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    int min_ind = 0;
    for(int i = 0; i < n-1; i++){
        min_ind = i;
        for(int j = i+1 ; j < n; j++){
            if(arr[j] < arr[min_ind])
                min_ind = j;
        }
        // now place the minimum value at the beginning of unsorted array
        int temp = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
    }
}
int main(){
    int arr[] = {4,7,3,1,30,55,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);

    // displaying the array after the bubble sort
    for(int i = 0; i < n; i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
    return 0;
}