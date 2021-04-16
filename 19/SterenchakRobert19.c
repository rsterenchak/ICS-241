/*
 * This program utilizes node struct as well as randomly generated size and integer variables in order to build a linked list utilizing custom functions in order to manipulate and display the appropriate data within each node.
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 19
 * November 12, 2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {//Node structure of information
  int data;
  struct node *next;
};

typedef struct node Node;//changes node to Node
typedef struct node* NodePointer;//changes node* to NodePointer

void insertIntoLinkedList(int , NodePointer *);
void displayLinkedList(NodePointer);
int addLinkedList(NodePointer);

/*Main function where functions are called and calculations are completed and printed to user.*/
int main(){
  
  srand(time(NULL)); // seeds time
  int size = 25 + rand() % 51;//generates random size variable
  
  NodePointer head = NULL;//initializes NodePointer head
  
  int i = 0;
  
  /*inserts randomly generated integer variables into linked list*/
  for(i = 0; i<size; i++){
    int randomData = rand() % 101;//generates new variable after each pass
    insertIntoLinkedList(randomData, &head);//function call for insertion  
  }

  displayLinkedList(head);//Displays linked list to user 

  int total = addLinkedList(head);//calls linked list sum function and returns the total
  float average = total/(float)size;//calculates average

  printf("sum = %i\n", total);//prints sum
  printf("count = %i\n", size);//prints size
  printf("average = %.2f\n", average);//prints calculated average in float form

  return 0;
  
}//end of main

/*Inserts integer data into linked list.*/
void insertIntoLinkedList(int number, NodePointer *head2){
  NodePointer newNode = NULL;//generates newNode pointer
  NodePointer previous = NULL;//generates previous pointer
  NodePointer current = *head2;//pointer that pointers to head2

  newNode = malloc(sizeof(Node));//creates a node on the heap

  if(NULL != newNode){

    newNode->data = number;//declares data of newNode as number integer

    while (NULL != current && (number > (current->data))){
      previous = current;//change previous to current
      current = current->next;//move current to next node
    }

    if (NULL == previous){//sets newNode as the head if linked list is empty
      *head2 = newNode;
      newNode->next = current;
    } 
    else{//inserts integer between previous and current
      previous->next = newNode;
      newNode->next = current;
    }
  }//end if

}//ends function 

/*Displays linked list to user when function is called.*/
void displayLinkedList(NodePointer current){

  if(NULL == current){//Prints if list is empty
    printf("The linked list is empty!\n\n");
  }
  else{//Prints if list contains valid Nodes
    printf("The list is: ");
    while(NULL != current){
      
      printf("%i", current->data);//Prints current data in the form of int
      current = current->next;//moves current to next node
      if((current)!= NULL){//verifies if current is not NULL prints comma
      printf(", ");
      }
      }
    printf("\n");
  }

}//ends function

int addLinkedList(NodePointer start){

  int sum = 0;//Declares sum integer
  int current = start->data;//Initializes integer variable equal to first node data
  sum = current;//Sets sum to first node also known as current variable
  start = start->next;//Moves start pointer to next node
  while(start != NULL){//Ensures addition continues until no nodes are left

    sum = sum + start->data;//adds sum and next node integer data
    start = start->next;//moves pointer to next node before loop continues
}
  return sum;//returns sum of all linked list integers to main()
}//ends function
