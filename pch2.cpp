// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"

bool b_alloc_table_2_dim(int **&piTable, int iSizeX, int iSizeY) {

	if ((iSizeX < 0) || (iSizeY < 0)) return false;

	piTable = new int*[iSizeX];

	for (int i = 0; i < iSizeX; i++)

		piTable[i] = new int[iSizeY];

	return true;
}

// In general, ignore this file, but keep it around if you are using pre-compiled headers.
