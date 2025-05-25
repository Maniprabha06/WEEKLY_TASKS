#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
	long type;
	char text[100];
};

int main() {
	int msgid=msgget(1234,0666);
	struct msg m;
	msgrcv(msgid,&m,sizeof(m.text),1,0);
	printf("Received Message: %s\n",m.text);
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
