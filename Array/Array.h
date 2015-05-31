#pragma once
#include <stdio.h>

template <class T>
class Array
{
private:
	T* m_tArray;
	int m_iCount;
public:
	Array(void) : m_tArray(0), m_iCount(0) {}

	Array(const Array<T> &src)
	{
		m_iCount = src.m_iCount;
		m_tArray = new T[m_iCount];
		for (int i = 0; i < src.m_iCount; i++)
			m_tArray[i] = src.m_tArray[i];
	}

	Array(int num) : m_iCount(num)
	{
		m_tArray = new T[m_iCount];
		for (int i = 0; i < m_iCount; i++)
			m_tArray[i] = 0;
	}

	void Add(T value)
	{
		T* newArray = new T[m_iCount + 1];
		for (int i = 0; i < m_iCount; i++)
			newArray[i] = m_tArray[i];
		newArray[m_iCount] = value;
		m_iCount += 1;
		if (m_tArray != NULL)
			delete[] m_tArray;
		m_tArray = newArray;
	}

	void SortAscending() { SortSelection(IsAscending); }

	void SortDescending() { SortSelection(IsDescending); }

	void QuickSort_Ascending() { QuickSort(IsAscending, 0, m_iCount); }

	void QuickSort_Descending() { QuickSort(IsDescending, 0, m_iCount); }
	
	int Find(T value)
	{
		for (int i = 0; i<m_iCount; i++)
			if (m_tArray[i] == value)
			{
				return i;
			}
		return -1;
	}
	
	int GetSize() { return m_iCount; }

	bool Remove(int index)
	{
		if (index < 0 || index >= m_iCount)
			return false;
		int newSize = 0;
		T* newArray = new T[m_iCount - 1];

		for (int i = 0; i < m_iCount; i++)
		{
			if (i != index)
			{
				newArray[newSize++] = m_tArray[i];
			}
		}
		m_iCount -= 1;
		if (m_tArray != NULL)
			delete[] m_tArray;
		m_tArray = newArray;
		return true;
	}

	bool Remove(int indBegin, int indEnd)
	{
		if (indBegin < 0 || indBegin > indEnd || indEnd > m_iCount - 1)
			return false;
		int newSize = 0;
		T* newArray = new T[m_iCount - (indEnd - indBegin + 1)];

		for (int i = 0; i < m_iCount; i++)
		{
			if (i < indBegin || i > indEnd)
			{
				newArray[newSize++] = m_tArray[i];
			}
		}
		m_iCount -= (indEnd - indBegin + 1);
		if (m_tArray != NULL)
			delete[] m_tArray;
		m_tArray = newArray;
		return true;
	}

	void Show()
	{
		printf("\n");
		for (int i = 0; i < m_iCount; i++)
			printf(" %d", m_tArray[i]);
		printf("\n");
	}

	void Clear() { this->~Array(); }

	bool IsEmpty() { return (m_iCount == 0); }

	~Array()
	{
		if (m_tArray != NULL)
		{
			delete[] m_tArray;
			m_tArray = 0;
		}
		m_iCount = 0;
	}
private:
	bool IsAscending(T a, T b) { return a > b; }
	
	bool IsDescending(T a, T b) { return b > a; }

	void SortSelection(bool(*sortType)(T a, T b))
	{
		for (int i = 0; i < m_iCount - 1; i++)
		{
			for (int j = i + 1; j < m_iCount; j++)
			{
				if (sortType(m_tArray[i], m_tArray[j]))
				{
					T temp = m_tArray[i];
					m_tArray[i] = m_tArray[j];
					m_tArray[j] = temp;
				}
			}
		}
	}

	void QuickSort(bool(*sortType)(T a, T b), int left, int right)
	{
		T key = m_tArray[(left + right) / 2];
		int i = left, j = right;

		while (i <= j)
		{
			while (sortType(m_tArray[i], key)) i++;
			while (!sortType(m_tArray[j], key)) j--;
			if (i <= j)
			{
				if (i < j)
				{
					T temp = m_tArray[i];
					m_tArray[i] = m_tArray[j];
					m_tArray[j] = temp;
				}
				i++;
				j--;
			}
		}

		if (left < j) QuickSort(sortType, left, j);
		if (i < right) QuickSort(sortType, i, right);
	}
};

