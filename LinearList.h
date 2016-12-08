/*
#	Formula Based Linear List Implementation
*/
#ifndef LINEARLIST_H
#define LINEARLIST_H


#include <iostream>

using namespace std;

template<class T> class LinearList
{	

	//Public Function Definitions
	public:
		LinearList(int MaxListSize = 10);				//Constructor, O(1)
		~LinearList() { delete[] element; }				//Destructor
		bool IsEmpty() const { return length == 0; }	//IsEmpty, Theta(1)
		int Length() const { return length; }			//Length of List, Theta(1)
		bool Find(int k, T& x) const;					//Return the k'th element of List in x, 
		int Search(const T& x) const;					//Return position of x
		LinearList<T>& Insert(int k, const T& x);
		LinearList<T>& Delete(int k, T& x);				//Delete k'th element and return it
		void DeleteSimilar(const T& x);
		void Output(ostream& out) const;				//Output the list
	
	//Private Class Members
	private:
		int length;
		int MaxSize;
		T* element; //Dynamic 1D array
};

//Constructor, O(1) 
template <class T> LinearList<T>::LinearList(int MaxListSize)	//Constructor
{
	cout << "	-> Linear List Constructor Call\n";
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

//Set x to the k'th element of the list
//Return false if no k'th, true otherwise, theta(1)
//Does an element exist at index k, if it does update the address of x to that element
template <class T> bool LinearList<T>::Find(int k, T& x) const	//Find
{
	if (k < 1 || k > length)
		return false;
	x = element[k - 1];
	return true;
};

//Locate x, return position of x if found
//Return 0 if x not in list, O(n)
template<class T> int LinearList<T>::Search(const T& x) const	//Search
{
	for (int i = 0; i < length; i++)
	{
		if (element[i] == x)
		{
			return ++i;
		}
	}
	return 0;
};


template<class T> LinearList<T>& LinearList<T>::Insert(int k, const T& x){
	if (k > length || k < 0){
		cout << "	Index out of bound error!\n";
		exit;
	}
	else if (length == MaxSize){
		cout<< " Array is Full!\n";
		exit;		
	}
	else{
		for (int i = length-1; i>=k; i--){
			element[i+1] = element [i];
		} 
		element [k] = x;
		length++;
		return *this;
	}
}


//Set x to the k'th element and delete it
//Show OutOfBounds error if no k'th element, theta(n)
template<class T> LinearList<T>& LinearList<T>::Delete(int k, T& x)	//Delete
{
	if (Find(k, x))
	{
		//Move elements k+1, ..., down
		for (int i = k; i < length; i++)
			element[i - 1] = element[i];
		length--;
		return *this;
	}
	else {
		cout << "	Index out of bound error!\n";
		exit;
	}
};

//Delete Similar Function
template<class T> void LinearList<T>::DeleteSimilar(const T& x){
	int t; //because search(x) will return int
	T temp;
	while (t = Search(x)){
		Delete(t, temp); //Delete location & store in temp
	}
}

//Output the list
template<class T> void LinearList<T>::Output(ostream& out) const
{
	for (int i = 0; i < length; i++)
	{
		out << element[i] << " ";
	}
};

#endif
