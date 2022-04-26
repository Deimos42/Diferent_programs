#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>

// ������� ������� ��������� ��������, ��������� �� ������� �� ������ � ��������� � ��� ����� � �������� ���������
// � ������ ������� �������� ������� � ���������� ������ ���������(��� ��������� ���� ����� ���������)
using namespace std;

void Read_file(char *fname, int *&A, int n);
int Summa(int *A, int dmin, int dmax, int n);
void Res(int *A, int n, char ch);
void End(int sa, int sb, int sc);

int main(char *fname)
{
    int sa,sb,sc;
    int dmin,dmax,anmax,bnmax,cnmax;

    setlocale(LC_ALL, "rus");

    printf("������� ������� ��������: ");
    scanf("%d\n",&anmax);
    scanf("%d\n",&bnmax);
    scanf("%d",&cnmax);

    int *A = new int[anmax];
    int *B = new int[bnmax];
    int *C = new int[cnmax];

    printf("������� ����������� ����� ���������:");
    scanf("%d",&dmin);
    printf("������� ������������ ����� ���������:");
    scanf("%d",&dmax);

    Read_file("lb1.txt",A,anmax);
    Read_file("lb2.txt",B,bnmax);
    Read_file("lb3.txt",C,cnmax);

    sa = Summa(A,dmin,dmax,anmax);
    sb = Summa(B,dmin,dmax,bnmax);
    sc = Summa(C,dmin,dmax,cnmax);

    Res(A,anmax,'A');
    Res(B,bnmax,'B');
    Res(C,cnmax,'C');

    End(sa,sb,sc);

    return 0;
}

void Read_file(char *fname, int *&A, int n)
{
    FILE *fout;
    fout=fopen(fname,"a+");

    for (int i = 0; i < n; i++)
        fscanf(fout,"%d", &A[i]);

    fclose(fout);
}

int Summa(int *A, int dmin, int dmax, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((A[i] >= dmin) && (A[i] <= dmax))
        {
            printf("i: %d\n",i);
            sum += A[i];
        }
    }

    return sum;
}

void Res(int *A, int n, char ch)
{
    for (int i = 0; i < n; i++)
        printf("%c[%d] = %3d\n", ch, i + 1, A[i]);
    printf("\n");
    delete [] A;
}

void End(int sa, int sb, int sc)
{
    printf("A:%d\nB:%d\nC:%d\n",sa,sb,sc);

    if ((sa == sb)&&(sa ==sc))
        printf("� ��� �������� ����� ���������\n");
    else if ((sa == sb)||(sa == sc)||(sb == sc))
        printf("� ���� �������� ����� ���������\n");
    if((sa > sb)&&(sa > sc))
        printf("� ������� %s ������ ����� ���������\n","A");
    else if ((sb > sa)&&(sb > sc))
        printf("� ������� %s ������ ����� ���������\n","B");
    else if ((sc > sa)&&(sc > sb))
        printf("� ������� %s ������ ����� ���������\n","C");

    return;
}


















