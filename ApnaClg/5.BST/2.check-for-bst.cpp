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

bool isBST(Node* root, Node* min, Node* max){

    if(root == NULL)
        return true;

    if(min != NULL and root->data <= min->data){
        return false;
    }
    if(max != NULL and root->data >= max->data){
        return false;
    }

    bool leftValid =  isBST(root->left,min,root);
    bool rightValid = isBST(root->right,root,max);

    return leftValid and rightValid;
}

int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    bool ch =isBST(root,NULL,NULL);
    if(ch) cout<<"Valid BST\n";
    else cout<<"Invalid BST\n";
    return 0;

}