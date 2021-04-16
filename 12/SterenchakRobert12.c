/*
 * This program utilizes several variables as well as pointers in order to successfully print addresses and values using only the dereferenced pointer. Addition is also something used to change the variable values using only the dereferenced pointers. 
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 12
 * October 15, 2019
 */
#include <stdio.h>
#include <stdlib.h>

/*Main function where variables and pointers are initialized*/
int main (void){
  
  char presetChar = 'f';//initial character
  int initialInt = 5;//inital integer
  double initialDub = 3.14;//initial double

  printf("Variable Values:\n");
  printf("presetChar = %c\n", presetChar);//initial char value printed
  printf("initalInt = %i\n", initialInt);//inital int value printed
  printf("initialDub = %f\n\n", initialDub);//initial double value printed

  char *charPointer = NULL;//initializes character pointer
  charPointer = &presetChar;//points to character value
  int *intPointer = NULL;//initializes integer pointer
  intPointer = &initialInt;//points to integer value
  double *doublePointer = NULL;//initializes double pointer
  doublePointer = &initialDub;//points to double value

  printf("Pointer names and addresses stored:\n");
  printf("charPointer = %p\n", charPointer);//prints address location of presetChar
  printf("intPointer = %p\n", intPointer);//prints address location of initialInt
  printf("doublePointer = %p\n\n", doublePointer);//prints address location of initalDub   

  printf("Pointer names and values using dereferencing:\n");
  printf("dereferenced charPointer = %c\n",*charPointer );//prints value of presetChar
  printf("dereferenced intPointer  = %i\n", *intPointer);//prints value of initialInt
  printf("dereferenced doublePointer  = %f\n\n", *doublePointer);//prints value of initialDub

  *charPointer = (*charPointer + 4);//Adds value of 4 to presetChar by using dereferencing
  *intPointer = (*intPointer + 4);//Adds value of 4 to initialInt by using dereferencing
  *doublePointer = (*doublePointer + 4);//Adds value of 4 to initialDub by using dereferencing

  printf("Pointer names and values using dereferencing after + 4:\n");
  printf("dereferenced charPointer = %c\n",*charPointer );//prints new value of presetChar
  printf("dereferenced intPointer  = %i\n", *intPointer);//prints new value of initialInt
  printf("dereferenced doublePointer  = %f\n\n", *doublePointer);//prints new value of initialDub

  printf("Variable Values:\n");
  printf("presetChar = %c\n", presetChar);//reprint of new char value
  printf("initalInt = %i\n", initialInt);//reprint of new int value
  printf("initialDub = %f\n\n", initialDub);//reprint of new double value
  
  return 0;
  
}//end of main


  


