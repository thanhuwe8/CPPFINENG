//
//  FullMatrix.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/3/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "FullMatrix.hpp"
template<class V, class TA>
FullMatrix<V, TA>::FullMatrix():MatrixStructure<V>()
{
	m_structure = FullArray<FullArray<V, TA>, std::allocator<FullArray<V, TA> > >();
	nr = nc = 1;
}

template<class V, class TA>
FullMatrix<V, TA>::FullMatrix(size_t rows, size_t columns):MatrixStructure<V>()
{
	// create an array of array.
	m_structure = FullArray<FullArray<V, TA>, std::allocator<FullArray<V,TA> > >(rows);
	
	// each row will hold a vector representing columns.
	for (size_t i = 1; i <= m_structure.Size(); i++)
	{
		m_structure[i] = FullArray<V, TA>(columns);
	}
	
	nr = rows;
	nc = columns;
}

template<class V, class TA>
FullMatrix<V, TA>::FullMatrix(const FullMatrix<V, TA>&source):MatrixStructure<V>(source)
{
	m_structure = source.m_structure;
	nr = source.nr;
	nc = source.nr;
}

template<class V, class TA>
FullMatrix<V, TA>::~FullMatrix()
{
	
}

template<class V, class TA>
size_t FullMatrix<V, TA>::Rows() const
{
	return nr;
}

template<class V, class TA>
size_t FullMatrix<V, TA>::Columns() const
{
	return nc;
}

// OPERATOR OVERLOADING RETURN REFERENCE TO ARRAYSTRUCTURE (MOST BASE CLASS)
template<class V, class TA>
ArrayStructure<V>& FullMatrix<V,TA>::operator[](size_t row)
{
	return m_structure[row];
}


template<class V, class TA>
const ArrayStructure<V>& FullMatrix<V, TA>::operator[](size_t row) const
{
	return m_structure[row];
}

template<class V, class TA>
FullMatrix<V, TA>& FullMatrix<V,TA>::operator=(const FullMatrix<V,TA>& source)
{
	if (this == &source)
		return (*this);
	
	// MATRIX STRUCTURE ASSIGNMENT
	MatrixStructure<V>::operator = (source);
	
	m_structure = source.m_structure;
	nr = source.nr;
	nc = source.nc;
	
	return *this;
}

