//
//  Array.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

// THIS CLASS IS ADAPTER CLASS FOR DIFFERENT KIND OF ARRAYS/
// ARRAYSTRUCTURE IS ACTUAL STORAGE
#ifndef Array_hpp
#define Array_hpp
#include "Array.hpp"
#include "ArrayStructure.hpp"
#include "FullArray.cpp"

#include <stddef.h>


template<class V, class I = int, class S = FullArray<V> >
class Array
{
private:
	S m_structure; // FullArray storage
	I m_start; //index of the array, prefer to start at index = 1.
	
public:
	// Constructor, Copy Constructor and Destructor.
	Array();
	Array(I size);
	Array(I size, I start);
	Array(I size, I start, const V& value);
	Array(const Array<V, I, S>& source);
	
	virtual ~Array();
	
	// Get
	I MinIndex() const;
	I MaxIndex() const;
	I Size() const;
	
	virtual V& operator[] (I index);
	virtual const V& operator[] (I index) const;
	
	Array<V, I, S>& operator = (const Array<V, I, S>& source);
};
#endif /* Array_hpp */
