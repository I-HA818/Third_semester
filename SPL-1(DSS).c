#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include<string.h>
#include <unistd.h>

                        void simulateArray();
                        void simulateStack();
                        void simulateQueue();
                        void simulateLinkedList();   
                         void simulateTree();
                         void simulateGraph();                                                           


void MENU(){

     int choice;

        printf("                                                  Data Structures\n");
        printf("                                                         |\n");
        printf("                                                         |\n");
        printf("                                                         |\n");
        printf("                                                         |\n");
        printf("                                      ----------------------------------------\n");
        printf("                                      |                                      |\n");
        printf("                                      |                                      |\n");
        printf("                                      |                                      |\n");
        printf("                            Linear Data Structures               Non-Linear Data Structures\n");
        printf("                                      |                                      |\n");
        printf("                                      |                                      |\n");
        printf("                  -------------------------------------              -----------------\n ");
        printf("                 |            |            |         |              |                |\n");
        printf("               1.Array    2.Stack       3.Queue  4.Linked List    5.Tree          6.Graph\n");
        printf("         \n \n                                      ");


                while (1) {

                printf("\nEnter the corresponding number of the data structure you want to know about(0 for exit): ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        simulateArray();
                        break;
                    case 2:
                        simulateStack();
                        break;
                    case 3:
                        simulateQueue();
                        break;
                    case 4:
                        simulateLinkedList();
                        break;
                    case 5:
                        simulateTree();
                        break;
                    case 6:
                        simulateGraph();
                        break;
                    default:
                        printf("Invalid choice.\n");

                   break;


                   case 0:
                       {
                            system("clear || cls");
                           printf("  \n\n\n\n\n\n\n                                                        ****THANK YOU****\n\n\n\n\n\n              ");

                            exit(0);
                       }


             }

        printf("                                                    \nPress Enter to continue...\n");
        getchar(); // Wait for Enter key
        getchar(); // Clear any remaining newline characters
    }

}
void displayDefinitions() {

    printf("=> Linear data structure is a data structure in which data elements are arranged sequentially or linearly, where each element is attached to its previous and next adjacent elements, is called a linear data structure. Examples of linear data structures are array, stack, queue, linked list, etc.\n\n\n");
    printf("=> Non linear data structures are where data elements are not placed sequentially or linearly are called non-linear data structures. In a non-linear data structure, we can�t traverse all the elements in a single run only. Examples of non-linear data structures are trees and graphs.\n\n\n");

}

void simulateArray() {
    printf("An array is a collection of items stored at contiguous memory locations. The idea is to store multiple items of the same type together. This makes it easier to calculate the position of each element by simply adding an offset to a base value, i.e., the memory location of the first element of the array (generally denoted by the name of the array).\n");
    int n,i,j,m,k;
    int choice;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    m=2*n;
    int array[n];
    printf("this is how the array looks like: \n\n");
    printf("index ---->  ");
    for(i=0;i<n;i++){
    if (i==0) printf("\t  %d    ",i);
    else printf("%d    ",i);
    }
    printf("\n");

   for(i=0;i<n;i++){
   		if(i==0) printf("\t         ____");
   	               else    printf(" ____");
   }
   printf("\n");
   //  printf("              /\\n");
    // printf("              ||\n");
     //printf("              ||\n");
     //printf("           elements\n");
         printf("elements --->");
    for(i=0;i<n;i++){
    		if(i==0) printf("\t|____|");
    		else printf("____|");
    		 
    	}
    	printf("\n\n");
	
	
    	for(i=0;i<n;i++){
    	    	printf("Enter the element %d of the array: ",i+1);
    		scanf("%d",&array[i]);
    		printf("After iteration %d the array looks like:\n",i+1);
    		//for(int l=0;l<n;l++){
		  //                printf(" ____");
	        //}
	        printf("\n");
    		 if(i==0)        printf("| %d  |",array[i]);
    		else {
    			for(j=0;j<i;j++) {
    			if(j==0) printf("| %d  |",array[j]);
    			     else printf(" %d  |",array[j]);
    			}
    			          printf(" %d  |",array[i]);
    		}
    		for(k=i+1;k<n;k++){
    			           printf("    |");
    		}    
    		printf("\n");
    		//for(int l=0;l<n;l++){
		  //                printf(" ----");
	        //}
	        
	        printf("\n");
	        
	        if(i!=n-1){
    		tryAgain:
    		printf("continue(1) or MENU(0)\n");
    		scanf("%d",&choice);
    		
    		if(choice==0){
    		for(i=0;i<n;i++){
    			array[i]=-1;
    		}
    		     system("clear || cls");
    		     MENU();
    		}
    		else if(choice==1) continue;
    		else {
    		
    		printf("Invalid choice,try again.\n");
    		goto tryAgain;
    		}
    		}
    		else {
    			printf("Array is full\n");
    			break;
    		}
    	}
    	printf("\n");
    MENU();
}

