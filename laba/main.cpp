#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>

// создаем массивы указанных размеров, заполняем их числами из файлов и суммируем в них числа в заданном диапазоне
// в ответе выводим название массива с наибольшей суммой элементов(или несколько если суммы совпадают)
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

    printf("Введите размеры массивов: ");
    scanf("%d\n",&anmax);
    scanf("%d\n",&bnmax);
    scanf("%d",&cnmax);

    int *A = new int[anmax];
    int *B = new int[bnmax];
    int *C = new int[cnmax];

    printf("Введите минимальное число диапазона:");
    scanf("%d",&dmin);
    printf("Введите максимальное число диапазона:");
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
        printf("В трёх массивах суммы совпадают\n");
    else if ((sa == sb)||(sa == sc)||(sb == sc))
        printf("В двух массивах суммы совпадают\n");
    if((sa > sb)&&(sa > sc))
        printf("в массиве %s больше сумма элементов\n","A");
    else if ((sb > sa)&&(sb > sc))
        printf("в массиве %s больше сумма элементов\n","B");
    else if ((sc > sa)&&(sc > sb))
        printf("в массиве %s больше сумма элементов\n","C");

    return;
}


















