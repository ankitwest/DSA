#include <bits/stdc++.h>
using namespace std;
//Both Recursive and Iterative Method

class node{
	public :
	int data;
	node* next;

	node(int val){
		data = val;
		next =NULL;
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

node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;

    node* dummyNode = new node(-1); // becoz we have to return the node 
    
    node* p3=dummyNode;

    while(p1!=NULL and p2!=NULL){
        if(p1->data < p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode->next;
}


node* mergeRecursion(node* &head1,node* &head2){

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
 
    node* result;
    if(head1->data < head2->data){
        result=head1;
        result->next = mergeRecursion(head1->next,head2);
    }
    else{
        result=head2;
        result->next = mergeRecursion(head1,head2->next);
    }
    return result;

}

int main(){
    node* head1=NULL;
    node* head2=NULL;

    int arr1[]={1,4,5,7};
    int arr2[]={2,3,6};

    for(int i=0;i<4;i++){
        insertAtTail(head1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertAtTail(head2,arr2[i]);
    }
    display(head1);
    display(head2);

    node* newNode = mergeRecursion(head1,head2);

    display(newNode);

    return 0;
}