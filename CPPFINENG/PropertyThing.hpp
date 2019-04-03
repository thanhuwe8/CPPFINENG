//
//  PropertyThing.hpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#ifndef PropertyThing_hpp
#define PropertyThing_hpp

#include <stdio.h>
#include <string>

template <class Name, class Value>
class PropertyThing
{
public:
	PropertyThing(){}
	virtual ~PropertyThing(){}
	virtual PropertyThing* Copy() const = 0;
	
	PropertyThing<Name,Value>& operator = (const PropertyThing<Name, Value>& source){}
};

#endif /* PropertyThing_hpp */
