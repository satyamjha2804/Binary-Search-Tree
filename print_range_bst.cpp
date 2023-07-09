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

void printRange(binarytreeNode<int>*root, int k1, int k2)
{
   
    if (root == NULL)
        return;
    if (k2 <root->data )
        printRange(root->left, k1, k2);
    else if (k1>root->data)
      printRange(root->right, k1, k2);
    else 
    {
        printRange(root->left, k1, k2);
        cout << root->data << " ";
       printRange(root->right, k1, k2);
    }
}


int main(){

binarytreeNode<int>*root= takeinputlevelwise();
int k1,k2;
cin>>k1>>k2;
printRange(root,k1,k2);
delete root;

}

