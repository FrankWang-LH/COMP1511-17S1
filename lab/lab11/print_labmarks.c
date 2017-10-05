// Frank and Tanya
// MAY 15 2017
// print student mark
// modified from provided files

// starting point for COMP1511 lab 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STUDENT_NAME_LENGTH 128
#define MAX_GRADE_STRING_LENGTH 22
#define MAX_LAB_NAME_LENGTH 32
#define MAX_LINE_LENGTH 4096

// introduce prototype for function
double grades2labmark(char grades[]);

struct student {
    int              zid;
    char             name[MAX_STUDENT_NAME_LENGTH + 1];
    char             lab_name[MAX_LAB_NAME_LENGTH + 1];
    char             lab_grades[MAX_GRADE_STRING_LENGTH + 1];
    struct student   *next;
};

struct student *read_students_file(char filename[]);
struct student *read_student(FILE *stream);

int main(int argc, char *argv[]) {

    double mark = 0.0;

    struct student *student_list = read_students_file(argv[1]);

    struct student *p = student_list;
    // go through the list
    while(student_list != NULL){
        // just print the student in the required lab
        if(strcmp(student_list -> lab_name,argv[2]) == 0){
            // calculate the mark with the function
            mark = grades2labmark(student_list -> lab_grades);
            // print the list
            printf("%d %-30s %-12s %-22s %4.1lf\n",student_list -> zid,student_list -> name,student_list -> lab_name,student_list ->  lab_grades, mark);
        }
        // continue to the next student until end of list
        student_list = student_list -> next;
        // free up memory
        struct student *next = p -> next;
        free(p);
        p = next;
    }

    return 0;
}

// function to calculate mark
double grades2labmark(char grades[]){
    double mark = 0.0;
    // go through the array
    int i = 0;
    while(grades[i] != 0){ 
        // add points for each mark       
        if(grades[i] == 'A'){
            mark = mark + 1.0;
        } else if(grades[i] == '+'){
            mark = mark + 0.2;// A+ = 1.2 and A = 1.0, which means "+" = 0.2
        } else if(grades[i] == 'B'){
            mark = mark + 0.8;
        } else if(grades[i] == 'C'){
            mark = mark + 0.5;
        } 
        i = i + 1;
    }

    // maximum mark is 10.0
    if(mark > 10.0){
        mark = 10.0;
    }
    
    return mark;
}


// DO NOT CHANGE THE CODE BELOW HERE - DO NOT CHANGE read_students_file

// read_students_file reads a file where line contains information for 1 student
// it creates a linked of student structs containing the information
// it returns a pointer to the head of the list

struct student *read_students_file(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr,"warning file %s could not  be opened for reading\n", filename);
        return NULL;
    }

    struct student *first_student = NULL;
    struct student *last_student = NULL;
    struct student *s;
    while ((s = read_student(fp)) != NULL) {
        if (last_student == NULL) {
            first_student = s;
            last_student = s;
        } else {
            last_student->next = s;
            last_student = s;
        }
    }
    return first_student;
}

// DO NOT CHANGE read_student

// read_student mallocs a student struct
// and reads a line in this format:
//
// 5099703 Tsun Bordignon thu13-sitar A+A+CABAB..A.
//
// stores the values in the struct field
// and returns a pointer to the struct

struct student *read_student(FILE *stream) {
    char line[MAX_LINE_LENGTH];

    struct student *s = malloc(sizeof (struct student));
    assert(s);

    if (fgets(line, MAX_LINE_LENGTH, stream) == NULL) {
        free(s);
        return NULL;
    }

    char *newline_ptr = strchr(line, '\n');
    assert(newline_ptr);
    *newline_ptr = '\0';

    char *space_ptr = strrchr(line, ' ');
    assert(space_ptr);
    strncpy(s->lab_grades, space_ptr + 1, MAX_GRADE_STRING_LENGTH);
    s->lab_grades[MAX_GRADE_STRING_LENGTH] = '\0';
    *space_ptr = '\0';

    space_ptr = strrchr(line, ' ');
    assert(space_ptr);
    strncpy(s->lab_name, space_ptr + 1, MAX_LAB_NAME_LENGTH);
    s->lab_name[MAX_LAB_NAME_LENGTH] = '\0';
    *space_ptr = '\0';

    space_ptr = strchr(line, ' ');
    assert(space_ptr);
    strncpy(s->name, space_ptr + 1, MAX_STUDENT_NAME_LENGTH);
    s->name[MAX_STUDENT_NAME_LENGTH] = '\0';
    *space_ptr = '\0';

    s->zid = atoi(line);
    s->next = NULL;
    return s;
}
