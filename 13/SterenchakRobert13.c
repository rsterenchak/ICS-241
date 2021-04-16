/*
 * This program utilizes an array of integers SIZE [5] along with pointers in order to print the integers and addresses corresponding to each index. A custom function is also used to dereference the address of one preset integer with the purpose of manipulating the original value. 
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 13
 * October 21, 2019
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void increaseIntViaPointer(int (*));//Custom function

/*Main function where variables and pointers are initialized*/
int main (void){
  
  int array[SIZE] = {13, 72, 88, 100, 17};//array of size 5 with preset integers at each index
  int *pointer = array;//points to array

  int value = 10;//preset integer variable


  printf("Printing the last element in the array:\n");//Begin printing of last element
  printf("array[4] = %i\n", array[4]);//First print using subsript notation
  printf("*(array + 4) = %i\n", *(array + 4));//Second print using pointer/offset notation
  printf("pointer[4] = %i\n", pointer[4]);//Third print using array subscript notation with the pointer
  printf("*(pointer + 4) = %i\n\n", *(pointer + 4));//Fourth print using pointer/offset notation with the pointer


  printf("Printing the contents of the array:\n");

  int i = 0;//initializes counter for following "for" loops

  printf("  Using the array subscript notation with the array name...\n   ");
  for(i = 0; i < SIZE; i++){
    printf(" %i", array[i]);//First print using subsript notation
    if(i < (SIZE-1)){
      printf(",");//Comma printed if not the last integer in array
    }
  }

  printf("\n  Using pointer/offset notation with the array name...\n   ");
  for(i = 0; i < SIZE; i++){
    printf(" %i", *(array + i));
    if(i < (SIZE - 1)){
      printf(",");//Comma printed if not the last integer in array 
    }
  }

  printf("\n  Using array subscript notation with pointer...\n   ");
  for(i = 0; i < SIZE; i++){
    printf(" %i", pointer[i]);
    if(i < (SIZE - 1)){
      printf(",");//Comma printed if not the last integer in array 
    }
  }

  printf("\n  Using pointer/offset notation with pointer...\n   ");
  for(i = 0; i < SIZE; i++){
    printf(" %i", *(pointer + i));
    if(i < (SIZE - 1)){
      printf(",");//Comma printed if not the last integer in array 
    }
  }
  
  printf("\n\nPrinting the addresses of each element in the array:\n");
  for(i = 0; i < SIZE; i++){
    printf("  &array[%i] = %p\n",i ,&array[i]);//Prints the address of each array index
  }

  printf("\nInteger variable BEFORE function call...\n");
  printf("  value = %i\n", value);//Printed value before function call
  
  increaseIntViaPointer(&value);//function call edits and prints variable from within function
  
  printf("Integer variable AFTER function call...\n");
  printf("  value = %i\n", value);//Printed value after function call from within main function

  return 0;
  
}//end of main

/*Custom function receiving the dereferenced address of value int variable*/
void increaseIntViaPointer(int *valueParam){

  *valueParam = (*valueParam + 100);//Adds 100 to dereferenced variable 

  printf("Inside increaseIntViaPointer() function, increasing parameter by 100...\n");
  printf("  valueParam = %i\n", *valueParam);//informs user and prints variable from within funtion
}

  


