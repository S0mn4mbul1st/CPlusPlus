#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CTreeStatic{

public:

	class CNodeStatic{

	public:

		CNodeStatic();

		void vSetValue(int iNewVal);

		int iGetChildrenNumber();

		void vAddNewChild();

		CNodeStatic *pcGetChild(int iChildOffset);

		void vPrint();

		void vPrintAllBelow();

		void vPrintUp();

		void v_tree_test();

		~CNodeStatic();

	private:

		vector<CNodeStatic> v_children;

		CNodeStatic *pc_parent_node;

		int i_val;
	};

public:

	CTreeStatic();

	CNodeStatic* pcGetRoot() {

		return &c_root;
	}

	void vPrintTree();

	virtual ~CTreeStatic();

private:

	CNodeStatic c_root;
};

