#include <bits/stdc++.h>
using namespace std;

#define ln  cout<<endl;

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

int maxPathSumUtil(Node* root, int &ans){
    if(root == NULL){
        return 0;
    }

    int left = maxPathSumUtil(root->left,ans);
    int right = maxPathSumUtil(root->right,ans);

    int nodeMax = max(maz(root->data , root->data + left + right) ,
                     max(root->data + left , root->data + right));
    
    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data , max(root->data +left , root->data + right));

    return singlePathSum;
}

int maxPathSum(Node* root){
    int ans = INT_MIN;

    maxPathSumUtil(root,ans);

    return ans;
}

 