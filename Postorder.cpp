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

void postOrder(Node* root){
	if(root == nullptr) return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

//it's similar to preorder, but instead of pushing right first and left next, so that due to the nature of stack
//we extract left first and right next. here we do opposite ( because we need right first and left second). 
//finally, since data is printed last in postoder, we need to reverse our answer array. as it's storing the
//values in preoder fasion. 
vector<int> iterativePostOrder(Node* root){
	vector<int>ans;
	if(root==NULL) return ans;
	stack<Node*>st;
	st.push(root);

	while(!st.empty()){
		root = st.top(); st.pop();
		ans.push_back(root->data);

		if(root->left!=NULL) st.push(root->left);
		if(root->right!=NULL) st.push(root->right);
	}

	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	Node* root = preMadeTree();
	cout<<"Printing tree iterativePostOrder"<<endl;
	vector<int> ans = iterativePostOrder(root);

	for(auto val:ans) cout<<val<<" ";
}