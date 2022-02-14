#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<vector>
#include<fstream> 


using namespace std;

void myoutput(vector<string> tab, string str)
{
	cout << str << endl;
	
	tab.push_back(str);
}
string BoolToStr(bool s) {
	
	if (s == true) return "1";
	
	else return "0";
}


int main()
{
	CFileLastError fs;

	fs.vOpenFile("Tasks.txt");

	vector<string> tab;

	////1
	CFileLastError test;

	test.vOpenFile("Task_A.txt");

	cout << test.bGetLastError() << endl;

	tab.push_back(BoolToStr(test.bGetLastError()));

	test.vPrintLine("Testing Line for A");

	cout << test.bGetLastError() << endl;

	tab.push_back(BoolToStr(test.bGetLastError()));

	test.vOpenFile("Task_A.1.1.txt");

	cout << test.bGetLastError() << endl;

	tab.push_back(BoolToStr(test.bGetLastError()));

	test.vPrintLine("Testing line for A.1.1");

	cout << test.bGetLastError() << endl;
	
	tab.push_back(BoolToStr(test.bGetLastError()));
	
	CFileLastError test6;
	
	test6.vPrintLine("Second Testing Line for A");
	
	cout << test6.bGetLastError() << endl;
	
	tab.push_back(BoolToStr(test6.bGetLastError()));
	
	//2
	
	CFileThrowEx test2;
	
	tab.push_back(test2.vOpenFile("Task_B.txt"));
	
	cout << tab[tab.size() - 1] << endl;
	
	tab.push_back(test2.vPrintLine("Testing Line for B"));
	
	cout << tab[tab.size() - 1] << endl;
	
	CFileThrowEx test3;
	
	tab.push_back(test3.vPrintLine("Second Testing Line for B"));
	
	cout << tab[tab.size() - 1] << endl;

	//3
	CFileErrCode test4;
	
	tab.push_back(BoolToStr(test4.vOpenFile("Task_C.txt")));
	
	cout << tab[tab.size() - 1] << endl;
	
	tab.push_back(BoolToStr(test4.vPrintLine("Testing Line for C")));
	
	cout << tab[tab.size() - 1] << endl;
	
	CFileErrCode test5;
	
	tab.push_back(BoolToStr(test5.vPrintLine("Second Testing Line for A")));
	
	cout << tab[tab.size() - 1] << endl;
	
	fs.vPrintManyLines(tab);


	return 0;
}