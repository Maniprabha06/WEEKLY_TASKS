#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char buffer[100];
	int fd = open("mypipe", O_RDONLY);
	if (fd==-1){
		perror("open for reading");
		return 1;
	}

	read(fd,buffer,sizeof(buffer));
	printf("Reader Received: %s\n",buffer);
	close(fd);
	return 0;
}
