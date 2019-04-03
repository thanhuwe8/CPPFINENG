
#include <iostream>
#include <map>
#include <set>

#include "PayoffStrategy.hpp"
#include "Payoff.hpp"
#include "Point.cpp"
#include "Point.hpp"

#include "Property.cpp"

using namespace std;


int main()
{
	Property<string, double> r;
	Property<string, double> sig;
	Property<string, double> K;
	
	r = Property<string, double>("interest rate", 0.08);
	sig = Property<string, double>("volatility", 0.30);
	K = Property<string, double>("Strike Price", 65.0);
	
	
}
