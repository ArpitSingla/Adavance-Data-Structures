#include<iostream>
using namespace std;

struct node{
  int info;
  node *left;
  node *right;
  int height;
};

int height(node *n){
  if(n==NULL){
    return 0;
  }
  return n->height;
}

int balanceFactor(node *n){
  if(n==NULL){
    return 0;
  }
  return height(n->left)-height(n->right);
}

node *newNode(int info){
	node *temp=new node();
  	temp->info=info;
  	temp->left=NULL;
  	temp->right=NULL;
  	temp->height=1;
  	return temp;
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
  root->left=temp->right;
  temp->right=root;
  temp->height=1+max(height(temp->left),height(temp->right));
  root->height=1+max(height(root->left),height(root->right));
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
  root->height=1+max(height(root->right),height(root->left));
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

void inOrder(node *n){
	if(n!=NULL){
		inOrder(n->left);
  		cout<<n->info<<" ";
  		inOrder(n->right);
	}
}
void preOrder(node *n){
	if(n!=NULL){
		cout<<n->info<<" ";
		preOrder(n->left);
  		preOrder(n->right);
	}
}
void postOrder(node *n){
	if(n!=NULL){
		postOrder(n->left);
  		postOrder(n->right);
  		cout<<n->info<<" ";
	}
}
int main(){
	int n;
    cin>>n;
    node* root = NULL;
    while(n--){
        char c;
        int a;
        cin>>c>>a;
        if (c == 'i'){
            root = insertNode(root,a);
        }
//        else if (c == 'd'){
//            root = deleteNode(root,a);
//        }
    }
  preOrder(root);
  cout<<endl;
  inOrder(root);
  cout<<endl;
  postOrder(root);
}
