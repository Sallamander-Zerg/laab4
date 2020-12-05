 #include <fcntl.h>
    #include <sys/stat.h>
    #include <semaphore.h>
    #include <stdio.h>

    #define SEM "/my_named_semaphore"
    #define SEM1 "/my_named_semaphore"
    void logging(){
    FILE *f=fopen("text.txt","a");
    fprintf(f, "Logging by process with id %d\n", getpid());
    fclose(f);
    }

    int main(int argc, char ** argv) {
    sem_t *sem;
    sem_t *sem1;
    
    if ( (sem = sem_open(SEM1, O_CREAT, 0777, 1)) == SEM_FAILED ) {
    logging(f);
    return 1;
    }
    if ( (sem = sem_open(SEM, O_CREAT, 0777, 0)) == SEM_FAILED ) {
    logging(f);
    return 1;
    }
	int pid=fork();
    if(!pid){
    sem_wait(sem);
    logging(f);
    sem_post(sem1);    
    }else{
    sem_wait(sem1);
   logging(f);
    sem_post(sem);	
    }
  sem_unlink(SEM1);
  sem_unlink(SEM);
    return 0;
    }
