//
//  MatrixStructure.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/3/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

// TEMPLATE CLASS FOR MATRIX

#ifndef MatrixStructure_hpp
#define MatrixStructure_hpp

#include "ArrayStructure.hpp"

template<class V>
class MatrixStructure
{
public:
	MatrixStructure();
	MatrixStructure(const MatrixStructure<V>& source);
	virtual ~MatrixStructure();
	
	// Get
	virtual size_t Rows() const = 0;
	virtual size_t Columns() const = 0;
	const V& Element(size_t row, size_t column) const;
	
	// Get min max index
	size_t MinRowIndex() const;
	size_t MaxRowIndex() const;
	size_t MinColumnIndex() const;
	size_t MaxColumnIndex() const;
	
	// Set
	void Element(size_t row, size_t column, const V& val);
	
	// operator overloading
	// []
	virtual ArrayStructure<V>& operator[](size_t index) = 0;
	virtual const ArrayStructure<V>& operator[](size_t index) const = 0;
	
	// ()
	const V& operator()(size_t row, size_t column) const;
	V& operator()(size_t row, size_t column);
	
	// =
	MatrixStructure<V>& operator = (const MatrixStructure<V>& source);
	
};
#endif /* MatrixStructure_hpp */


