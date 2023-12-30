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

vector<int> iterativePreOrder(Node* root){
	vector<int> ans;
	if(root==NULL){
		cout<<"Tree does not exist"<<endl;
		return ans;
	}
	stack<Node*>st;
	st.push(root);

	while(!st.empty()){
		Node* node = st.top(); st.pop();
		ans.push_back(node->data);

		if(node->right!=NULL) st.push(node->right);
		if(node->left!=NULL) st.push(node->left);
	}
	return ans;
}

int main(){
	Node* root = preMadeTree();
	cout<<"Printing tree preOrder"<<endl;
	vector<int> ans=iterativePreOrder(root);

	for(auto val:ans) cout<<val<<" ";
}