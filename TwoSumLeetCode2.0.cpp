/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    map <int, int> m;
    for(int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if(m.find(complement) != m.end()){
            return vector<int>({m[complement], i});
        }
        m[nums[i]] = i;
    }
    return vector<int>();
}
int main(){
    std::vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(11);
    arr.push_back(15);
    int target = 9;
    vector <int> sol = twoSum(arr,target);
    if(!sol.empty()){
        cout << sol[0] <<"," << sol[1] << endl;
    }
    else{
        cout << "Nothing found" << endl;
    }

    return 0;
    // T(N) = O(n)
}