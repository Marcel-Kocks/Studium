#include<stdio.h>
#include"str.h"

void main() {
	printf("%d\n", atoi("0012345002"));

	printf("%d\n", strcmp("Hallo", "Halo"));

	printf("%s\n", strcat("Hallo", "123"));

	printf("%s\n", strstr("HalloPeter", "lo"));
}