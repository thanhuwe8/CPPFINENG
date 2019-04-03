//
//  Set.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include <set>
#include <list>
#include <iostream>
#include <iterator>


using namespace std;

// SetThing = abstract class
template <class V>
class SetThing{};


// Set header
template <class V>
class Set: public SetThing<V>
{
private:
	// only data member is set from stl
	set<V> s;
	
public:
	// typedef for iterator of set of type V
	typedef typename set<V>::iterator iterator;
	typedef typename set<V>::const_iterator const_iterator;
	
	Set();
	Set(const set<V>& stlSet); //create a Set from STL set
	Set(const Set<V>& s2); // copy constructor
	Set(const  list<V>& con); // From an STL list
	Set<V>& operator=(const Set<V>& s2);
	virtual ~Set();
	
	
	// Standard set operation
	friend Set<V> Intersection(const Set<V>& s1, const Set<V>& s2);
	Set<V> operator^(const Set<V>& s2);
	
	friend Set<V> Union(const Set<V>& s1, const Set<V>& s2);
	Set<V> operator+(const Set<V>& s2);
	
	friend Set<V> Difference(const Set<V>& s1);
	Set<V> operator-(const Set<V>& s2);
	
	friend Set<V> SymmetricDifference(const Set<V>& s1, const Set<V>& s2);
	Set<V> operator% (const Set<V>& s2);
	
	
	// function inline
	template<class V2>
	Set<pair<V,V2> > operator*(const Set<V2>& s2);
	
	
	template <class V2>
	Set<pair<V,V2>> CartesianProduct(const Set<V2>& s2);
	
	iterator Begin();
	const_iterator Begin() const;
	iterator End();
	const_iterator End() const;
	
	// Operation on a single set
	long Size() const;
	void Insert(const V& v);
	void Insert(const Set<V>& v);
	
	void Remove(const V& v);
	void Replace(const V& Old, const V& New);
	void Clear();
	
	bool Contains(const V& v) const;
	bool Empty() const;
	
	void operator+(const V& v);
	void operator-(const V& v);
	
	bool Subset(const Set<V>& s2) const;
	bool Superset(const Set<V>& s2) const;
	bool Intersects(const Set<V>& s2) const;
	
	
	
};
