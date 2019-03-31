
#include <iostream>

using namespace std;


class B
{
private:
	double* d;
public:
	B(){d = new double(1.0);}
	virtual ~B(){cout << "Base destructor\n"; delete d;}
	
	// declare member function to be virtual to allow override in derived class
	// when using pointer.
	virtual void pra(){
		cout << "this is a base class" << endl;
	}
};

class D: public B{
private:
	int* iarr;
public:
	D(int N){
		iarr = new int[N];
	}
	
	~D(){
		cout << "Derived class destructor" << endl;
		delete[] iarr;
	}
	
	void pra(){
		cout << "This is derived class " << endl;
	}
};


class E: public D{
private:
	int* iarr2;
public:
	E(int N2, int N):D(N2){
		iarr2 = new int[N];
	}
	
	~E(){
		cout << "Derived class destructor 2" << endl;
	}
	
	void pra(){
		cout << "This is derived class 2" << endl;
	}
};

// abstract base class;
class Payoff
{
public:
	Payoff(); // default constructor
	Payoff(const Payoff& source); // copy constructor;
	
	Payoff& operator=(const Payoff& source); // assignment operator overloading
	
	virtual double payoff(double S) const = 0; // pure virtual function.
};


class CallPayoff:public Payoff
{
private:
	double K;
public:
	// default, constructor, copy constructor
	CallPayoff();
	CallPayoff(double Strike);
	CallPayoff(const CallPayoff& source);
	
	virtual ~CallPayoff();

	// Selector
	double Strike() const;

	// Modifier
	void Strike(double NewStrike);
	
	// assignment operator overloading
	CallPayoff& operator=(const CallPayoff& source);
	
	// calculate payoff. Promise to not change the function member data.
	double payoff(double S) const;
	
};





int main()
{
//	B a = B();
//	a.pra();
//
	B* c = new D(10);
	c->pra();
	
	cout << "END TEST 1" << endl;
	
	B* e = new E(10,12);
	e->pra();
	
	delete c;
	
	
	return 0;
}
