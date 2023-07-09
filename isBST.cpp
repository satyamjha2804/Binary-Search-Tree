#include <iostream>
using namespace std;
#include<queue>
template <typename T>

class binarytreeNode{
    public:
    T data;
    binarytreeNode *left;
    binarytreeNode *right;

    binarytreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~ binarytreeNode(){
        delete left;
        delete right;
    }
};
binarytreeNode<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
   
   binarytreeNode<int>*root=new binarytreeNode<int>(rootdata);

   queue<binarytreeNode<int>*> pendingNodes;
   pendingNodes.push(root);
   while(pendingNodes.size()!=0){
    binarytreeNode<int>*front=pendingNodes.front();
    pendingNodes.pop();

    cout<<"ENTER LEFT CHILD OF"<< front->data<<endl;
    int leftchildData;
    cin>>leftchildData;
    if(leftchildData!=-1){
        binarytreeNode<int>* child= new binarytreeNode<int>(leftchildData);
        front->left=child;
        pendingNodes.push(child);
    }

    cout<<"ENTER RIGHT CHILD OF"<< front->data<<endl;
    int rightchildData;
    cin>>rightchildData;
    if(rightchildData!=-1){
        binarytreeNode<int>* child= new binarytreeNode<int>(rightchildData);
        front->right=child;
        pendingNodes.push(child);
    } 
}
return root;

}


int minimum(binarytreeNode<int>*root){
    if(root==NULL){
        return INT_MAX;
    }
     return min(root->data, min(minimum(root->left),minimum(root->right)));

}

int maximum(binarytreeNode<int>*root){
    if(root==NULL){
        return INT_MIN;
    }
     return max(root->data, max(maximum(root->left),maximum(root->right)));

}



bool isBST(binarytreeNode<int>*root){
if(root==NULL){
    return true;
}
int leftMax=maximum(root->left);
int rightMin=minimum(root->right);
bool output= (root->data>leftMax) && (root->data<rightMin) && isBST(root->left)&& isBST(root->right);
return output;
}

int main(){

binarytreeNode<int>*root= takeinputlevelwise();
if(isBST(root)){
    cout<<"true"<<endl;
}
else{
    cout<<"false"<<endl;
}

delete root;

}

