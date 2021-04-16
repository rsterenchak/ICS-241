/*
 * This program utilizes several variables, if, and switch statements in order to correctly display all numbers between one and nine hundred and ninety-nine translated into the Japanese language. By primarily using a "for" loop to iterate through all numbers this program was able to correctly display and print the japanese translations beginning from the hundreds place, then the tens, and finally the ones place.
 *
 * Robert Sterenchak
 * ICS212 - Assignments 07
 * September 20, 2019
 */

#include <stdio.h>

int main(void){
           
           /*Integer used to keep count during "for" loop iteration*/
	   int count = 0;
	   int number = 0;
	   /*Initial declaration of integer calculation necessary to use with switch statements*/
	   int hundreds = (number/1) % 10;
	   int tens = (number/10) % 10;	   
	   int ones = (number/1) % 10;
	   
	   /*"For" loop iterates through all numbers starting from number 1*/
	   for(count=1; count<=999; count++){
	     number = count;
	     /*Print statement iteratively begins each printed translation*/
	     printf("%i = ", count);
	     /*Calculations for number placing are redeclared in order to keep up with the count*/
	     hundreds = (number/100) % 10;
	     tens = (number/10) % 10;
	     ones = (number/1) % 10;
	     
	     /*"If" statement that determines whether or not it is necessary to begin with hundreds*/
	     if(number>=100){
	     /*"Switch" statement that begins analyzation of hundreds place number"*/
	     switch (hundreds){
	     /*Case is chosen depending on calculation*/  
             case 1:
               printf("hyaku ");
	       break;
             case 2:
               printf("nihyaku ");
	       break;
             case 3:
               printf("sanhyaku ");
	       break;
             case 4:
               printf("yonhyaku ");
	       break;
             case 5:
               printf("gohyaku ");
	       break;
             case 6:
               printf("rokuhyaku ");
	       break;
             case 7:
               printf("nanahyaku ");
	       break;
             case 8:
               printf("hachihyaku ");
	       break;
             case 9:
               printf("kyuuhyaku ");
	       break;
	       default: 
	       printf("\n");

             }
	     }

	     /*"If" statement that determines if it is necessary to begin with tens*/
	     if(number >=10){
	     /*"Switch" statement that begins analyzation of tens place number*/
	     switch (tens){
	       /*Case is chosen depending on calculation*/
	       case 1:
               printf("jyuu ");
	       break;
             case 2:
               printf("nijiyuu ");
	       break;
             case 3:
               printf("sanjiyuu ");
	       break;
             case 4:
               printf("yonjiyuu ");
	       break;
             case 5:
               printf("gojiyuu ");
	       break;
             case 6:
               printf("rokujiyuu ");
	       break;
             case 7:
               printf("nanajiyuu ");
	       break;
             case 8:
               printf("hachijiyuu ");
	       break;
             case 9:
               printf("kyuujiyuu ");
	       break;
	     /*Prevents additional spacing between hundreds and ones place when tens place is 0 */
	     case 0:
	       printf("");
	       break;
	     default:
	       printf("\n");
	       break;
	     }
	     }
	     /*"Switch" statement that begins analyzation of ones place number*/
	     switch (ones){
	     /*Case is chosen depending on calculation*/
	     case 1: 
	       printf("ichi\n");
	       break;
	     case 2:
	       printf("ni\n");
	       break;
	     case 3:
	       printf("san\n");
	       break;
	     case 4:
	       printf("yon\n");
	       break;
	     case 5:
	       printf("go\n");
	       break;
	     case 6:
	       printf("roku\n");
	       break;
	     case 7:
	       printf("nana\n");
	       break;
	     case 8:
	       printf("hachi\n");
	       break;
	     case 9:
	       printf("kyuu\n");
	       break;
	     /*Default case necessary to provide newline spacing*/  
	     default:
               printf("\n");
	       break;
	     }

	   }
	   return 0;



}
