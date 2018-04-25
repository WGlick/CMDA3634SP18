#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "cuda.h"
#include "functions.c"


int main (int argc, char **argv) {

  /* Part 2. Start this program by first copying the contents of the main function from 
     your completed decrypt.c main function. */

  /* Q4 Make the search for the secret key parallel on the GPU using CUDA. */

  //declare storage for an ElGamal cryptosytem
  unsigned int n, p, g, h, x;
  unsigned int Nints;

  //get the secret key from the user
  printf("Enter the secret key (0 if unknown): "); fflush(stdout);
  char stat = scanf("%u",&x);

  printf("Reading file.\n");

  /* Q3 Complete this function. Read in the public key data from public_key.txt
    and the cyphertexts from messages.txt. */
  FILE *file = fopen("public_key.txt","r");
  fscanf(file,"%u\n%u\n%u\n%u\n",&n,&p,&g,&h);
  fclose(file);

  // find the secret key
  if (x==0 || modExp(g,x,p)!=h) {
    printf("Finding the secret key...\n");
    double startTime = clock();
    for (unsigned int i=0;i<p-1;i++) {
      if (modExp(g,i+1,p)==h) {
        printf("Secret key found! x = %u \n", i+1);
        x=i+1;
      } 
    }
    double endTime = clock();

    double totalTime = (endTime-startTime)/CLOCKS_PER_SEC;
    double work = (double) p;
    double throughput = work/totalTime;

    printf("Searching all keys took %g seconds, throughput was %g values tested per second.\n", totalTime, throughput);
  }

  /* Q3 After finding the secret key, decrypt the message */

  unsigned int Nchars;


  FILE *file2 = fopen("messages.txt","r");
  fscanf(file2,"%u %u\n",&Nchars,&Nints);
  unsigned int *Zmessage = (unsigned int *) malloc(Nints * sizeof(unsigned int)); 
  unsigned int *a = (unsigned int *) malloc(Nints*sizeof(unsigned int));
  unsigned char *message = (unsigned char *) malloc(Nints*sizeof(unsigned char));
    for (int i =0; i < Nints; i++) {
      fscanf(file2,"%u %u\n",&Zmessage[i], &a[i]);
  }
  fclose(file2);

  ElGamalDecrypt(Zmessage,a,Nints,p,x);

  convertZToString(Zmessage, Nints, message, Nchars);
  printf("%s \n",message);

  return 0;
}
