// C++ program for the above approach
#include<iostream>
using namespace std;
int m=7;
// Node class to represent
// a node of the linked list.
class Node {
public:
	int data;
	char d;
	Node* next;
	// Default constructor
	Node()
	{
		data = 0;
		d=' ';
		next = NULL;
	}

	// Parameterised Constructor
	Node(int data,char d1)
	{
		this->data = data;
		this->d=d1;
		this->next = NULL;
	}
};

// Linked list class to
// implement a linked list.
class Linkedlist {
	Node* head;
	Node* h[7];
public:
	// Default constructor
	Linkedlist()
	{
	       head = NULL;
			for(int i=0;i<7;i++)
	       {h[i]=NULL;}
	}

	// Function to insert a
	// node at the end of the
	// linked list.
	void insertNode(int,char);

	// Function to print the
	// linked list.
	void printList();

	// Function to delete the
	// node at given position
	 void deleteNode(int);
	 void searchNode(int);
};

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int u)
{        int y=0,e=0;
	 y=u%m;
	 Node *temp=h[y];
	 Node *temp1 = h[y];

	 if (h[y] == NULL)
	  {
		cout<< "List empty." <<endl;
		return;
	  }
	Node *temp2=h[y]->next;

       while(temp1!=NULL)
       { if(temp1->data==u)
	 {   temp->next=temp2;
	      temp1->data=0;
	      temp1->d=' ';
	     //delete temp1;
	     cout<<"\nelement deleted\n ";
	     return;
	 }
	else{   temp=temp->next;
		temp2=temp2->next;
		temp1=temp1->next;
		e++;
	    }

	}


}

void Linkedlist::searchNode(int u)
{        int y=0,e=0;
	 y=u%m;
	 Node *temp=h[y];
	 Node *temp1 = h[y];

	 if (h[y] == NULL)
	  {
		cout << "List empty." << endl;
		return;
	  }
	Node *temp2=h[y]->next;

       while(temp1!=NULL)
       { if(temp1->data==u)
	 {
	     cout<<"\nKey:"<<u<<"Record:"<<temp->d;

	   //  cout<<"\nelement deleted\n ";
	     return;
	 }
	else{   temp=temp->next;
		temp2=temp2->next;
		temp1=temp1->next;
		e++;
	    }

	}


}


// Function to insert a new node.
void Linkedlist::insertNode(int data,char d2)
{       int hv=0;
	// Create the new Node.
	Node* newNode = new Node(data,d2);
	 hv=data%m;
	// Assign to head
	if (h[hv] == NULL) {
		h[hv] = newNode;
		return;
	}

	// Traverse till end of list
	Node* temp = h[hv];
	while (temp->next != NULL) {

		// Update temp
		temp = temp->next;
	}

	// Insert at the last.
	temp->next = newNode;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{             for(int o=0;o<m;o++)
	  {
		Node* temp = h[o];

		// Check for empty list.
		if (h[o] == NULL)
		{
		cout << "List" << o <<"is Empty"<<endl;
	      //return;
		 }

		// Traverse the list.
		while (temp != NULL)
		   {
		cout << temp->data <<"->";
		temp = temp->next;
		   }
	      cout <<"\n";
	    }
}

// Driver Code
int main()
{
	Linkedlist list;
	 int k,ch=0,k1=0;
	 char d1;
	 do{ cout<<"\n 1) Insert 2) Dispaly 3) Delete 4)Search 5) Exit\n";
	     cout<< "\nEnter your choice:";
	     cin>>ch;
	  switch(ch)
	  {
		case 1:
	    cout<<"\nEnter Key Value:";
	    cin>>k1;
	    cout<<"\nEnter Data:";
	    cin>>d1;
	// Inserting nodes
	list.insertNode(k1,d1);
	      break;
       case 2:
		cout << "Elements of the list are: ";
		// Print the list
		list.printList();
		cout << endl;
		break;
       case 3:
	   cout<<"\n Enter key of record to be deleted:";
	   cin>>k1;
	   // Delete node at position 2.
	   list.deleteNode(k1);
	   break;
       case 4:   cout<<"\n Enter key of record to be serached:";
	   cin>>k1;
	     list.searchNode(k1);
	   }
	   }while(ch<5);
	return 0;
}