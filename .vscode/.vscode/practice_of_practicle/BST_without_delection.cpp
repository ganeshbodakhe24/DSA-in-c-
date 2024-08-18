#include<iostream>
using namespace std;

//creating the node 
struct node{
	int data;
	struct node * left;
	struct node * right;
};

//inserting the root node 
struct node * insert_root(){
	struct node * newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->left=NULL;
	newnode->right=NULL;
	cout<<"\nEnter the root node :";
	int data;
	cin>>data;
	newnode->data=data;
	return newnode;

}

// printing inorder sequence
void inorder(struct node * root){
	if(root!=NULL){
		inorder(root->left);
		cout<<"  "<<root->data;
		inorder(root->right);
	}
}

//printing the preorder sequence
void preorder(struct node * root){
	if(root!=NULL){
		cout<<"  "<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}

//printing the postorder
void postorder(struct node * root){
	if(root!=NULL){
		
		postorder(root->left);
		postorder(root->right);
                cout<<"  "<<root->data;
	}
}
// to search an value 
struct node * search (struct node * root, int value){
	while(root!=NULL){
	if(root->data<value){
		root=root->right;
	}
	else if(root->data>value){
		root=root->left;
	}
	else if (root->data==value){
		cout<<"\nThe value is found  : " <<root->data;
		
		return root;
	}else{

	}

	}
	cout<<"\nElement is not found !!!!!!!!!";
	cout<<endl;
	return NULL;

}

//inserting the node in the tree 
void insert_node(struct node * root){
	int data;
	cout<<"\nEnter node : ";
	cin>>data;
	struct node * newnode;
	struct node *prev;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->data=data;
	while(root!=NULL){
		prev=root;
	if(newnode->data<root->data){
		root=root->left;
	}
	else if(newnode->data>root->data){
		root=root->right;
	}
	else{
	cout<<"\nduplication not allowed";
	}
     }
	if(newnode->data<prev->data){
		prev->left=newnode;
	}
	if(newnode->data>prev->data){
		prev->right=newnode;
	}	
}

// finding inorder Sucessor for delete node 
struct node * inorderSucessor(struct node * root){
        root=root->right;
        while(root->left!=NULL){
            root=root->left;

        }
        return root;
}


struct node * deleteNode(struct node* root , int value){
    struct node *ipost;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //searching for node
    if(value<root->data){
        root->left=deleteNode(root->left,value);
    }
    else  if(value>root->data){
        root->right=deleteNode(root->right,value);
    }
    else{
        //delete
        ipost=inorderSucessor(root);
        root->data=ipost->data;
        root->right=deleteNode(root->right,ipost->data);

    }

    return root;
}
int main(){
	struct node *root;// creating root node
	root=insert_root(); //inserting root node first 
	char value;
	//inserting node upto not get n or N
	while(value!='N' && value!='n'){
		
		        insert_node(root);
                cout<<"\nDo you want insert ? ";
		cin>>value;
	}
	value='y';
	while(value!='N' && value!='n'){
	cout<<"\nThe display inorder is ";
	inorder(root);

	//cout<<"\nThe display preorder is ";
	//preorder(root);

	//cout<<"\nThe postorder inorder is ";
	//postorder(root);


	cout<<"\nEnter search element :";
	int element;
	cin>>element;
	struct node *temp;
   temp= search(root ,element);

	cout<<"\nEnter want to delete node : ";
	cin>>element;
	deleteNode(root ,element);

	cout<<"do you wnat to continue...";
	cin>>value;
	}

return 0;
}