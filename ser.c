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
  s->flag=1;
  printf("Enter data\n");
 
  fgets(s->info,512,stdin);
  s->flag=0;
  

shmdt(s);
system("ipcs -m");
}
