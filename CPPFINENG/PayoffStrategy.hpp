//
//  PayoffStrategy.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 3/31/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef PayoffStrategy_hpp
#define PayoffStrategy_hpp

#include <stdio.h>

// light weight payoff strategy

class PayoffStrategy
{
public:
	virtual double price(double S0) const = 0;
};

class CallStrategy: public PayoffStrategy
{
private:
	double K;
public:
	CallStrategy(double strike){K = strike;}
	double price(double S) const
	{
		if (S>K)
			return (S-K);
		return 0;
	}
};

class BullSpreadStrategy:public PayoffStrategy
{
private:
	double K1;
	double K2;
	
public:
	BullSpreadStrategy(double strike1, double strike2)
	{
		K1 = strike1; K2 = strike2;
	}
	
	double price(double S) const
	{
		if (S >= K2) return K2-K1;
		if (S <= K1) return 0.0;
		return S-K1;
	}
};


// Strategy Pattern.
// this class used to hold pointer to different kind of strategies for payoff
class PayoffLight
{
private:
	PayoffStrategy* ps;
public:
	PayoffLight(PayoffStrategy& strat){
		ps = &strat;
	};
};

#endif /* PayoffStrategy_hpp */
