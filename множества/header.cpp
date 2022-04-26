#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "header.h"
#include "stddef.h"

using namespace std;

int const n = 100;

/*
Set::Set(const Set &X):size1(X.size1)                   // Set::Set(const Set &X):size1(X.size1),mas(new int[size1])
{
    mas = new int[size1];
    for(int i = 0; i < size1; i++)
        mas[i] = X.mas[i];
*/


Set::~Set()
{
   //delete[]mas;
   size1 = 0;
}

void Set::Vvod()
{
    int elem;
    int k = 0;
    cout << "¬ведите размер множества: ";
    cin >> size1;
    for(int i = 0; i < size1; i++)
    {
        k = 0;
        cout << "¬ведите число: ";
        cin >> elem;

        while((elem != mas[k])and(k <= size1))  // <=
        {
            k += 1;
        }

        if(k > size1) // k > size1
            mas[i] = elem;
        else
        {
            i -= 1;
            size1 -= 1;  // возможно стоит здесь и в for работать с копией size1
        }

    }
}

void Set::Vivod()
{
    for(int k = 0; k < size1; k++)
    {
        cout << "mas[" << k << "] = " << mas[k] << endl;
    }
}

// посмотреть выделение пам€ти массива
void Set::Add(int elem)
{
    int k = 0;

    if(size1 == 0)
    {
        size1 += 1;
        cout << "222 size1: " << size1 << endl;
        mas[0] = elem;  // mas[k]
        k += 1;
    }
    else
    {
        //while((elem != mas[k])and(k < size1))  // k < size1
        //{
        //    k += 1;
        //}

		while(k < size1)
        {
            if(elem == mas[k])
                break;
            k += 1;
        }

        if(k >= size1)  //   elem == mas[k]
        {
            size1 += 1;
            //k += 1;  //
            cout << "223 size1: " << size1 << endl;
            mas[k] = elem;
        }
    }
    //Vivod();
}

void Set::Poisk(int chisl)
{
    int k = 0;
    int index;

    //while((k < size1)and(mas[k] != chisl))
    //{
    //    k += 1;
    //}

    while(k < size1)
    {
        if(mas[k] == chisl)
            break;
        k += 1;
    }

    if(mas[k] == chisl)
    {
        index = k;
        cout << "Ёто число есть во множестве" << endl;
        cout << "≈го индекс: " << index << endl;
    }
    else
    {
        cout << "“акого числа нет во множестве" << endl;
    }
}

void Set::Del(int chisl)    // если будет надо сделать что-то с последниим элементом массива, так как он не удал€етс€ а просто не читаетс€ прогой
{
    int k = 0;
    int index;

    //while((k < size1)and(mas[k] != chisl))
    //{
    //    k += 1;
    //}

    while(k < size1)
    {
        if(mas[k] == chisl)
            break;
        k += 1;
    }

    if(mas[k] == chisl)
    {
        index = k;
        for(int j = index; j < size1-1; j++)
        {
            mas[j] = mas[j+1];
        }
        //mas[size1] = 0; // если будут проблемы - удалить
        size1 -= 1;
    }
}

// операторные функции не всегда верно работают
Set operator&(Set& A,Set& B)
{
    int i;
    int j;
    int elem;
    Set P;
    cout << "P.size1: " << P.size1 << endl;

    cout << "A.size1: " << A.size1 << endl;
    cout << "B.size1: " << B.size1 << endl;
    for(int k = 0; k < A.size1; k++)
    {
        elem = A.mas[k];
        cout << "k: " << k << endl;
        cout << "333 elem: " << elem << endl;
        P.Add(elem);
        cout << "P.size1: " << P.size1 << endl;
    }


    bool flag;
    for(int j = 0; j < B.size1; j++)
    {
        flag = false;
        for(int i = 0; i < A.size1; i++)
        {
            cout << "j: " << j << endl;
            cout << "i: " << i << endl;
            if(B.mas[j] == A.mas[i])
            {
                flag = true;
                cout << "true " << endl;
                break;
            }
        }
        if(flag == false)
        {
            elem = B.mas[j];
            cout << "B.mas[j]: " << B.mas[j] << endl;
            P.Add(elem);
            cout << "P.size1: " << P.size1 << endl;
        }
    }

    P.Vivod();
    cout << "------------" << endl;
    cout << "P.size1: " << P.size1 << endl;
    return P;

}

// проблемы с считванием последнего элемента в пересечении
Set operator|(Set& A,Set& B)
{
    int i = 0;
    int j = 0;
    int elem;
    Set C;
    cout << "A.size1: " << A.size1 << endl;
    cout << "B.size1: " << B.size1 << endl;
    cout << "C.size1: " << C.size1 << endl;

    bool flag;
    for(int j = 0; j < B.size1; j++)
    {
        flag = false;
        for(int i = 0; i < A.size1; i++)
        {
            cout << "j: " << j << endl;
            cout << "i: " << i << endl;
            if(B.mas[j] == A.mas[i])
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            elem = B.mas[j];
            cout << "B.mas[j]: " << B.mas[j] << endl;
            C.Add(elem);
            cout << "C.size1: " << C.size1 << endl;
        }
    }

    C.Vivod();
    cout << "C.size1: " << C.size1 << endl;
    return C;
}






