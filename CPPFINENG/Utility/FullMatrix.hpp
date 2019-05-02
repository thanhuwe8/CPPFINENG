//
//  FullMatrix.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/3/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef FullMatrix_hpp
#define FullMatrix_hpp

#include <stdio.h>
#include "MatrixStructure.cpp"
#include "FullArray.hpp"

template<class TValue, class TA = std::allocator<TValue> >
class FullMatrix: public MatrixStructure<TValue>
{
private:
	FullArray<FullArray<TValue,TA>, std::allocator<FullArray<TValue, TA> > > m_structure;
	size_t nr, nc;
	
public:
	FullMatrix();
	FullMatrix(size_t rows, size_t columns);
	FullMatrix(const FullMatrix<TValue, TA>& source);
	virtual ~FullMatrix();
	
	// Get
	virtual size_t Rows() const;
	virtual size_t Columns() const;
	
	// Set
	// empty.
	
	// NOTE THAT ALL OPERATOR OVERLOADING RETURN ARRAYSTRUCTURE OBJECT WHICH IS
	// THE MOST BASE CLASS.
	// Operator
	virtual ArrayStructure<TValue>& operator[](size_t index);
	virtual const ArrayStructure<TValue>& operator[](size_t index) const;
	
	FullMatrix<TValue, TA>& operator = (const FullMatrix<TValue, TA>& source);
};

#endif /* FullMatrix_hpp */
