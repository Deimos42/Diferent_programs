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

    cout << "���� � ����� 1 ���������: " << endl;

    cout << "������� ������ ���������: ";
    cin >> Asize;
    for(int i = 0; i < Asize; i++)
    {
        cout << "���������� ����� � 1 ���������: " << endl;
        cout << "������� �����: ";
        cin >> elem;
        A.Add(elem);
    }
    //A.Vvod();
    A.Vivod();

    cout << "���� � ����� 2 ���������: " << endl;

    cout << "������� ������ ���������: ";
    cin >> Bsize;
    for(int i = 0; i < Bsize; i++)
    {
        cout << "���������� ����� � 1 ���������: " << endl;
        cout << "������� �����: ";
        cin >> elem;
        B.Add(elem);
    }
    //B.Vvod();
    B.Vivod();

    /*
    cout << "���������� ����� � 1 ���������: " << endl;
    cout << "������� �����: ";
    cin >> elem;
    A.Add(elem);
    A.Vivod();

    cout << "���������� ����� � 2 ���������: " << endl;
    cout << "������� �����: ";
    cin >> elem;
    B.Add(elem);
    B.Vivod();

    cout << "������� ����� ������� �������� ������ ��������� � 1 ���������: " << endl;
    cin >> chisl;
    A.Poisk(chisl);
    A.Vivod();
    cout << "������� ����� ������� �������� ������ ��������� �� 2 ���������: " << endl;
    cin >> chisl;
    B.Poisk(chisl);
    B.Vivod();

    cout << "������� ����� ������� �������� ������ ������� �� 2 ���������: " << endl;
    cin >> chisl;
    B.Del(chisl);
    B.Vivod();
    */

    Set W1;
    cout << "�����������: " << endl;
    W1 = A & B;
    W1.Vivod();

    Set W2;
    cout << "�����������: " << endl;
    W2 = A | B;
    W2.Vivod();







    return 0;
}
