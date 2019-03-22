#pragma once

template<typename T>
class CMergeSort
{
private:
	int m_nMid;
	T	* m_Temp;

public:
	CMergeSort();
	~CMergeSort();
	void operator=(const CMergeSort &) = delete;
	CMergeSort(const CMergeSort&) = delete;

public:
	void Sort(T * pArr, int nLeft, int nRight);
	
private:
	void Merge(T * pArr, int nLeft, int nMid, int nRight);
	void Release();

};
