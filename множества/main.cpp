#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
#include "header.h"

using namespace std;

int main()
{
    int chisl;
    int elem;
    setlocale(LC_ALL,"rus");
    Set A;
    Set B;
    int Asize;
    int Bsize;

    cout << "Ввод и вывод 1 множества: " << endl;

    cout << "Введите размер множества: ";
    cin >> Asize;
    for(int i = 0; i < Asize; i++)
    {
        cout << "Добавление числа к 1 множеству: " << endl;
        cout << "Введите число: ";
        cin >> elem;
        A.Add(elem);
    }
    //A.Vvod();
    A.Vivod();

    cout << "Ввод и вывод 2 множества: " << endl;

    cout << "Введите размер множества: ";
    cin >> Bsize;
    for(int i = 0; i < Bsize; i++)
    {
        cout << "Добавление числа к 1 множеству: " << endl;
        cout << "Введите число: ";
        cin >> elem;
        B.Add(elem);
    }
    //B.Vvod();
    B.Vivod();

    /*
    cout << "Добавление числа к 1 множеству: " << endl;
    cout << "Введите число: ";
    cin >> elem;
    A.Add(elem);
    A.Vivod();

    cout << "Добавление числа к 2 множеству: " << endl;
    cout << "Введите число: ";
    cin >> elem;
    B.Add(elem);
    B.Vivod();

    cout << "Введите число наличие которого хотите проверить в 1 множестве: " << endl;
    cin >> chisl;
    A.Poisk(chisl);
    A.Vivod();
    cout << "Введите число наличие которого хотите проверить во 2 множестве: " << endl;
    cin >> chisl;
    B.Poisk(chisl);
    B.Vivod();

    cout << "Введите число наличие которого хотите удалить во 2 множестве: " << endl;
    cin >> chisl;
    B.Del(chisl);
    B.Vivod();
    */

    Set W1;
    cout << "Объединение: " << endl;
    W1 = A & B;
    W1.Vivod();

    Set W2;
    cout << "Пересечение: " << endl;
    W2 = A | B;
    W2.Vivod();







    return 0;
}
