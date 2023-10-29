#include<iostream>
using namespace std;

class Node{
    public:
        int reg;
        float price;
        Node* prev;
        Node* next;
};
class AlphaCars{
    public: 
        Node* head;
        Node* tail;
        AlphaCars(){
            head = tail = NULL;
        }
        // we will insert in such a way that head contains the least expensive car and the tail contains the most expensive car
        void insert(int r, float p){
            Node* new_node = new Node();
            new_node->reg = r;
            new_node->price = p;
            
            if(head==NULL){
                new_node->prev = NULL;
                new_node->next = NULL;
                head = tail = new_node;
            }
            else if(p < head->price){
                new_node->prev = NULL;
                new_node->next = head;
                //update head
                head = new_node;
            }
            else if(p>tail->price){
                new_node->next = NULL;
                new_node->prev = tail;
                //update tail
                tail = new_node;
            }
            else{
                // insert after head ( it is neither minimum nor maximum value)
                new_node->prev = head;
                new_node->next = head->next;
                (head->next)->prev = new_node;
                head->next = new_node;
            }
        }
        // function that returns the max priced car
        float maxPricedCar(){
            if(head==NULL){
                return 0;
            }
            else{
                return tail->price;
            }
        }
        // function that returns the min priced car
        float minPricedCar(){
            if(head==NULL){
                return 0;
            }
            else{
                return head->price;
            }
        }
};
int main(){
    AlphaCars* acars = new AlphaCars();
    acars->insert(1, 457.6);
    acars->insert(1, 432.6);
    acars->insert(1, 489.6);
    acars->insert(1, 357.6);
    acars->insert(1, 557.6);
    acars->insert(1, 857.6);
    float max = acars->maxPricedCar();
    float min = acars->minPricedCar();
    cout << "Max price: " << max << endl;
    cout << "Min price: " << min << endl;
    cout << "Profit margin: " << (max-min)/2 << endl;

    delete acars;
    return 0;
}