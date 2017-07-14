#include <iostream>
#include <ostream>

class A
{
private:
	int x;
public:
	A() { x = 0; }
	A operator+(const A& rhs){
	
	}

	friend std::ostream & operator<<(std::ostream & os, const A & x) {
		os << x.x << std::endl;
		return os;
	}
};

A operator+(const A& lhs, const A& rhs){

}

int main()
{
	//A a[17];
	A *a = new A[17];
	delete[] a;
	return 0;
}
