//
//  MAPS.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 3/31/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef MAPS_hpp
#define MAPS_hpp

#include <stdio.h>
#include <iostream>

template<class Type, int def_size>
class Array
{
private:
	Type* m_data;
	int m_size;
	
public:
	
	Array();
	Array(int size);
	Array(const Array<Type, def_size>& source);
	virtual ~Array();
	
	int Size() const;
	
	const Type& operator[](int index) const; // constant array
	Type& operator[](int index); // non constant array
	
	Array<Type, def_size>& operator=(const Array<Type, def_size>& source);
};






#endif /* MAPS_hpp */
