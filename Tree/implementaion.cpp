#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildtree(node* root){
    cout<<"ENter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"ENter the data for inserting in left: "<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the data for inserting in right: "<<endl;
    root->right=buildtree(root->right);
    return root;

}
void levelOrder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
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
void buildFromLevelOrder(node* &root){
    queue<node*>q;
    cout<<"Enter the data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"Enter the left node for :"<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"ENter the right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}
void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root=NULL;
    buildFromLevelOrder(root);
    levelOrder(root);
    /*
    //creating tree
    root=buildtree(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    cout<<"Printing the data after the level order traversal "<<endl;
    levelOrder(root);
    cout<<"Inorder traversal is ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal is ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal is ";
    postorder(root);
    */
    return 0;
}