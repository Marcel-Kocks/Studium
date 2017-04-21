#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

#define Array_lengh (10000)

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int *begin, int *end)
{
	int *ptr;
	int *split;
	if (end - begin <= 1)
		return;
	ptr = begin;
	split = begin + 1;
	while (++ptr <= end) {
		if (*ptr < *begin) {
			swap(ptr, split);
			++split;
		}
	}
	swap(begin, split - 1);
	quicksort(begin, split - 1);
	quicksort(split, end);
}


void main() {

	FILE *pf;
	pf = fopen("random.txt", "w");

	if (!pf)
		return;

	for (int i = 0; i < Array_lengh; i++) {
		fprintf(pf, "%d\n", rand() % 1000);
	}

	fclose(pf);

	pf = fopen("random.txt", "r+");
	//int nums[Array_lengh];
	int* nums = malloc(sizeof(int)*Array_lengh);
	if (!nums) {
		//ERROR
		exit(99);
	}
	for (int i = 0; !feof(pf); i++) {
		fscanf(pf, "%d", &nums[i]);
	}

	quicksort(nums, nums + Array_lengh - 1);

	fclose(pf);

	pf = fopen("sorted.txt", "w");

	for (int i = 0; i < Array_lengh; i++) {
		fprintf(pf, "%d\n", nums[i]);
	}

	fclose(pf);
}