/*
CIS 1057 Assignment 5
Author: John Glatts
TA: Shi Kai Fang
Due Date: 26 November 2018
========================
 SORTING UNIT TEST
========================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* Function Prototypes */
void enter_grades(char [][50], float[], int);
void print_report(char [][50], float[], int);
float average_grade(float[], int);
float median_grade(float[], int);


int main(int argc, char const *argv[])
{
    int student_size;

    srand(time(NULL));
    printf("__________________________________________________\n");
    printf("\n\tStudent Test Results Report");
    printf("\n__________________________________________________\n");
    printf("\n\nHow many students are being added??\n --> ");
    scanf("%d", &student_size);

    // declare string arrays for all the names
    // have to declare these with integers, windows has a compiler error if initialize with student_size (works on linux)
    char student_names[50][50];
    float student_grades[50];

    // enter all the names and grades
    enter_grades(student_names, student_grades, student_size);


    return 0;
}


void random_grade(int index, float grades[])
{
    grades[index] = rand() % 100 + 1;
}


/* Enter student grades and sort them as they're entered */
void enter_grades(char names[][50], float grades[], int size)
{
    float temp;
    char temp_names[50][50];
    char first_check_char, second_check_char;
    int names_entered = 0;

    for (int i = 0; i < size; ++i) {
        // ask for student name first
        printf("\nEnter student name\n --> ");
        // space has to be in front for the scanf() to work on windows CL.
        scanf(" %[^\n]s", names[i]);
        // get grades and sort from highest to lowest
        random_grade(i, grades);
        names_entered++;

        // sort grades as there entered, plz baby jesus
        // make sure we can check a value at i-1
        if (i >= 1 ) {
            // loop through the current amount of names entered
            for (int j = 0; j < names_entered; ++j) {
                // loop to keep checking names
                for (int k = 0; k < names_entered; ++k) {
                    // place names in the right order
                    first_check_char = names[k][0];
                    second_check_char = names[k-1][0];
                    if (first_check_char < second_check_char){
                        temp = grades[k];
                        strcpy(temp_names[k], names[k]);
                        grades[k] = grades[k - 1];
                        strcpy(names[k], names[k - 1]);
                        grades[k - 1] = temp;
                        strcpy(names[k - 1], temp_names[k]);
                    }
                }
            }
            // test print to see what the sort is really doing
            printf("\n");
            for (int k = 0; k < size; ++k) {
                printf("%s --> %.1f", names[k], grades[k]);
                printf("\n");
            }

        }

    }
    // once all grades are entered, print formatted report
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
        // add formatting tools instead of padding
        printf("\nName: %s \t\t\tGrade: %0.1f\n", names[i], grades[i]);
    }

    /* call other functions to return information */
    average = average_grade(grades, size);
    median = median_grade(grades, size);

    printf("\nAverage: %.1f    Median: %.1f    Highest: %.1f    Lowest: %.1f\n", average, median, highest, lowest);

}


/* Return the average grade */
float average_grade(float grades[], int size)
{
    float sum = 0;
    float avrg;

    for (int i = 0; i < size; ++i)
    {
        sum += grades[i];
    }

    avrg = sum / size;
    return avrg;
}


/* Return median grade as a double */
float median_grade(float grades[], int size)
{
    float middle_number;

    // check if array is even
    if(size % 2 == 0) {
        middle_number = (grades[(size - 1) / 2 ] + grades[size / 2]) / 2;
    }
    else {
        middle_number = grades[size / 2];
    }

    return middle_number;
}
