#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *factorial(void *arg)
{
    int n = *((int *)arg);
    long long *result = malloc(sizeof(long long)); // result store karne ke liye dynamic memory allocate karta hai.
    *result = 1;                                   // factorial vlaue 1 start karta hai

    for (int i = 1; i <= n; i++)
    {
        *result *= i;
    } // loop ke through factorial calculate karta hai

    pthread_exit((void *)result);
}

int main()
{
    pthread_t thread;
    int num;
    long long *fact_result; // for result

    printf("Enter a number: ");
    scanf("%d", &num);

    pthread_create(&thread, NULL, factorial, &num);
    pthread_join(thread, (void **)&fact_result);

    printf("Factorial of %d is: %lld\n", num, *fact_result); //%lld: long long integer ke liye format specifier.
    free(fact_result);                                       // free space

    printf("Main thread: Work completed.\n");
    return 0;
}
