//#include <stdafx.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <ctime>


#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <cstdio>


using namespace std;

const int N = 10;  // ����� �������
const int M = 1;  // ���-�� ������������ ����������

// ��������� ��������� �� ������� �����
// ������� 2(� ��������)
struct zap
{
    int key;
};

int sw; // ������� �������
int ch; // ������� ���������

void Random(vector<zap> &X)
{
    for(int i = 0; i < X.size(); i++)
        X[i].key = rand() % 100;
    return;
}

void Sli(int j,int r,int m,int h, vector<zap> &X)
{
    zap w;
    ch++;
    if((j+r)<=h)
    {
        if(m > 1)
        {
            m = m/2;
            Sli(j,r,m,h,X);
            if((j+r+m)<=h)
            {
                Sli(j+m,r,m,h,X);
            }
            Sli(j+m,r-m,m,h,X);
        }
        else if(X[j].key > X[j+r].key)
        {
            w = X[j];
            X[j] = X[j+r];
            X[j+r] = w;
            sw++;
        }
    }
}

int main()
{
    int m,j,h;
    vector<zap> X(N);
    int h1, t = 0,s = 0,c = 0;

    srand(time(NULL));
    for(int i = 0; i < M; i++)
    {
        m = 1;
        h = N-1;
        j = 0;
        Random(X);
        t -= clock();
        sw = 0;
        ch = 0;
        do
        {
            j = 0;
            while((j+m) <= h)
            {
                Sli(j,m,m,h,X);
                j = j+m+m;
            }
            m = m + m;
        }
        while(m <= h);
        t += clock();
        s += sw;
        c += ch;
    }

    // �����

    for(int i = 0; i < N; i++)
        cout << X[i].key << ' ';

    cout << endl;
    //cout.precision(10);
    setlocale(LC_ALL,"Russian");
    cout << "��� ���������� ������� ����� " << N << " � ������� ���� �����������:" << endl;
    cout << s / M << " ������� � " << c / M << " ��������� �� " << (double)t/(M*100) << " ������" << endl;
    // (double)t/(M*1000)
    return 0;
}
