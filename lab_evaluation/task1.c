#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    int student_id;
    char name [50];
    float marks ;
    char grade; 
}
Student; // structure 
void *calculate_grade(void *arg) //data converting void student .
{
    Student *s = (Student *)arg; 
    if (s->marks >= 85) s->grade = 'A';
    else if (s->marks >= 70) s->grade = 'B';
    else if (s->marks >= 60) s->grade = 'C';
    else if (s->marks >= 50) s->grade = 'D';
    else s->grade = 'F';
    printf("\nStudent:\n");
    printf("id: %d\n", s->student_id);
    printf("Name : %s\n", s->name);
    printf("Marks: %.2f\n", s->marks);
    printf("Grade: %c\n", s->grade);

    pthread_exit(NULL);
}
int main() { 
    pthread_t threads [3]; // thread array
    Student students[3] = {
        {1146,"Eman",89,'-'},
     {1142,"nimra",70,'-'},
      {1201,"ayema",40,'-'},
    };
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, calculate_grade, &students[i]);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
} 
