#include<iostream>
using namespace std;

struct myArray{
    int total;
    int used;
    int * arr;
};

// function to create array
void createArray(myArray* a, int t, int u){
    a->total = t;
    a->used = u;
    a->arr = new int [a->used];
}

// function to set array
void setArray(myArray *a){
    for( int i = 0; i < a->used; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> (a->arr)[i]; 
    }
}
// traversal
void traversal(myArray* a){
    for( int i = 0; i < a->used; i++){
        cout << (a->arr)[i] << " "; 
    }
    cout << endl;
}

// deleting element from an index
void deleteElement(myArray * a, int index){
    for(int i = index; i<=a->used-2; i++){
        (a->arr)[i] = (a->arr)[i+1];
    }
    a->used--;
}
int main(){
    myArray array;
    createArray(&array, 100, 6);
    
    setArray(&array);
    traversal(&array);

    deleteElement(&array, 3);
    traversal(&array);

    delete [] array.arr;
    return 0;

}