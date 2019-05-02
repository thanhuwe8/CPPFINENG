//
//  FullArray.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

// TEMPLATE DERIVED CLASS FOR ARRAY ONE DIMENSION
#include "FullArray.hpp"

template<class V, class TA>
FullArray<V, TA>::FullArray():ArrayStructure<V>()
{
	m_vector = std::vector<V, TA>(1);
}

template<class V, class TA>
FullArray<V, TA>::FullArray(size_t size):ArrayStructure<V>()
{
	m_vector = std::vector<V, TA>(size);
}

template<class V, class TA>
FullArray<V, TA>::~FullArray()
{}

template <class V, class TA>
size_t FullArray<V, TA>::Size() const
{
	return m_vector.size();
}

template <class V, class TA>
V& FullArray<V, TA>::operator[] (size_t index)
{
	return m_vector[index-1];
}

template <class V, class TA>
const V& FullArray<V, TA>::operator[] (size_t index) const
{
	return m_vector[index-1];
}

template<class V, class TA>
FullArray<V, TA>& FullArray<V, TA>::operator = (const FullArray<V, TA>& source)
{
	if(this==&source)
		return *this;
	
	ArrayStructure<V>::operator = (source);
	
	m_vector = source.m_vector;
	
	return (*this);
}
