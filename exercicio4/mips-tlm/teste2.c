volatile int procCounter = 0;

volatile int *lock = (volatile int *) ADDRESS;

//volatile int *lockSum = (volatile int *) LOCK_SUM;

volatile int a = 0, b = 0;

int hist[26];
volatile int done = 0;
void AcquireLock() {
//      printf("LOCK %d\n", *lock);
        while (*lock);
//      printf("PASSEI\n");
}

void ReleaseLock() {
//      printf("RELEASING LOCK\n");
        *lock = 0;
//      printf("TESTE\n");

}

int main() {
        int procNumber;
        AcquireLock();
        procNumber = procCounter++;
        ReleaseLock();

        int vet[20];
        char *str = "abcdefgdfddfsdffdsfssfdsfasdaaqeqwa\0";
        int n = sizeof(str)/sizeof(char);
        int i,j,k;
        //for (i = 0; i < 20; i++) vet[i] = i;
        if (procNumber == 0) {
                for (i=0; i < n/2; i++) {
                        int num = str[i] - 'a';
                        AcquireLock();
                        hist[num]++;
                        ReleaseLock();
                }
                AcquireLock();
                done++;
                ReleaseLock();
        }


        else if (procNumber == 1) {
                for (i=n/2; i < n; i++) {
                        int num = str[i] - 'a';
                        AcquireLock();
                        hist[num]++;
                        ReleaseLock();
                }
                AcquireLock();
                done++;
                ReleaseLock();
        }

        while(done < 2);
        if


}