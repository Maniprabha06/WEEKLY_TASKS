#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid =fork();
	if(pid==0){
		for(int i=0;i<5;i++){
			printf("child (PID %d): %d\n",getpid(), i);
			sleep(1);
		}
	}
	else{
		for(int i=0;i<5;i++){
			printf("Parent (PID %d): %d\n",getpid(),i);
			sleep(1);
		}
	}
	return 0;
}
