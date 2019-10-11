#include<iostream>
#define ll long long
using namespace std;

struct node{
  ll info;
  node *left,*right;
  ll height;
};

ll height(node *n){
  if(n==NULL){
    return 0;
  }
  else{
   ll ldepth=height(n->left);
  ll rdepth=height(n->right);
  return max(ldepth,rdepth)+1;
  }
}

ll balanceFactor(node *n){
  if(n==NULL){
    return 0;
  }
  return height(n->left)-height(n->right);
}

node *newNode(ll info){
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

node *insertNode(node *root,ll info){
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
  ll balance=balanceFactor(root);
  if(balance>1 && info<root->left->info){
  	cout<<root->info<<endl;
    return rightRotate(root);
  }
  else if(balance<-1 && info>root->right->info){
  	cout<<root->info<<endl;
    return leftRotate(root);
  }
  else if(balance>1 && info>root->left->info){
  	cout<<root->info<<endl;
    root->left=leftRotate(root->left);
    return rightRotate(root);
  }
  else if(balance<-1 && info<root->right->info){
  	cout<<root->info<<endl;
    root->right=rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

node* inOrderSuccessor(node* root) {
    node* current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    return current;
}

node *deleteNode(node *root,ll info){
	node *temp;
	if(root==NULL){
		return 0;
	}
	if(info<root->info){
		root->left=deleteNode(root->left,info);
	}
	else if(info>root->info){
		root->right=deleteNode(root->right,info);
	}
	else{
		if(root->left==NULL || root->right==NULL){
			temp=root;
			if(root->left==NULL){
				root=root->right;
			}
			else if(root->right==NULL){
				root=root->left;
			}
			delete(temp);
		}
		else{
			node *temp=inOrderSuccessor(root->right);
			root->info=temp->info;
			root->right=deleteNode(root->right,temp->info);
		}
	}
	if(root==NULL){
		return root;
	}
	root->height=1+max(height(root->left),height(root->right));
	ll balance=balanceFactor(root);
	if(balance > 1 && balanceFactor(root->left)  < 0) {
        cout<<root->info<<'\n';
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if(balance > 1 && balanceFactor(root->left) >= 0) {
        cout<<root->info<<'\n';
        return rightRotate(root);
    }
    else if(balance < -1 && balanceFactor(root->right) > 0) {
        cout<<root->info<<'\n';
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    else if(balance < -1 && balanceFactor(root->right) <= 0) {
        cout<<root->info<<'\n';
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
	long long n;
    cin>>n;
    node* root = NULL;
    while(n--){
        char c;
        long long a;
        cin>>c>>a;
        if (c == 'i'){
            root = insertNode(root,a);
        }
        else if (c == 'd'){
            root = deleteNode(root,a);
        }
    }
  preOrder(root);
  cout<<endl;
  inOrder(root);
  cout<<endl;
  postOrder(root);
}
