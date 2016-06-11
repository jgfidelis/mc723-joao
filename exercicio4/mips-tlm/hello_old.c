#include <stdio.h>

#define ADDRESS 0x6410000;

volatile int procCounter = 0;

volatile int *lock = (volatile int *) ADDRESS;

int main() {
	
	printf("Hello World\n");
	
	printf("Lendo: %d\n", *lock);

	*lock = 10;

	printf("Lendo: %d\n", *lock);

	*lock =0;
		
	printf("Lendo: %d\n", *lock);
	return 0;
}
