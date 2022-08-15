#include <bits/stdc++.h>
using namespace std;

#define ln  cout<<endl;

//We can also use class in place of struct , just add public in it.
//Struct in the function receiving can also be removed. and also inside the main struct

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(struct Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}r
void preorder(struct Node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(struct Node* root){
    if(root == NULL){
        return ;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}


int main(){
   
   struct Node* root= new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);

   root->left->left = new Node(4);
   root->left->right = new Node(5);

   root->right->left = new Node(6);
   root->right->right = new Node(7);
  /*
  1
/  \
2   3
/ \ / \
4 5 6  7
*/

   preorder(root);
    ln;
   inorder(root);
    ln;
   postorder(root);
   ln;

   return 0;
}

 