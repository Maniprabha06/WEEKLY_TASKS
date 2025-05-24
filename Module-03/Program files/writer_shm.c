#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	int shmid = shmget(1234, sizeof(int),0666 | IPC_CREAT);
	int *data = (int *)shmat(shmid,NULL,0);

	(*data)++;
	printf("writer value : %d/n",*data);
	shmdt(data);
	return 0;
}
