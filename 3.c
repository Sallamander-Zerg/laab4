#include <pthread.h>
#include <stdio.h>

int count; 
int atoi(const char *nptr);
void *potok(void *param); 

int main(int argc, char *argv[])
{
  pthread_t tid; 
  pthread_attr_t attr; 

if (argc != 2) {
  fprintf(stderr,"usage: progtest <integer value>\n");
  return -1;
}

if (atoi(argv[1]) < 0) {
  fprintf(stderr,"Аргумент %d не может быть отрицательным числом\n",atoi(argv[1]));
  return -1;
}


  pthread_attr_init(&attr);


  pthread_create(&tid,&attr,potok,argv[1]);


  pthread_join(tid,NULL);
  printf("count = %d\n",count);
}


void *potok(void *param) 
{
  int i, upper = atoi(param);
  count = 0;

  if (upper > 0) {
    for (i = 1; i <= upper; i++)
    count += i;
  }

  pthread_exit(0);
}
