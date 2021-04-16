#define MAX_RECORDS 20
#define MAX_STRING 12

/**
 * A "student" structure.
 * Stores the following attributes of a student:
 *   1) number: Student ID number
 *   2) first: First name
 *   3) last: Last name
 *   4) age
 *   5) gpa
 */
struct student {
  int number;
  char first[MAX_STRING];
  char last[MAX_STRING];
  int age;       
  double gpa;    
};
// Student alias for struct student.
typedef struct student Student;