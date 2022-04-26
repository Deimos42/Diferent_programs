#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include "header.h"

using namespace std;

// �����������
template <typename T>
Stack<T>::Stack(int s)
{
    size = s > 0 ? s: 10;   // ���������������� ������ �����
    stackPtr = new T[size]; // �������� ������ ��� ����
    top = -1; // �������� -1 ������� � ���, ��� ���� ����
}

// ����������
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; // ������� ����
}

// ������� ������� ������  Stack ��� ��������� �������� � ����
// ������������ �������� - true, �������� ������� ���������
//                                    false, ������� � ���� �� ��������
template <typename T>
bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false; // ���� �����

    top++;
    stackPtr[top] = value; // �������� ������� � ����

    return true; // �������� ���������� ��������
}

// ������� ������� ������  Stack ��� �������� �������� �� ����
// ������������ �������� - true, �������� ������� ���������
//                                    false, ���� ����
template <typename T>
bool Stack<T>::pop()
{
    if (top == - 1)
        return false; // ���� ����

    stackPtr[top] = 0; // ������� ������� �� �����
    top--;

    return true; // �������� ���������� ��������
}

template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
  assert(nom <= top);
  //cout << "�������: "<< top << endl;

  return stackPtr[top - nom];
}


// ����� ����� �� �����
template <typename T>
void Stack<T>::printStack()
{
    for (int ix = size -1; ix >= 0; ix--)
        cout << stackPtr[ix] << endl;
}


