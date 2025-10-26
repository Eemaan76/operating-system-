#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *greeting(void *arg)
{
    char *name = (char *)arg; // argument ko string change krna
    printf("Thread says: Hello, %s! Welcome to the world of threads.\n", name);
    return NULL;
}

int main()
{
    pthread_t thread; // pthread_t thread; : ek thread variable declare karta hai jisme thread id store hogi
    char name[50];    // user ka naam store karne ke liye

    printf("Enter your name: ");
    scanf("%s", name); // user ka naam read karta hai aur name variable mein store karta hai

    pthread_create(&thread, NULL, greeting, (void *)name);
    printf("Main thread: Waiting for greeting...\n"); // thread create karta hai jo greeting function ko call karega

    pthread_join(thread, NULL);
    printf("Main thread: Greeting completed.\n"); // wait karta hai jab tak greeting thread complete nahi hota

    return 0;
}
