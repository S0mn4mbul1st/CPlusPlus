// CTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	CTable variable ;
	variable.arrayPrinter();
	variable.setValue(3, 20);
	cout << variable.getsName() + "'s average: " << variable.getAvg() << endl;
	variable.bSetNewSize(5);
	variable.setValue(3, 20);
	variable.arrayPrinter();


	cout << endl << endl;

	CTable *variable1 = new CTable("A", 5);
	variable1->arrayPrinter();
	variable1->setValue(3, 20);
	cout << endl << variable1->getsName() + "'s average: " << variable1->getAvg() << endl;
	variable1->bSetNewSize(6);
	variable1->setValue(3, 40);
	variable1->arrayPrinter();

	cout << endl << endl;

	CTable *variable12 = new CTable("B", 0);

	cout << endl << endl;

	CTable *variable11 = new CTable("C" , -1);

	cout << endl << endl;

	CTable *variable2 = new CTable(*variable1);
	cout << variable2->getsName() + "'s average: " << variable2->getAvg() << endl;
	variable2->arrayPrinter();

	cout << endl << endl;

	
	CTable *variable23 = new CTable(*variable12);
	cout << variable23->getsName() + "'s average: " << variable23->getAvg() << endl;
	variable23->arrayPrinter();
	
	cout << endl << endl;

	CTable *variable22 = new CTable(*variable11);

	cout << endl << endl;

	CTable *new_variable = variable.pcClone();
	cout << new_variable->getsName() + "'s average: " << new_variable->getAvg() << endl;
	new_variable->arrayPrinter();


	cout << endl << endl;

	variable1->arrayPrinter();
	v_mod_tab(variable1, 10);
	cout << endl;
	variable1->arrayPrinter();
	variable1->setValue(3, 20);
	cout << endl;
	variable1->arrayPrinter();
	cout << endl << variable1->getsName() + "'s average: " << variable1->getAvg() << endl;

	cout << endl << endl;

	variable.arrayPrinter();
	v_mod_tab(variable, 2);
	cout << endl;
	variable.arrayPrinter();
	cout << endl;
	variable.setValue(3, 20);
	variable.arrayPrinter();
	variable.setValue(1, 20);
	cout << endl;
	variable1->arrayPrinter();
	cout << endl << variable1->getsName() + "'s average: " << variable1->getAvg() << endl;

	cout << variable.getsName();

	return 0;
}