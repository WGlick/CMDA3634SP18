#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "functions.h"

int main (int argc, char **argv) {

	//seed value for the randomizer 
  double seed = clock(); //this will make your program run differently everytime
  //double seed = 0; //uncomment this and your program will behave the same everytime it's run

  srand(seed);

  int bufferSize = 1024;
  unsigned char *message = (unsigned char *) malloc(bufferSize*sizeof(unsigned char));

  printf("Enter a message to encrypt: ");
  int stat = scanf (" %[^\n]%*c", message); //reads in a full line from terminal, including spaces

  //declare storage for an ElGamal cryptosytem
  unsigned int n, p, g, h,x;

  printf("Reading file.\n");

  /* Q2 Complete this function. Read in the public key data from public_key.txt,
    convert the string to elements of Z_p, encrypt them, and write the cyphertexts to 
    message.txt */
  FILE *file = fopen("public_key.txt","r");
  fscanf(file,"%u\n%u\n%u\n%u\n",&n,&p,&g,&h);
  fclose(file); 
    

  unsigned int charsPerInt = (n-1)/8;

  padString(message, charsPerInt);
  printf("Padded Message = \"%s\"\n", message);

  unsigned int Nchars = strlen(message);
  unsigned int Nints  = strlen(message)/charsPerInt;

  //storage for message as elements of Z_p
  unsigned int *Zmessage =
      (unsigned int *) malloc(Nints*sizeof(unsigned int));

  //storage for extra encryption coefficient 
  unsigned int *a =
      (unsigned int *) malloc(Nints*sizeof(unsigned int));

  // cast the string into an unsigned int array
  convertStringToZ(message, Nchars, Zmessage, Nints);

  //Encrypt the Zmessage with the ElGamal cyrptographic system
  ElGamalEncrypt(Zmessage,a,Nints,p,g,h);
  
  file = fopen("messages.txt","w");
  fprintf(file,"%u %u\n",Nchars, Nints);
  for (int i =0; i < Nints; i++) {
    fprintf(file,"%u %u\n",Zmessage[i], a[i]);
}
  fclose(file);
    
  return 0;
}
