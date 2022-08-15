#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;int hd;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void leftView(Node* root){
    if (root == NULL) return ;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
    int n=q.size();
    for(int i=0;i<n;i++){     
        Node* fr = q.front();  q.pop();

        if(i == 0) cout<<fr->data<<" ";  //v.push_back(fr->data);

        if(fr->left) q.push(fr->left);
        if(fr->right) q.push(fr->right);
        }
    }
}

void rightView(Node* root){
    if (root == NULL) return ;
        
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
    int n=q.size();
    for(int i=0;i<n;i++){     
        Node* fr = q.front();  
        q.pop();

        if(i == n-1) cout<<fr->data<<" ";
            
        if(fr->left)  q.push(fr->left);   
        if(fr->right)  q.push(fr->right);
           
        }
    }
}

void topView(Node* root){
    if(root == NULL) return ;

    queue<Node*> q;
    map<int,int> m;
    int hd =0;
    root->hd = hd;
    q.push(root);

    while(!q.empty()){
    int n=q.size();

    for(int i=0;i<n;i++){     
        Node* node = q.front();  
        q.pop();
        hd = node->hd;
            if(m[hd]==0)  //first time
                m[hd] = node->data;
            if(node->left){
                node->left->hd = hd-1;
                q.push(node->left);
            }
            if(node->right){
                node->right->hd = hd+1;
                q.push(node->right);
            }
    }
}

    for(auto x:m)
        cout<<x.second<<' ';

}


    void topView2(Node *root)
    {
        // vector<int> v;
        if(root==NULL) return ;
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            auto p = q.front();q.pop();
            Node* node = p.first;
            int h = p.second;
            if(m[h]==0) m[h]=node->data;
            if(node->left) q.push({node->left,h-1});
            if(node->right) q.push({node->right,h+1});
        }
    }
    
    for(auto x:m)
        cout<<x.second<<" ";

    // return v;
    
    }
 void topView3(Node* root)
    {
        // queue for holding nodes and their horizontal
        // distance from the root node
        queue<pair<Node*, int> > q;
 
        // pushing root node with distance 0
        q.push(make_pair(root, 0));
 
        // hd is currect node's horizontal distance from
        // root node l is currect left min horizontal
        // distance (or max in magnitude) so far from the
        // root node r is currect right max horizontal
        // distance so far from the root node
 
        int hd = 0, l = 0, r = 0;
        stack<int> left;
        vector<int> right;
 
        Node* node;
 
        while (q.size()) {
 
            node = q.front().first;
            hd = q.front().second;
 
            if (hd < l) {
                left.push(node->data);
                l = hd;
            }
            else if (hd > r) {
                right.push_back(node->data);
                r = hd;
            }
 
            if (node->left) q.push(make_pair(node->left, hd - 1));
           
            if (node->right) q.push(make_pair(node->right, hd + 1));
           
 
            q.pop();
        }
        // printing the left node's data in reverse order
        while (left.size()) {
            cout << left.top() << " ";
            left.pop();
        }
 
        // then printing the root node's data
        cout << root->data << " ";
 
        // finally printing the right node's data
        for (auto x : right) {
            cout << x << " ";
        }
    }

int32_t main(){
    Node* root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

   root->left->left = new Node(4);
   root->left->right = new Node(5);

   root->right->left = new Node(6);
   root->right->right = new Node(7);



   // Node* root = new Node(1);
   //  root->left = new Node(2);
   //  root->right = new Node(3);
   //  root->left->right = new Node(4);
   //  root->left->right->right = new Node(5);
   //  root->left->right->right->right = new Node(6);




    rightView(root);
    cout<<endl;
    leftView(root);
    cout<<endl;
    topView(root);
    cout<<endl;
    topView2(root);
    cout<<endl;
    topView3(root);


/*
  1
/  \
2   3
/ \ / \
4 5 6  7
*/

   return 0;
}