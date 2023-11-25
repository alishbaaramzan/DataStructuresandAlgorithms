#include<iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r){
    int an = mid-l+1;
    int bn =  r - mid;
    int a[an], b[bn];
    // filling a
    for(int i = 0; i < an; i++){
        a[i] = arr[l+i];
    }
    // filling b
    for(int j = 0; j < bn; j++){
        b[j] = arr[mid+1+j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i<an && j<bn){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while(i<an){
        arr[k++] = a[i++];
    }
    while(j<bn){
        arr[k++] = b[j++];
    }
}
void mergeSort(int arr[], int l, int r){
    if(l>=r)
        return;
    else{
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr, l, mid, r);
    }
}
int main(){
    int arr[] = {1,6,7,4,3,9,11,5};
    mergeSort(arr,0,7);
    // displaying the sorted array
    for(int i = 0; i < 8; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}