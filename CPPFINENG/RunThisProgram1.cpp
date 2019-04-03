//
//  RunThisProgram1.cpp
//  CPPFINENG
//
//  Created by Minh Thành Nguyễn on 4/2/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <map>
#include <set>

#include "PayoffStrategy.hpp"
#include "Payoff.hpp"
#include "Point.cpp"
#include "Point.hpp"

using namespace std;

template <class V> void mySwap(V& v1, V& v2)
{
	V tmp = v2;
	v2 = v1;
	v1 = tmp;
}

typedef map<int, double> SparseRow;

template <int N> struct SparseMatrix
{
	map<int, SparseRow> data;
	
};

template <int N>
void print(SparseMatrix<N>& sm)
{
	SparseRow sr;
	SparseRow::const_iterator it;
	
	for (int row = 0; row < N; row++)
	{
		SparseRow sr = sm.data[row];
		
		// Now iterate over row
		for (it = sm.data[row].begin(); it != sm.data[row].end(); it++)
		{
			cout << (*it).second << ", ";
		}
		cout << endl;
		
	}
	
}

template <class T>
void print(const set<T>& myset, const string& name)
{
	cout << endl << name << ", size of the set is " << myset.size() << endl;
	
	cout << "[";
	for(auto i = myset.begin(); i!=myset.end();++i)
	{
		cout << (*i) << ", ";
	}
	cout << "]" << endl;
}

template <class T>
void UnionSet(const set<T>& s1, const set<T>& s2, set<T>& myunion)
{
	set<int>::iterator i = myunion.begin();
	insert_iterator<set<int>> insertiter(myunion, i);
	
	set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), insertiter);
}


template <class T>
bool subset(const set<T>& super, const set<T>& sub)
{
	return includes(super.begin(), super.end(), sub.begin(), sub.end());
}


int runthisprogram()
{
	
	CallStrategy call(20.0);
	PayoffLight pay1(call);
	
	Point<double, double> p1(1.0, 1.0);
	Point<double, double> p2;
	
	int j = 10;
	int k = 20;
	mySwap(j, k);
	
	cout << "This is map section" << endl;
	const int N = 5;
	
	// this is map
	SparseRow current;
	
	current.insert(pair<int, double> (0, -2.0));
	current.insert(pair<int, double> (1, 1.0));
	
	SparseMatrix<N> sparseMat;
	sparseMat.data[0] = current;
	
	int currentIndex = 0;
	
	cout << "Start to print" << endl;
	for (int row = 0;row<N-1;row++)
	{
		current.clear();
		current.insert(pair<int, double> (currentIndex, 1.0));
		current.insert(pair<int, double> (currentIndex+1, -2.0));
		current.insert(pair<int, double> (currentIndex+2, 1.0));
		
		sparseMat.data[row] = current;
		currentIndex++;
		
	}
	
	current.clear();
	current.insert(pair<int, double> (N-2, 1.0));
	current.insert(pair<int, double> (N-1, -2.0));
	sparseMat.data[N-1] = current;
	print(sparseMat);
	
	set<string> first;
	
	first.insert("r");
	first.insert("T");
	first.insert("sigma");
	
	set<string> second(first);
	second.insert("r");
	second.insert("K");
	second.insert("S");
	second.insert("b");
	
	print(first, "thanh1");
	print(second, "thanh2");
	
	// test inserter
	cout << "Test Inserter" << endl;
	set<int> third;
	third.insert(1);
	third.insert(2);
	third.insert(3);
	
	set<int> fourth(third);
	fourth.insert(51);
	fourth.insert(52);
	
	set<int> myunion2;
	UnionSet(third, fourth, myunion2);
	
	print(myunion2, "abc");
	
	return 0;
}

