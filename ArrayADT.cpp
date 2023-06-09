#include<iostream>
using namespace std;

struct myArray{
    int total_size;
    int used_size;
    int * arr;
};
// function to check if array is sorted
bool isSortedAscending(myArray *a){
    bool check = true;
    int temp = a->arr[0];
    // for incrasing order
    for(int i = 1; i < a->used_size; i++){
        if(a->arr[i]< temp){
            check = false;
        }
        temp = a->arr[i];
    }
    return check;
}
bool isSortedDescending(myArray *a){
    bool check = true;
    int temp = a->arr[0];
    // for incrasing order
    for(int i = 1; i < a->used_size; i++){
        if(a->arr[i]> temp){
            check = false;
        }
        temp = a->arr[i];
    }
    return check;
}
// function to create the array inside the structure
void createArray(myArray *a, int t, int u){
    a->total_size = t;
    a->used_size = u;
    a->arr = new int[a->total_size];
}

// function to set the values in the array inside the structure
void setArray(myArray *a){
    int n;
    for(int i = 0; i < a->used_size; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> n;
        (a->arr)[i] = n;
    }
}
// function to show contents of the array inside the structure
void showArray(myArray *a){
    for(int i = 0; i < a->used_size; i++){
        cout << (a->arr)[i] << " ";
    }
    cout << endl;
}
// function to insert number at an index
void insert(myArray *a, int n, int i){
    if(isSortedAscending(a) || isSortedDescending(a)){
        int *temp = new int[a->used_size+1];
        int c = 0;
        for(int j = 0; j <=a->used_size; j++){
            if(j==i){
                temp[j] = n;
            }
            else{
                temp[j] = a->arr[c];
                c++;
            }
        }
        a->used_size++;
        for(int j = 0; j < a->used_size; j++){
            a->arr[j] = temp[j];
        }
        delete [] temp;
    }
    else{
        int temp;
        temp = a->arr[i];
        a->arr[i] = n;
        a->arr[a->used_size] = temp;
        a->used_size++;
    }
}
// this function deletes element from an index
void deleteAnElement(myArray *a, int i){
    if(i==a->used_size-1){
        a->used_size--;
    }
    else{
        int *temp = new int[a->used_size-1];
        int c = 0;
        for(int j = 0; j < a->used_size; j++){
            if(j==i){
                continue;
            }
            temp[c] = a->arr[j];
            c++;
        }
        a->used_size--;
        for(int j = 0; j < a->used_size; j++){
            a->arr[j] = temp[j];
        }
        delete [] temp;
    }
}
int main(){
    myArray array;

    cout << "Creating an array\n";
    createArray(&array, 10, 3);

    cout << "Setting the array\n";
    setArray(&array);
    showArray(&array);

    cout << "Inserting 4 at index 1\n";
    insert(&array, 4, 1);
    showArray(&array);

    cout << "Deleting element at index 1\n";
    deleteAnElement(&array, 1);
    showArray(&array);

    delete [] array.arr;
    return 0;


}