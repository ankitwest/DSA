#include <bits/stdc++.h>
using namespace std;

#define ln  cout<<endl;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val){

    if(root == NULL){
        Node* n = new Node(val);
        return n;
    }
    if(val < root->data)
        root->left= insertBST(root->left, val);
    if(val > root->data)
        root->right= insertBST(root->right, val);
    
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* searchInBST(Node* root , int key){

    if(root == NULL){
        return NULL;
    }

    if(root->data == key)
       return root;
    if(key < root->data )
        return searchInBST(root->left, key);
    
        return searchInBST(root->right, key);  
}
//Not got 
Node* inorderSucc(Node* root);
Node* deleteInBST(Node* root,int key);


int main(){
    struct Node* root = NULL;
    root = insertBST(root ,5); 
    insertBST(root ,1); 
    insertBST(root ,3); 
    insertBST(root ,4); 
    insertBST(root ,2); 
    insertBST(root ,6); 

    inorder(root);
    ln;

    //searchInBST
   if(searchInBST(root,6)==NULL)
   cout<<"Key doesn't exist\n";
   else
   cout<<"Key does exist\n";
/*
  4
/  \
2    5
/ \   \
1  3    6
*/

    //deleteInBST
    inorder(root); ln;
    root = deleteInBST(root,2);
    inorder(root);

    return 0;
}


//     Node* root = new Node(4);
//     root->left = new Node(2);
//    root->right = new Node(5);
//    root->left->left = new Node(1);
//    root->left->right = new Node(3);
//    root->right->right = new Node(6);

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr and curr->left){
        curr = curr->left;
    }
    return curr;
}
Node* deleteInBST(Node* root,int key){
    if(key < root->data)
        root->left = deleteInBST(root->left,key);
    else if(key > root->data)
        root->right = deleteInBST(root->right,key);
    else {
        if(root->left==NULL){
            Node* temp = root->right;
            free(temp);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            free(temp);
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right,temp->data);
    }
        return root;
}
