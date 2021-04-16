/*
 * This program utilizes several variables and three pre-defined user functions in order to correctly read user input and compare this input to the randomly generated computer value. Human input and computer generated int values are compared to determine winner of rock, paper, and scissors game. This program will continue running until user decides to exit using the 'q' or 'Q' commands.  
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 09
 * October 02, 2019
 */
#include <stdio.h>
#include <stdlib.h>

#define TITLE "Let's play rock, paper, scissors, human!\n\n"

int compare(int, int);//This function conducts comparison to determine who won and if game was a tie.
int count(int);//This function helps in counting wins and losses.
int end(char);//This function provides a way to end program runtime.

int main (void){

  
  int compWin = 0;//computer win count
  int humaWin = 0;//human win count
  int tieGam = 0;//tie game count

  char endGame;//variable used to help continue while loop execution 
  char humanPlay = 'c';//character value initially chosen by user
  int humanNum;//int value used for comparison inside the compare()function
  
  /*While loop ensures game continuously runs until parameter is not met.*/
  while (endGame != 'q'){
    
  printf(TITLE);//Let's play message 
  srand(time(NULL));//initializes random number
  int compNum = (0 + rand() % 3);//generates computer play value between 0-2 inclusive

  /*This while loop continous to run if incorrect value is entered.*/
  while((humanPlay != 'r')||(humanPlay != 'p')||(humanPlay != 's')){
  printf("Please choose 'r' for rock, 'p' for paper, or 's' for scissor. \n");
  printf("You may also press q to quit the program. ");
  humanPlay = getchar();//recieves human char input
  getchar();

  /*Correlates humanPlay value to an int value to be compared later*/
  if(humanPlay == 'r'){
    humanNum = 0;
    break;
  }

  /*Correlates humanPlay value to an int value to be compared later*/
  if(humanPlay == 'p'){
    humanNum = 1;
    break;
  }
  /*Correlates humanPlay value to an int value to be compared later*/
  if(humanPlay == 's'){
    humanNum = 2;
    break;
  }

  /* If this value is chosen runtime finish of program has begun, starting with printing game results*/
  if(humanPlay == 'q'){
    printf("User Wins          Computer Wins          Ties\n");
    printf("   %i                      %i                %i\n", humaWin, compWin, tieGam);
    printf("GAME OVER\n");
    int runtimeEnd = end(humanPlay);//Calls third function to execute exit program command.
    }
  
  /* If this value is chosen runtime finish of program has begun, starting with printing game results*/
  if(humanPlay == 'Q'){
    printf("User Wins          Computer Wins          Ties\n");
    printf("%i,                        %i                %i\n", humaWin, compWin, tieGam);
    printf("GAME OVER\n");    
    int runtimeEnd = end(humanPlay);//Calls third function to execute exit program command.
  }

  /*If incorrect value is the following message will display to the user*/
  if((humanPlay != 'r')&&(humanPlay != 'p')&&(humanPlay != 's')&&(humanPlay != 'q')&&(humanPlay != 'Q'))\
    {
      printf("You've inputted an incorrect character. Please try again.\n\n");//Error message
    }

  }//ends while loop

  
  int result = compare(compNum, humanNum);//Function compares int values chosen by computer and human
  int counter = count(result);//Function helps to count wins of computer, human , and ties.

  /*Prints beginning of print statement containing computer result to user*/
  if(compNum==0){
    printf("Computer's Rock vs ");
  }
  /*Prints beginning of print statement containing computer result to user*/
  if(compNum==1){
    printf("Computer's Paper vs ");
  }
  /*Prints beginning of print statment containing computer result to user*/
  if(compNum==2){
    printf("Computer's Scissors vs ");
  }
  /*Prints backend of print statement containing human result to user*/
  if(humanNum==0){
    printf("Your Rock\n");
  }
  /*Prints backend of print statement containing human result to user*/
  if(humanNum==1){
    printf("Your Paper\n");
  }
  /*Prints backend of print statement containing human result to user*/
  if(humanNum==2){
    printf("Your Scissors\n");
  }

  /*Prints statement result and adds to counter*/
  if(result == 0){
  printf("COMPUTER WINS!!!\n\n");
  compWin = compWin + counter;
  //count function
  }

  /*Prints statement result and adds to counter*/
  if(result == 1){
    printf("HUMAN WINS!!!\n\n");
    humaWin = humaWin + counter;
  //count function
  }

  /*Prints statement result and adds to counter*/
  if(result == 2){
    printf("ITS A TIE!!!\n\n");
    tieGam = tieGam + counter;
  //count function
  }                                 
  }//While loop end

  return 0;
  
}

/*Executes program end*/
int end(char humanPlay){
  exit(0);//command executes runtime finish of program
}

/*Adds value to wincounts inside main function*/
int count(int result){
  int x = result;
  int winCount;//return value to user

  if(x == 0){
    winCount = 1;
    return winCount;//returns value of 1 to be added to win count variable
  }
  if(x == 1){
    winCount = 1;
    return winCount;//returns value of 1 to be added to win count variable
  }
  if(x == 2){
    winCount = 1;
    return winCount;//returns value of 1 to be added to win count variable
  }


}

/*Compares int values and returns an int value determinant on 'if' statements inside function*/
int compare(int compNum, int humanNum){
  int x = compNum;//computer's number is set to x to make combinations easier to read
  int y = humanNum;//human's number is set to y to make combinations easier to read
  int result;//variable returned to the main function

  if(x == y){
    result = 2;//tie
    return result;//return value 2
  }

  if(((x==0) && (y==2))){
    result = 0;//computer wins
    return result;//return value 0
  }
  if(((x==1) && (y==0))){
    result = 0;//computer wins                                                                          
    return result;//return value 0
  }
  if(((x==2) && (y==1))){
    result = 0;//computer wins                                                                          
    return result;//return value 0
  }

  if(((x==2) && (y==0))){
    result = 1;//human wins                                                                           
    return result;//return value 1
  }

  if(((x==0) && (y==1))){
    result = 1;//human wins                                                                             
    return result;//return value 1
  }

  if(((x==1) && (y==2))){
    result = 1;//human wins                                                                          
    return result;//return value 1
  }

}
