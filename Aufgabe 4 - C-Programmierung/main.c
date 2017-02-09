#include<stdlib.h>
#include<stdio.h>

float absolute(float in) {
	return (in >= 0) ? in : -in;
}

void main() {
	printf("%f\n", absolute(-55.0));
}