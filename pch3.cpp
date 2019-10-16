// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"


bool b_alloc_table_2_dim(int **& piTable, int iSizeX, int iSizeY) {

	if ((iSizeX < 0) || (iSizeY < 0)) return false;

	piTable = new int*[iSizeX];

	for (int i = 0; i < iSizeX; i++)

		piTable[i] = new int[iSizeY];

	return true;

}


bool b_dealloc_table_2_dim(int **& piTable, int iSizeX, int iSizeY) {

	if (iSizeX < 0 || iSizeY < 0) return false;

	for (int i = 0; i < iSizeX; i++) {

		delete[]  piTable[i];
	}

	delete[] piTable;

	return true;

}