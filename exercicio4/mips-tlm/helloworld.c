#include <stdio.h>

#define ADDRESS 0x6410000;
#define LOCK_SUM 0x6420000;

volatile int procCounter = 0;

volatile int *lock = (volatile int *) ADDRESS;

//volatile int *lockSum = (volatile int *) LOCK_SUM;

volatile int a = 0, b = 0;

void AcquireLock() {
//	printf("LOCK %d\n", *lock);
	while (*lock);
//	printf("PASSEI\n");
}

void ReleaseLock() {
//	printf("RELEASING LOCK\n");
	*lock = 0;
//	printf("TESTE\n");

}

int main() {
	int procNumber;
//	printf("getting lock\n");
	AcquireLock();
//	printf("got lock\n");
	procNumber = procCounter;
	procCounter++;
	//printf("Core %d releasing lock...\n", procNumber+1);
	ReleaseLock();
	int N = 200;
	int vet[N];
	int i;
	for (i = 0; i < N; i++) vet[i] = i;

	if (procNumber == 0) {
		for (i = 0; i < N/2; i++) {
			a += vet[i];
		}
	}


	else if (procNumber == 1) {
		AcquireLock();
		for (i = N/2; i < N; i++){
			b += vet[i];
		}
		ReleaseLock();
	}
	int c;
	if (procNumber == 0) {
		AcquireLock();
		c = a + b;
		ReleaseLock();
	}
	if (procNumber == 0)
		printf("SOMA %d\n", c);
	return 0;
}
