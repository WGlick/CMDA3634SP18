#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//Since this function is essentially the same as my gcd function, I also do not expect it to have much hang as the numbers get larger as the number of calculations it needs to perform are relatively small.
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

if (answer == 1) {
printf("%d and %d are coprime.",b,a);
} 

else {
printf("%d and %d are not coprime.",b,a);
} 
}



