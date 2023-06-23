#include<iostream>
using namespace std;

// Linear Search Algo
// Time Complexity : O(n)
bool linearSearch(int arr[], int size ,int target){
    bool check = false;
    for(int i = 0; i < size; i++){
        if(arr[i]==target){
            check = true;
            break;
        }
    }
    return check;
}
int main(){
    int arr[12] = {1,2,4,52,56,8,3,5,7,4,11,9};
    int target = 2; 
    if(linearSearch(arr, 12, target)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" <<endl;
    }
    return 0;
}