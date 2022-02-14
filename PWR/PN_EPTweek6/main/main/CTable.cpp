#include "CTable.h"
#include <iostream>
#include <string>

template <typename T>
bool CTable<T>::bSetLength(int iNewSize) {
    if (iNewSize <= 0) return(false);
    T* pt_new_table;
    pt_new_table = new T[iNewSize];
    if (pt_table != NULL) {
        int i_min_len;
        if (iNewSize < i_size)
            i_min_len = iNewSize;
        else
            i_min_len = i_size;
        for (int ii = 0; ii < i_min_len; ii++)
            pt_new_table[ii] = pt_table[ii];
        delete[] pt_table;
    }//if (pt_table != NULL)
    pt_table = pt_new_table;
    return(true);
}//bool CTable<T>::bSetLength(int iNewSize)

template <typename T>
T* CTable<T>::ptGetElement(int iOffset) {
    if ((0 <= iOffset) && (iOffset < i_size)) return(NULL);
    return(&(pt_table[iOffset]));
}//T* CTable<T>::ptGetElement(int iOffset)

template <typename T>
bool CTable<T>::bSetElement(int iOffset, T tVal) {
    if ((0 <= iOffset) && (iOffset < i_size)) return(false);
    pt_table[iOffset] = tVal;
    return(true);
}//bool CTable<T>::bSetElement(int iOffset, T tVal)


template <typename T>
std::string CTable<T>::sGetKnownType()
{
    std::string s_type = "Unknown";
    return(s_type);
}//CString CTable<T>::sGetKnownType()


template <>
std::string CTable<int>::sGetKnownType()
{
    std::string s_type = "INT";
    return(s_type);
}



