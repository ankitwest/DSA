#include <bits/stdc++.h>
using namespace std;
#define ln     cout<<"\n";  

//A bit hard
struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calcPointers(Node *root, Node **first,Node **mid , Node **last, Node **prev){
    if(root == NULL){
        return;
    }

    calcPointers(root->left,first,mid,last,prev);

    if(*prev and (*prev)->data > root->data){
        if(!*first){   //first time violation
            *first = *prev;
            *mid = root;
        }
        else{     //second time violation
            *last = root;
        }
    }
    *prev = root;  //it will become prev for its right subtree
    calcPointers(root->right, first, mid, last, prev);
}
void restoreBST(Node *root){
    Node *first,*mid,*last,*prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;

    calcPointers(root,&first,&mid,&last,&prev);

     //case 1
    if(first and last){
        swap(&(first->data), &(last->data));
    }
    else if(first and mid){
        swap(&(first->data), &(mid->data));
    }
}
void inorder(Node *root){
    if(root ==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
/*
    6
   /  \
   9   3
  / \    \
 1  4    13
*/

// 3 and 9 are swapped
Node *root = new Node(6);
   root->left = new Node(9);
   root->right = new Node(3);

   root->left->left = new Node(1);
   root->left->right = new Node(4);

   root->right->right = new Node(13);

    inorder(root); ln;
   restoreBST(root);
    inorder(root);

return 0;
   }