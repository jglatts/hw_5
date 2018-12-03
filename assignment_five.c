/*

CIS 1057 Assignment 5
Author: John Glatts
TA: Shi Kai Fang
Due Date: 2 December 2018

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Function Prototypes */
void enter_grades(char [][50], float[], int);
void print_report(char [][50], float [], int);
float highest_grade(float[], int);
float lowest_grade(float[], int);
float average_grade(float[], int);
float median_grade(float[], int);
int highest_grade_name(float[], int);
int lowest_grade_name(float[], int);


int main(int argc, char const *argv[])
{
    int student_size;

    printf("__________________________________________________\n");
    printf("\n\tStudent Test Results Report");
    printf("\n__________________________________________________\n");
    printf("\n\nHow many students are being added??\n --> ");
    scanf("%d", &student_size);

    // have to declare these with integers, windows has a compiler error if initialized with student_size
    char student_names[50][50];
    float student_grades[50];

    // enter all the names and grades
    enter_grades(student_names, student_grades, student_size);

    return 0;
}


/* Enter student grades and sort them as they're entered */
void enter_grades(char names[][50], float grades[], int size)
{
    float temp;
    char temp_names[50][50];
    char first_char_check, second_char_check;
    int grades_entered = 0;

    for (int i = 0; i < size; ++i) {
        // ask for student name first
        printf("\nEnter student name\n --> ");
        // space has to be in front for the scanf() to work
        scanf(" %[^\n]s", names[i]);
        // get grades and sort from highest to lowest
        printf("\nEnter grade for %s\n --> ", names[i]);
        scanf("%f", &grades[i]);
        grades_entered++;

        // sort names as there entered
        // make sure we can check a value at i-1
        if (i >= 1 ) {
            // loop through the current amount of grades entered
            for (int j = 0; j < grades_entered; ++j) {
                // loop to keep checking adjacent values
                // change to sort by the Names, not the grades
                for (int k = 0; k < grades_entered; ++k) {
                    first_char_check = names[k][0];
                    second_char_check = names[k - 1][0];
                    if (first_char_check < second_char_check){
                        temp = grades[k];
                        strcpy(temp_names[k], names[k]);
                        grades[k] = grades[k - 1];
                        strcpy(names[k], names[k - 1]);
                        grades[k - 1] = temp;
                        strcpy(names[k - 1], temp_names[k]);
                    }
                }
            }
        }

    }
    // once all grades are entered, print formatted report
    print_report(names, grades, size);
}


/* Print a nice report and call other helper functions to get information */
void print_report(char names[][50], float grades[], int size)
{
    float average, median, highest, lowest;
    int highest_name_index, lowest_name_index;

    printf("\n\n\n*************************************");
    printf("\n\tSorted Test Results");
    printf("\n*************************************\n");

    for (int i = 0; i < size; ++i)
    {
        printf("\nName: %-15s \tGrade: %3.1f\n", names[i], grades[i]);
    }
    // call helper functions for information
    highest_name_index = highest_grade_name(grades, size);
    lowest_name_index = lowest_grade_name(grades, size);
    highest = highest_grade(grades, size);
    lowest = lowest_grade(grades, size);
    average = average_grade(grades, size);
    median = median_grade(grades, size);

    // print grade information
    printf("\nAverage: %3.1f    Median: %3.1f    Highest: %3.1f    Lowest: %3.1f\n", average, median, highest, lowest);
    printf("\nHighest Grade: %s \t\tLowest Grade: %s\n", names[highest_name_index], names[lowest_name_index]);
}


/* Return the average grade */
float average_grade(float grades[], int size)
{
    // add sort to beginning
    float sum = 0;
    float avrg;

    for (int i = 0; i < size; ++i)
    {
        sum += grades[i];
    }

    avrg = sum / size;
    return avrg;
}


/* Return median grade as a float */
float median_grade(float grades[], int size)
{
    float middle_number, temp;

    // sort the grades
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (grades[j] > grades[j + 1]) {
                temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }

    // check if array is even
    if(size % 2 == 0) {
        middle_number = (grades[(size - 1) / 2 ] + grades[size / 2]) / 2;
    }
    else {
        middle_number = grades[size / 2];
    }

    return middle_number;
}


/* Return highest grade as a float */
float highest_grade(float grades[], int size)
{
    float temp;

    // sort the grades
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (grades[j] > grades[j + 1]) {
                temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }

    return grades[size - 1];
}


/* Return lowest grade as a float */
float lowest_grade(float grades[], int size)
{
    float temp;

    // sort the grades
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (grades[j] > grades[j + 1]) {
                temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }

    return grades[0];
}


/* Return the index of the highest grade
 * print_report() will use the index to display the correct name
 * */
int highest_grade_name(float grades[], int size) {
    int high_idx = 0;

    // find the index of the highest grades
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (grades[j] > grades[high_idx]) {
                high_idx = j;
            }
        }
    }

    return high_idx;
}


/* Return the index of the lowest grade
 * print_report() will use the index to display the correct name
 * */
int lowest_grade_name(float grades[], int size) {
    int low_idx = 0;

    // find the index of the highest grades
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grades[j] < grades[low_idx]) {
                low_idx = j;
            }
        }
    }

    return low_idx;
}
