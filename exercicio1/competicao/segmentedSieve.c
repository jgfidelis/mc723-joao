#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>

void changeBit(char* vec, int n) {
    vec[n/8] ^= (-1 ^ vec[n/8]) & (1 << n%8);
}

int getBit(char *vec, int n) {
    return (vec[n/8] >> n%8) & 1;
}

main(int argc, char *argv[])
{
  //int n = 104395301;
  int n = atoi(argv[1]);
  //n = 100000;
  int primos =0;

  int maxValue = n*(log(n) + log(log(n)));

  int maxSqr = sqrt(maxValue);

  char *vetor = (char *)calloc(maxValue/8, sizeof (char));

  int i, p;
  //changeBit(vetor, 1);//marcar o número dois como primo
  //printf("Maxvalue: %d e maxsqr:%d\n", maxValue, maxSqr);
  for (i=2; i <= maxSqr; i++){
    if (getBit(vetor, i-1) == 0) {
        primos++;
        for (p = i; p<=maxValue; p+=i){
            changeBit(vetor, p-1);
        }
    }
  }

  for (i=maxSqr+1; i <= maxValue; i++) {
    if (getBit(vetor, i-1) == 0){
        primos++;
        //printf("Achado primo: %i e primos: %d\n", i, primos);
        if (primos == n){
            printf("Achei o n-ésimo: %d\n", i);
            return 0;
        }
    }

  }

  // char *vetor = (char *)calloc(100, sizeof(char));
  // //printf("EITA\n");
  // changeBit(vetor, 7);
  // //changeBit(vetor, 0);
  // printf("Got: %d\n", getBit(vetor, 7));
  // printf("Got: %d\n", getBit(vetor, 8));
  // int teste = vetor[0] & 0xFF;
  // printf("Teste: %d\n", teste);
  free(vetor);
    

    return 0;
}