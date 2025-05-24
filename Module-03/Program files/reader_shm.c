#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	int shmid=shmget(1234,sizeof(int),0666);
	int *data=(int *)shmat(shmid,NULL,0);
	printf("Reader value : %d\n", *data);
	shmdt(data);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
