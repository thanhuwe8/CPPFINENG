//
//  Set.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "Set.hpp"
#include <algorithm>
#include <iterator>

template <class V>
Set<V>::Set()
{
	s = set<V>();
}

template <class V>
Set<V>::Set(const set<V>& stlSet)
{
	s = stlSet;
}

template <class V>
Set<V>::Set(const Set<V>& s2)
{
	s = set<V>(s2.s);
}


template <class V>
Set<V>::Set(const list<V>& con)
{ // From am STL container (list, vector)
	
	s = set<V>();
	
	// Create list iterator
	
	// Print every character in the list
	for (auto a = con.begin(); a != con.end(); ++a)
	{
		s.insert(*a);		// Will only be inserted once
	}
}

template<class V>
Set<V>& Set<V>::operator=(const Set<V>& s2)
{
	if (this==&s2)
	{
		return *this;
	}
	
	return *this;
}

template<class V>
Set<V> Intersection(const Set<V>& s1, const Set<V>& s2)
{
	set<V> myintersect;
	// note this one
	typename set<V>::iterator i = myintersect.begin();
	insert_iterator<set<V> > insertiter(myintersect, i);
	set_intersection(s1.s.begin(), s1.s.end(), s2.s.begin(), s2.s.end(), insertiter);
	
	return Set<V>(myintersect);
}

template<class V>
Set<V> Set<V>::operator^(const Set<V>& s2)
{
	return Intersection(*this, s2);
}

template<class V>
Set<V> Union(const Set<V>& s1, const Set<V>& s2)
{
	set<V> myunion;
	typename set<V>::iterator i = myunion.begin();
	insert_iterator<set<V> > insertiter(myunion, i);
	set_union(s1.s.begin(), s1.s.end(), s2.s.begin(), s2.s.end(), insertiter);
	
	return Set<V>(myunion);
}

template<class V>
Set<V> Set<V>::operator+(const Set<V>& s2)
{
	return Union(*this, s2);
}

template<class V>
Set<V> Difference(const Set<V>& s1, const Set<V>& s2)
{
	set<V> mydiff;
	typename set<V>::iterator i = mydiff.begin();
	insert_iterator<set<V> > insertiter(mydiff, i);
	set_difference(s1.s.begin(), s1.s.end(), s2.s.begin(), s2.s.end(), insertiter);
	
	return Set<V>(mydiff);
}

template<class V>
Set<V> Set<V>::operator-(const Set<V>& s2)
{
	return Difference(*this, s2);
}










