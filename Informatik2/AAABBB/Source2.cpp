

class AAA
{
public:
	int a;
	AAA(int aaa) { a = aaa; }
};


class BBB
{
public:
	AAA a;
	BBB() : a(0) {};
};
