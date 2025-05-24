#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd = open("mypipe", O_WRONLY);
	if(fd==-1) {
		perror("open for writing");
		return 1;
	}

	char msg[] = "Hello from sender!";
	write(fd,msg,strlen(msg)+1);
	close(fd);
	return 0;
}
