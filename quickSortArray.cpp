#include<iostream>
using namespace std;

int pivot(int arr[], int l, int r){
    int i = l-1;
    int j = l;
    for(; j < r; j++){
        if(arr[j] < arr[r]){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}
void quickSort(int arr[], int l, int r){
    if(l>=r)
        return;
    else{
        int pi = pivot(arr, l, r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
int main(){
    int arr[] = {1,6,7,4,3,9,11,5};
    quickSort(arr,0,7);
    // displaying the sorted array
    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}