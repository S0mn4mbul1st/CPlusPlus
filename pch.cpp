
#include "pch.h"
#include <iostream>
using namespace std;

int* arr;
const int val = 5; 

void v_alloc_table_add_5(int iSize) {

	if (iSize < 0) {

		cout << "Invalid Size is entered\n\n";

		iSize = 0;
	}

	arr = new int[iSize];

	cout << "\n\nArray is Allocated\n";

	for (int i = 0; i < iSize; i++)

		arr[i] = i + val;

	cout << "Numbers : ";

	for (int i = 0; i < iSize; i++)

		cout << arr[i] << " ";


	delete[] arr;

	cout << "\n\nArray is Deallocated\n";

}
