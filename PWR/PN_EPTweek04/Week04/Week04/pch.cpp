// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
#include <atlstr.h>

using namespace std;


CFileLastError:: CFileLastError() {
	
	b_last_error = false;
	
	pf_file = NULL;

	s_Name = "";

}

CFileLastError:: CFileLastError(string sFileName) {

	b_last_error = false;

	vOpenFile(sFileName);
}

CFileLastError:: ~CFileLastError() {

	if (pf_file != NULL)	fclose(pf_file);

}

void CFileLastError::vPrintLine(string sText) {

	b_last_error = false;
	
	if (pf_file == NULL)  b_last_error = true;
	
	else fprintf(pf_file, sText.c_str());

}

void CFileLastError::vPrintManyLines( vector<string> sText ) {

	for (int i = 0; ( i < sText.size() ); i++)
	{
		vPrintLine(sText[i]);
		
		vPrintLine("\n");
	}
}

bool CFileLastError::bGetLastError() {

	return b_last_error;
}

void CFileLastError::vOpenFile(string sFileName)
{
	b_last_error = false;
	
	if (pf_file != NULL)	fclose(pf_file);

	pf_file = fopen( sFileName.c_str() , "w+" );
	
	s_Name = sFileName;
	
	if (pf_file == NULL)	b_last_error = true;

	else	b_last_error = false;

}

//********************************************************************************************************************************************************

CFileThrowEx:: CFileThrowEx() {
	
	pf_file = NULL;
	
	s_Name = "";

}

CFileThrowEx:: CFileThrowEx(string sFileName) {

	vOpenFile(sFileName);
}

CFileThrowEx:: ~CFileThrowEx() {

	if (pf_file != NULL)	fclose(pf_file);

}

string CFileThrowEx::vOpenFile(string sFileName) {

	try
	{
		pf_file = fopen(sFileName.c_str(), "w+");
	
		if (pf_file == NULL) throw 0;
	}
	catch (int e)
	{
		return "It's wrong\n";
	}
	
	s_Name = sFileName;
	
	return "It's good\n";

}

string CFileThrowEx::vPrintLine(string sText) {

	try
	{
		if (pf_file == NULL) throw 0;
	
		fprintf(pf_file, sText.c_str());
	}
	catch (int e)
	{
		return "File not open\n";
	}
	return "Line saved\n";

}

void CFileThrowEx::vPrintManyLines(vector<string> sText) {

	for (int i = 0; i < sText.size(); i++)	vPrintLine(sText[i]);

}

//********************************************************************************************************************************************************

CFileErrCode::CFileErrCode()
{
	pf_file = NULL;

	s_Name = "";
}

CFileErrCode::CFileErrCode(string sFileName)
{
	vOpenFile(sFileName);
}

CFileErrCode::~CFileErrCode()
{
	if (pf_file != NULL)	fclose(pf_file);
		
}

bool CFileErrCode::vOpenFile(string sFileName){

	pf_file = fopen(sFileName.c_str(), "w+");

	if (pf_file == NULL) return false;

	s_Name = sFileName;

	return true;
}

bool CFileErrCode::vPrintLine(string sText)
{
	if (pf_file == NULL)	return false;

	else
	{
		fprintf(pf_file, sText.c_str());
	
		return true;
	}

}

bool CFileErrCode::vPrintManyLines(vector<string> sText)
{
	for (int i = 0; i < sText.size(); i++)
	
		if (vPrintLine(sText[i]) == false) 	return false;
		
	return true;
}