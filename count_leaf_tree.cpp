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
int count_leaf(treenode<int>*root){
if(root->children.size()==0){
    return 1;
}
int a=0;
for(int i=0; i< root->children.size();i++){
   a+=count_leaf(root->children[i]);
}
  return a;
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
cout<< "NO OF LEAF NODES:"<<count_leaf(root)<<endl;
}