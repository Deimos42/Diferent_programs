#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

void Error(int p, int n);
int Byte(int x, int p, int n);

int main()
{
    int x,p,n,v;
    setlocale(LC_ALL, "rus");
    printf("Введите число x: ");
    scanf("%d",&x);
    printf("Введите число бит: ");
    scanf("%d",&n);
    printf("Введите номер позиции: ");
    scanf("%d",&p);
    printf("Введённое число: %08x\n",x);

    Error(p,n);
    v = Byte(x,p,n);
    printf("Результат:     %08x\n",v);

    return 0;
}

void Error(int p, int n)
{
    if((p <= 0) || (p >= 32))
        printf("Неправильно введённые данные(ошибка в p)\n");
    if((n < 0) || (n >= 32))
        printf("Неправильно введённые данные(ошибка в n)\n");
    if((p+1-n) <= 0)
        printf("Неправильно введённые данные(справа от p нет такого числа бит)\n");

    return;
}

int Byte(int x, int p, int n)
{
    int resul;
    unsigned mask = 0;
    unsigned mask1;
    unsigned mask2;

    mask = ~(mask);
    printf("mask:  %08x\n",mask);
    mask1 = mask << p-n;
    printf("mask1: %08x\n",mask1);
    mask2 = mask >> (32-p-1);
    printf("mask2: %08x\n",mask2);
    mask = mask1 & mask2;
    printf("mask:  %08x\n\n",mask);
    resul = x ^ mask;

    return resul;
}



