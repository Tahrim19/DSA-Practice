#include<iostream>
#include<cstdlib>

// Linked List Insertion and Deletion using stack

struct node{
	int number;
	node* next;
	node* previous;
};

node* start = nullptr;

// function to push a node ( Insertion ) 
void PushNode(){
	node* temporary = new node(); // dynamically allocating memory to new node
	std::cout << "Enter a number: ";
	std::cin >> temporary -> number;
	temporary -> next = start; // The new node's next points to the current top
	temporary -> previous = nullptr; // The new node is the new top, so previous is nullptr
	if (start != nullptr){ // will only run when its first node
		start -> previous = temporary;
	}
	start = temporary; // Update the top pointer to the new node
}

// function to print the node
void print(){
	node * current = start; // initialize current pointer to start of list
	while(current != nullptr){ // loop will continue current pointer qill not be null
		std::cout << "Number:" << "\t" << current -> number ;
		std::cout << std::endl;
		current = current -> next; // moving the current pointer to next node
	}
}

// function to pop a node ( Deletion )

int main()
{
	for(int i = 1 ; i < 5 ; i++){
		PushNode();
	}
	print();
return 0;
}

