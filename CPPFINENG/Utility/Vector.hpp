//
//  Vector.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/3/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include "Array.cpp"

template<class V, class I=int, class S=FullArray<V> >
class Vector: public Array<V,I,S>
{
public:
	Vector();
	Vector(I size);
	Vector(I size, I start);
	Vector(I size, I start, const V& val);
	Vector(const Vector<V,I,S>& source);
	Vector(const Array<V,I,S>& source);

	virtual ~Vector();
	
	Vector<V,I,S>& operator=(const Vector<V,I,S>& source);
	Vector<V,I,S>& operator-() const;
	
	friend Vector<V,I,S> operator+(const Vector<V,I,S>& v, const V& a);
	friend Vector<V,I,S> operator+(const V& a, const Vector<V,I,S>& v);
	friend Vector<V,I,S> operator-(const Vector<V,I,S>& v, const V&a);
	friend Vector<V,I,S> operator-(const V& a, const Vector<V,I,S>& v);
	friend Vector<V,I,S> operator*(const Vector<V,I,S>& v, const V& a);
	friend Vector<V,I,S> operator*(const V& a, const Vector<V,I,S>& v);
	friend Vector<V,I,S> operator/(const Vector<V,I,S>& v, const V& a);
	
	Vector<V,I,S> operator+(const Vector<V,I,S>& v) const;
	Vector<V,I,S> operator-(const Vector<V,I,S>& v) const;
	Vector<V,I,S> operator*(const Vector<V,I,S>& v) const;
	Vector<V,I,S> operator/(const Vector<V,I,S>& v) const;
	
	Vector<V,I,S>& operator+=(const S& v) const;
	Vector<V,I,S>& operator-=(const S& v) const;
	Vector<V,I,S>& operator*=(const S& v) const;
	Vector<V,I,S>& operator/=(const S& v) const;
	
	Vector<V,I,S>& operator+=(const Vector<V,I,S>& v) const;
	Vector<V,I,S>& operator-=(const Vector<V,I,S>& v) const;
	Vector<V,I,S>& operator*=(const Vector<V,I,S>& v) const;

	
};


#endif /* Vector_hpp */
