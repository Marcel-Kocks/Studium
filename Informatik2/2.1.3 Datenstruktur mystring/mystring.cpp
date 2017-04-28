#include "stdafx.h"
#include "mystring.h"

mystring * str_create()
{
	mystring* pmstr = (mystring*)malloc(sizeof(mystring));
	pmstr->str = (char*)malloc(sizeof(char));
	*(pmstr->str) = 0;
	return pmstr;
}

void str_destroy(mystring * s)
{
	free(s->str);
	free(s);
}

void str_set(mystring * s, char * buf)
{
	//s->str = strcpy(s->str, buf);
	s->str = (char*)malloc(strlen(buf) * sizeof(char));
	
	char * start = s->str;

	for (; *buf; buf++,start++) {
		*start = *buf;
	}
	*start = 0;
}

const char * str_get(mystring * s)
{
	return s->str;
}

void str_add(mystring * s, mystring * t)
{
	//s->str = strcat(s->str, t->str);
	char * nw = (char*)malloc(sizeof(char)*(strlen(s->str) + strlen(t->str)));
	
	char * startS = s->str, *startT = t->str, *startN = nw;

	for (; *startS; startS++,startN++) {
		*startN = *startS;
	}
	for (; *startT; startT++, startN++) {
		*startN = *startT;
	}
	*startN = 0;
	s->str = nw;
}

void str_insert(mystring * s, mystring * t, int pos)
{
	size_t srclen = strlen(t->str);
	size_t dstlen = strlen(s->str);
	char *m = (char*) malloc(srclen + dstlen + 1);

	memcpy(m, s->str, pos);
	memcpy(m + pos, t->str, srclen);
	memcpy(m + pos + srclen, s->str + pos, dstlen - pos + 1);

	s->str = m;
}

int str_length(mystring * s)
{
	return strlen(s->str);
}

int str_test(mystring * s, mystring * t)
{
	return (strstr(s->str, t->str) == NULL) ? 0 : 1;
}
