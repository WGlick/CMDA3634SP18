#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//I think this function will actually be ok when the numbers become larger because the modulo operation will significantly cut down the number of computations necessary, and each run of the program does not perform that many operations aside from checking the relationship between the numbers and performing on % command.
int gcd(int a, int b) {
int status;

if (a == b) {
status = 1;

}

if (b==0) {
status = a;

}
else {

if (a % b == 0) {
status = b;
}
else {
int rem=a % b;
status = gcd(b,rem);
}
}
return status;
}

void main() {
int b;
int a;
printf("Enter the first number:");
scanf("%d",&b);
printf("Enter the second number:");
scanf("%d",&a);
int answer=gcd(a,b);

printf("The greatest common denominator of %d and %d is %d.",b,a,answer); 
}


