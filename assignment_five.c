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
void enter_grades(char [][50], float[], int);
void print_report(char [][50], float[], int);


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
	float student_grades[student_size];	

	// enter all the names and grades
	enter_grades(student_names, student_grades, student_size);


	return 0;
}


/* Enter student grades and sort them as they're entered */
void enter_grades(char names[][50], float grades[], int size)
{
	float temp;
	char temp_names[size][50];   

	for (int i = 0; i < size; ++i)
	{
		// ask for student name first
		printf("\nEnter student name\n --> ");
		scanf(" %[^\n]s", names[i]);   // space has to be in front for the scanf() to work 
		// get grades and sort from highest to lowest
		printf("\nEnter grade for %s\n --> ", names[i]);
		scanf("%f", &grades[i]); 

		if ( i >= 1) {
			if (grades[i] < grades[i - 1]) {
					temp = grades[i];
					strcpy(temp_names[i], names[i]);
					grades[i] = grades[i - 1];
					strcpy(names[i], names[i - 1]);
					grades[i - 1] = temp;
					strcpy(names[i - 1], temp_names[i]);
				}

			}

	}

	// once all grades are entered, print formated report
	print_report(names, grades, size);

}

/* Print a nice report and call other helper functions to get information */
void print_report(char names[][50], float grades[], int size)
{
	float average, median, lowest = grades[0], highest = grades[size - 1];
	char highest_name[50], lowest_name[50];

	strcpy(highest_name, names[size - 1]);
	strcpy(lowest_name, names[0]);

	printf("\n\n\n__________________________________________________\n");
	printf("\n\tSorted Test Results");
	printf("\n__________________________________________________\n");

	for (int i = 0; i < size; ++i)
	{
		printf("\nName: %s              Grade: %0.1f\n", names[i], grades[i]);
	}

	/* call other functions to return information
	 average, median, highest, lowest, and name of highest score / name of lowest score
	printf("\n%s\n", );
	printf("%s\n", );
	printf("%s\n", );
	printf("%s\n", );
	*/

}	