int stack[10];
int top=-1;
void push(int x){
    if(top==9){
        printf("Can not pop any item cause the stack is currently empty.");
        return;
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Stack is empty.");
        return;
    }
    else{
        int item=stack[top];
        top--;
        printf("The popped item is : %d\n",item);
    }
}
void displayStack(){
    if(top==-1){
            printf("            |__|\n");

    }
    else{
        printf("Currently the stack looks like this:\n\n");
    for(int i=top;i>=0;i--){
            if(i==top)  {
                    printf("         TOP--> |%d |\n",stack[i]);

            }
    else
        printf("                |%d |\n",stack[i]);


    }
    }
}
void simulateStack() {
     printf("Stack is a linear data structure that follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out). LIFO implies that the element that is inserted last, comes out first and FILO implies that the element that is inserted first, comes out last.\n");
     printf("\nWe can do certain operations on an array ,such as push(insertion) and pop(deletion).Do you want to simulate the satck operations?\n (yes(1)/no(2)\n ");
     int choice;
     int choice2;
     int n;
     scanf("%d", &choice);
     system("clear || cls");
     while(1){
                switch (choice) {
                    case 1:


                        printf("The stack is currently empty with zero elements.\n\n");
                        displayStack();

                        label:
                        printf("What do you want to simulate?\n");
                        printf("1.PUSH.\n2.POP.\nPRESS 3 for MENU\n");
                        scanf("%d",&choice2);
                        if(choice2==1){
                            {
                                int x;
                                int c;
                                for(int i=0;i<10;i++){

                                    printf("Enter an element to push: ");
                                    scanf("%d",&x);

                                push(x);
                                displayStack();
                                again:
                                printf("Continue?(1) or No(0)?\n");
                                scanf("%d",&c);
                                if(c==0){
                                        goto label;
                                    break;
                                }
                                else if(c==1) continue;
                                else {
                                    printf("Wrong command!\n");
                                    goto again;
                                }
                                }
                            }
                        }
                        else if(choice2==2){
                            int c;

                                for(int i=0;i<10;i++){
                                    printf("Press enter to pop: ");
                                    getchar();
                                    getchar();
                                pop();
                                displayStack();
                                printf("Continue?(1) or No(0)?\n");
                                scanf("%d",&c);
                                if(c==0){
                                        goto label;
                                    break;
                                }
                                else continue;
                                }
                            }
                            else if(choice2==3)
                            {

                                while(top!=-1){
                                top--;
                                    }
                                    system("clear || cls");
                                MENU();
                            }


                            case 2:
                        exit(0);
                        }
                        break;
                        }


}

int queue[10];
int front=-1;
int rear=-1;

void enqueue(int x){
    if(rear==9){
        printf("queue overflow.");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("The queue is empty.\n");
    }
    else if(front==rear){
         front=rear=-1;
         printf("The dequeued element is %d\n",queue[front]);
    }
    else{
        printf("The dequeued item is: %d\n",queue[front]);
        front++;
        //rear ++;
    }
}
void displayQueue(){
    if(front==-1 && rear==-1){
        printf("The queue is empty.");
    }
    else{
        printf("The current state of the queue is : \n\n");
        for(int i=front;i<=rear;i++){
                if(i==front) printf("                      Front--> %d  ",queue[i]);
                    else if(i==rear) printf("              %d <--Rear",queue[i]);
                        else
                            printf("%d  ",queue[i]);
        }
    }
}

