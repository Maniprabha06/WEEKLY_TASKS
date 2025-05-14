#include <unistd.h>
#include <string.h>

int main() {
	const char *text="Pre-Onboard Learning Module-01\n";
	write(1,text, strlen(text));
	return 0;
}
