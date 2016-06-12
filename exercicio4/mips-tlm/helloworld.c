#include <stdio.h>
#include <string.h>
#define ADDRESS 0x6410000;

volatile int procCounter = 0;

#define THREAD_NUM 2
#define SIZE 26
volatile int *lock = (volatile int *) ADDRESS;

int hista[SIZE];
int histb[SIZE];
volatile int done=0;
void AcquireLock() {
	while (*lock);
}

void ReleaseLock() {
	*lock = 0;
}

void g() {
	int procNumber;
	AcquireLock();
	procNumber = procCounter++;
	ReleaseLock();
	//input
	char *str = "noqncjueyuirytcnbcnbvbbvaasoaospasskaposkderyuwetuygbcbchjbvhvgegwgccyvwytynbcvpqwiufyqamxbchkz\0";
	//input size
	int n = strlen(str);
	int i;
	//first core will process the first half of the string
	if (procNumber == 0) {
		for (i=n*procNumber/THREAD_NUM; i < n*(procNumber+1)/THREAD_NUM; i++) {
			int num = str[i] - 'a';
			hista[num]++;
		}
	AcquireLock();
	done++;
	ReleaseLock();
	}

	//second core will process the second half of the string
	else if (procNumber == 1) {
		for (i=n*procNumber/THREAD_NUM; i < n; i++) {
			int num = str[i] - 'a';
			histb[num]++;
		}
		AcquireLock();
		done++;
		ReleaseLock();
	}
	//after both are done, the first core will merge the two partial histograms and display the output
	if (procNumber == 0) {
		int hist[SIZE];
		while(done < THREAD_NUM);
		for(i = 0; i < SIZE; i++) hist[i] = hista[i]+histb[i];
		for (i = 0; i < SIZE; i++) {
			printf("%d ", hist[i]);
		}
		printf("\ndone!\n");
	}

}

int main() {

	g();

	return 0;
}
