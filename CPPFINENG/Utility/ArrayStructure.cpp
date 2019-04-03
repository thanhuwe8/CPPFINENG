//
//  ArrayStructure.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "ArrayStructure.hpp"

template<class V>
inline const V& ArrayStructure<V>::Element(size_t index) const
{
	return ((*this)[index]);
}

template<class V>
size_t ArrayStructure<V>::MinIndex() const
{
	return 1;
}

template<class V>
size_t ArrayStructure<V>::MaxIndex() const
{
	return Size();
}

template<class V>
inline void ArrayStructure<V>::Element(size_t index, const V& val)
{
	(*this)[index] = val;
}

template<class V>
ArrayStructure<V>& ArrayStructure<V>::operator= (const ArrayStructure<V>& source)
{
	return *this;
}


