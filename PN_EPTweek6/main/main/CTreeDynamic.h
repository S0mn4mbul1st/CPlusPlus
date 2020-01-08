#pragma once
#include "CNodeDynamic.h"

template <typename T>
class CTreeDynamic
{
public:
    CTreeDynamic() { c_root = new CNodeDynamic<T>(); };
    ~CTreeDynamic() { c_root->~CNodeDynamic(); delete c_root; };
    CNodeDynamic<T>* pcGetRoot() { return c_root; };
    void vPrintTree() { (*c_root).vPrintAllBelow(); };
    bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode, CNodeDynamic<T>* childParentNode);
    int countTreeSize();
    int countTreeSum();
    int countTreSum();
    int pcGetChild(int i);
    int iGetChildrenNumber() {

        return c_root.size();
    }
protected:
    int CTSHelper(CNodeDynamic<T>* Node);
    int CTSHelp(CNodeDynamic<T>* Node);
private:
    int cSize;
    int sum;
    T i_val;
    CNodeDynamic<T>* c_root;

};

