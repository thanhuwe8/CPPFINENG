//
//  MatrixStructure.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/3/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef MatrixStructure_hpp
#define MatrixStructure_hpp

#include <stdio.h>
#include "ArrayStructure.hpp"

template<class TValue>
class MatrixStructure
{
public:
	MatrixStructure();
	MatrixStructure(const MatrixStructure<TValue>& source);
	virtual ~MatrixStructure();
	
	// Get
	virtual size_t Rows() const = 0;
	virtual size_t Columns() const = 0;
	
	const TValue& Element(size_t row, size_t column) const;
	
	// Get min max index
	size_t MinRowIndex() const;
	size_t MaxRowIndex() const;
	size_t MinColumnIndex() const;
	size_t MaxColumnIndex() const;
	
	// Set
	void Element(size_t row, size_t column, const TValue& val);
	
	// operator overloading
	// []
	virtual ArrayStructure<TValue>& operator[](size_t index) = 0;
	virtual const ArrayStructure<TValue>& operator[](size_t index) const = 0;
	
	// ()
	const TValue& operator()(size_t row, size_t column) const;
	TValue& operator()(size_t row, size_t column);
	
	// =
	MatrixStructure<TValue>& operator = (const MatrixStructure<TValue>& source);
	
};
#endif /* MatrixStructure_hpp */


