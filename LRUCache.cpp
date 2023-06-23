#include<iostream>
#include<map>
using namespace std;

struct Node{
    int key;
    int value;
    struct Node *next;
    struct Node *prev;
};
class LRUCache{
    struct Node *head;
    struct Node *tail;
    map<int, Node*>m;
    int capacity;
    static int count;
    public:
        LRUCache(){
            head = new Node();
            tail = new Node();
            head->key = 0;
            head->value = 0;
            head->next = tail;
            head->prev = NULL;

            tail->key = 0;
            tail->value = 0;
            tail->next = NULL;
            tail->prev = head;

            this->capacity = 0; // default capacity     
        }

        LRUCache(int capacity){
            head = new Node();
            tail = new Node();
            head->key = 0;
            head->value = 0;
            head->next = tail;
            head->prev = NULL;

            tail->key = 0;
            tail->value = 0;
            tail->next = NULL;
            tail->prev = head;

            this->capacity = capacity;    
        }

        // function to add a node to cache
        void addNode(int key, int value){
            struct Node* newNode = head->next;
            newNode->key = key;
            newNode->value = value;

            if(m.find(key)!=m.end()){
                struct Node *p = m[key];
                m.erase(key);
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete(p);
            }
            if(count>capacity){
                struct Node *p = m[tail->prev->key];
                m.erase(tail->prev->key);
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete(p);
            }
            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            newNode->prev = head;
            m[key] = newNode;
            count++;
            cout << "Node added" << newNode->key << endl;
        }

        void traversal(){
            struct Node *ptr = head;
            while(ptr!=NULL){
                cout << ptr->key << " = " << ptr->value << endl;
                ptr = ptr->next;
            }
            delete(ptr);
        }
};
int LRUCache :: count = 0;
int main(){
    LRUCache cache(4);
    cache.addNode(1,2);
    cache.addNode(2,5);
    cache.addNode(3,6);
    //cache.addNode(3,7);
    cache.addNode(4,2);
    cache.addNode(5,5);
    cache.traversal();
    return 0;
    }