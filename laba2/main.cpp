#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>

// создаем 2 матрицы указанных размеров, заполняем их числами из файлов
// строки каждой из матриц проверяем на наличие отрицательных элементов
// а матрицу - на наличие нулевых элементов


using namespace std;
void Read_file(char *fname, int **A, int n, int m);
void Res(int **A, int n, int m, int *mas, int k, char ch);
void M_type(int mA, int nA, int mB, int nB, int k1, int k2,int **A,int **B,int *mas1,int *mas2);
int Minus(int **A, int n, int m);
void Ma(int n, int m, int **A, int *mas, int k);
int Min(int *X, int m, int k);
void N_type(int mA, int nA, int mB, int nB, int k1, int k2,int **A,int **B,int *mas1,int *mas2);
void vvo(int n, int m, int **A, char ch);
void Memor(int n, int **A);
void Pre_Min(int n, int m, int **A, int k, int *mas);


// 1 процедура - 1 действие; без циклов в главной; new в отдельную процедуру
int main(char *fname)
{
    int mA,nA,mB,nB;
    int k1,k2;

    setlocale(LC_ALL,"rus");
    printf("Введите количество строк 1 матрицы: ");
    scanf("%d",&nA);
    printf("Введите количество столбцов 1 матрицы: ");
    scanf("%d",&mA);

    printf("Введите количество строк 2 матрицы: ");
    scanf("%d",&nB);
    printf("Введите количество столбцов 2 матрицы: ");
    scanf("%d",&mB);

    int **A = new int*[nA];   // n строк
    for(int i = 0; i < nA; i++)
        A[i] = new int[mA];   // m столбцов

    int **B = new int*[nB];
    for(int i = 0; i < nB; i++)
        B[i] = new int[mB];

    int *mas1 = new int[nA];
    int *mas2 = new int[nB];

    Read_file("lb1.txt",A,nA,mA);
    Read_file("lb2.txt",B,nB,mB);

    k1 = Minus(A,nA,mA);
    k2 = Minus(B,nB,mB);

    M_type(mA,nA,mB,nB,k1,k2,A,B,mas1,mas2);
    N_type(mA,nA,mB,nB,k1,k2,A,B,mas1,mas2); // не работает 2 способ

    return 0;
}


void M_type(int mA,int nA,int mB,int nB,int k1,int k2,int **A,int **B,int *mas1,int *mas2)
{
    Ma(nA,mA,A,mas1,k1);
    Ma(nB,mB,B,mas2,k2);

    vvo(nA,mA,A,'A');
    vvo(nB,mB,B,'B');

    Res(A,nA,mA,mas1,k1,'A');
    Res(B,nB,mB,mas2,k2,'B');

    Memor(nA,A);
    Memor(nB,B);

    return;
}

void N_type(int mA,int nA,int mB,int nB,int k1,int k2,int **A,int **B,int *mas1,int *mas2)
{
    int k = 0;

    Pre_Min(nA,mA,A,k1,mas1);
    Pre_Min(nB,mB,B,k2,mas2);

    vvo(nA,mA,A,'A');
    vvo(nB,mB,B,'B');

    Res(A,nA,mA,mas1,k1,'A');
    Res(B,nB,mB,mas2,k2,'B');

    Memor(nA,A);
    Memor(nB,B);

    return;
}


void Read_file(char *fname,int **A, int n, int m)
{
    FILE *fout;
    fout=fopen(fname,"a+");

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            fscanf(fout,"%d",&A[i][j]);
        }
    fclose(fout);
    return;
}

void vvo(int n, int m, int **A, char ch)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            printf("%c[%d][%d] = %3d\n", ch, i + 1, j + 1, A[i][j]);
    return;
}

void Res(int **A, int n, int m, int *mas, int k, char ch)
{
    if(k > 0)
        for(int i = 0; i < n; i++)
        {
            if(mas[i] == 1)
                printf("%d строка - есть отрицательный элемент\n",i + 1); // из-за того что индексируется с 0
            else
                printf("%d строка - нет отрицательных элементов\n",i + 1);
        }
    else
        printf("В матрице нет элементов равных 0\n");

    return;
}

void Memor(int n, int **A)
{
    for(int i = 0; i < n; i++)
        delete []A[n];
    delete[]A;

    return;
}

int Minus(int **A, int n, int m)
{
    int i = 1;
    int j = 1;
    int k = 0;

    while((i <= (n))&&(k == 0))
    {
        j = 1;
        while((j <= (m))&&(k == 0))
        {
            if(A[i-1][j-1] == 0)
                k = 1;
            else
                j = j + 1;
        }
        i = i + 1;
    }

    return k;
}

void Ma(int n, int m, int **A, int *mas, int k)
{
   if(k == 1)
   {
       for(int i = 0; i < n; i++)
       {
           int j = 0;
           while((j < (m-1))&&((A[i][j]) >= 0))
               j = j + 1;
           if((A[i][j] < 0))
               mas[i] = 1;
           else
               mas[i] = 0;
       }
   }
   return;

}

void Pre_Min(int n, int m, int **A, int k, int *mas)
{
    for(int i = 0; i < n; i++)
    {
        printf("число i: %d\n",i);
        mas[i] = Min(A[i],m,k);
    }


    return;
}

int Min(int *X, int m, int k)
{
    int j = 0;
    int v;
    if(k == 1)
    {
        while((j < m)&&(X[j] >= 0))
            j = j + 1;

        if(X[j] < 0)
            v = 1;
        else
            v = 0;
        return v;
    }
}


