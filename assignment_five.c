/*

CIS 1057 Assignment 5
Author: John Glatts
TA: Shi Kai Fang
Due Date: 29 November 2018

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* Function Prototypes */
void enter_grades(char [][50], float[], int);
void print_report(char [][50], char [][50], float [], float [], int);
void temp_values(char [][50], char [][50], float [], float [], int);
float average_grade(float[], int);
float median_grade(float[], int);


int main(int argc, char const *argv[])
{
    int student_size;

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


/* Enter student grades and sort them as they're entered */
void enter_grades(char names[][50], float grades[], int size)
{
    float temp, temp_grades[50];
    char temp_names[50][50];
    char first_char_check, second_char_check;
    int grades_entered = 0;

    for (int i = 0; i < size; ++i) {
        // ask for student name first
        printf("\nEnter student name\n --> ");
        // space has to be in front for the scanf() to work
        scanf(" %[^\n]s", names[i]);
        strcpy(temp_names[i], names[i]);
        // get grades and sort from highest to lowest
        printf("\nEnter grade for %s\n --> ", names[i]);
        scanf("%f", &grades[i]);
        temp_grades[i] = grades[i];
        grades_entered++;

        // sort grades as there entered, plz baby jesus
        // make sure we can check a value at i-1
        if (i >= 1 ) {
            // loop through the current amount of grades entered
            for (int j = 0; j < grades_entered; ++j) {
                // loop to keep checking adjacent values
                // change to sort by the Names, not the grades
                for (int k = 0; k < grades_entered; ++k) {
                    //printf("\nChecking Values %.1f and %.1f", grades[k], grades[k - 1]);
                    first_char_check = names[k][0];
                    second_char_check = names[k - 1][0];
                    printf("\nChecking Values %c and %c", first_char_check, second_char_check);
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
    print_report(temp_names, names, temp_grades, grades, size);
}


/* Print a nice report and call other helper functions to get information */
void print_report(char temp_names[][50], char names[][50],  float temp_grades[], float grades[], int size)
{
    float average, median;

    printf("\n\n\n__________________________________________________\n");
    printf("\n\tSorted Test Results");
    printf("\n__________________________________________________\n");

    for (int i = 0; i < size; ++i)
    {
        printf("\nName: %s \tGrade: %3.2f\n", names[i], grades[i]);
    }
    // another sort to make it easier to find values
    temp_values(temp_names, names, temp_grades, grades, size);

    average = average_grade(temp_grades, size);
    median = median_grade(temp_grades, size);

    // use the temp_grades array to get data
    // fix median and average grades
    printf("\nAverage: %3.2f    Median: %3.2f    Highest: %3.2f    Lowest: %3.2f\n", average, median, temp_grades[size - 1], temp_grades[0]);
    printf("\nHighest Grade: %s \t\tLowest Grade: %s\n", temp_names[size-1], temp_names[0]);
}


/* Sort by grades and store in a temp. array. Easier to get data this way. */
    void temp_values(char temp_names[][50], char names[][50], float temp_grades[], float grades[], int size){
    float temp;
    char secondary_temp_names[50][50];

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            // rework the alg. to place names in correct locations
            if (temp_grades[j] > temp_grades[j + 1]) {
                temp = temp_grades[j];
                strcpy(secondary_temp_names[j], temp_names[j]);
                temp_grades[j] = temp_grades[j + 1];
                strcpy(temp_names[j], temp_names[j + 1]);
                temp_grades[j + 1] = temp;
                strcpy(temp_names[j + 1], secondary_temp_names[j]);
            }
        }
    }
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
