//
//  Point.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 3/31/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template<class TFirst, class TSecond>
class Point
{
private:
	TFirst m_first;
	TSecond m_second;
	
public:
	Point();
	Point(TFirst first, TSecond second);
	Point(const Point<TFirst, TSecond>& source);
	virtual ~Point();
	
	// Get
	TFirst First() const;
	TSecond Second() const;
	
	// Set
	void First(const TFirst& val);
	void Second(const TSecond& val);
	
	// MEMBER FUNCTION
	double Distance(const Point<TFirst, TSecond>& p) const;
	
	// Assignment operator
	Point<TFirst, TSecond>& operator=(const Point<TFirst, TSecond>& source);
	
	// print
//	friend ostream& operator << (ostream& os, const Point<TFirst, TSecond>& p);
};

#endif /* Point_hpp */
