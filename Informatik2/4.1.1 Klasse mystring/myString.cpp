#include "stdafx.h"
#include "myString.h"

myString::myString()
{
	data = (char*)malloc(sizeof(char));
	*data = 0;
	length = 0;
}

myString::myString(char * t)
{
	length = strlen(t);
	data = (char*)malloc((length + 1) * sizeof(char));
	strcpy(data, t);
}


myString::~myString()
{
	printf("MyString Destruktor: %d %s\n",(int)data,data);
	free(data);
}

myString::myString(const myString & s)
{
	//myString(s.data);
	data = (char*)malloc((s.length+1)*sizeof(char));
	strcpy(data, s.data);
	length = s.length;
}

myString & myString::operator=(const myString & s)
{
	//return myString(s.data);
	data = (char*)realloc(data, (s.length + 1) * sizeof(char));
	strcpy(data, s.data);
	length = s.length;
	return *this;
}

myString & myString::operator=(const char * s)
{
	length = strlen(s);
	data = (char*)realloc(data, (length + 1) * sizeof(char));
	strcpy(data, s);
	return *this;
}

myString myString::operator+(const myString & s) 
{
	myString out = *this;
	out += s;

	return out;
}

myString & myString::operator+=(const myString & rhs)
{
	length += rhs.length;
	data = (char*)realloc(data, (length + 1) * sizeof(char));
	strcat(data, rhs.data);
	return *this;
}

bool myString::operator==(const myString & rhs)
{
	return (strcmp(data, rhs.data)==0)?true:false;
}

bool myString::operator<(const myString & rhs)
{
	return (strcmp(data,rhs.data)<0)?true:false;
}

bool myString::operator>(const myString & rhs)
{
	return (strcmp(data, rhs.data)>0) ? true : false;
}

bool myString::operator<=(const myString & rhs)
{
	return operator<(rhs)||operator==(rhs);
}

bool myString::operator>=(const myString & rhs)
{
	return operator>(rhs) || operator==(rhs);
}

ostream & operator<<(ostream & os, const myString & s)
{
	os << s.data;
	return os;
}
