// third_task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int ** pi_table;

	cout << "Allocation Result : " << b_alloc_table_2_dim(pi_table, 5, 3) << endl;

	cout << "Deallocation Result : " << b_dealloc_table_2_dim(pi_table, 5, 3) << endl;

}

