#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstdio>
#include <iomanip>

#include "header.h"
#include "head_d.h"
#include "header.cpp"
#include "header_d.cpp"


using namespace std;


int main()
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

    cout << "Исходный однонаправленный список: " << endl;
    list1.printStack(); // вывод однонаправленного списка на экран
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
        list1.printStack(); // вывод однонаправленного списка на экран
    }



    Dek<char> myDek(11);
    Dek<char> myDek2(11);

    char ch;
    char c1,c2;
    int flag2;
    int x = 0;

    FILE *fiut;
    fiut = fopen("deck1.txt","a+");

    for(int i = 0; i < 11; i++)
    {
        fscanf(fiut,"%c",&ch);
        myDek.endek(ch);
    }
    fclose(fiut);

    myDek.didek();
    myDek.printDek();

    char *A = "OYUIEAJ";

    for(int s = 0; s < 11; s++)
    {
        //myDek.printDek(); // вывод дека
        flag2 = 0;
        c1 = myDek.redek();
        for(int k = 0; k < 7; k++)
            if(A[k] == c1)
            {
                flag2 = 1;
                //cout << flag2 << endl;
            }

        if(flag2 == 1)
        {
            myDek.endek(c1);
            //cout << flag2 << endl;
        }
        else
            myDek2.endek(c1);
        myDek.dedek();

    }

    myDek.printDek(); // вывод дека
    myDek2.printDek(); // вывод дека




    return 0;
}





/*

int main ()
{
    setlocale(LC_ALL,"rus");
    Dek<char> myDek(11); // объект класса дек

    myDek.printDek(); // вывод дека

    char ch;
    char c1,c2;
    FILE *fiut;
    fiut = fopen("deck1.txt","a+");

    for(int i = 0; i < 11; i++)
    {
        fscanf(fiut,"%c",&ch);
        myDek.endek(ch);
    }
    fclose(fiut);

    myDek.dedek();
    myDek.printDek(); // вывод дека

    ch = 'G';
    myDek.indek(ch);
    myDek.printDek(); // вывод дека

    c1 = myDek.redek();
    c2 = myDek.ridek();
    cout << c1 << endl;
    cout << c2 << endl;

    // удаление элемента из начала дека
    myDek.dedek();
    myDek.dedek();

    myDek.printDek(); // вывод дека


    return 0;
}


*/


/*
void Read_file(char *fname,Stack <int>list1)  // list1(7)
{
    int num;
    FILE *fout;
    fout=fopen(fname,"a+");

    for(int i = 0; i < 7; i++)
    {
        fscanf(fout,"%d",&num);
        list1.push(num);
    }
    fclose(fout);

    list1.printStack(); // вывод стека на экран

}

int main()
{
    int k;
    setlocale(LC_ALL,"rus");
    Stack <int>list1(7);
    Read_file("list.txt",list1);

    cout << "\nУдаляем два элемента из стека:\n";

    //list1.pop(); // удаляем элемент из стека
    //list1.pop(); // удаляем элемент из стека
    list1.printStack(); // вывод стека на экран
    k = list1.Peek(5);
    //cout << k;

    return 0;
}
*/







