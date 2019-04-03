//
//  LineSegment.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 3/31/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef LineSegment_hpp
#define LineSegment_hpp

#include <stdio.h>
#include "Point.hpp"

#endif /* LineSegment_hpp */

// class for
template <class T>
class LineSegment
{
private:
	Point<T,T> e1;
	Point<T,T> e2;
public:
	LineSegment();
	LineSegment(const Point<T,T>& p1, const Point<T,T>& p2);
	LineSegment(const LineSegment<T>& l);
	virtual ~LineSegment();
	
	Point<T,T> start() const;
	Point<T,T> end() const;
	
	void start(const Point<T,T>& pt);
	void end(const Point<T,T>& pt);
	
	double length() const;
	
	Point<T,T> midPoint() const;
};
