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

    for(int s = 0; s < 11; s++)         // ��������: �� ����������� ��� � ��������
    {
        //myDek.printDek(); // ����� ����
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

    myDek.printDek(); // ����� ����
    myDek2.printDek(); // ����� ����




    return 0;
}





/*

int main ()
{
    setlocale(LC_ALL,"rus");
    Dek<char> myDek(11); // ������ ������ ���

    myDek.printDek(); // ����� ����

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
    myDek.printDek(); // ����� ����

    ch = 'G';
    myDek.indek(ch);
    myDek.printDek(); // ����� ����

    c1 = myDek.redek();
    c2 = myDek.ridek();
    cout << c1 << endl;
    cout << c2 << endl;

    // �������� �������� �� ������ ����
    myDek.dedek();
    myDek.dedek();

    myDek.printDek(); // ����� ����


    return 0;
}


*/


















