//
//  Property.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "Property.hpp"
template<class Name, class Value>
Property<Name, Value>::Property()
{
	nam = Name();
	con = Value();
}

template<class Name, class Value>
Property<Name, Value>::Property(const Name& name)
{
	nam = name;
	con = Value();
}

template<class Name, class Value>
Property<Name, Value>::Property(const Name& name, const Value& t)
{
	nam = name;
	con = t;
}

template<class Name, class Value>
Property<Name, Value>::Property(const Property<Name, Value>& source)
{
	nam = source.nam;
	con = source.con;
}

template<class Name, class Value>
Property<Name, Value>::~Property()
{
	std::cout << "Destructor called" << std::endl;
}

template<class Name, class Value>
Property<Name, Value>& Property<Name, Value>::operator=(const Property<Name, Value> &source)
{
	if (this==&source)
		return *this;
	nam = source.nam;
	con = source.con;
	
	return *this;
}


template <class Name, class Value>
PropertyThing<Name, Value>* Property<Name, Value>::Copy() const
{
	
	return new Property(*this);
}

template <class Name, class Value>
Value Property<Name, Value>::operator()() const
{
	return con;
}

template <class Name, class Value>
void Property<Name, Value>::operator()(const Value& t)
{
	con = t;
}

template <class Name, class Value>
Name Property<Name, Value>::name() const
{
	return nam;
}

template<class Name, class Value>
bool Property<Name, Value>::operator == (const Property<Name, Value>& prop2)
{
	if (nam == prop2.name())
		return nam;
	
	return false;
}

template<class Name, class Value> bool Property<Name, Value>::operator !=(const Property<Name, Value>& prop2)
{
	if (*this == prop2.name())
		return false;
	
	return true;
}


