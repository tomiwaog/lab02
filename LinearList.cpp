#include <iostream>
#include <stdlib.h>
#include "LinearList.h"
using namespace std;

int main(){

	LinearList<int> L;
	L.Insert(0,2);
	L.Insert(1,6);
	L.Insert(2,2);
	L.Insert(3,12);
	L.Insert(4,6);
	L.Insert(5,8);
	L.Insert(6,2);
	L.Insert(7,10);
	L.Output(cout);
	cout<<endl;
	
	L.DeleteSimilar(2);
	L.Output(cout);
	cout<<endl;
}
