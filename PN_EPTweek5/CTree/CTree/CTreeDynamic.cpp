#include "pch.h"
#include "CTreeDynamic.h"
#include <algorithm>


using namespace std;

CTreeDynamic::CTreeDynamic(){

	pc_root = new CNodeDynamic();
}

void CTreeDynamic::vPrintTree(){

	pc_root->vPrintAllBelow();
	
	cout << "\n";
}

CTreeDynamic::~CTreeDynamic(){

	delete pc_root;
}

void CTreeDynamic::CNodeDynamic::vAddNewChild(){

	CNodeDynamic *pc_newNode = new CNodeDynamic();
	
	pc_newNode->pc_parent_node = this;
	
	v_children.push_back(pc_newNode);
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetChild(int iChildOffset){

	if ( ( iChildOffset < 0 ) || ( iChildOffset > iGetChildrenNumber() ) )	return NULL;
	
	else	return v_children.at(iChildOffset);
}

void CTreeDynamic::CNodeDynamic::vPrintAllBelow(){

	vPrint();

	if ( !v_children.empty() ){

		cout << " -> (";
	
		for (int i = 0; i < v_children.size(); i++)
		
			v_children.at(i)->vPrintAllBelow();
		
		cout << " )\t";
	}

}

void CTreeDynamic::CNodeDynamic::vPrintUp(){

	CNodeDynamic *pc_current = this;
	
	while (pc_current != NULL){

		pc_current->vPrint();
	
		pc_current = pc_current->pc_parent_node;
	}
}

vector<CTreeDynamic::CNodeDynamic*>* CTreeDynamic::CNodeDynamic::pGetChildren(){

	return &v_children;
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pGetParent(){

	return pc_parent_node;
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcFindRoot(){

	CNodeDynamic *pc_current = this;

	while (pc_current->pc_parent_node != NULL)
	
		pc_current = pc_current->pc_parent_node;
	
	return pc_current;
}

bool CTreeDynamic::bMoveSubtree(CTreeDynamic::CNodeDynamic *pcParentNode, CTreeDynamic::CNodeDynamic *pcNewChildNode){

	if (pcParentNode != NULL && pcNewChildNode != NULL && pcNewChildNode->pGetParent() != NULL && pcParentNode->pcFindRoot() != pcNewChildNode->pcFindRoot()){

		pcParentNode->pGetChildren()->push_back(pcNewChildNode);
	
		vector<CNodeDynamic*> *pc_children = pcNewChildNode->pGetParent()->pGetChildren();
		
		pc_children->erase(remove(pc_children->begin(), pc_children->end(), pcNewChildNode), pc_children->end());
		
		return true;
	}
	else return false;
}

int CTreeDynamic::iNodeAmount(){

	return iNodeAmountFrom(pc_root);
}

int CTreeDynamic::iNodeAmountFrom(CTreeDynamic::CNodeDynamic *pc_current){

	int value = 1;
	
	for (int i = 0; i < pc_current->pGetChildren()->size(); i++)
	
		value += iNodeAmountFrom(pc_current->pGetChildren()->at(i));
	
	return value;
}

CTreeDynamic::CNodeDynamic::~CNodeDynamic(){

	for (int i = 0; i < v_children.size(); i++)
	
		delete v_children.at(i);
	
}

CTreeDynamic::CNodeDynamic::CNodeDynamic() {
	
	i_val = 0; pc_parent_node = NULL;
}

void CTreeDynamic::CNodeDynamic::vSetValue(int iNewVal) { 
	
	i_val = iNewVal;
}

int CTreeDynamic::CNodeDynamic::iGetChildrenNumber() {
	
	return v_children.size(); 
}

void CTreeDynamic::CNodeDynamic::vPrint() {

	cout << " " << i_val;
}