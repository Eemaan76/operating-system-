#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Structure to store student information
typedef struct
{
    int student_id;
    char name[50];
    float gpa;
} Student;

// Thread function to check Dean's list eligibility
void *check_student(void *arg)
{
    Student *s = (Student *)arg; // Convert void* to Student*
    printf("\nStudent ID: %d\n", s->student_id);
    printf("Name: %s\n", s->name);
    printf("GPA: %.2f\n", s->gpa);

    int *is_deans_list = malloc(sizeof(int)); // Allocate memory for result
    if (s->gpa >= 3.2)
    {
        printf("Status: In Dean's List \n");
        *is_deans_list = 1; // eligible
    }
    else
    {
        printf("Status: Not eligible for Dean's List \n");
        *is_deans_list = 0; // not eligible
    }

    pthread_exit(is_deans_list); // Return result
}

int main()
{
    pthread_t threads[3]; // Thread array
    Student students[3] = {
        {1146, "eman", 3.2},
        {1201, "nimra", 3.1},
        {1127, "ali", 2.6}};

    int *result;
    int total_deans = 0;

    // Create one thread per student
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, check_student, &students[i]);
    }

    // Join all threads and collect results
    for (int i = 0; i < 3; i++)
    {
        pthread_join(threads[i], (void **)&result);
        total_deans += *result;
        free(result); // Free memory allocated in thread
    }

    printf("\nTotal students on Dean's List: %d\n", total_deans);
    printf("Main thread: Work completed.\n");
    return 0;
}
