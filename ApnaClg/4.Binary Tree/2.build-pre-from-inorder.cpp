#include <bits/stdc++.h>
using namespace std;

//Not understood , a bit difficult

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

int search(int inorder[], int start , int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1; 
}

Node* buildTree(int preorder[], int inorder[],int start, int end){
    static int idx=0;
    if(start > end){
        return NULL;
    }
    //starting from 0th element because root comes at first
    int curr =preorder[idx];
    idx++;

    Node* node = new Node(curr);
    if(start == end){
        return node;
    }

    int pos = search(inorder,start,end,curr);
    node->left = buildTree(preorder,inorder,start , pos-1); //first left subtree
    node->right = buildTree(preorder, inorder, pos+1 ,end);
 
  return node;
  
}

void inorderPrint(struct Node* root){

    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}




//build-post-from-inorder


int search2(int inorder[], int start , int end, int val){
    for(int i=start; i<=end; i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1; 
}
Node* buildTree2(int postorder[], int inorder[],int start, int end){
    static int idx=4;
    if(start > end){
        return NULL;
    }
    //starting from last element because root comes at first
    int val =postorder[idx];
    idx--;

    Node* node = new Node(val);
    if(start == end){
        return node;
    }

    int pos = search2(inorder,start,end,val);
    node->right = buildTree2(postorder, inorder, pos+1 ,end); //first right subtree
    node->left = buildTree2(postorder,inorder,start , pos-1); 

  return node;
}
void inorderPrint2(struct Node* root){

    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    //finding the first element according to preorder and then rest
    struct Node* root = buildTree(preorder,inorder,0,4);
    inorderPrint(root);
    cout<<endl;

    struct Node* root2 = buildTree2(postorder,inorder,0,4);
    inorderPrint2(root2);
    return 0;
}
