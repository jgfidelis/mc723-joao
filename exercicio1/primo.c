#include <stdio.h>
#include <omp.h>
int primo(int n)
{
  int i;

  for(i = 2; i < n; i ++)
    if (n % i == 0)
      return 0;
  
  return 1;
}

main(int argc, char *argv[])
{
  //int n = 104395301;
  int n = atoi(argv[1]);
  //n = 100000;
  int primos =1;
  int i = 0;
  #pragma omp parallel for
  for (i = 3; i <= n; i++) {
	if (i%2 != 0)
		if (primo(i))
			#pragma omp atomic
			primos++;
	  
  }
  printf("Número de primos: %d\n", primos);
  return 0;
}	
	
