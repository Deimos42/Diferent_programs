#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstdio>
#include <iomanip>

#include "header_d.cpp"

using namespace std;


int deck()
{
    setlocale(LC_ALL,"rus");
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

    for(int s = 0; s < 11; s++)         // дописать: не заполняется дек с гласными
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


















