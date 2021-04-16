/*
 * This program utilizes several self made custom functions as well as an array of 0 values in order to count and keep track of letters used within sentences typed or text files processed by this program. The program properly gives instructions to the user and when the user declares EOF (end of file) the letter counts are printed to the user.   
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 11
 * October 14, 2019
 */
#include <stdio.h>
#include <stdlib.h>

/*Constant SIZE for array*/
#define SIZE 26

void printInstructions(void);
void loopAndCountLetters(int[]);
void outputResults(int[], int);

/*Main function where function calls are initalized for this program.*/
int main (){
  
  int letters[SIZE]= {0};

  printInstructions();//function 1
  loopAndCountLetters(letters);//function 2
  outputResults(letters, SIZE);//function 3
  
  return 0;
  
}//end of main

/*This function prints initial instructions to the user.*/
void printInstructions(void){

  printf("This program will count the letters of the alphabet.\n");
  printf("Type several sentences, or use input redirection to input a file.\n");
  printf("To exit program, enter EOF (end of file) by pressing Ctrl-D.\n");

}//end of function

/*This function loops continuously increments each array value by one, specified by user input.*/
void loopAndCountLetters(int a[]){
  char inputChar = 'a';//inital character value
  int index = 0;//initial integer value

  /*Ensures input does not end until user gives the command.*/
  while(inputChar!=EOF){
    inputChar = getchar();//Receives user input
    
    if((inputChar>='A')&&(inputChar<='Z')){//Checks if letter input is uppercase
      index = (inputChar - 'A');//calculates array position
      a[index]++;//increments array value at specified position
    }
    if((inputChar>='a')&&(inputChar<='z')){//Checks if letter input is lowercase
      index = (inputChar -'a');//calculates array position
      a[index]++;//increments array value at specified position
    }
  }//end while loop
}//end of function

void outputResults(int a[], int size){
  int i = 0;//initial integer value
  char start = 'a';//initial character value
  printf("Character        Count\n");//prints heading for ouput results
  /*Loops through each array position printing incremented values*/
  for(i=0; i<size; i++){
    printf("        %c            %d\n", start, a[i]);//prints alphabet and letter count
    start++;//increments through alphabet
  }//end of for loop
}//end of function
  


