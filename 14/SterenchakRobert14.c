/*
 * This program utilizes a pointer array of functions, integer variables, declared custom functions, and error checking with "if" statements in order to ensure valid input while using the commandline arguments instead of runtime user input.
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 14
 * October 21, 2019
 */
#include <stdio.h>
#include <string.h>


int add(int, int);//addition of the parameters
int sub(int, int);//subtraction of the parameters
int mul(int, int);//multiplication of the parameters
int div(int, int);//division of the parameters


/*Main function where variables and pointers are initialized, commandline input is also utilized*/
int main(int argc, char *argv[]){
  
  if(argc < 4){//Ensures number of arguments are not less than 4.
    printf("Error: 4 command line arguments are expected, only %i present.\n", argc);
  }

  if(((argv[1][0]) < '0')||((argv[1][0]) > '9')){//Error check to ensure valid range
    printf("Error: The first argument is not a character between 0 and 9 inclusive.\n");//First argument
  }

  if(((argv[3][0]) < '0')||((argv[3][0]) > '9')){//Error check to ensure valid range
    printf("Error: The third argument is not a character between 0 and 9 inclusive.\n");//Third argument
  }

  if(((argv[2][0]) < '+')||((argv[2][0]) == ',')||((argv[2][0]) > '/')){//Error check for valid operator
    printf("Error: %c is not a valid math operation. Use: + - . /\n", argv[2][0]);//Second argument
  }

  int number1 = argv[1][0] - '0';//translates character to an integer
  int number2 = argv[3][0] - '0';//translates character to an integer

  int index = argv[2][0] - '+';//Finds specific index
  
  int (*calcArray[5])(int, int) = {add, NULL, sub, mul, div};//initialization of pointer array to custom functions

  int result = calcArray[index](number1, number2);//Pointer function call to complete math operation

  printf("%i %c %i = %i \n",number1, argv[2][0], number2, result);//Prints equation and result to user

  return 0;
  
}//end of main

/*Performs addition*/
int add(int var1, int var2){

int total = var1 + var2;
return total;

}
  
/*Performs subtraction*/
int sub(int var1, int var2){

int total = var1 - var2;
return total;

}

/*Performs multiplication*/
int mul(int var1, int var2){

int total = var1 * var2;
return total;

}

/*Performs division*/
int div(int var1, int var2){

int total = (var1 / var2);
return total;

}
