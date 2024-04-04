#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data "<<val<<endl;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    Node* temp=head;
    int length = 0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void insertAthead(Node* & tail,Node* &head,int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;

    }
}

void insertAtTail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp=new Node(d);

        tail->next=temp;
        temp->prev=tail;
        tail=temp;

    }
}

void insertAtposition(Node* &tail ,Node* &head , int position ,int d){
    //insert at starting 
    if(position == 1)
    {
        insertAthead(tail,head,d);
        return;
    }
    Node* temp=head;
    int count  = 1;

    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    //insert at last position 
    if(temp->next==NULL){
        insertAtTail(tail,head,d);
        return;
    }
    //creating a node for d
    Node* nodeToinsert=new Node(d);

    nodeToinsert->next=temp->next;
    temp->next->prev=nodeToinsert;
    temp->next=nodeToinsert;
    nodeToinsert->prev=temp;
}
void deleteNode(int position, Node* &head){
    
    //deleting first node
    if(position==1)
    {
        Node* temp =head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp; 
    }
    else
    {
        //deleting any middle node or last node
        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    cout<<getLength(head)<<endl;    
    insertAthead(tail,head,11);
    print(head);
    insertAtTail(tail,head,13);
    print(head);
    insertAtposition(tail,head,3,100);
    print(head);
    deleteNode(3,head);
    print(head);
    deleteNode(1,head);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    return 0;

}