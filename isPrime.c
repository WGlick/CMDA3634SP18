#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//I think as the number inputted becomes larger, this program will start to experience serious hang. The reason for this is because this code is very inefficient. It stores all the values that are less than the entered number, and also loops through several lists. 

void main() {

  int N;

  printf("Enter a number:");
  scanf("%d",&N);

  // make storage for flags
  int *isPrime = (int*) malloc((N+1)*sizeof(int));

  //initialize, i.e. set everything 'true'
  for (int n=0;n<=N;n++) isPrime[n] = 1; 

  int sqrtN = (int) sqrt(N);

  for (int i=2;i<=sqrtN;i++) {
    if (isPrime[i]) { //if i is prime
      for (int j=i*i;j<=N;j+=i) {
        isPrime[j] = 0;//set j not prime
      }
    }
  }

  // count the number of primes we found 
  int cnt =0;
  for (int n=0;n<=N;n++) {
    if (isPrime[n]) {
      cnt++;
    }
  } 

  //make a list of them
  int *primes = (int*) malloc(cnt*sizeof(int));

  //loop once more and build the list
  cnt =0;
  for (int n=0;n<=N;n++) {
    if (isPrime[n]) {
      primes[cnt++] = n;
    }
  } 



 int prime = 0;
  for (int n=0;n<cnt;n++) {
 	if(primes[n] == N) {
		prime = 1;	
}

}

if (prime) {
		printf("%d is prime",N);
}
else {
printf("%d is not prime",N);
}


}
