#include <stdio.h>   
#include <stdlib.h>
#include "student.h"
#include "getdouble.h"
#include "stringinput.h"

/**
 * YOU MUST RUN creating.c BEFORE RUNNING THIS PROGRAM to get student.data.
 * All associated files for creating.c and this program
 * will need to be in the same folder.
 *
 * Asks the user for student information, stores the information in
 * a Student struct and writes out the structure to a binary file.
 * Asks information for up to 20 students.
 *
 * The following files are needed to compile:
 *   getdouble.c
 *   stringinput.c
 *   student.h
 *   getdouble.h
 *   stringinput.h
 *   makefile-writing
 *
 * To compile:
 *   % rm program
 *   % make -f makefile-writing
 * To run:
 *   % ./program
 *
 * @author Ed Meyer
 * @original_author William Albritton
 */

/** Function prototype */
void printStudent(Student);
  
int main() {

  // Used to store and write out Student information.
  // -1 means no student data.
  Student studentX = {-1, "", "", 0, 0.0 };
  // Output filehandle and name of the file.
  FILE *filePointer = NULL;    
  char *fileName = "students.data";
  
  // Error checking variables.
  int fileClosed = 0;  
  int seekError = 0;
  int writeError = 0;
  int sizeFirstName = 0;
  int sizeLastName = 0;
  char dummyString[MAX_STRING] = {'\0'};
 
  // Open a connection to a file for writing a binary file.
  // note: using "wb" will overwrite the data
  // "rb+" = update an existing file for reading and writing
  // "b" is for binary file
  filePointer = fopen(fileName, "rb+");
  // If cannot open the filehandle, terminate the program.
  if (filePointer == NULL) {
    printf("File '%s' could not be opened.\n", fileName);
    exit(1);
  } else {
    // The file will only store 20 records, ensure the student being added
    // is between the amount that will be stored in the file.
    printf("Enter student number (0 to %d), or %d to quit: \n", MAX_RECORDS - 1, MAX_RECORDS); 
    studentX.number = getdouble();
    
    // Keep adding students as long as the number is between the acceptable amount.
    // Any number outside the acceptable range will end the program.
    while (studentX.number >= 0 && studentX.number < MAX_RECORDS) {
      
      // Get the student information.
      printf("Enter first name, last name, age, and gpa separated by spaces: \n");
      
      // Get the first name.
      // The user will type all information on a single line, but only retrieve
      // enough characters allotted for first name.
      sizeFirstName = getstring(studentX.first, MAX_STRING);
      
      // Note: Use MAX_STRING - 2, as the getstring() function only reads size-1 characters,
      // so the function actually reads size-2 characters,
      // as the function needs to identify the space or newline character or tab
      // that is used to separate the string inputs from the user
      if (sizeFirstName > MAX_STRING - 2) {
        printf("ERROR: Cannot enter first name greater than %d characters\n", MAX_STRING - 2); 
        // Clear the input stream.
        getline2(dummyString, MAX_STRING);
        continue;
      }
      
      // Repeat the same steps above for last name.
      // Get the last name. Same as the first name.
      // The user will type all information on a single line, but only retrieve
      // enough characters allotted for last name.
      sizeLastName = getstring(studentX.last, MAX_STRING);
      // Error checking.
      if (sizeLastName > MAX_STRING - 2) {
        printf("ERROR: Cannot enter last name greater than %d characters\n", MAX_STRING - 2);
        // Clear the input stream.
        getline2(dummyString, MAX_STRING);
        continue;
      }
      
      // The rest of the information left is the age and gpa.
      studentX.age = getdouble();
      studentX.gpa = getdouble();

      // Debugging statements.
      //printf("sizeFirstName = %d (%s)\n", sizeFirstName, studentX.first);
      //printf("sizeLastName =  %d (%s)\n", sizeLastName, studentX.last);
      
      // Use fseek() to find the insertion point of the new student.
      // Insertion point is student number * size of a Student structure.
      // SEEK_SET is to start the offset at the beginning of the file.
      seekError = fseek(filePointer, (studentX.number) * sizeof(Student), SEEK_SET);
      // Error checking.
      if (0 == seekError) {
        printf("Record #%d was correctly located in file \"%s\".\n", studentX.number, fileName);
      } else {
        printf("Record #%d was NOT correctly located in file \"%s\".\n", studentX.number, fileName);
      }
         
      // Write the student structure to the file.
      // Will overwrite records with the same student number.
      writeError = fwrite(&studentX, sizeof(Student), 1, filePointer);
      // Error checking.
      if (1 == writeError) {
        printf("Record #%d was correctly written to file  \"%s\". \n", studentX.number, fileName);
      } else {
        printf("Record #%d was NOT correctly written to file  \"%s\". \n", studentX.number, fileName);
      }
      // Output record.
      printStudent(studentX);
      // Prompt user again to continue inserting students.
      printf("Enter student number (0 to %d), or %d to quit: \n", MAX_RECORDS - 1, MAX_RECORDS);
      studentX.number = getdouble();     
    }      
    
    // Close the file connection.
    fileClosed = fclose(filePointer);
    // Error checking.
    if (0 == fileClosed) {
      printf("File connection to \"%s\" closed successfully.\n", fileName);
    } else {
      printf("File connection to \"%s\" did NOT close successfully.\n", fileName);
    }
  }
}

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

Enter student number (0 to 19), or 20 to quit: 
0
Enter first name, last name, age, and gpa separated by spaces: 
Bubba Smith 20 2.2
Record #0 was correctly located in file  "students.data". 
Record #0 was correctly written to file  "students.data". 
     0       Bubba       Smith   20  2.2  
Enter student number (0 to 19), or 20 to quit: 
5
Enter first name, last name, age, and gpa separated by spaces: 
Surfer Dude 40 4.0
Record #5 was correctly located in file  "students.data". 
Record #5 was correctly written to file  "students.data". 
     5      Surfer        Dude   40  4.0  
Enter student number (0 to 19), or 20 to quit: 
1
Enter first name, last name, age, and gpa separated by spaces: 
Sally Suzuki 29 3.3
Record #1 was correctly located in file  "students.data". 
Record #1 was correctly written to file  "students.data". 
     1       Sally      Suzuki   29  3.3  
Enter student number (0 to 19), or 20 to quit: 
20
File connection to "students.data" closed successfully.


 */
