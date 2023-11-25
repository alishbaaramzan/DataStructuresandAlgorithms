#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
};
class Doubly{
    public:
        Node* head;
        Doubly(){
            head = NULL;
        }
        void insert(int val){
            Node* new_node = new Node();
                new_node->data = val;
                new_node->prev = NULL;
                new_node->next = head;
                head = new_node;
        }
        void display(){
            Node* ptr = head;
            while(ptr!=NULL){
                cout << ptr->data << " <-> ";
                ptr = ptr->next;
            }
            cout << "NULL" << endl;
        }
        void mergedSortLinkedList(){
            head = mergeSort(head);
        }
        Node* merge_list(Node* head1, Node* head2){
            Node* dummy = new Node;
            Node* ptr = dummy;

            while(head1 && head2){
                if(head1->data < head2->data){
                    ptr->next = head1;
                    head1->prev = ptr;
                    head1 = head1->next;
                }
                else{
                    ptr->next = head2;
                    head2->prev = ptr;
                    head2 = head2->next;
                }
                ptr = ptr->next;
            }
            if(head1){
                ptr->next = head1;
            }
            else{
                ptr->next = head2;
            }
            return dummy->next;
        }
        Node* mergeSort(Node* head){
            if(head==NULL || head->next == NULL){
                return head;
            }
            Node* slow = head;
            Node* fast = head->next;
            while(fast!=NULL && fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            Node* left = head;
            Node* right = slow->next;
            slow->next = NULL; // making independent lists

            left = mergeSort(left);
            right = mergeSort(right);

            return merge_list(left,right);
        }
};
int main(){
    Doubly* dll = new Doubly();
    dll->insert(1);
    dll->insert(4);
    dll->insert(6);
    dll->insert(2);
    dll->insert(11);
    dll->insert(0);
    dll->insert(19);
    dll->insert(9);

    dll->display();

    dll->mergedSortLinkedList();
    dll->display();

    delete dll;
    return 0;
}