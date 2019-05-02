//
//  Vector.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/3/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "Vector.hpp"

template<class V, class I, class S>
Vector<V,I,S>::Vector():Array<V,I,S>(){}

template<class V, class I, class S>
Vector<V,I,S>::Vector(I size):Array<V,I,S>(size){}

template<class V, class I, class S>
Vector<V,I,S>::Vector(I size, I start):Array<V,I,S>(size, start){}

template<class V, class I, class S>
Vector<V,I,S>::Vector(I size, I start, const V& val):Array<V, I, S>(size, start, val){}

template<class V, class I, class S>
Vector<V,I,S>::Vector(const Vector<V,I,S>& source):Array<V,I,S>(source){}

template<class V, class I, class S>
Vector<V, I, S>::~Vector(){}

template<class V, class I, class S>
Vector<V, I, S>& Vector<V, I, S>::operator = (const Vector<V, I, S>& source)
{
	if (this==&source)
		return (*this);
	Array<V,I,S>::operator=(source);
	
	return *this;
}

template <class V, class I, class S>
Vector<V, I, S> Vector<V, I, S>::operator- () const
{
	Vector<V,I,S> result(Size(), MinIndex());
	
	for (I i = MinIndex(); i <= MaxIndex(); i++)
	{
		result[i] = -(*this)[i];
		
	}
	
	return result;
}

template< class V, class I, class S>
Vector<V, I, S> Vector<V, I, S>::operator+(const Vector<V,I,S>& v, const V& a)
{
	Vector<V, I, S> result(v.Size(), v.MinIndex());
	
	for (I i = v.MinIndex(); i <= v.MaxIndex(); i++)
	{
		result[i] = v[i] + a;
	}
}

