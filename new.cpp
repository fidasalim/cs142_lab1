#include <iostream>
using namespace std;

class Node {
    public:
   //Data
   int data;
   //pointer to the neXt Node
   Node *next;
   //constucter that makes the pointer to null
   Node(){
       next = NULL;
   }
    
};

class LinkedList {
    public:
    //head + circles inside linked with each other 
    //head -> Node type pointer
    Node *head;
    Node *tail;
    
    //construct
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    //circles inside linked with  each other
    //rules how circles will be linked
    
    
    
    //insert
    void insert(int value){
        //if !st NOde is added
        Node *temp = new Node;
        //********//temp has the address of the nodes will be stord in the stack
                   // creates a circle in the heap and give back the address of the circle
        
        //Insert data in the node
        temp->data = value;
        //*********    //temp will point to the data of the node which has the values;
        //1ST nODE only
        if(head == NULL){
            head = temp; // head will store temp and temp store pointer of first
            tail = temp;
        }
        //Any other NOde only
        else{
            tail->next = temp;
            tail = temp;
        }
        
    }
    // A->B=C," A points to an address find the B and store C in B"
    //insert at specific position
    void insertAt(int pos,int value){
        //reach the position before the position
        Node *current = head;
        Node *current1 = head;
        //looping for finding the number of elements in the list.
        int j = 0;
        while(current1!=NULL){
			j++;
			current1= current1->next;
		}
		//comparing the position with total elements and concluding
		if(j<pos){
			cout<<"Linked List does not have that many elements"<<endl;
		}
		        //updating the code for 1st position
		else{
			if (pos==1){
		      	Node *temp = new Node;
		        temp->data = value;
		        temp->next = current;
		        head = temp;	
			}
			//updating code for other positions
			else{
				
				int i = 1;
		        while(i<pos-1){
		            i++;
		            current = current->next;
		    	}
	        //Create a Node
	        Node *temp = new Node;
	        temp->data = value;
	        temp->next = current->next;
	        current->next = temp;
	    	}
		}

	}
    //deletion of last element
    void dlt(){
        //store the tail into temp
        Node * temp = tail;
    	//before tail has to pont to null
    	Node *current = head;
        while(current->next != tail){
            current= current->next;  //contonue till temp = null'
        }
        current->next = NULL;
    	// update tail
    	tail = current;
    	//delete th temp
    	delete temp;
	}
	//delete at specific position
	void dltAt(int pos){
        //store the tail into temp
        Node *current = head;
        Node *temp;
        Node *current1 = head;
        //finding the number of elements in linked list
        int j = 0;
        while(current1!=NULL){
			j++;
			current1= current1->next;
		}
		//if the position is greater than the total elements
		if(j<pos){
			cout<<"Linked List does not have that many elements"<<endl;
		}
		else{	//updating for the 1st position
			if (pos==1){
		        temp = current->next;
		        current->next = NULL;
				head = temp;	
			}
			else{
				//updating for 2nd position
				int i = 1;
		        while(i<pos-1){
		            i++;
		            current = current->next;
		            //contonue till we get the position
        		}
		//deleting the node
        	temp = current->next;
        	current->next = NULL;
	        temp->next = temp;
		    }
	        //Delete a Node
	        
	        
	    	}
		}
	
    //display
    void display(){
        Node *current = head;
        while(current!= NULL){
            cout<<current->data<<"->";
            current= current->next;  //contonue till temp +null'
        }
        cout<<"NULL"<<endl;
    }
    //Returns the number of items in the linked list.
    int countItem(){
		//reading the total number node
		Node *current = head;
		int i = 0;
		//looping
		while(current!=NULL){
			i++;
			current= current->next;
		}
		return i;
	}

};
	


int main()
{
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.display();
    cout<<endl<<"The total number of items in the LInked list is "<<l1.countItem()<<endl;
    l1.dlt();
    l1.display();
    cout<<endl<<"The total number of items in the LInked list is "<<l1.countItem()<<endl;
    l1.insertAt(9,7);
    l1.insertAt(1,7);
    l1.display();
    l1.dltAt(1);
    l1.display();
    l1.dltAt(5);
    l1.dltAt(3);
    l1.display();
    return 0;
}

