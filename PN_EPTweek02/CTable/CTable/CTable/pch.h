#ifndef PCH_H
#define PCH_H
#include <iostream>

using namespace std;


class CTable {

private:

	string s_name = "Admin";

	int *arr;
	
    int stL = 0;

public:

	CTable();

	CTable(string sName, int iTableLen);

	CTable(CTable & pcOther);

	~CTable();

	void vSetName(string sName);

	bool bSetNewSize(int iTableLen);

	string getsName();

	CTable* pcClone();

	int* getArr();

	bool setValue(int index, int val);

	double getAvg();

	void arrayPrinter();
};


void v_mod_tab(CTable *pcTab, int iNewSize);

void v_mod_tab(CTable cTab, int iNewSize);

#endif //PCH_H
