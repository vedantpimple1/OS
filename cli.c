#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>

struct data{
  char info[512];
  int flag;
};
int main()
{
  key_t key=ftok("abc.txt",'a');
  int id=shmget(key,512,0666| IPC_CREAT);
  struct data*s=shmat(id, NULL,0);

  while(s->flag!=0)
  {
    printf("Wiating...\n");
    sleep(2);
    
  }
  printf("Recieved is : \n");
  printf("%s",s->info);

shmdt(s);
shmctl(id, IPC_RMID,0);
system("ipcs -m");
}
