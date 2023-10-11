/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
*/

#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    char roman;
    int integer;
    Node* next;
    
        Node(){}
        Node(char roman, int integer){
            this->roman = roman;
            this->integer = integer;
        }
        ~Node(){
            delete next;
        }
};

class Stack{
    Node* top;
    public:
        Stack(){
            top = NULL;
        }
        
        bool isEmpty(){
            if(top==NULL){
                cout << "Stack is empty" << endl;
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            Node* newptr = new Node();
            if(newptr==NULL){
                cout << "Stack overflow" << endl;
                delete newptr;
                return true;
            }
            else{
                return false;
            }
           
        }

        void push(char r, int i){
            if(!isFull()){
                Node* newptr = new Node(r,i);
                newptr->next = top;
                top = newptr;
            }
        }

        void pop(){
            if(!isEmpty()){
                cout << "Roman " << top->roman << " having integer value " << top->integer << " has been popped\n"; 
                top = top->next;
            }
        }

        int romanToInteger(string s){
            int integer_val = 0;
            int i = 0;
            while(s[i]!='\0'){
                if(s[i]=='I'){
                    push(s[i],1);
                }
                else if(s[i]=='V'){
                    push(s[i],5);
                }
                else if(s[i]=='X'){
                    push(s[i],10);
                }
                else if(s[i]=='L'){
                    push(s[i],50);
                }
                else if(s[i]=='C'){
                    push(s[i],100);
                }
                else if(s[i]=='D'){
                    push(s[i],500);
                }
                else if(s[i]=='M'){
                    push(s[i],1000);
                }
                i++;
            }
            Node* newptr = new Node();
            newptr = top;
            while(newptr!=NULL){
                if(newptr->next == NULL){
                    integer_val+=newptr->integer;
                    cout << newptr->integer << "  added" << endl;
                    cout << "Total is " << integer_val << endl;
                }
                else if(newptr->integer <= newptr->next->integer){
                    integer_val+=newptr->integer;
                    cout << newptr->integer << "  added" << endl;
                    cout << "Total is " << integer_val << endl;
                }
                else{
                    integer_val+=newptr->integer;
                    newptr->next->integer *=-1;
                    cout << newptr->integer << "  added" << endl;
                    cout << "Total is " << integer_val << endl;
                }
                pop();
                newptr = newptr->next;
            }
            delete newptr;
            return integer_val;
        }
        ~Stack(){
            delete top;
        }
};
int main(){
    Stack* s = new Stack();
     string roman1 = "XIV";
    int integer_value_of_roman1 = s->romanToInteger(roman1);
    cout << "Roman converted to integer is " << integer_value_of_roman1 << endl;

     string roman2 = "LVIII";
    int integer_value_of_roman2 = s->romanToInteger(roman2);
    cout << "Roman converted to integer is " << integer_value_of_roman2 << endl;

    string roman3 = "MCMXCIV";
    int integer_value_of_roman3 = s->romanToInteger(roman3);
    cout << "Roman converted to integer is " << integer_value_of_roman3 << endl;
    return 0;
}