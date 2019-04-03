//
//  Property.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef Property_hpp
#define Property_hpp

#include <stdio.h>
#include <iostream>
#include "PropertyThing.cpp"
#include <string>

using namespace std;

template<class Name = string, class Value = double>
class Property: public PropertyThing<Name, Value>
{
private:
	Name nam;
	Value con;
	
public:
	Property();
	Property(const Name& name);
	Property(const Name& name, const Value& t);
	Property(const Property<Name, Value>& source);
	
	virtual~Property();
	
	virtual Value operator()() const;
	virtual void operator()(const Value& t);
	
	virtual Name name() const;
	
	Property<Name, Value>& operator=(const Property<Name, Value>& source);
	
	PropertyThing<Name, Value>* Copy() const;
	
	bool operator == (const Property<Name, Value>& prop2);
	bool operator != (const Property<Name, Value>& source);
	
	//void accept(PropertyThingVisitor<Name, Value>& pv);
	
	
	
};
#endif /* Property_hpp */
