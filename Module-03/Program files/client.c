#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
	int sock=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in server = {
		.sin_family=AF_INET,
		.sin_port=htons(8080),
		.sin_addr.s_addr=inet_addr("127.0.0.1")
	};

	connect(sock, (void *)&server,sizeof(server));
	send(sock, "Hi from client!",16,0);
	char buffer[100];
	read(sock,buffer,sizeof(buffer));
	printf("Server : %s\n",buffer);
	close(sock);
	return 0;
}
