#include<iostream>
using namespace std;

struct node{
  int info;
  node *left,*right;
  int height;
}

node *newNode(node *root, int info){
  node *temp=new node();
  temp->info=info;
  temp->left=0;
  temp->right=0;
  temp->height=1;
  return temp;
}

node *insertNode(node *root,int info){
  if(root==NULL){
    return newNode(info);
  }
  if(info<root->info){
    root->left=insertNode(root->left,info);
  }
  else if(info>root->info){
    root->right=insertNode(root->right,info);
  }
  else{
    return root;
  }
  node->height=1+max(height(root->left),height(root->right));
  int balance=balanceFactor(root);
  if(balance>1 && info<root->left->info){
    return rightRotate(root);
  }
  else if(balance<-1 && info>root->right->info){
    return leftRotate(root);
  }
  else if(balance>1 && info>root->left->info){
    root->left=leftRotate(root->left);
    return rightRotate(root);
  }
  else if(balance<-1 && info<root->right->info){
    root->right=rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

node *leftRotate(node *root){
  node *temp;
  temp=root->right;
  root->right=temp->left;
  temp->left=root;
  temp->height=1+max(height(temp->left),height(temp->right));
  root->height=1+max(height(root->left),height(root->right));
  return temp;
}

node *rightRotate(node *root){
  node *temp;
  temp=root->left;
  root->left=temp->right`;
  temp->right=root;
  temp->height=1+max(height(temp->left),height(temp->right));
  root->height=1+max(height(root->left),height(root->right));
  return temp;
}

int balanceFactor(node *n){
  if(n==NULL){
    return 0;
  }
  return balanceFactor(root->left)-balanceFactor(root->right);
}

int height(node *n){
  if(n==NULL){
    return 0;
  }
  return n->height;
}

void inOrder(node *n){
  inOrder(n->left);
  cout<<n->info<<" ";
  inOrder(n->right);
}
void preOrder(node *n){
  cout<<n->info<<" ";
  inOrder(n->left);
  inOrder(n->right);
}
void postOrder(node *n){
  inOrder(n->left);
  inOrder(n->right);
  cout<<n->info<<" ";
}
int main(){
  int n,value;
	cout<<"Enter the number of nodes: ";
	cin>>n;
	node *root;
	cout<<"Enter the value of nodes: ";
	cin>>value;
	root=insertNode(root,value);
	for(int i=0;i<n-1;i++){
		cout<<"Enter the value of nodes: ";
		cin>>value;
		insert(root,value);
	}
  preOrder(root);
  cout<<endl;
  inOrder(root);
  cout<<endl;
  postOrder(root);
  cout<<endl;
}
