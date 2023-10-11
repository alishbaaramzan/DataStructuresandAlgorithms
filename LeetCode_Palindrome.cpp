/*Given an integer x, return true if x is a 
palindrome, and false otherwise.*/
#include<iostream>
#include<string.h>
using namespace std;

bool palindrome(string num_str){
    int len = 0;
    for(int i = 0; i <100; i++){
        if(num_str[i]=='\0'){
            break;
        }
        len++;
    }

    bool check = true;
    for(int i = 0; i < len/2; i++){
        if(num_str[i]==num_str[len-i-1]){
            check = true;
        }
        else
            check = false;
    }
    return check;
}

bool palindrome_recursion(string num, int i, int len){
    if (i>=len/2){
        return true;
    }
    if(num[i]==num[len-i-1]){
        return palindrome_recursion(num,++i,len);
    }
    return false;
}
int main(){
    string num;
    std :: cin >> num;
    // bool isPalindrome = palindrome(num);
    // if(isPalindrome==true){
    //     std :: cout << num << " is a palindrome" << endl;
    // }
    // else{
    //     std :: cout << num << " is not a palindrome" << endl;
    //}
    int len = 0;
    for(int i = 0; i <100; i++){
        if(num[i]=='\0'){
            break;
        }
        len++;
    }
    bool isPalindrome = palindrome_recursion(num,0,len);
    if(isPalindrome==true){
        std :: cout << num << " is a palindrome" << endl;
    }
    else{
        std :: cout << num << " is not a palindrome" << endl;
    }
    return 0;
}