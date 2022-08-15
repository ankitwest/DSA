#include <bits/stdc++.h>
using namespace std;

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
int countNodes(Node* root);
int sumNodes(Node* root);

int calcHeight(Node* root){  //O(n)

    if(!root) return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight,rHeight)+1;

}

int calcDiameter(Node* root){  //O(n^2)

    if (root == NULL){
        return 0;
    }
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    int rootDiameter = lHeight + rHeight + 1;

   

    return max(rootDiameter , max(lDiameter ,rDiameter));
}

int calcDiameterRecursive(Node *root, int &height){  //O(n)

    if(root == NULL){
        height = 0;
        // int dia = 0;
        return 0;
    }
    int lh=0,rh=0;
    int lDiameter=calcDiameterRecursive(root->left,lh);
    int rDiameter=calcDiameterRecursive(root->right,rh);

    //int rootDiameter = lh + rh +1;   //currDiameter
    height = max(lh,rh)+ 1;     //currHeight

    //return max(rootDiameter , max(lDiameter ,rDiameter));
    return max({ lh+rh+1 ,lDiameter ,rDiameter });

}

int main(){
       struct Node* root= new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);

   root->left->left = new Node(4);
   root->left->right = new Node(5);

   root->right->left = new Node(6);
   root->right->right = new Node(7);

   cout<<countNodes(root)<<endl;
   cout<<sumNodes(root)<<endl;

   cout<<"Height is : "<<calcHeight(root)<<endl;
   cout<<"Diameter is : "<<calcDiameter(root)<<endl;

    int height =0;
  cout<<"Diameter is : "<<calcDiameterRecursive(root , height )<<endl;

  /*
  1
/  \
2   3
/ \ / \
4  5 6  7
*/

}


int countNodes(Node* root){
    if( root == NULL)
     return 0;

     return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(Node* root){
    if(root == NULL)
     return 0;

     return sumNodes(root->left) + sumNodes(root->right) + root->data;
}