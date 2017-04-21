#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define TopListCount 20

struct list_entry {
	struct list_entry* next;
	char* name;
	unsigned int count;
};

int list_increment(struct list_entry* pList, char* name) {
	for (; pList; pList = pList->next) {
		if (!strcmp(name, pList->name)) {
			pList->count++;
			return 1;
		}
	}
	return 0;
}

struct list_entry* list_add(struct list_entry* pList, char* name) {
	struct list_entry* neu = (struct list_entry*) malloc(sizeof(struct list_entry));
	neu->name = name;
	neu->count = 1;
	neu->next = pList;
	return neu;
}

void ausgabe(struct list_entry* pList) {
	for (; pList; pList = pList->next) {
		printf("%s   %d\n", pList->name, pList->count);
	}
	printf("\n\n");
}
void swap(struct list_entry *a, struct list_entry *b)
{
	struct list_entry tmp = *a;
	*a = *b;
	*b = tmp;
}

void remove_special_chars(char *c) {
	char *out = c;
	while (*c != '\0') {
		if (*c >= 'a' && *c <= 'z') {
			*out++ = tolower(*c);
		}
		c++;
	}
	*out = '\0';
}

struct list_entry* top10(struct list_entry *pList, struct list_entry *erg) {
	for (int i = 0; i < TopListCount; i++) {
		erg[i] = *pList;
	}
	for (; pList; pList = pList->next) {
		if (pList->count > erg[0].count) {
			int i, a;
			for (i = 0; i < TopListCount && pList->count >= erg[i].count; i++)
				;
			i--;
			for (a = 0; a < i; a++) {
				erg[a] = erg[a + 1];
			}
			erg[i] = *pList;
		}
	}
	return erg;
}

void main() {
	FILE* pFile = fopen("Buddenbrocks.txt", "r");
	struct list_entry* list = 0;

	while (!feof(pFile)) {
		char* in = (char*)malloc(100 * sizeof(char));
		fscanf(pFile, "%s", in);
		char *p = in;
		for (; *p; ++p) *p = tolower(*p);
		remove_special_chars(in);
		if (*in == '\0')
			continue;
		if (!list_increment(list, in)) {
			list = list_add(list, in);
		}
	}
	ausgabe(list);
	struct list_entry erg[TopListCount];
	top10(list, erg);
	printf("\n\n\nTop%d\n\n\n", TopListCount);
	for (int i = TopListCount - 1; i >= 0; i--) {
		printf("%3d.%s  %d\n", TopListCount - i, erg[i].name, erg[i].count);
	}
	system("pause");
}