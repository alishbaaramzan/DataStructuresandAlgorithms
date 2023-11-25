#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data = val;
            left = right = NULL;
        }
};
class BST{
    Node* root;
    public:
        BST(){
            // initializing the tree with root node NULL
            root = NULL;
        }
        // function to calculate the inorder successor
        Node* inorderSucc(Node* root){
            // inorder successor of a node is the leftmost child of it's right subtree
            Node* succ = NULL;
            Node* temp = root->right;
            while(temp->left!=NULL){
                succ = temp;
                temp = temp->left;
            }
            return succ;
        }
        // printing the tree in ascending order
        void inorderTraversal(Node* node){
            if(node == NULL)
                return;
            else{
                inorderTraversal(node->left);
                cout << node->data << " ";
                inorderTraversal(node->right);
            }
        }
        void printInorder(){
            inorderTraversal(root);
        }
        // function to insert a value in BST
        void insert(int val){
            root = insertRecursion(root,val);
             }
        Node* insertRecursion(Node* root, int val){
            if(root==NULL){
                return new Node(val);
            }
            if(val < root->data){
                root->left = insertRecursion(root->left, val);
            }
            else if(val > root->data){
                root->right = insertRecursion(root->right, val);
            }
            return root;
        }
         // function to search a value int the tree
         bool search(int val){
            return searchRecursion(root, val);
         }
         bool searchRecursion(Node* root, int val){
            if(root==NULL){
                return false;
            }
            if(root->data==val){
                return true;
            }
            else if(val<root->data){
                return searchRecursion(root->left, val);
            }
            else if(val>root->data){
                return searchRecursion(root->right, val);
            }

         }
         // function to delete a value from the tree
        void deleteValue(int val){
            root = deleteRecursion (root, val);
        }
        Node* deleteRecursion(Node* root, int val){
            if(root==NULL){
                return root;
            }
            // if the val lies in left subtree, move to left subtree
            if(val < root->data){
                root->left = deleteRecursion(root->left, val);
            }
            // if the val lies in right subtree, move to right subtree
            else if(val > root->data){
                root->right = deleteRecursion(root->right, val);
            }
            // if the val is equal to the data of the root
            else{
                //now we check for case 1 and 2
                if(root->left==NULL){
                    // replace the node with it's right subtree
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if(root->right==NULL){
                    // replace the node with it's left subtree
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
                // case 3
                // we have to calculate the inorder successor first
                Node* inordersucc = inorderSucc(root);
                // replacing the node to be deleted with it's inorder successsor
                root->data = inordersucc->data;
                // deleting the inorder successor from the right subtree
                root->right = deleteRecursion(root->right, inordersucc->data);

            }
            return root;
        }
};
int main(){
    BST* binarytree = new BST();         
    binarytree->insert(50);             
    binarytree->insert(30);
    binarytree->insert(40);

    // checking if the values have been inserted correct
    if(binarytree->search(40)){
        cout << "Yes the values have been correctly inserted" << endl;
        binarytree->printInorder();
        cout << endl;
    }

    binarytree->deleteValue(50);
    // checking if the value has been deleted correctly
    if(!binarytree->search(50)){
        cout << "Yes the values have been correctly deleted" << endl;
        binarytree->printInorder();
        cout << endl;
    }
    delete binarytree;
    return 0;
}