//
//  Payoff.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 3/31/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "Payoff.hpp"


// Plain Vanilla Call Payoff
CallPayoff::CallPayoff():Payoff()
{
	K = 100;
}

CallPayoff::CallPayoff(double Strike):Payoff()
{
	K = Strike;
}

CallPayoff::CallPayoff(const CallPayoff& source){
	K = source.K;
}

CallPayoff::~CallPayoff()
{
	printf("Successful Destruction");
}

CallPayoff& CallPayoff::operator=(const CallPayoff &source)
{
	if (this == &source) return *this;
	
	Payoff::operator=(source);
	
	K = source.K;
	
	return *this;
}

void CallPayoff::Strike(double NewStrike){
	K = NewStrike;
}

double CallPayoff::payoff(double S) const
{
	if (S>K)
		return (S-K);
	return 0.0;
}

// Bull Spread Strategy Payoff
BullSpreadPayoff::BullSpreadPayoff():Payoff()
{
	K1 = K2 = 100.0;
	buyValue = 3.0;
	sellValue = 1.0;
}

BullSpreadPayoff::BullSpreadPayoff(double strike1, double strike2,
								   double BuyVal, double SellVal):Payoff()
{
	K1 = strike1;
	K2 = strike2;
	
	buyValue = BuyVal;
	sellValue = SellVal;
}

BullSpreadPayoff::BullSpreadPayoff(const BullSpreadPayoff& source):Payoff()
{
	K1 = source.K1;
	K2 = source.K2;
	
	buyValue = source.buyValue;
	sellValue = source.sellValue;
}

BullSpreadPayoff::~BullSpreadPayoff()
{
	printf("Successful Destruction");
}

double BullSpreadPayoff::Strike1() const
{
	return K1;
}

double BullSpreadPayoff::Strike2() const
{
	return K2;
}

void BullSpreadPayoff::Strike1(double NewStrike1)
{
	K1 = NewStrike1;
}


void BullSpreadPayoff::Strike2(double NewStrike2)
{
	K2 = NewStrike2;
}

BullSpreadPayoff& BullSpreadPayoff::operator=(const BullSpreadPayoff &source)
{
	if (this==&source) return *this;
	
	Payoff::operator=(source);
	
	K1 = source.K1;
	K2 = source.K2;
	
	buyValue = source.buyValue;
	sellValue = source.sellValue;
	
	return *this;
}

double BullSpreadPayoff::payoff(double S) const
{
	// K2 is higher strike price
	if(S >= K2)
		return K2-K1;
	if(S <= K2)
		return 0.0;
	return S-K1;
}

double BullSpreadPayoff::profit(double S) const
{
	return payoff(S) - (buyValue - sellValue);
	
}





