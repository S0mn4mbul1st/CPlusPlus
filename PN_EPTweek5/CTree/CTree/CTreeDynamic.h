#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CTreeDynamic{

public:

	class CNodeDynamic{

	public:
		
		CNodeDynamic();

		void vSetValue(int iNewVal);
		
		int iGetChildrenNumber();
		
		void vAddNewChild();
		
		CNodeDynamic *pcGetChild(int iChildOffset);

		void vPrint();
		
		void vPrintAllBelow();
		
		void vPrintUp();
		
		vector<CNodeDynamic*>* pGetChildren();
		
		CNodeDynamic* pGetParent();
		
		CNodeDynamic* pcFindRoot();

		virtual ~CNodeDynamic();

	private:

		vector<CNodeDynamic*> v_children;

		CNodeDynamic *pc_parent_node;

		int i_val;
	};

public:

	CTreeDynamic();

	CNodeDynamic *pcGetRoot() { 
		
		return pc_root;
	}

	void vPrintTree();

	static bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);

	int iNodeAmount();

    ~CTreeDynamic();

private:

	int iNodeAmountFrom(CNodeDynamic *pc_current);

	CNodeDynamic *pc_root;
};