#include <bits/stdc++.h>
using namespace std;

//Queue is used , good one
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

void printLevelOrder(Node* root){
    if(root== NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            
        }
        else if(!q.empty()){   //if q is non empty 
            q.push(NULL);  //then push NULL again to mark the end of the queue
        }
    }
}
// at start => 1 NULL
//1 left right then NULL => 2 3 NULL
//2 left right , 3 left right then NULL => 4 5 6 7 NULL
//at last no left right , so no element in queue  

int sumAtK(Node* root,int k){
    if (root==NULL) {
        return -1; //cant find sum
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level=0;int sum=0;

    while(!q.empty()){
        
        Node* node=q.front();
        q.pop();

        if(node!=NULL){
            if(level==k) 
            sum+=node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    cout<<sum<<endl;
    return 0;
}

int32_t main(){
    Node* root=new Node(1);
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

   printLevelOrder(root);
   cout<<endl;

   sumAtK(root,2);
   cout<<endl;
   return 0;
}

