//
//  Payoff.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 3/31/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef Payoff_hpp
#define Payoff_hpp

#include <stdio.h>

// abstract base class;
class Payoff
{
public:
	Payoff(); // default constructor
	Payoff(const Payoff& source); // copy constructor;
	
	Payoff& operator=(const Payoff& source); // assignment operator overloading
	
	//virtual double payoff(double Strike); // pure virtual function.
	
	virtual ~Payoff();
};


// Plain Vanilla Call Payoff
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
	
	// Get
	double Strike() const;
	
	// Set
	void Strike(double NewStrike);
	
	// Assignment overloading
	CallPayoff& operator=(const CallPayoff& source);
	
	// calculate payoff. Promise to not change the function member data.
	double payoff(double S) const;
	
};


// Bull Spread Strategy Payoff
// buy call lower, sell call higher
// buy put higher, sell put lower.
class BullSpreadPayoff:public Payoff
{
private:
	double K1;
	double K2;
	
	double buyValue;
	double sellValue;
	
public:
	BullSpreadPayoff();
	BullSpreadPayoff(double strike1, double strike2,
					 double BuyVal, double SellVal);
	BullSpreadPayoff(const BullSpreadPayoff& source);
	
	virtual ~BullSpreadPayoff();
	
	// Get
	double Strike1() const;
	double Strike2() const;
	
	// Set
	void Strike1(double NewStrike1);
	void Strike2(double NewStrike2);
	
	// Assignment overloading
	BullSpreadPayoff& operator=(const BullSpreadPayoff& source);
	
	double payoff(double S) const;
	
	double profit(double S) const;
	
};

#endif /* Payoff_hpp */
