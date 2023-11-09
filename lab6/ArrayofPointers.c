/*
Name: John Currie
Date: 10/8/2023
Course: CSI2107
HW#: Lab 05: ““Arrays of Pointers to Functions”
Objective: To design and implement array of function pointer.
The purpose of this program is to modify existing code related to examslecting
grades for individual students in a 2D matrix and determining the minimum, maximum,
and each average.
// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.
*/
#include <stdio.h>
#include <stdlib.h>
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);
int main()
{
    int grades[3][4] = {{77, 68, 86, 73}, {96, 87, 89, 78}, {70, 90, 86, 81}};
    void (*processGrades[4])(int, int, int[3][4]) = {printArray, minimum, maximum, average};
    unsigned int choice = 0;
    while(choice != 4){
        printf("%s", "Enter a choice:\n0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n3 Print the average on all tests for each student\n4 End program\n");
        scanf("%u", &choice);
        if(choice >= 0 && choice <= 3){
            (*processGrades[choice])(3, 4, grades);
        }else if(choice != 4){
            printf("%s", "Invalid choice\n");
        }
    }
}
// takes a 2D array of grades, and integers of students and exams as an argument and prints the array
void printArray(int students, int exams, int grades[students][exams]){
    printf("%s", "                 [0]  [1]  [2]  [3]\n");
    for(int i = 0; i < students; i++){
        printf("Student Grades[%d] ", i);
        for(int j = 0; j < exams; j++){
            printf("%-5d", grades[i][j]);
        }
        puts("");
    }
    puts("");
}
// takes a 2D array of grades, and integers of students and exams as an argument and prints the minimum grade of all students
void minimum(int students, int exams, int grades[students][exams]){
    int min = grades[0][0];
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            if(grades[i][j] < min){
                min = grades[i][j];
            }
        }
    }
    printf("Minimum grade: %d\n\n", min);
}
// takes a 2D array of grades, and integers of students and exams as an argument and prints the maximum grade of all students
void maximum(int students, int exams, int grades[students][exams]){
    int max = grades[0][0];
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            if(grades[i][j] > max){
                max = grades[i][j];
            }
        }
    }
    printf("Maximum grade: %d\n\n", max);
}
// takes a 2D array of grades, and integers of students and exams as an argument and prints the average grade for each student
void average(int students, int exams, int grades[students][exams]){
    int sum = 0;
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            sum += grades[i][j];
        }
        printf("The average grade for student %d is %.2f\n", i+1, (float)sum/exams);
        sum = 0;
    }
    puts("");
}
