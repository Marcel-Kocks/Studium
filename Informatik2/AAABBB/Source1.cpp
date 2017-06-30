

class A
{
private:
	int x;
public:
	A() { x = 0; }
};

int main()
{
	//A a[17];
	A *a = new A[17];
	delete[] a;
	return 0;
}
