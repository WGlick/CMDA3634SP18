#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//I do not expect this function to have much hang as the numbers become larger as the amount of calculations done are really very small, regardless of the number itself.
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
scanf("%d",&a);
printf("Enter the second number:");
scanf("%d",&b);

int answer = gcd(b,a);
int lcm = (b * a) / (answer);


printf("The least common multiple of %d and %d is %d\n",a,b,lcm);


}
