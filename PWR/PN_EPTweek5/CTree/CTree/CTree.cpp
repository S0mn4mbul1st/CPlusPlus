#include "pch.h"
#include "CTreeDynamic.h"
#include "CTreeStatic.h"
#include <iostream>

int main()
{
	CTreeStatic::CNodeStatic s_var; 

	CTreeDynamic::CNodeDynamic d_var; 

	s_var.vAddNewChild();

	s_var.vAddNewChild();

	s_var.pcGetChild(0)->vSetValue(1);

	s_var.pcGetChild(1)->vSetValue(2);

	s_var.pcGetChild(0)->vAddNewChild();

	s_var.pcGetChild(0)->vAddNewChild();

	s_var.pcGetChild(0)->pcGetChild(0)->vSetValue(11);

	s_var.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	s_var.pcGetChild(1)->vAddNewChild();

	s_var.pcGetChild(1)->vAddNewChild();

	s_var.pcGetChild(1)->pcGetChild(0)->vSetValue(21);

	s_var.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	s_var.vPrintAllBelow(); 


	cout << endl << endl;


	d_var.vAddNewChild();

	d_var.vAddNewChild();

	d_var.pcGetChild(0)->vSetValue(1);

	d_var.pcGetChild(1)->vSetValue(2);

	d_var.pcGetChild(0)->vAddNewChild();

	d_var.pcGetChild(0)->vAddNewChild();

	d_var.pcGetChild(0)->pcGetChild(0)->vSetValue(11);

	d_var.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	d_var.pcGetChild(1)->vAddNewChild();

	d_var.pcGetChild(1)->vAddNewChild();

	d_var.pcGetChild(1)->pcGetChild(0)->vSetValue(21);

	d_var.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	d_var.vPrintAllBelow();

	cout << endl << endl;

	return 0;
}