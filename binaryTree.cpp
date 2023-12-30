#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int _data){
		data = _data;
		left = nullptr;
		right = nullptr;
	}
};

Node* createTree(){

	cout<<"Enter the value of Node: \n";
	int data;
	cin>>data;
	if(data == -1){
		return nullptr;
	}
// 
	//creat the root Node first
	Node* root = new Node(data);

	//making left subtree
	cout<<"Going left of "<<root->data<<endl;
	root->left = createTree();

	//making right subtree
	cout<<"Going right of "<<root->data<<endl;
	root->right = createTree();

	return root;
}

Node* preMadeTree(){
	Node* root = new Node(1);
	Node* a = new Node(2);
	root->left = a;
	Node* b = new Node(4);
	a->left = b;
	b->left=NULL; b->right = NULL;
	Node* c = new Node(5);
	a->right = c;
	c->left=NULL; c->right = NULL;

	Node* d = new Node(3);
	root->right = d;
	Node* e = new Node(6);
	d->left = e;
	e->left = NULL; e->right=NULL;
	Node* f = new Node(7);
	d->right = f;
	f->left = NULL; f->right = NULL;

	return root;
}

void preOrder(Node* root){
	if(root == nullptr) return;

	//NLR
	//printing node
	cout<<root->data<<" ";
	//going left
	preOrder(root->left);
	//going right
	preOrder(root->right);
}

void inOrder(Node* root){
	if(root == nullptr) return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node* root){
	if(root == nullptr) return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";

}

//Breadth First Traversal
void levelOrder(Node* root){
	//first add the root node to the queue
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int count = 0;

	//we take values from front, if front is a node, we print it nd insert its children
	//if it's not a node then we go the next line and add a null if there are children present
	//null denotes that all the children of that level have been added
	while(!q.empty()){
		Node* front = q.front();
		q.pop();

		if(front==NULL){
			cout<<endl;
			count++;
			if(!q.empty()){
				q.push(NULL);
			}
		}else{
			cout<<front->data<<" ";

			if(front->left != NULL){
				q.push(front->left);
			}
			if(front->right!=NULL){
				q.push(front->right);
			}
		}

	}
	cout<<"depth is "<<count;
}

int main(){
	Node* root = createTree();
	// cout<<"Printing tree preOrder"<<endl;
	// preOrder(root);
	// cout<<"\nPrinting tree inOrder"<<endl;
	// inOrder(root);
	// cout<<"\nPrinting tree postOrder"<<endl;
	// postOrder(root);
	// cout<<"\nPrinting tree levelOrder"<<endl;
	levelOrder(root);
}