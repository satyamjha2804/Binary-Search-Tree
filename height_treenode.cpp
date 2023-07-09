#include <iostream>
using namespace std;
#include<queue>
template<typename T>
#include<vector>


class treenode{
   public:
   T data;
   vector< treenode <T> *>children;
   treenode(T data){
    this->data=data;
   }
};


treenode<int>* takeinputlevelwise(){
  int rootdata;
  cout<<"enter root data"<<endl;
  cin>>rootdata;
  treenode<int>*root=new treenode<int>(rootdata);
  queue<treenode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size()!=0){
   treenode<int> *front=pendingNodes.front();
   pendingNodes.pop();
   cout<<"enter no. of children of "<< front->data<<endl;
   int numchild;
   cin>>numchild;
   for(int i=0;i<numchild;i++){
    int childData;
    cout<<"enter "<< i<< "th child of "<<front->data<<endl;
    cin>>childData;
    treenode<int>*child=new treenode<int>(childData);// dynamically 
    front->children.push_back(child);
    pendingNodes.push(child);

   }
  }
  return root;
}


int height_tree(treenode<int>*root){
    int temp=0,height=0;
   if(root==NULL){
    return 0;
   }
   if(root->children.size()==0){
    return 0;
   }

   for(int i=0;i<root->children.size();i++){
    temp=height_tree(root->children[i]);
    if(temp>height){
        height=temp;
    }
   }
  return height+1;
}

void printTree(treenode<int>*root){
 if(root==NULL){
    return;
 }
 cout<<root->data<<":";
 for(int i=0;i<root->children.size();i++){
    cout<<root->children[i]->data<<",";     
 }
 cout<<endl;

 for(int i=0;i< root->children.size();i++){
    printTree(root->children[i]);
 }

}


int main(){

treenode<int>*root=takeinputlevelwise();
printTree(root);
cout<<"HEIGHT OF TREE IS :"<<height_tree(root)<<endl;

}
