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


/* Test helper func() because of the buffer overflow */
void enter_grades(int grades[], int index)
{
	int temp;

	fflush(stdin);
	printf("Enter Grade...\n --> ");
	scanf("%d%*c", &grades[index]);

	// sort grades as they're entered
	if (grades[index] < grades[index - 1])
	{
		temp = grades[index];
		grades[index] = grades[index - 1];
		grades[index - 1] = temp;
	}
}


/* Start of program, user enter grades until limit is reached */ 
void enter_names(char names[][50], int grades[], int size)
{
	int temp;
	char temp_array[size];

	// SORT the grades as they're entered
	// skips over the first name\grade pair, damnit
	for (int i = 0; i < size; ++i)
	{
		// add seperate scanf() for number grade
		printf("\nEnter Name...\n --> ");
		fgets(names[i], 150, stdin);
		//fflush(stdin);
		fgets(temp_array[i], 10, stdin); // will this work for int?
		grades[i] = atoi(temp_array[i]);
	}

	printf("\n");

	// test print
	for (int test = 0; test < size; ++test)
	{
		printf("\nName: %s -- Grade: %d;\n", names[test], grades[test]);
	}
}


int main(int argc, char const *argv[])
{
	int student_size;
	char student_grades[student_size]; // size of the actual grades array will be same size as the amount of students
	char student_names[student_size][50]; 	// declare a 2-D array of strings to hold student names 
	
	printf("__________________________________________________\n");
	printf("\n\tStudent Test Results Report");
	printf("\n__________________________________________________\n");
	printf("\n\nHow many students are being added??\n --> ");
	scanf("%d", &student_size);
	enter_grades(student_names, student_grades, student_size);

	/*
	do
	{

	} while (quit_compare != 0); // may be overkill, doublecheck
	*/

	return 0;

}

