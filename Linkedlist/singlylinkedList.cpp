#include<bits/stdc++.h>
using namespace std;


 class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;

    }

    //destructor
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
void insertAthead(Node* &head ,int d){
    //CREAATE NEW NODE
    Node* temp=new  Node(d);
    temp->next=head;
    head=temp;
}
void insertAttail(Node* &tail ,int d){
    // CREATE NEW NODE
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;

}
void insertAtposition(Node* &tail, Node* & head,int position ,int d){
    //insert at starting
    Node* temp=head;
    int count=1;
    if(position==1){
        insertAthead(head,d);
        return;
    }
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //insert at end
    if(temp->next==NULL){
        insertAttail(tail,d);
        return;
    }
    
    //create node for d
    Node* nodeToinsert=new Node(d);
    nodeToinsert->next=temp->next;
    temp->next=nodeToinsert;
}

bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node*,bool>visited;
    Node* temp=head;
    while(temp!=NULL){
        //cycle is present
        if(visited[temp]==true){
            cout<<"Present cycle at "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
void deleteNode(int position, Node* &head){
    
    //deleting first node
    if(position==1)
    {
        Node* temp =head;
        head=head->next;
        //memory free
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
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

Node* floydCycleloop( Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            cout<<"Present at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStarting(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* intersection=floydCycleloop(head);
    Node* slow=head;

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;

    }
    return slow;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    //Create a New node
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    
    //head pointer  to node1;
    Node* head=node1;
    Node* tail=node1;
    // print(head);
    insertAttail(tail,12);
    // print(head);
    insertAttail(tail,15);
    // print(head);
    // insertAttail(tail,25);
    // print(head);
    // insertAttail(tail,35);
    // print(head);
    insertAtposition(tail, head,4,22);
    tail->next=head->next;
    // print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    if(floydCycleloop(head)){
        cout<<"cycle is present"<<endl;

    }
    else{
        cout<<"cycle is not present"<<endl;
    }

    cout<<"Starting node of loop is "<<getStarting(head)->data<<endl;
    // deleteNode(4,head);
    // print(head);
    // cout<<"head "<<head->data<<endl;
    // cout<<"tail "<<tail->data<<endl;

    return 0;
}
