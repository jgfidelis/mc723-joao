#include <stdio.h>
#include "calcPrimo.h"

main(int argc, char *argv[])
{
  //int n = 104395301;
  int n = atoi(argv[1]);
  //n = 100000;
  int primos =1;
  int i = 0;
  for (i = 3; i <= n; i++) {
	if (i%2 != 0)
		if (calc_primo(i))
			primos++;
	  
  }
  printf("Número de primos: %d\n", primos);
  return 0;
}	
