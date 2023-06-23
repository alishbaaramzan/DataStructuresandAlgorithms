/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,7,11,9};
    int target = 9;
    int index1, index2 = 0;
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        for(int j = i; j < sizeof(arr)/sizeof(arr[0]); j++){
            if(arr[i] + arr[j] == target){
                index1 = i;
                index2 = j;
                break;
            }
        }
    }
    cout << "[" << index1 << "," << index2 << "]" << endl;
    return 0;
    // T(N) = O(n**2)
}