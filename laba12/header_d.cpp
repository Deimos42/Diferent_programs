#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstdio>
#include <iomanip>

#include "head_d.h"

using namespace std;

// ����������� �� ���������
template<typename T>
Dek<T>::Dek(int sizeDek) :
    size(sizeDek), // ������������� ���������
    begin(0), end(0), elemCT(0)
{
    // �������������� ������ ������� ��� ��������� ����� � ������ �������
    dekPtr = new T[size +  1];
}

// ����������� �����������
template<typename T>
Dek<T>::Dek(const Dek &otherDek) :
    size(otherDek.size) , begin(otherDek.begin),
    end(otherDek.end), elemCT(otherDek.elemCT),
    dekPtr(new T[size + 1])
{
    for (int ix = 0; ix < size; ix++)
        dekPtr[ix] = otherDek.dekPtr[ix]; // �������� ���
}

template<typename T>
Dek<T>::~Dek()
{
    delete [] dekPtr;
}

template<typename T>
void Dek<T>::endek(const T &newElem)
{
    // ���������, ���� �� ��������� ����� � ����
    assert(elemCT < size);

    // �������� �������� �� ��, ��� ��� �������� ����������� � 0 �������
    dekPtr[end++] = newElem;

    elemCT++;

    // �������� ��������� ���������� ����
    if (end > size)
        end -= size + 1; // ���������� end �� ������ ����
}

template<typename T>
void Dek<T>::indek(const T &newElem)  // ��������
{
    char val;
    val = newElem;
    assert(elemCT < size);

    for(int i = end; i > 0; i--)
        dekPtr[i] = dekPtr[i-1];

    dekPtr[begin] = val; // dekPtr[0]

    elemCT++;


    if (end > size)
        end -= size + 1;
}

// ������� �������� �������� �� ������ ����
template<typename T>
T Dek<T>::dedek()
{
    // ���������, ���� �� � ���� ��������
    assert(elemCT > 0);

    T returnValue = dekPtr[begin++];
    elemCT--;

    // �������� ��������� ���������� ����
    if (begin > size)
        begin -= size + 1; // ���������� behin �� ������ ����

    return returnValue;
}

// ������� �������� �������� �� ����� ����
template<typename T>
T Dek<T>::didek()
{
    assert(elemCT > 0);

    T returnValue = dekPtr[end--];
    elemCT--;

    if (end < 0)
        end += size + 1;

    return returnValue;
}


template<typename T>
T Dek<T>::dydek()
{
    int iLast;
    assert(elemCT > 0);
    if (end >= size)
        size = end;
    else
        iLast = end - begin + 1;
    for(int i = begin; i < end-iLast; i++)
    {
        dekPtr[i] = dekPtr[i+iLast];
    }
    dekPtr[end] = dekPtr[end-iLast];

    T returnValue = dekPtr[end-iLast];

    return returnValue;
}


template<typename T>
void Dek<T>::printDek()
{
    cout << "���: ";

    if (end == 0 && begin == 0)
        cout << " ������\n";
    else
    {
        for (int ix = end; ix >= begin; ix--)
            cout << dekPtr[ix] << " ";
        cout << endl;
    }
}

template<typename T>
T Dek<T>::redek()
{
    assert(elemCT > 0);
    T returnValue = dekPtr[begin];

    return returnValue;
}

template<typename T>
T Dek<T>::ridek()
{
    assert(elemCT > 0);
    T returnValue = dekPtr[end];

    return returnValue;
}


template<typename T>
T Dek<T>::sredek(int z)
{
    assert(elemCT > 0);

    T returnValue = dekPtr[begin+z];

    return returnValue;
}
