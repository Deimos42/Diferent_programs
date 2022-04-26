#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include "header.h"

using namespace std;

// конструктор
template <typename T>
Stack<T>::Stack(int s)
{
    size = s > 0 ? s: 10;   // инициализировать размер стека
    stackPtr = new T[size]; // выделить память под стек
    top = -1; // значение -1 говорит о том, что стек пуст
}

// деструктор
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; // удаляем стек
}

// элемент функция класса  Stack для помещения элемента в стек
// возвращаемое значение - true, операция успешно завершена
//                                    false, элемент в стек не добавлен
template <typename T>
bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false; // стек полон

    top++;
    stackPtr[top] = value; // помещаем элемент в стек

    return true; // успешное выполнение операции
}

// элемент функция класса  Stack для удаления элемента из стек
// возвращаемое значение - true, операция успешно завершена
//                                    false, стек пуст
template <typename T>
bool Stack<T>::pop()
{
    if (top == - 1)
        return false; // стек пуст

    stackPtr[top] = 0; // удаляем элемент из стека
    top--;

    return true; // успешное выполнение операции
}

template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
  assert(nom <= top);
  //cout << "вершина: "<< top << endl;

  return stackPtr[top - nom];
}


// вывод стека на экран
template <typename T>
void Stack<T>::printStack()
{
    for (int ix = size -1; ix >= 0; ix--)
        cout << stackPtr[ix] << endl;
}


