#include <fcntl.h>
    #include <sys/stat.h>
    #include <semaphore.h>
    #include <stdio.h>

    #define SEM "/my_named_semaphore"
    void log(FILE *f){
    fprintf(f, "Logging by process with id %d\n", getpid());
    }

    int main(int argc, char ** argv) {
    sem_t *sem;
m   FILE *f = fopen("text.txt", "a");
    if ( argc == 2 ) {
    printf("Dropping semaphore...\n");
    if ( (sem = sem_open(SEM, 0)) == SEM_FAILED ) {
   
    return 1;
    }
    sem_post(sem);
    
    printf("Semaphore dropped.\n");
    return 0;
    }

    if ( (sem = sem_open(SEM, O_CREAT, 0777, 0)) == SEM_FAILED ) {
    log(f);
    return 1;
    }

    printf("Semaphore is taken.\nWaiting for it to be dropped.\n");
    if (sem_wait(sem) < 0 )
 
    if ( sem_close(sem) < 0 )
  
    return 0;
    }

