#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *work(void *arg)
{
    int num = *(int *)arg; // int num = *(int*)arg; : argument ko integer mein convert karta hai.
    // arg thread ko diya gya argument

    printf("Thread %d started. ID = %lu\n", num, pthread_self()); // pthread_self() : current thread ka unique ID print karta hai.

    int t = (rand() % 3) + 1; // random 1-3 seconds
    sleep(t);

    printf("Thread %d finished after %d seconds.\n", num, t);
    return NULL;
}

int main()
{
    pthread_t threads[5];
    int nums[5];
    srand(time(NULL)); // srand(time(NULL)) : random numbers ko alag alag banane ke liye.

    for (int i = 0; i < 5; i++)
    {
        nums[i] = i + 1;
        pthread_create(&threads[i], NULL, work, &nums[i]); // lop chly gi har thread ko ik unique no mily ga
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }
    // pthread_join() : main thread wait karega jab tak har thread khatam nahi hota.
    printf("All threads done!\n");
    return 0;
}
