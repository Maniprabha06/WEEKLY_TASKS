#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
	long type;
	char text[100];
};

int main() {
	int msgid=msgget(1234,0666 | IPC_CREAT);
	struct msg m={1,"Helloo Prabhaa!!!"};
	msgsnd(msgid,&m,sizeof(m.text),0);
	printf("Sent Message : %s\n",m.text);
	return 0;
}