void simulateQueue() {
     printf("A Queue is defined as a linear data structure that is open at both ends and the operations are performed in First In First Out (FIFO) order.\n\n\n");
      printf("\nWe can do certain operations on queue ,such as enqueue(insertion) and dequeue(deletion).Do you want to simulate the queue operations?\n (yes(1)/no(2)\n ");
      int choice;
     int choice2;
     int n;
     scanf("%d", &choice);
     system("clear || cls");
     while(1){
                switch (choice) {
                    case 1:


                        printf("The queue is currently empty with zero elements.\n\n");
                        displayQueue();

                        label:
                        printf("What do you want to simulate?\n");
                        printf("1.Enqueue.\n2.Dequeue.\nPRESS 3 for MENU\n");
                        scanf("%d",&choice2);
                        if(choice2==1){
                            {
                                int x;
                                int c;
                                for(int i=0;i<10;i++){

                                    printf("Enter an element to enqueue: ");
                                    scanf("%d",&x);

                                enqueue(x);
                                displayQueue();
                                again:
                                printf("\nContinue?(1) or No(0)?\n");
                                scanf("%d",&c);
                                if(c==0){
                                        goto label;
                                    break;
                                }
                                else if(c==1) continue;
                                else {
                                    printf("Wrong command!\n");
                                    goto again;
                                }
                                }
                            }
                        }
                        else if(choice2==2){
                            int c;

                                for(int i=0;i<10;i++){
                                    printf("Press enter to dequeue: ");
                                    getchar();
                                    getchar();
                                dequeue();
                                displayQueue();
                                printf("\nContinue?(1) or No(0)?\n");
                                scanf("%d",&c);
                                if(c==0){
                                        goto label;
                                    break;
                                }
                                else continue;
                                }
                            }
                            else if(choice2==3)
                            {


                                    system("clear || cls");
                                MENU();
                            }


                            case 2:
                        exit(0);
                        }
                        break;
                        }
}

void simulateLinkedList() {
     printf("A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers :\n");
     printf("Linked lists are made of several nodes,Each node contains two parts. The first part stores the data and the second part stores the pointer to the next node.The first node is called the head.The list start from the head.\nThe nodes look kinda like this:\n\n");
     printf("                               ______ ______       ______ ______       ______ ______\n");
     printf("                     Head---> | Data | Next | --->| Data | Next | --->| Data | Next | --->NULL\n");
     printf("                               ------ ------       ------ ------       ------ ------\n");
     printf("                                      ^                   ^                   ^\n");
     printf("                                      |                   |                   |\n");
     printf("                                      |                   |                   |\n");
     printf("                                    Node                 Node               Node\n");
}

void simulateTree() {
     printf("A tree is a hierarchical data structure defined as a collection of nodes. Nodes represent value and nodes are connected by edges. A tree has the following properties: The tree has one node called root. The tree originates from this, and hence it does not have any parent.\n");
}
void simulateGraph() {
     printf("A Graph is a non-linear data structure consisting of vertices and edges. The vertices are sometimes also referred to as nodes and the edges are lines or arcs that connect any two nodes in the graph. More formally a Graph is composed of a set of vertices( V ) and a set of edges( E ). The graph is denoted by G(E, V).\n");
}

int main() {

for (int i = 0; i <= 100; i+=1) {
        system("cls");
        printf("                                             Loading %d percent\n", i);

        usleep(500);
    }

    system("clear || cls");
;
    printf("                                             __________________________\n");
    printf("                                             |Data Structure Simulator|\n");
    printf("                                             |          (DSA)         |\n");
    printf("                                             **************************\n\n\n");
    printf("                                             Press Enter to continue...\n\n");
    getchar(); // Wait for Enter key

    printf("What is a data structure?\n");
    printf("A data structure is a storage that is used to store and organize data.It is a way of arranging data on a computer so that it can be accessed and updated efficiently..\n");
    printf("There are two types of data structures.These are - 1.Linear data structures & 2.Non-linear data structures.\n\n\n");
    displayDefinitions();
    printf("Press Enter to continue...\n");
    getchar();
    system("clear || cls");

        MENU();

    return 0;
}
