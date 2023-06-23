#include<iostream>
using namespace std;

bool binarySearch(int arr[], int low, int high, int target){
    if(low>high){
        return false;
    }
    if(arr[low]== target || arr[high]==target){
        return true;
    }
    if(target <= arr[(low+high)/2]){
        return binarySearch(arr,low,(low+high)/2,target);
    }
    if(target >= arr[(low+high)/2]){
        return binarySearch(arr,(low+high)/2,high,target);
    }
}
int main(){
    int arr[12] = {1,3,4,6,7,8,9,11,14,33,34,66};
    int target = 3; 
    bool check =binarySearch(arr, 0, 11, target); 
    if(check){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" <<endl;
    }
    return 0;
}