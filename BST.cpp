#include<iostream>
using namespace std;
struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
};
BSTNode* root = NULL;

// node insertion in binary tree
BSTNode* insertion(BSTNode* node , int value){
	if(node == NULL){
		BSTNode* temp = new BSTNode();
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	if(value > node->data){
		node->right = insertion(node->right , value);
	}
	else{
		node->left = insertion(node->left , value);
	}
	return node;
}

void searching(BSTNode*node , int tosearch){
	if(node == NULL){
		cout<<"not found";
	}
	else if(node->data == tosearch){
		cout<<"found";	
	}
	else if(tosearch > node->data && node->right != NULL){
		searching(node->right , tosearch);
	}
	else if(tosearch < node->data && node->left != NULL){
	searching(node->left , tosearch);
	}
	else{
		cout<<"not found";
	}
}

BSTNode* deletion(BSTNode* node , int todel){
	if(node == NULL){
		cout<<"empty";
	}
	if(todel < node->data){
		node->left = deletion(node->left , todel);
	}
	else if(todel > node->data){
		node->right = deletion(node->right , todel);
	}
	else{  // having one child
		if(node->left == NULL){
			BSTNode* temp = node->right;
			delete(node);
			return temp;
		}
		if(node->right == NULL){
			BSTNode* temp = node->left;
			delete(node);
			return temp;
		}
		else{
			// having two child , using smaller number approach.
			BSTNode*temp = node->right;
			// find smallest
			while(temp->left != NULL){
				temp = temp->left;
			}
			int small = temp->data;
			node->data = small;
			node->right = deletion(node->right , todel);
		}
	}
}

// In order traversal
void InOrder(BSTNode* node){ // root node will be present in the middle
	if(node!= NULL){
		InOrder(node->left);
		cout<<node->data << endl;
		InOrder(node->right);
	}
}

// Pre order traversal
void PreOrder(BSTNode* node){ // root node will be present in the starting 
	if(node!= NULL){
		cout<<node->data << endl;
		InOrder(node->left);
		InOrder(node->right);
	}
}

// Post order traversal
void PostOrder(BSTNode* node){ // root node will be present in the end
	if(node!= NULL){
		InOrder(node->left);
		InOrder(node->right);
		cout<<node->data << endl;
	}
}

// height of each node in BST
int Height(BSTNode* node){
	if(node == NULL){
		return 0;
	}
	else{
		int LeftHeight = Height(node->left);
		int RightHeight = Height(node->right);
		int var = max(LeftHeight,RightHeight) + 1;
		cout<< node->data << " " << var << endl;
		return var;
	}
}


int main(){
//	root = insertion(root,75);
//	root = insertion(root ,85);
//	root = insertion(root,25);
//	root = insertion(root,5);
//	root = insertion(root,95);
//	PreOrder(root);
//	cout<<endl;
//	int search;
//	cout<<"enter number to be searched.";
//	cin>>search;
//	searching(root,search);
//	cout<<endl;
//	int todel;
//	cout<<"enter number to be delete.";
//	cin>>todel;
//	root = deletion(root,todel);
//	cout<<"the value "<<todel<< "is deleted." << endl;
//	cout<<endl;
//	PreOrder(root);
//	cout<<endl;
//	Height(root);
//	return 0;

	int op;
	char choice = 'y';
	while (choice == 'y'){
		cout<<"1. Insertion" << endl;
		cout<<"2. Searching" << endl;
		cout<<"3. Deletion" << endl;
		cout<<"4. In Order Traversal" << endl;
		cout<<"5. Pre Order Traversal" << endl;
		cout<<"6. Post Order Traversal" << endl;
		cout<<"7. Height of each node in BST" << endl;
		cout<<"Enter the operation you want to perform:"<<endl;
		cin>>op;
		switch (op){
		case 1:
			int value;
			cout<<"Enter the value to be inserted:"<<endl;
			cin>>value;
			root = insertion(root,value);
			break;
		case 2:
			int search_value;
			cout<<"Enter the value to be searched:"<<endl;
			cin>>search_value;
			searching(root,search_value);
			break;
		case 3:
			int delete_value;
			cout<<"Enter the value to be deleted:"<<endl;
			cin>>delete_value;
			root = deletion(root,delete_value);
			break;
		case 4:
			InOrder(root);
			break;
		case 5:
			PreOrder(root);
			break;
		case 6:
			PostOrder(root);
			break;
		case 7:
			Height(root);
			break;
		case 8: 
		break;	
		default:
			cout<<"invalid choice!";
	}
	cout<<"do you want to continue? y/n";
	cin>>choice;
}


}

