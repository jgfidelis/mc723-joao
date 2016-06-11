#include <stdio.h>
#include <malloc.h>

#define ADDRESS 0x6410000;
#define LOCK_SUM 0x6420000;

volatile int procCounter = 0;

volatile int *lock = (volatile int *) ADDRESS;

//volatile int *lockSum = (volatile int *) LOCK_SUM;

volatile int a = 0, b = 0;

volatile int *hista;
volatile int *histb;
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
	AcquireLock();
	procNumber = procCounter;
	procCounter++;	
	ReleaseLock();
		
	int vet[20];
	char *str = "abcdefgdfddfsdffdsfssfdsfasdaaqeqwa\0";
	int n = sizeof(str)/sizeof(char);
	int i,j,k;
	//for (i = 0; i < 20; i++) vet[i] = i;
	if (procNumber == 0) {
		hista = (volatile int *)malloc(sizeof(volatile int)*26);
		for (i = 0; i < 26; i++) hista[i] = 0;
		for (i=0; i < n/2; i++) {
			int num = str[i] - 'a';
			hista[num]++;
		}
	}
	
	
	else if (procNumber == 1) {
		AcquireLock();
		histb = (volatile int *)malloc(sizeof(volatile int)*26);
		for (i = 0; i < 26; i++) histb[i] = 0;
		for (i=n/2; i < n; i++) {
			int num = str[i] - 'a';
			histb[num]++;
		}
		ReleaseLock();
	}
	int histFinal[26];
	if (procNumber == 0) {
		
		AcquireLock();
		for (i = 0; i < 26; i++) {
			histFinal[i] = hista[i] + histb[i];
		}
		ReleaseLock();
	}
	
	if (procNumber == 0) {
	//	printf("SOMA %d\n", c);
		for (i =0; i < 26; i++)
			printf("%d ", histFinal[i]);
		printf("\n done\n");
		free(hista);
		free(histb);
	}
	return 0;
}
