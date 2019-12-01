#include "pch.h"

#include "CTreeStatic.h"


CTreeStatic::CTreeStatic(){

}

void CTreeStatic::vPrintTree(){

	c_root.vPrintAllBelow();
}

CTreeStatic::~CTreeStatic(){

}

void CTreeStatic::CNodeStatic::vAddNewChild(){

	v_children.push_back( CNodeStatic() );

	v_children.back().pc_parent_node = this;
}

CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset){

	if ( ( iChildOffset < 0 ) || ( iChildOffset > iGetChildrenNumber() ) )	return NULL;
	
	else	return &v_children.at(iChildOffset);
}

void CTreeStatic::CNodeStatic::vPrintAllBelow(){

	vPrint();

	for (int i = 0; i < v_children.size(); i++)
	
		v_children.at(i).vPrintAllBelow();

	
}

void CTreeStatic::CNodeStatic::vPrintUp(){

	CNodeStatic *pc_current = this;
	
	while (pc_current != NULL){

		pc_current->vPrint();
	
		pc_current = pc_current->pc_parent_node;
	}
}

CTreeStatic::CNodeStatic::~CNodeStatic(){

}

CTreeStatic::CNodeStatic::CNodeStatic() {
	
	i_val = 0;
	
	pc_parent_node = NULL; 
}

void CTreeStatic::CNodeStatic::vSetValue(int iNewVal) {
	
	i_val = iNewVal; 
}

int CTreeStatic::CNodeStatic::iGetChildrenNumber() {
	
	return v_children.size();
}

void CTreeStatic::CNodeStatic::vPrint() {
	
	cout << " " << i_val; 
}

void CTreeStatic::CNodeStatic::v_tree_test()
{
	CNodeStatic c_root;
	
	c_root.vAddNewChild();
	
	c_root.vAddNewChild();
	
	c_root.pcGetChild(0)->vSetValue(1);
	
	c_root.pcGetChild(1)->vSetValue(2);
	
	c_root.pcGetChild(0)->vAddNewChild();
	
	c_root.pcGetChild(0)->vAddNewChild();
	
	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);

	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root.pcGetChild(1)->vAddNewChild();

	c_root.pcGetChild(1)->vAddNewChild();

	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);

	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
}