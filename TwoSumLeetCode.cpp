/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include<iostream>
using namespace std;

struct Indices{
    int index1;
    int index2;
};

int main(){
    int arr[] = {0,1,2,3,5,6};
    int target = 5;
    Indices *indices = new Indices[100];
    int ind = 0;

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        for(int j = i+1; j < sizeof(arr)/sizeof(arr[0]); j++){
            if(arr[i] + arr[j] == target){
                indices[ind].index1 = i;
                indices[ind].index2 = j;
                ind++;
            }
        }
    }

    for(int i = 0; i < ind; i++){
        cout << indices[i].index1 << " " << indices[i].index2 << endl;
    }
    return 0;
    // Time Complexity = n*n + n = n^2 = O(N^2)
}