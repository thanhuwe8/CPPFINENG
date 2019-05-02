//
//  ArrayStructure.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

// MOST BASE CLASS FOR ARRAY DATA (ARRAY, VECTOR, MATRIX)

#ifndef ArrayStructure_hpp
#define ArrayStructure_hpp

#include <stdio.h>

template<class V>
class ArrayStructure
{
public:
	ArrayStructure();
	ArrayStructure(const ArrayStructure<V>& source);
	virtual ~ArrayStructure();
	
	virtual size_t Size() const = 0;
	const V& Element(size_t index) const;
	
	size_t MinIndex() const;
	size_t MaxIndex() const;
	
	void Element(size_t index, const V& val);
	
	virtual V& operator[](size_t index) = 0;
	virtual const V& operator[](size_t index) const = 0;
	
	ArrayStructure<V>& operator=(const ArrayStructure<V>& source);
	
};
#endif /* ArrayStructure_hpp */
