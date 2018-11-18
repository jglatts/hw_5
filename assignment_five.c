/*

CIS 1057 Assignment 5 
Author: John Glatts
TA: Fang
Due Date: 26 November 2018

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* Function Prototypes */
void enter_grades(char [][50], int[], int);


int main(int argc, char const *argv[])
{
	int student_size;

	printf("__________________________________________________\n");
	printf("\n\tStudent Test Results Report");
	printf("\n__________________________________________________\n");
	printf("\n\nHow many students are being added??\n --> ");
	scanf("%d", &student_size);

	// declare string arrays for all the names
	char student_names[student_size][50];
	int student_grades[student_size];	

	// enter all the names and grades
	enter_grades(student_names, student_grades, student_size);


	return 0;
}


void enter_grades(char names[][50], int grades[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		// ask for student name first
		printf("\nEnter student name\n --> ");
		scanf(" %[^\n]s", names[i]);   // space has to be in front for the scanf() to work 
	}

	// test print
	for (int test = 0; test < size; ++test)
	{
		printf("\nName: %s\n", names[test]);
	}

}
