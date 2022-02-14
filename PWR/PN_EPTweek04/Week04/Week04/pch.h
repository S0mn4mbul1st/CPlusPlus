#ifndef PCH_H
#define PCH_H
#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
#include <atlstr.h>

using namespace std;


class CFileLastError {

private: 


	FILE *pf_file; 

	bool b_last_error; 

	string s_Name = ""; 

public: 
	
	CFileLastError();
	
	CFileLastError(string sFileName);
	
	~CFileLastError();

	void vOpenFile(string sFileName);
	
	void vPrintLine(string sText);
	
	void vPrintManyLines(vector<string> sText);

	bool bGetLastError();
};

class CFileThrowEx
{
public:
	CFileThrowEx();
	CFileThrowEx(string sFileName);
	~CFileThrowEx();
	string vOpenFile(string sFileName);
	string vPrintLine(string sText);
	void vPrintManyLines(vector<string> sText);
private:
	FILE *pf_file;
	string s_Name;
};

class CFileErrCode {

private:

	FILE *pf_file;

	string s_Name;

public:

	CFileErrCode();

	CFileErrCode(string sFileName);

	~CFileErrCode();

	bool vOpenFile(string sFileName);

	bool vPrintLine(string sText);

	bool vPrintManyLines(vector<string> sText);

};
#endif 


/* CString objects can grow as a result of concatenation operations.
CString objects follow "value semantics." Think of a CString object as an actual string, not as a pointer to a string.
You can freely substitute CString objects for const char* and LPCTSTR function arguments.
A conversion operator gives direct access to the string's characters as a read-only array of characters (a C-style string)*/