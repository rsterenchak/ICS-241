#include <stdio.h>  
#include <stdlib.h>
#include "student.h"
#include "getdouble.h"
#include "stringinput.h"

/**
 * YOU MUST RUN creating.c BEFORE RUNNING THIS PROGRAM to get student.data.
 * Run writing.c to insert students into student.data binary file.
 *
 * Reads in a binary file of student structures with 20 fixed-length records.
 * Stores each record in an array, then prints it all out.
 *
 * The following files are needed to compile:
 *   getdouble.c
 *   getdouble.h
 *   stringinput.c
 *   stringinput.h
 *   student.h
 *   makefile-reading
 *
 * To compile:
 *   % rm program
 *   % make -f makefile-reading
 * To run:
 *   % ./program
 * @modified_author Robert Sterenchak
 * @author Ed Meyer
 * @original_author William Albritton
 */

/** Function prototype */
void printStudent(Student);
  
int main() {

  
  FILE *filePointer2 = NULL;//Initializes filePointer2
  char *fileName2 = "students.txt";//Initializes filename pointer for students.txt

  // Loop increment variable.
  int i = 0;
  // Used to temporarily store a student before it gets stored in an array.
  Student studentX = {-1, "", "", 0, 0.0};
  // Used to store all student records.
  Student studentArray[MAX_RECORDS] = {-1, "", "", 0, 0.0};
  
  // Input filehandle and filename.
  FILE *filePointer = NULL;
  char *fileName = "students.data";
  
  // Error checking variables.
  int fileClosed = 0;
  int readError = 0;
  
  // Open a connection to a file for reading a binary file.
  // "rb" to read from a binary file
  filePointer = fopen(fileName, "rb");

  filePointer2 = fopen(fileName2, "w");//Opens and creates student.txt and makes file "writable"

  // If cannot open the filehandle, terminate the program.//modified_author - changed for filePointer2
  if ((filePointer == NULL)|(filePointer2 == NULL)) {
    printf("File \"%s\" could not be opened.\n", fileName);
    printf("File \"%s\" could not be written.\n", fileName2);//Prints Error message if not opened.
    exit(1);//Exits Program
  } else {
  
    // Keep reading until the EOF is reached.
    while (0 == feof(filePointer)) {
      // Read in an amount of bytes equal to a student structure.
      // The file pointer will automatically advance at every read.
      readError = fread(&studentX, sizeof(Student), 1, filePointer);
      // Successful read.
      if (1 == readError) {
        // Store the student record in the array.
        printf("Record #%d was correctly read from file \"%s\".\n", i, fileName);
        studentArray[i] = studentX;
        // Print out the student.
        printStudent(studentArray[i]);
       
      } else {
        printf("Record #%d was NOT correctly read from file \"%s\".\n", i, fileName);
      }
      i++;
    }

    // Close the file connection.
    fileClosed = fclose(filePointer);
    // Error checking.
    if (0 == fileClosed) {
      printf("File connection to \"%s\" closed successfully.\n", fileName);
    } else {
      printf("File connection to \"%s\" did NOT close successfully.\n", fileName);
    }
      
    // Display all records.
    // -1 records are ignored as they are non-existent students.
    printf("\nNumber   FirstName    LastName  Age  GPA  \n"); 
    printf("------   ---------    --------  ---  ---  \n");
    fprintf(filePointer2, "\nNumber   FirstName    LastName  Age  GPA  \n");
    fprintf(filePointer2, "------   ---------    --------  ---  ---  \n");
    for (i = 0; i < MAX_RECORDS; i++) {
      if (-1 != studentArray[i].number) {
        printStudent(studentArray[i]);
	fprintf(filePointer2, "%6d  %10s  %10s  %3d  %3.1f\n", studentArray[i].number, studentArray[i].first, studentArray[i].last, studentArray[i].age, studentArray[i].gpa);//Prints all variables from array into student.txt file
      }
    }                                                                           
    fileClosed = fclose(filePointer2);//Initializes closing of student.txt file connection
    /*Error checking for to ensure file connection to student.txt is closed*/
    if (0 == fileClosed) {
      printf("\nFile connection to \"%s\" closed successfully.\n", fileName2);
    } else {
      printf("\nFile connection to \"%s\" did NOT close successfully.\n", fileName2);
    }

  }
}//Ends MAIN

/**
 * Prints the attributes of a student structure.
 * For example:
 *      1       Susan      Suzuki   11  2.5
 *
 * @param studentX A student structure to be printed.
 */
void printStudent(Student studentX) {
  printf("%6d  %10s  %10s  %3d  %3.1f  \n", 
         studentX.number, 
         studentX.first, 
         studentX.last, 
         studentX.age, 
         studentX.gpa);
}

/*
Record #0 was correctly read from file "students.data". 
     0      Bubba     Smith   20  2.2  
Record #1 was correctly read from file "students.data". 
     1      Sally    Suzuki   29  3.3  
Record #2 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #3 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #4 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #5 was correctly read from file "students.data". 
     5     Surfer      Dude   40  4.0  
Record #6 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #7 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #8 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #9 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #10 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #11 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #12 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #13 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #14 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #15 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #16 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #17 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #18 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #19 was correctly read from file "students.data". 
    -1                         0  0.0  
Record #20 was NOT correctly read from file "students.data". 
File connection to "students.data" closed successfully.

Number  FirstName  LastName  Age  GPA  
------  ---------  --------  ---  ---  
     0      Bubba     Smith   20  2.2  
     1      Sally    Suzuki   29  3.3  
     5     Surfer      Dude   40  4.0 
*/

