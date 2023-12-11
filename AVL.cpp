#include <iostream>
using namespace std;
#define SPACE 10

class Node{
    public:
        int data;
        //int height; --> redundant as height of tree is being calulated by recursion
        Node* left;
        Node* right;
    Node(int val){
        data = val;
       // height = 0;
        left = right = NULL;
    }
};
class AVL{
    public:
        Node* root;
        AVL(){
            root = NULL;
        }
        // function to find the inorder successor
        Node* inOrderSucc(Node* n){
            if(n==NULL){
                return n;
            }
            else{
                Node* succ = NULL;
                Node* temp = n->right;

                while(temp!=NULL){
                    succ = temp;
                    temp = temp->left;
                }
                return succ;
            }
        }
        // max function
        int max(int n1, int n2){
            if(n1>n2) return n1;
            else return n2;
        }
        // function to get height
        int height(Node* n){
            if(n==NULL)
                return -1;
            else
                return (1 + max(height(n->left), height(n->right)));
        }
        // function to calculate the balancing factor
        int balance(Node* n){
            return (height(n->left)-height(n->right));
        }
        // code for right rotate
        Node* rightrotate(Node* y){
            Node*x = y->left;
            Node*T2 = x->right;

            // rotating
            x->right = y;
            y->left = T2;

            return x;
        }
        // code for left rotate
        Node* leftrotate(Node* x){
            Node* y = x->right;
            Node* T2 = y->left;

            // rotating
            y->left = x;
            x->right = T2;

            return y;
        }
        // insertion function using recursion
        Node* insert(Node* r, int val){
            // bas case
            if(r==NULL){
                cout << val << " successfully added" << endl;
                return new Node(val);
            }
            // move to left subtree
            else if(val < r->data){
                r->left = insert(r->left, val);
            }
            // move to right subtree
            else if(val > r->data){
                r->right = insert(r->right, val);
            }
            // calculating balancing factor of the node
            int bf = balance(r);
            // now th four conditions
            if(bf>1 && val<r->left->data)
                return rightrotate(r);
            else if(bf<-1 && val>r->right->data)
                return leftrotate(r);
            else if(bf<-1 && val<r->right->data){
                r->right = rightrotate(r->right);
                return leftrotate(r);
            }
            else if(bf>1 && val>r->left->data){
                r->left= leftrotate(r->left);
                return rightrotate(r);
            };
            return r; 
        }
        // prinitng the preorder traversal
        void preOrder(Node* r){
            if(r==NULL)
                return;
            else{
                cout << r->data << " ";
                preOrder(r->left);
                preOrder(r->right);
            }
        }
        // to print the tree
        void print2D(Node * r, int space) {
        if (r == NULL) // Base case  1
        return;
        space += SPACE; // Increase distance between levels   2
        print2D(r -> right, space); // Process right child first 3 
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5 
        cout << " "; // 5.1  
        cout << r -> data << "\n"; // 6
        print2D(r -> left, space); // Process left child  7
    }
    Node* deleteNode(Node* r, int val){
        // if there exists no such value in the tree
        if(r==NULL){
            return r;
        }
        // go in left subtree
        else if(val < r->data){
            r->left = deleteNode(r->left, val);
        }
        // go in the right subtree
        else if(val > r->data){
            r->right = deleteNode(r->right, val);
        }
        // if the node to be deleted in found
        else{
            if(r->left==NULL){
                Node* temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL){
                Node* temp = r->left;
                delete r;
                return temp;
            }
            else{
                // find the inorder successor 
                Node* inorderSucc = inOrderSucc(r);

                // replacing the value of r with that of inorder successor
                r->data = inorderSucc->data;

                // deleting the inorder successor
                r->right = deleteNode(r->right, inorderSucc->data);
            }
        }
        //finding the balance factor
        int bf = balance(r);

        // catering all six cases
        if(bf==2 && balance(r->left) >=0)
            return rightrotate(r);
        else if(bf==2 && balance(r->left)== -1){
            r->left = leftrotate(r->left);
            return rightrotate(r);
        }
        else if(bf==-2 && balance(r->right)<=0)
            return leftrotate(r);
        else if(bf==-2 && balance(r->right) == 1){
            r->right = rightrotate(r->right);
            return leftrotate(r);
        }
        return r;
    }
};
int main(){
    AVL* avl = new AVL();
    avl->root = avl->insert(avl->root, 12);
    avl->root = avl->insert(avl->root, 18);
    avl->root = avl->insert(avl->root, 8);
    avl->root = avl->insert(avl->root, 17);
    avl->root = avl->insert(avl->root, 4);
    avl->root = avl->insert(avl->root, 11);
    avl->root = avl->insert(avl->root, 5);
    avl->root = avl->insert(avl->root, 6);


    // prinitng the preorder traversal
    avl->preOrder(avl->root);

    // printing the 2D structure
    avl->print2D(avl->root, 5);
    
    // deleting two  nodes and then printing
    avl->root = avl->deleteNode(avl->root, 18);
    avl->root = avl->deleteNode(avl->root, 17);
    avl->preOrder(avl->root);
    avl->print2D(avl->root, 5);

    // deallocating memory
    delete avl;

    return 0;
}