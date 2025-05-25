#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
	int server_fd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server={
		.sin_family=AF_INET,
		.sin_port=htons(8080),
		.sin_addr.s_addr = INADDR_ANY
	};

	bind(server_fd, (void *)&server, sizeof(server));
	listen(server_fd,1);

	int client_fd=accept(server_fd,NULL,NULL);
	char buffer[100];
	read(client_fd,buffer,sizeof(buffer));
	printf("Client: %s\n",buffer);
	send(client_fd, "Hi from server!",16,0);
	close(client_fd);
	close(server_fd);
	return 0;
}
