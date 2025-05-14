#include <stdio.h>

int main(){
	long long int result=0,i;
	for(i=0;i<2000000000;i++){
		result+=(i*2)/3 + (i%7);
	}
	printf("result: %lld\n",result);
	return 0;
}
