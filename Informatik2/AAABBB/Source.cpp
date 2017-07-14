

class AAA
{
public:
	int a;
	AAA(int aaa) { a = aaa; }
	AAA() {};
};


class BBB : public AAA
{
public:
	AAA a;
	BBB() : AAA(0) {};
};
