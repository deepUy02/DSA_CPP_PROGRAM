#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void LevelOrderTraversal(Node* &root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
    
        if(temp==NULL){
            //purana level traverse ho chuka hai 
            cout<<endl;

            if(!q.empty()){
                //queue still has some element
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            } 
        }
    }
}
Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
Node* deleteformBST(Node* root,int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteformBST(root->right,mini);
            return root;
        }

    }
    else if(root->data > val){
        root->left=deleteformBST(root->left,val);
        return root;
    }
    else{
        root->right=deleteformBST(root->right,val);
        return root;
    }
}
Node* insertIntoBST(Node* root, int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
}
Node takeInput(Node* &root){
    int data;
    cin>> data;
    while(data!= -1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}
int main(){

    Node* root=NULL;
    cout<<"Enter the data to create the BST" <<endl;
    takeInput(root);

    cout<<"printing the BST"<<endl;
    LevelOrderTraversal(root);
    cout<<endl<<"Minimum value is: "<<minVal(root)->data<<endl;
    cout<<"Maximum value is: "<<maxVal(root)->data<<endl;

    //deletion 
    root=deleteformBST(root,50);
    cout<<"printing the BST"<<endl;
    LevelOrderTraversal(root);
    cout<<endl<<"Minimum value is: "<<minVal(root)->data<<endl;
    cout<<"Maximum value is: "<<maxVal(root)->data<<endl;
    return 0;
}