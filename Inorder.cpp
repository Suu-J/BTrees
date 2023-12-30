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

void inOrder(Node* root){
	if(root == nullptr) return;

	inOrder(root->left);

	cout<<root->data<<" ";

	inOrder(root->right);
}

vector<int> iterativeInorder(Node* root){
	vector<int> ans;
	if(root==NULL) return ans;
	stack<Node*>st;
	Node* node = root;

	while(1){
		//when we meet valid nodes, we try to go left further
		if(node!=NULL){
			//to save old nodes we passed by, we need to put it in stack
			st.push(node);
			node=node->left;
		}else{
			//once we reach the end, that is, the null, we will take our saved nodes, first store the data 
			//then move on to right side. this way the left nodes will print first because we are going left
			if(st.empty()) break;
			node = st.top(); st.pop();
			ans.push_back(node->data);
			node=node->right;
		}
	}

	return ans;
}

int main(){
	Node* root = preMadeTree();
	cout<<"Printing tree iterativeInorder"<<endl;
	vector<int> ans = iterativeInorder(root);

	for(auto val:ans) cout<<val<<" ";
}