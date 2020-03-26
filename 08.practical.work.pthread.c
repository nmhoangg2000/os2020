#include <stdio.h>
#include <pthread.h>
int Primenum(int n, int i) {
    if (i == 1) 
	return 1;
    else
    {
        if (n % i == 0) 
	return 0;
        else
        {
            return Primenum(n, i-1);
        }
    }
}

void *prime() {
    int n = 2;
    printf("Print all prime numbers from 2 to 1.000.000: \n");
    while (n <= 1000000) {
        int check = n/2;
        if (Primenum(n, check) == 1) {
            printf ("%d ",n);
        } 
        n++;
    }
}



void *fibo() {
    int a = 1, b = 1, c = 0;
    printf("Print all numbers in Fibonacci sequence from 2 to 1.000.000: ");
    while (c <= 1000000) {
        c = a + b;
        a = b;
        b = c;
        printf ("%d \n",c);
    };    
}

int main() {
    int thread1, thread2;
    pthread_t tid1, tid2;
    thread1 = pthread_create(&tid1, NULL, prime, NULL);
    thread2 = pthread_create(&tid2, NULL, fibo, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
