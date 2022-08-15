#include <bits/stdc++.h>
using namespace std;

#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug1(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head , int val){
	node* n = new node(val);

	if(head==NULL){
		    head = n;
		return;
		}

	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
}
void insertAtHead(node* &head,int val){
	node* n = new node(val);
	n->next=head;
	head = n;
}
void display(node* head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl; 
}
node* reverseK(node* &head,int k){

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count =0;
    while(currptr!=NULL and count<k){
        nextptr = currptr->next;

        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;

        count++;
    }

   if(nextptr!=NULL){
  head->next = reverseK(nextptr,k);
   }

    return prevptr;
}

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,0);
	insertAtHead(head,23);

    display(head);
    
    int k=2;
    node* newHead= reverseK(head,k);
    display(newHead);
    return 0;
}