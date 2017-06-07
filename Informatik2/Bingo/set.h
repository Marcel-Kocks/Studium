#pragma once
#include <ostream>

class set
{
	friend set& operator+=(set& s1, const set& s2);
	friend set& operator-=(set& s1, const set& s2);
	friend set& operator*=(set& s1, const set& s2);
	friend set& operator+=(set& s, const int e);
	friend set& operator-=(set& s, const int e);
	friend set operator+ (const set& s1, const set& s2);
	friend set operator- (const set& s1, const set& s2);
	friend set operator* (const set& s1, const set& s2);
	friend set operator~ (const set& s);
	friend set operator+ (const set& s1, const int e);
	friend set operator- (const set& s1, const int e);
	friend bool operator<= (const set& s1, const set& s2);
	friend bool operator< (int e, const set& s2);
	friend bool operator! (const set& s);

	friend std::ostream& operator<< (std::ostream& os, const set& s);
private:
	unsigned char data[32];
public:
	set();

};

