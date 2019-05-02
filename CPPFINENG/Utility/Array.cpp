//
//  Array.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

// THIS CLASS IS ADAPTER CLASS FOR DIFFERENT KIND OF ARRAYS/
// ARRAYSTRUCTURE IS ACTUAL STORAGE
#include "Array.hpp"
#include <stddef.h>

template <class V, class I, class S>
Array<V,I,S>::Array()
{
	m_structure = S();
	m_start = 1;
}

template <class V, class I, class S>
Array<V, I, S>::Array(I size)
{
	m_structure = S(size_t(size));
	m_start = 1;
}

template<class V, class I, class S>
Array<V,I,S>::Array(I size, I start)
{
	m_structure = S(size_t(size));
	m_start = start;
}

template<class V, class I, class S>
Array<V,I,S>::Array(I size, I start, const V& value)
{
	m_structure = S(size_t(size));
	m_start = start;
	
	for (I i = MinIndex(); i <= MaxIndex(); i++)
	{
		(*this)[i] = value;
	}
}

template<class V, class I, class S>
Array<V, I, S>::Array(const Array<V, I, S>& source)
{
	m_structure = source.m_structure;
	m_start = source.m_start;
}

template<class V, class I, class S>
Array<V, I, S>::~Array()
{
	
}

// GET
template<class V, class I, class S>
I Array<V, I, S>::MinIndex() const
{
	return m_start;
}

template<class V, class I, class S>
I Array<V, I, S>::MaxIndex() const
{
	return m_start+Size()-1;
}

template<class V, class I, class S>
I Array<V, I, S>::Size() const
{
	return I(m_structure.Size());
}

template<class V, class I, class S>
inline V& Array<V, I, S>::operator[](I index)
{
	return m_structure[index-m_start+1];
}

template<class V, class I, class S>
inline const V& Array<V,I,S>::operator[](I index) const
{
	return m_structure[index-m_start+1];
}

template<class V, class I, class S>
Array<V, I, S>& Array<V, I, S>::operator = (const Array<V, I, S>& source)
{
	if (this==&source)
		return *this;
	
	m_structure = source.m_structure;
	m_start = source.m_start;
	
	return *this;
}









