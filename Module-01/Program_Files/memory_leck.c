#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	int *ptr=(int*) malloc(5 * sizeof(int));
	if(ptr==NULL){
		printf("Memory allocation failed\n");
		return 1;
	}
	for(int i=0;i<5;i++){
		ptr[i]=i*10;
	}
	for(int i=0;i<5;i++){
		printf("Value: %d\n",ptr[i]);
	}
	printf("Sleeping for 55 seconds");
	sleep(55);
	return 0;
}
