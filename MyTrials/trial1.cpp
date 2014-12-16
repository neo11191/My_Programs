#include <bits/stdc++.h>

using namespace std;

class Vehicle
{
	protected : int wheels;
	public:
	Vehicle() {cout << "Base class constructor called" << endl;};
	virtual void test(){cout << "Base class test" << endl;}
};

class Car : public Vehicle
{
	public :
		Car(int a) { wheels = a; cout << "Car Constructor" << endl;}
		void test(){cout << "Car class test" << wheels << endl;}
};



int main()
{
	Vehicle v1;
	Car C1(4);
	C1.test();
	v1.test();
	Vehicle *V1 = &C1;
	V1->test();
	return 0;
}
