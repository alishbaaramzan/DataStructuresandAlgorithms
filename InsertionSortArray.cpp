#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){

    for(int i = 1; i < n; i++){
        int curr = arr[i];
        int j;
        for(j=i-1; j >=0; j--){
            if(arr[j] < curr)
                break;
            arr[j+1] = arr[j];
        }
        arr[j+1] = curr;
    }
}
int main(){
    int arr[] = {4,7,3,1,30,55,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);

    // displaying the array after the bubble sort
    for(int i = 0; i < n; i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
    return 0;
}