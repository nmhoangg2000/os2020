#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;
//int sem_wait(sem_t *sem);
//int sem_post(sem_t *sem);
//int sem_destroy(sem_t *sem);
//int sem_init(sem_t *sem, int pshared, unsigned int value);

void *Primenum(void *value)
{
  int i,n,j;
  for(i=1; i<=1000; i++)
  {
    n=0;
    for(j=1; j<=1000; j++)
    {
      if(i%j==0) n++;
    }
      if(n==2)
      {
        sem_wait(&s);
        printf("(%d) " ,i);
        sem_post(&s);
      }
  }
}

void *fibo(void *value)
{

  int a = 0, b = 1, c = 0;
  printf("%d ", a);
  printf("%d ", b);
  c = a + b;
  while (c <= 1000)
  {
    sem_wait(&s);
    printf("%d ", c);
    sem_post(&s);
    a = b;
    b = c;
    c = a + b;
  }

}


int main(void)
{
  sem_init(&s, 0, 1);
  printf("prim_num\nfibo_num\n");
  pthread_t tid_1, tid_2;
  pthread_create(&tid_1, NULL, Primenum, NULL);
  pthread_create(&tid_2, NULL, fibo, NULL);
  pthread_join(tid_1, NULL);
  pthread_join(tid_2, NULL);
  sem_destroy(&s);
  printf("\n");
  return 0;
}
