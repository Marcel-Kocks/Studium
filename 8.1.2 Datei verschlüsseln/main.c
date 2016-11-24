#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

void main() {
	FILE *fIn, *fOut;
	char* str = (char*)malloc(50 * sizeof(char));
	printf("Source-File: ");
	scanf("%s", str);
	while ((fIn = fopen(str, "rb+")) == 0)
	{
		printf("Datei existiert nicht!\n");
		printf("Source-Datei: ");
		scanf("%s", str);
	}

	printf("Dest-File: ");
	scanf("%s", str);
	fOut = fopen(str, "wb+");

	printf("Password: ");
	scanf("%s", str);

	char* pw = str;

	while (!feof(fIn))
	{
		char c = fgetc(fIn);
		c = c^*str;
		str++;
		if (*str == 0)
			str = pw;

		fprintf(fOut, "%c", c);
	}

	fclose(fOut);
	fclose(fIn);
}