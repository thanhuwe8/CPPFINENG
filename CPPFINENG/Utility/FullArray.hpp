//
//  FullArray.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

// TEMPALTE CLASS FOR ARRAY ONE DIMENSION
#ifndef FullArray_hpp
#define FullArray_hpp

#include <stdio.h>
#include <vector>
#include "ArrayStructure.cpp"

template<class V, class TA = std::allocator<V> >
class FullArray:public ArrayStructure<V>
{
private:
	std::vector<V, TA> m_vector;
	
public:
	FullArray();
	FullArray(size_t size);
	FullArray(const FullArray<V, TA>& source);
	virtual ~FullArray();
	
	virtual size_t Size() const;
	
	V& operator[](size_t index);
	const V& operator[](size_t index) const;
	
	FullArray<V, TA>& operator=(const FullArray<V,TA>& source);
};
#endif /* FullArray_hpp */
