#include "CNodeDynamic.h"
#include "CNodeDynamic.cpp"
#include "CTreeDynamic.cpp"
#include <iostream>
#include <string>
#include <algorithm>
#include "CTreeDynamic.h"

using namespace std;


int main()
{
    cout << "Trees of type String\n\n";
   
    

    CTreeDynamic<string> tree1;

    CTreeDynamic<string> tree2;

    //first tree
    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(0)->vSetValue("a");
    tree1.pcGetRoot()->pcGetChild(1)->vSetValue("b");
    tree1.pcGetRoot()->pcGetChild(2)->vSetValue("c");
    tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue("kk");

    cout << " Children of 1st tree  =\n";
    tree1.pcGetRoot()->pcGetChild(2)->vPrintAllBelow(); cout << endl;

    //second tree
    tree2.pcGetRoot()->vSetValue("d");
    tree2.pcGetRoot()->vAddNewChild();
    tree2.pcGetRoot()->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->vSetValue("qq");
    tree2.pcGetRoot()->pcGetChild(1)->vSetValue("hh");
    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("k");
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("l");
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue("m");

    cout << "\n Children of 2nd tree  =\n";
    tree2.pcGetRoot()->vPrintAllBelow();

    std::cout << "\n\nTree1 has size before move = " << tree1.countTreeSize() << std::endl;
    std::cout << "Tree2 has size before move = " << tree2.countTreeSize() << std::endl;

    tree1.bMoveSubtree((&tree1)->pcGetRoot()->pcGetChild(2), (&tree2)->pcGetRoot()->pcGetChild(0), (&tree2)->pcGetRoot());


    cout << "\n\n Move trees\n";

    cout << "\n Children  =\n";
    tree1.pcGetRoot()->pcGetChild(2)->vPrintAllBelow();

    cout << "\n\n Children  =\n";
    tree2.pcGetRoot()->vPrintAllBelow(); cout << endl;

    std::cout << "\nTree1 has size after move = " << tree1.countTreeSize() << std::endl;
    std::cout << "Tree1 has size after move = " << tree2.countTreeSize() << std::endl;
  
    
    cout << "Trees of type Double\n\n";
    CTreeDynamic<double> tree3, tree4;

    //first tree
    tree3.pcGetRoot()->vAddNewChild();
    tree3.pcGetRoot()->vAddNewChild();
    tree3.pcGetRoot()->vAddNewChild();
    tree3.pcGetRoot()->pcGetChild(0)->vSetValue(1.1);
    tree3.pcGetRoot()->pcGetChild(1)->vSetValue(2.4);
    tree3.pcGetRoot()->pcGetChild(2)->vSetValue(1.12);
    tree3.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    tree3.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(1.1);

    cout << " Children 0(3) =\n";
    tree3.pcGetRoot()->pcGetChild(2)->vPrintAllBelow(); cout << endl;

    //second tree
    tree4.pcGetRoot()->vSetValue(0.4);
    tree4.pcGetRoot()->vAddNewChild();
    tree4.pcGetRoot()->vAddNewChild();
    tree4.pcGetRoot()->pcGetChild(0)->vSetValue(22.2);
    tree4.pcGetRoot()->pcGetChild(1)->vSetValue(333.33);
    tree4.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree4.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(0.54);
    tree4.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(21.43);
    tree4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    tree4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(9.54);

    cout << "\n Children 10 =:\n";
    tree4.pcGetRoot()->vPrintAllBelow();


    tree3.bMoveSubtree((&tree3)->pcGetRoot()->pcGetChild(2), (&tree4)->pcGetRoot()->pcGetChild(0), (&tree4)->pcGetRoot());


    cout << "\n\n Move trees\n";

    cout << "\n Children 0(3) =\n";
    tree3.pcGetRoot()->pcGetChild(2)->vPrintAllBelow();

    cout << "\n\n Children 10 =\n";
    tree4.pcGetRoot()->vPrintAllBelow(); cout << endl;
    
    
    cout << "Trees of type Int\n\n";
    CTreeDynamic<int> treea, treeb;

    //first tree
    treea.pcGetRoot()->vAddNewChild();
    treea.pcGetRoot()->vAddNewChild();
    treea.pcGetRoot()->vAddNewChild();
    treea.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    treea.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    treea.pcGetRoot()->pcGetChild(2)->vSetValue(3);
    treea.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    treea.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    cout << " Children 0(3) =\n";
    treea.pcGetRoot()->pcGetChild(2)->vPrintAllBelow(); cout << endl;

    //second tree
    treeb.pcGetRoot()->vSetValue(10);
    treeb.pcGetRoot()->vAddNewChild();
    treeb.pcGetRoot()->vAddNewChild();
    treeb.pcGetRoot()->pcGetChild(0)->vSetValue(14);
    treeb.pcGetRoot()->pcGetChild(1)->vSetValue(15);
    treeb.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    treeb.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    treeb.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(16);
    treeb.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(17);
    treeb.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    treeb.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(18);

    cout << "\n Children 10 =\n";
    treeb.pcGetRoot()->vPrintAllBelow();


    treea.bMoveSubtree(treea.pcGetRoot()->pcGetChild(2), treeb.pcGetRoot()->pcGetChild(0), treeb.pcGetRoot());


    cout << "\n\n Move trees\n";

    cout << "\n Children 0(3)=\n";
    treea.pcGetRoot()->pcGetChild(2)->vPrintAllBelow();

    cout << "\n\n Children 10 =\n";
    treeb.pcGetRoot()->vPrintAllBelow(); cout << endl;
}


