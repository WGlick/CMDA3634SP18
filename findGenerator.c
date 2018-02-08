#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//I would expect this program to lag or to stop working entirely because we need to compile an entire list, run lots of exponential operations, and do modulo operations at every step.
int int_pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

void main() {

int N;
printf("Enter a prime number:");
scanf("%d",&N);
int *list = (int*) malloc((N)*sizeof(int));
int gen = 0;
for(int g=1;g<N;g++) {
  int generator = 1;
  for(int x=1;x<N;x++) {
    int temp = int_pow(g,x);
    int entry = (int) temp % (int) N;

    list[x] = entry;
}
  for(int i=1;i<N;i++) {
    for(int j =1;j<N;j++) {
      if(j != i) {
	if(list[i] == list[j]) {
	  generator = 0;
}		
}
}
}
  if(generator == 1) {
    gen = g;
    break;
}
}

printf("%d is a generator of Z_%d",gen,N);

}
