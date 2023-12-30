#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int _data){
		data = _data;
		left = NULL;
		right = NULL;
	}
};

Node* createTree(){
	int data;
	cout<<"Enter Node Data: ";
	cin>>data;

	if(data==-1) return NULL;

	Node* root = new Node(data);

	root->left = createTree();
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

//BFS traversal method 1
vector<vector<int>> levelOrder(Node* root){
	vector<vector<int>> res;
	if(root == NULL) return res;

	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	vector<int> temp;


	while(!q.empty()){
		Node* front = q.front();
		q.pop();

		if(front==NULL){
			res.push_back(temp);
			temp = {};
			if(!q.empty()){
				q.push(NULL);
			}
		}else{
			temp.push_back(front->data);

			if(front->left!=NULL) q.push(front->left);
			if(front->right!=NULL) q.push(front->right);
		}
	}

	return res;
}

//BFS traversal method2
vector<vector<int>> BFS(Node* root){
	vector<vector<int>> res;
	if(root==NULL) res;
	queue<Node*>q;
	q.push(root);

	while(!q.empty()){
		vector<int> temp;
		int size = q.size();

		for(int i = 0; i<size; i++){
			Node* front = q.front();
			q.pop();

			temp.push_back(front->data);
			if(front->left!=NULL) q.push(front->left);
			if(front->right!=NULL) q.push(front->right);
		}
		res.push_back(temp);
	}
	return res;

}


int main(){
	vector<vector<int>> res;
	
	Node* root = preMadeTree();
	res = levelOrder(root);


	for(auto i:res){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

