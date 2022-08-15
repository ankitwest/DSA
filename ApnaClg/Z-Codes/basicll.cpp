//OneNote Done

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node *head =NULL;

void insertAtTail(int val)
{
	Node *NewNode = new Node();
	NewNode->data = val;
	if(head==NULL)
	{
		head = NewNode;
		return;
	}
	Node *temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = NewNode;
	NewNode->next =NULL;
}
void insertAtHead(int val)
{
	Node *NewNode = new Node();
	NewNode->data = val;
	if(head==NULL)
	{
		head = NewNode;
		return;
	}
	NewNode->next = head;
	head = NewNode;

}
void insertAfterNode(int pos,int val)
{
	pos--;
	Node *NewNode= new Node();
	NewNode->data=val;
	if(head==NULL)
	{
		head = NewNode;
		return;
	}
	Node *temp = head;

	while(temp->next!=NULL and pos>0)
	{
		temp = temp->next;
		pos--;
	}
	Node *temp2=temp->next;
	temp->next = NewNode;
	NewNode->next = temp2;
}

void printList()
{
	Node *temp =head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int searchNode(int val)
{
	Node *temp=head;
	int pos=1;
	if(temp->data==val)
		return pos;
	
	while(temp->next!=NULL)
	{
		temp = temp->next;
		pos++;
		if(temp->data==val)
			return pos;
	}
	return -1;

}

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    // int t=1;   //cin>>t;
    // while(t--)solve(); 
    // return 0;
    insertAtTail(5); printList();
    insertAtTail(10); printList();
    insertAtHead(3); printList();
    insertAtHead(1); printList();

    insertAfterNode(3,7); printList();

    cout<<searchNode(1)<<endl;
    printList();
}



