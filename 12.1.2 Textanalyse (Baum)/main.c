#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define TopListCount 25

struct list_entry {
	struct list_entry* next;
	char* name;
	unsigned int count;
};

struct tree_node {
	struct tree_node* right;
	struct tree_node* left;
	unsigned int count;
	char* name;
};

void createNewNode(struct tree_node** ppNode, char* name) {
	struct tree_node* neu = (struct tree_node*) malloc(sizeof(struct tree_node));
	neu->count = 1;
	neu->left = 0;
	neu->right = 0;
	neu->name = name;
	*ppNode = neu;
}

int tree_increment(struct tree_node* pNode, char* name) {
	if (!pNode) {
		return 0;
	}
	if (strcmp(name, pNode->name) == 0) {
		pNode->count++;
		return 1;
	}
	if (strcmp(name, pNode->name) > 0) {
		if (tree_increment(pNode->right, name)) {
			return 1;
		}
		else {
			createNewNode(&(pNode->right), name);
			return 1;
		}
	}
	if (strcmp(name, pNode->name) < 0) {
		if (tree_increment(pNode->left, name)) {
			return 1;
		}
		else {
			createNewNode(&(pNode->left), name);
			return 1;
		}
	}
}

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

void ausgabe(struct tree_node* pNode) {
	if (pNode) {
		ausgabe(pNode->left);
		printf("%s   %d\n", pNode->name, pNode->count);
		ausgabe(pNode->right);
	}
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

void top10(struct tree_node *pNode, struct tree_node *erg) {
	if (pNode) {
		top10(pNode->left, erg);
		if (pNode->count > erg[0].count) {
			int i, a;
			for (i = 0; i < TopListCount && pNode->count >= erg[i].count; i++)
				;
			i--;
			for (a = 0; a < i; a++) {
				erg[a] = erg[a + 1];
			}
			erg[i] = *pNode;
		}
		top10(pNode->right, erg);
	}
}

void main() {
	FILE* pFile = fopen("Buddenbrocks.txt", "r");
	struct tree_node* node = 0;
	createNewNode(&node, "marcel");
	node->count = 0;

	while (!feof(pFile)) {
		char* in = (char*)malloc(100 * sizeof(char));
		fscanf(pFile, "%s", in);
		char *p = in;
		for (; *p; ++p) *p = tolower(*p);
		remove_special_chars(in);
		if (*in == '\0')
			continue;
		tree_increment(node, in);
	}
	//ausgabe(node);
	struct tree_node erg[TopListCount];
	for (int i = 0; i < TopListCount; i++) {
		erg[i] = *node;
	}
	top10(node, erg);
	printf("\n\n\nTop%d\n\n\n", TopListCount);
	for (int i = TopListCount - 1; i >= 0; i--) {
		printf("%3d.%s  %d\n", TopListCount - i, erg[i].name, erg[i].count);
	}
	system("pause");
}