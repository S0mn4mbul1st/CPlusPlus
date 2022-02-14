#include <iostream>
#include <string>
#include "pch.h"

using namespace std;

CTable::CTable() {

	cout << "without: " + s_name << endl;

	arr = new int[stL] {};
}

CTable::CTable(string sName, int iTableLen) {

	if (iTableLen > 0) {

		stL = iTableLen; 

		s_name = sName;

		cout << "parameter: " + s_name << endl;

		delete arr;

		arr = new int[iTableLen] {};
	}

	else {
		stL = 0;

		return;
	}
}

CTable::CTable(CTable & pcOther) {

	if (pcOther.stL > 0) {

		stL = pcOther.stL;

		s_name = pcOther.s_name + "_copy";

	
		arr = new int [pcOther.stL];

		for (int i = 0; i < pcOther.stL; i++)

			arr[i] = pcOther.arr[i]; 

		cout << "copy: " + s_name << endl;
	}

	else {
		cout << "Error\n";

		return;
	}
}

int* CTable::getArr() {
	
	return arr;
}

CTable* CTable::pcClone() { 
	
	return this; 
}

string CTable::getsName() {

	return s_name;
}

bool CTable::bSetNewSize(int iTableLen) {

	if (iTableLen > 0) {

		stL = iTableLen;

		delete arr;

		arr = new int[iTableLen] {};

		return true;
	}

	else return false;
}

void CTable::vSetName(string sName) {

	s_name = sName;
}


CTable::~CTable() {
 
	delete[] arr;
}

bool CTable::setValue(int index, int val) {

	if ((index >= 0) && (index < stL))
	{
		arr[index] = val;

		return true;
	}

	else return false;
}

double CTable::getAvg() {

	if (stL < 1) return 0.0; 

	double avg = 0; 

	for (int i = 0; i < stL; i++)  avg += arr[i]; 

	avg /= stL; 

	return avg;
}

void v_mod_tab(CTable *pcTab, int iNewSize) {

	if (iNewSize < 0) return;

	pcTab->bSetNewSize(iNewSize);

}


void v_mod_tab(CTable cTab, int iNewSize) {

	
	if (iNewSize < 0) return;

	cTab.bSetNewSize(iNewSize) ;

}


void CTable::arrayPrinter() {

	if (stL > 0) {

		cout << s_name + "'s Array ->  ";

			for(int i = 0; i < stL; i++)

				cout << arr[i] << "    ";
	}

	else return;

}