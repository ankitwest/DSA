#include <bits/stdc++.h>
using namespace std;

class node{
	public :
	int data;
	node* next;

	node(int val){
		data = val;
		next =NULL;
	}
};
node* head = NULL;

void insertAtTail(int val){
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
void insertAtHead(int val){
	node* n = new node(val);
	n->next=head;
	head = n;
}

void display(){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl; 
}
int search(int key){
	int pos =1;
	node* temp = head;
	while(temp!=NULL){
		if(temp->data==key)
			return pos;
		else pos++;

		temp = temp->next;
	}
	return -1;
}

void deleteAtHead(){
	node* toDelete = head;
	head=head->next;

	delete toDelete;
}

void deletion(int val){

    	if(head==NULL)
		return;

	node* temp = head;
	while(temp->next->data!=val){
		temp = temp->next;
	}
	node* toDelete = temp->next;
	temp->next=temp->next->next;

	delete toDelete;
}

int main()
{
	insertAtTail(1);
	insertAtTail(2);
	insertAtTail(3);
	insertAtHead(0);
	insertAtHead(23);
	display();
	cout<<search(1)<<endl;

	deletion(1);
	display();

	deleteAtHead();
	display();
	return 0;	
}

//control + option + N  =  To run 
//control + option + M  = To stop  