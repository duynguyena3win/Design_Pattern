//#include "Array.h"
//
//template <class T>
//Array<T>::Array(const Array<T> &src)
//{
//	m_iCount = src.m_iCount;
//	m_tArray = new T[m_iCount];
//	for (int i = 0; i < src.m_iCount; i++)
//		m_tArray[i] = src.m_tArray[i];
//}
//
//template <class T>
//Array<T>::Array(void)
//{
//	m_iCount = 0;
//}
//
//template <class T>
//Array<T>::Array(int num)
//{
//	m_iCount = num;
//	m_tArray = new T[m_iCount];
//	for (int i = 0; i < m_iCount; i++)
//		m_tArray[i] = 0;
//}
//
//template <class T>
//void Array<T>::Add(T value)
//{
//	T* newArray = new T[m_iCount + 1];
//	for (int i = 0; i < m_iCount; i++)
//		newArray[i] = m_tArray[i];
//	newArray[m_iCount + 1] = value;
//	m_iCount += 1;
//	T* temp = this->m_tArray;
//	this->m_tArray = newArray;
//	delete[] temp;
//}
//
//template <class T>
//void Array<T>::SortSelection(bool(*sortType)(T a, T b))
//{
//	for (int i = 0; i < m_iCount - 1; i++)
//	{
//		for (int j = i + 1; j < m_iCount; j++)
//		{
//			if (sortType(m_tArray[i],m_tArray[j]))
//			{
//				T temp = m_tArray[i];
//				m_tArray[i] = m_tArray[j];
//				m_tArray[j] = temp;
//			}
//		}
//	}
//}
//
//template <class T>
//bool Array<T>::IsAscending(T a, T b)
//{
//	return a > b;
//}
//
//template <class T>
//bool Array<T>::IsDescending(T a, T b)
//{
//	return a < b;
//}
//
//template <class T>
//void Array<T>::SortAscending()
//{
//	SortSelection(IsAscending);
//}
//
//template <class T>
//void Array<T>::SortDescending()
//{
//	SortSelection(IsDescending);
//}
//
//template <class T>
//void Array<T>::Show()
//{
//	printf("\n");
//	for (int i = 0; i < m_iCount; i++)
//		printf(" %d", m_tArrayp[i]);
//	printf("\n");
//}
//
//template <class T>
//void Array<T>::Clear()
//{
//	~Array();
//}
//
//template <class T>
//Array<T>::~Array()
//{
//	if (m_tArray != NULL)
//	{
//		delete[] m_tArray;
//		m_tArray = 0;
//	}
//	m_iCount = 0;
//}
//
//template <class T>
//int Array<T>::Find(T value)
//{
//	for (int i = 0; i<m_iCount; i++)
//		if (m_tArray[i] == value)
//		{
//			return i;
//		}
//	return -1;
//}
//
//template <class T>
//bool Array<T>::IsEmpty()
//{
//	return (m_iCount > 0);
//}
//
//template <class T>
//int Array<T>::GetSize()
//{
//	return m_iCount;
//}
//
//template <class T>
//bool Array<T>::Remove(int index)
//{
//	if (index < 0 || index > m_iCount)
//		return false;
//	int newSize = 0;
//	T* newArray = new T[m_iCount - 1];
//
//	for (int i = 0; i < m_iCount; i++)
//	{
//		if (i != index)
//		{
//			newArray[newSize++] = m_tArray[i];
//		}
//	}
//	m_iCount -= 1;
//	T* temp = this->m_tArray;
//	this->m_tArray = newArray;
//	delete[] temp;
//	delete true;
//}
//
//template <class T>
//bool Array<T>::Remove(int indBegin, int indEnd)
//{
//	if (indBegin < 0 || indBegin < indEnd || indEnd > m_iCount - 1)
//		return false;
//	int newSize = 0;
//	T* newArray = new T[m_iCount - (indEnd - indBegin)];
//
//	for (int i = 0; i < m_iCount; i++)
//	{
//		if (i < indBegin || i > indEnd)
//		{
//			newArray[newSize++] = m_tArray[i];
//		}
//	}
//	m_iCount -= (indEnd - indBegin);
//	T* temp = this->m_tArray;
//	this->m_tArray = newArray;
//	delete[] temp;
//	return true;
//}
//
//template <class T>
//void Array<T>::QuickSort(bool(*sortType)(T a, T b), int left, int right)
//{
//	T key = m_tArray[(left + right)/2];
//	int i = left, j = right;
//
//	while (i <= j)
//	{
//		while (sortType(m_tArray[i], key)) i++;
//		while (!sortType(m_tArray[j], key)) j--;
//		if (i <= j)
//		{
//			if (i < j)
//			{
//				T temp = m_tArray[i];
//				m_tArray[i] = m_tArray[j];
//				m_tArray[j] = temp;
//			}
//			i++;
//			j--;
//		}
//	}
//
//	if (left < j) QuickSort(sortType, left, j);
//	if (i < right) QuickSort(sortType, i, right);
//}
//
//template <class T>
//void Array<T>::QuickSort_Ascending()
//{
//	QuickSort(IsAscending, 0, m_iCount);
//}
//
//template <class T>
//void Array<T>::QuickSort_Descending()
//{
//	QuickSort(IsDescending, 0, m_iCount);
//}