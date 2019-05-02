//
//  MatrixStructure.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/3/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef MatrixStructure_cpp
#define MatrixStructure_cpp

#include "MatrixStructure.hpp"

template <class V>
inline const V& MatrixStructure<V>::Element(size_t row, size_t column) const
{
	return (*this)[row][column];
}

template<class V>
size_t MatrixStructure<V>::MinRowIndex() const
{
	return 1;
}

template<class V>
size_t MatrixStructure<V>::MaxRowIndex() const
{
	return Rows();
}

template<class V>
size_t MatrixStructure<V>::MinColumnIndex() const
{
	return 1;
}

template<class V>
size_t MatrixStructure<V>::MaxColumnIndex() const
{
	return Columns();
}

template<class V>
inline void MatrixStructure<V>::Element(size_t row, size_t column, const V& val)
{
	(*this)[row][column] = val;
}

template <class V>
MatrixStructure<V>& MatrixStructure<V>::operator= (const MatrixStructure<V>& source)
{
	return *this;
}

template<class V>
inline V& MatrixStructure<V>::operator()(size_t row, size_t column)
{
	return (*this)[row][column];
}

template<class V>
inline const V& MatrixStructure<V>::operator()(size_t row, size_t column) const
{
	return (*this)[row][column];
}

#endif	// MatrixStructure_cpp
