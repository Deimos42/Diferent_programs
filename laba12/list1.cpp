#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstdio>
#include <iomanip>
#include "header.cpp"
#include "header_d.cpp"

using namespace std;


int list1()
{
    int num;
    int k,flag = 0;
    setlocale(LC_ALL,"rus");

    Stack <int>list1(7);
    Stack <int>list2;
    FILE *fout;
    fout=fopen("list.txt","a+");

    for(int i = 0; i < 7; i++)
    {
        fscanf(fout,"%d",&num);
        list1.push(num);
    }
    fclose(fout);

    cout << "Исходный однонапрпавленный список: " << endl;
    list1.printStack(); // вывод стека на экран
    cout << "" << endl;

    for(int j = 0; j < 7; j++)
    {
        k = list1.Peek(j);
        if(k % 7 == 0)
            flag = 1;
    }
    if(flag == 1)
    {
        for(int j = 0; j < 7; j++)
        {
            k = list1.Peek(j);
            if(k % 2 != 0)
                list2.push(k);
        }
        list1 = list2;
        cout << "Полученный однонаправленный список: " << endl;
        list1.printStack(); // вывод стека на экран
    }

    return 0;
}

