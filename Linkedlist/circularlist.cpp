#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;

    }
    //destructor
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            next=NULL;
            delete next;

        }
        cout<<"Memory is free for node with data "<< val<<endl;

    }
};

void insertNode(Node* &tail,int element,int d){


    //empty list
    if(tail==NULL)
    {
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;

    }
    else
    {
        //non empty list
        //assuming that the element is present in the list
        Node* curr=tail;
        while(curr->data!=element)
        {
            curr=curr->next;

        }
        //element found
        Node* temp = new Node(d);
        temp->next=curr->next;
        curr->next=temp;

    }
}

void deleteNode(Node* & tail,int value){

    //empty list
    if(tail==NULL)
    {
        cout<<"Listt is eempty ,please checck  again "<<endl;
        return;
    }
    else
    {
        //non empty list 
        //assuming that the value is present in the linked list 
        Node* prev=tail;
        Node* curr =prev->next;
        
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;

        }
        prev->next=curr->next;
        //1 node list
        if(curr==tail)
        {
            tail=NULL;
        }
        //2 node linked list
        else if(tail==curr)
        {
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}
bool isCircular( Node* head){
    //empty list 
    if(head == NULL){
        return true;
    }

    Node* temp=head -> next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;

}
void print(Node* tail){
    Node* temp=tail;

    //empty list 
    if (tail == NULL)
    {
        cout<<"List is empty"<<endl;
        return; 
    }
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;
}
int main(){

    Node* tail=NULL;

    //empty list mme print kr rhe 
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,4);
    print(tail);

    insertNode(tail,4,5);
    print(tail);

    insertNode(tail,5,6);
    print(tail);

    // insertNode(tail,6,7);
    // print(tail);

    // insertNode(tail,7,8);
    // print(tail);

    // deleteNode(tail,3);
    // print(tail);
    if(isCircular(tail)){
        cout<<"Linked List is Circular in Nature"<<endl;

    }
    else{
        cout<<"Linked list is not Circular"<<endl;
    }

    return 0;

}
