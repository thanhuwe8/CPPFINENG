//
//  Point.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 3/31/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "Point.hpp"
#include <math.h>
#include <iostream>

// default constructor
template <class TFirst, class TSecond>
Point<TFirst, TSecond>::Point()
{
	m_first = TFirst();
	m_second = TSecond();
}

// constructor
template<class TFirst, class TSecond>
Point<TFirst, TSecond>::Point(TFirst first, TSecond second)
{
	m_first = first;
	m_second = second;
}

// copy constructor
template<class TFisrt, class TSecond>
Point<TFisrt, TSecond>::Point(const Point< TFisrt, TSecond>& source)
{
	m_first = source.m_first;
	m_second = source.m_second;
}

// Destructor template
template<class TFirst, class TSecond>
Point<TFirst, TSecond>::~Point()
{
	std::cout << "Destructor of point called" << std::endl;
}

// Set first coordinate
template <class TFirst, class TSecond>
void Point<TFirst, TSecond>::First(const TFirst& val)
{
	m_first = val;
}

// Set second coordinate
template<class TFirst, class TSecond>
void Point<TFirst, TSecond>::Second(const TSecond& val)
{
	m_second = val;
}

// calculate distance
template <class TFirst, class TSecond>
double Point<TFirst, TSecond>::Distance(const Point<TFirst, TSecond>& p) const
{
	TFirst a = p.m_first-m_first;
	TSecond b = p.m_second - m_second;
	
	return sqrt(a*a+b*b);
}


// ASSIGNMENT OPERATOR ALWAYS RETURN REFERENCE VARIABLE
template <class TFirst, class TSecond>
Point<TFirst, TSecond>& Point<TFirst, TSecond>::operator=(const Point<TFirst, TSecond>& source)
{
	if (this==&source)
		return *this;
	m_first = source.m_first;
	m_second = source.m_second;
}


//template <class TFirst, class TSecond>
//ostream& operator << (ostream& os, const Point<TFirst, TSecond>& p)
//{
//	os << "(" << p.m_first << "," << p.m_second << ")\n";
//	return os;
//}
