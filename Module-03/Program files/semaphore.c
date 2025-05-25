
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/wait.h>

void sem_wait(int semid){
	struct sembuf sb={0,-1,1};
	semop(semid,&sb,1);
}

void sem_signal(int semid){
	struct sembuf sb={0,1,1};
	semop(semid,&sb,1);
}
int main() {
	key_t key=1234;
	int semid=semget(key,1,0666 | IPC_CREAT);
	semctl(semid,0,SETVAL,1);
	pid_t pid=fork();
	for(int i=0;i<2;i++){
		if(pid == 0 && i==1)continue;
		if(pid > 0 && i==0)continue;

		sem_wait(semid);
		printf("process %d is accessing the file...\n",getpid());
		sleep(2);
		printf("process %d done\n",getpid());
		sem_signal(semid);
	}
	if(pid > 0){
		wait(NULL);
		semctl(semid,0,IPC_RMID);
	}
	return 0;
}
