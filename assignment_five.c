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


/* load strings in 2-D array */

/*
void load_ray(char names_ray[][30], int size)
{
	for (int i = 0; i < size ; ++i)
	{
		printf("Enter Comment...\n");
		scanf("%s", names_ray[i]);
	}
}

void print_strings(char names[][30], int size)
{
	printf("\n************************************\n");
	for (int i = 0; i < size; ++i)
	{
		printf("  %s  ", names[size]);
	}
	printf("\n************************************\n");

}


void find_value(char names_ray[][30], int size)
{
	char find_value;

	printf("\nEnter a character to search for...\n --> ");
	scanf("%c", &find_value);  // remove ampersand when implementing

	printf("\nIndex[%d] --> %s\n", find_value, names_ray[find_value]);
	//loop through all values and check each one
	// get ASCII numbers to properly check
	/*
	for (int i = 0; i < size; ++i)
	{
		/* code */
	/*
}


/* sort strings, smallest to largest */
/*
void sort_strings(char names_ray[][30], int size)
{
	char temp[size][30]; //temp storage for the greater value, does it have to be 2-D?

	/* Bubble sort to find smallest string */
	/*
	for (int s = 0; s < size - 1; ++s)
	{
		for (int value = 0; value < size - s - 1; ++value)
		{
			if (strlen(names_ray[value]) > strlen(names_ray[value + 1]))
			{
				// use strcpy() to copy the values
				strcpy(temp[value], names_ray[value]);
				strcpy(names_ray[value], names_ray[value + 1]);
				strcpy(names_ray[value + 1], temp[value]);
			}
		}
		// gets length of smallest string?
		printf("\nLength of string[%d] --> %ld\n", s, strlen(names_ray[s]));
	}
}



/*
void del_string(char names_ray[][30], int size)
{

}
*/

/* Start of program, user enter grades until limit is reached */ 
void enter_grades(char names[][50], int grades[], int size)
{
	// SORT the grades as they're entered
	for (int i = 0; i < size; ++i)
	{
		printf("\nEnter Name...\n --> ");
		scanf("%s")
	}
}


int main(int argc, char const *argv[])
{
	int student_size;

	printf("__________________________________________________\n");
	printf("\n\tStudent Test Results Report");
	printf("\n__________________________________________________\n");
	printf("\n\nHow many students are being added??\n --> ");
	scanf("%d", &student_size);

	char student_names[student_size][50]; 	// declare a 2-D array of strings to hold student names 
	int student_grades[student_size]; // size of the actual grades array will be same size as the amount of students
	enter_grades(student_names, student_grades, student_size);
	/*
	do
	{

	} while (quit_compare != 0); // may be overkill, doublecheck
	*/

	return 0;

}

