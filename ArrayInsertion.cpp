#include <iostream>
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
//insertion at an index
void insert(myArray *a, int n, int i){
    if(a->used< a->total){
    for(int j = a->used-1; j>=i; j--){
        (a->arr)[j+1] = (a->arr)[j];
    }
    (a->arr)[i] = n;
    a->used++;
    }
    else{
        cout << "Not enough space " << endl;
    }
}
//sorted insertion
void sortedInsertion(myArray *a, int n){
    int index;
    if(a->used< a->total){
    
    // setting index for ascending order
    if(a->arr[0] < a->arr[1]){
    for(int i = 0; i < a->used; i++){
        if(a->arr[i] > n){
            index = i-1;
            break;
        }
    }
    }
    // setting index for descending order
    else if(a->arr[0] > a->arr[1]){
    for(int i = 0; i < a->used; i++){
        if(a->arr[i] < n){
            index = i-1;
            break;
        }
    }
    }
    for(int i = a->used-1; i >=index; i--){
        (a->arr)[i+1] = (a->arr)[i];
    }
    (a->arr)[index] = n;
    a->used++;
    }
    else{
        cout << "Not enough space " << endl;
    }
}
int main(){
    myArray array;
    createArray(&array, 100, 5);

    setArray(&array);
    traversal(&array);

    insert(&array, 4, 3);
    traversal(&array);
    
    sortedInsertion(&array, 2);
    traversal(&array);

    delete [] array.arr;
    return 0;

}