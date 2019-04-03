//
//  MAPS.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 3/31/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "MAPS.hpp"

// default constructor
template<class Type, int def_size>
Array<Type, def_size>::Array()
{
	// use basic array in C++
	m_data = new Type[def_size];
	m_size = def_size;
}

// constructor
template<class Type, int def_size>
Array<Type, def_size>::Array(int size)
{
	m_data = new Type[size];
	m_size = size;
}

// copy constructor
template<class Type, int def_size>
Array<Type, def_size>::Array(const Array<Type, def_size>& source)
{
	m_size = source.m_size;
	m_data = new Type[m_size];
	for(int i=0; i<m_size;i++){
		m_data[i] = source.m_data[i];
	}
}





