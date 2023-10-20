#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int arr[] = {4,7,3,1,30,55,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);

    // displaying the array after the bubble sort
    for(int i = 0; i < n; i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
    return 0;
}