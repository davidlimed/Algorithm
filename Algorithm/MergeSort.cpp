#include "stdafx.h"
#include "MergeSort.h"

template<typename T>
CMergeSort<T>::CMergeSort():
	m_nMid(0),
	m_Temp(nullptr)
{
}

template<typename T>
CMergeSort<T>::~CMergeSort()
{
	this->Release();
}

template<typename T>
void CMergeSort<T>::Sort(T * pArr, int nLeft, int nRight)
{
	if (nLeft >= nRight)
		return;
	
	m_nMid = ((nLeft + nRight) / 2);
	Sort(pArr, nLeft, m_nMid); // 왼쪽 분할
	Sort(pArr, m_nMid + 1, nRight); // 오른쪽 분할
	
	Merge(pArr, nLeft, m_nMid, nRight);
}

template<typename T>
void CMergeSort<T>::Merge(T * pArr, int nLeft, int nMid, int nRight)
{
	T * pTempArr = nullptr;

	int nLeftIdx = nLeft;
	int nTempIdx = nLeftIdx;
	int nRightIdx = nMid + 1;
	
	pTempArr = new T[nRight];

	while (nLeftIdx <= nMid && nRightIdx < nRight) // 합병
	{
		if ( pArr[nLeftIdx] < pArr[nRightIdx] )
			pTempArr[nTempIdx] = pArr[nLeftIdx++];
		else
			pTempArr[nTempIdx] = pArr[nRightIdx++];
	}

	//복사
	for (int i = 0; i < nRight; ++i)
	{
		pArr[i] = pTempArr[i];
	}

	delete[] pTempArr;
	pTempArr = nullptr;
}

template<typename T>
void CMergeSort<T>::Release()
{
	if (!m_Temp)
		return;

	delete[] m_Temp;
	m_Temp = nullptr;
}
