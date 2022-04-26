#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "header.h"


using namespace std;
int q,w,s,d;
Pol L;
Pol E;

int main()
{
    setlocale(LC_ALL,"rus");
    int n;
    int mn;
    cout << "\n" << endl;
    cout << "Введите для какого многочлена вы будете выполнять операции?(1/2)" << endl;
    cin >> mn;

    cout << "Что вы хотите сделать?" << endl;
    cout << "1: Ввести слагаемое и добавить его в начало" << endl;
    cout << "2: Ввести слагаемое и добавить его в конец" << endl;
    cout << "3: Удалить слагаемое из начала" << endl;
    cout << "4: Удалить слагаемое из конца" << endl;
    cout << "----" << endl;
    cout << "5: Вывод многочлена" << endl;
    cout << "6: Сложить многочлены" << endl;
    cout << "7: Вычесть многочлены" << endl;
    cout << "8: Умножить многочлены" << endl;
    cout << "9: Делить многочлены без остатка" << endl;
    cout << "10: Найти остаток от деления многочленов"  << endl;            // "10: Делить многочлены с остатком"
    cout << "11: Выйти из программы" << endl;
    cout << "12: Тест1" << endl;
    cout << "13: Тест2" << endl;
    cout << "14: Тест3" << endl;
    cout << "Цифра: ";
    cin >> n;
    switch(n)
    {
        case 1:
        {
            cout << "Введите коэффицент: " << endl;
            cin >> q;
            cout << "Введите степень x: " << endl;
            cin >> w;
            cout << "Введите степень y: " << endl;
            cin >> s;
            cout << "Введите степень z: " << endl;
            cin >> d;

            if(mn == 1)
                L.AddN(q,w,s,d);
            if(mn == 2)
                E.AddN(q,w,s,d);

            main();
            break;
        }
        case 2:
        {
            cout << "Введите коэффицент: " << endl;
            cin >> q;
            cout << "Введите степень x: " << endl;
            cin >> w;
            cout << "Введите степень y: " << endl;
            cin >> s;
            cout << "Введите степень z: " << endl;
            cin >> d;

            if(mn == 1)
                L.AddK(q,w,s,d);
            if(mn == 2)
                E.AddK(q,w,s,d);

            main();
            break;
        }
        case 3:
        {
            if(mn == 1)
                L.DelN();

            if(mn == 2)
                E.DelN();

            main();
            break;
        }
        case 4:
        {
            if(mn == 1)
                L.DelK();
            if(mn == 2)
                E.DelK();

            main();
            break;
        }
        case 5:
        {
            if(mn == 1)
                L.Vved2();
            if(mn == 2)
                E.Vved2();

            main();
            break;
        }
        case 6:
        {
            Pol S;
            S = L + E;
            //S.Vved2();
            main();
            break;
        }
        case 7:
        {
            Pol N;
            N = L - E;
            //N.Vved2();
            main();
            break;
        }
        case 8:
        {
            Pol D;
            D = L * E;
            //D.Vved2();   // неправильно выводит
            main();
            break;
        }
        case 9:
        {
            Pol F;
            L.Sum();
            E.Sum();
            L.Sort();
            E.Sort();
            F = L / E;
            main();
            break;
        }
        case 10:
        {
            Pol Y;
            L.Sum();
            E.Sum();
            L.Sort();
            E.Sort();
            Y = L % E;
            main();
            break;
        }
        case 11:
        {
            break;
        }
        case 12:
        {
            // тест
            Pol L1;
            Pol E1;
            Pol X;
            L1.AddN(1,2,3,4);
            L1.AddN(0,2,3,4);
            L1.AddN(1,1,2,2);
            E1.AddK(2,2,3,4);
            E1.AddK(5,2,3,4);
            E1.AddK(2,2,1,1);
            cout << "Первый многочлен: " << endl;
            L1.Vved2();
            cout << " " << endl;
            cout << "Второй многочлен: " << endl;
            E1.Vved2();
            cout << " " << endl;
            cout << "Сумма: " << endl;
            X = L1 + E1;
            cout << " " << endl;
            cout << "Разность: " << endl;
            X = L1 - E1;
            cout << " " << endl;
            cout << "Произведение: " << endl;
            X = L1 * E1;
            cout << " " << endl;
            cout << "Деление без отстатка: " << endl;
            L1.Sum();
            E1.Sum();
            L1.Sort();
            E1.Sort();
            X = L1 / E1;
            cout << " " << endl;
            //cout << "Деление с остатком: " << endl;
            cout << "Остаток от деления: " << endl;
            X = L1 % E1;
            main();
            break;
        }

        case 13:
        {
            Pol L2;
            Pol E2;
            Pol W;
            L2.AddN(1,2,3,4);
            L2.AddN(1,1,2,2);
            E2.AddK(7,2,3,4);
            E2.AddK(3,1,2,2);
            L2.Sum();
            E2.Sum();
            L2.Sort();
            E2.Sort();
            cout << "Первый многочлен: " << endl;
            L2.Vved2();
            cout << " " << endl;
            cout << "Второй многочлен: " << endl;
            E2.Vved2();
            cout << " " << endl;
            cout << "Деление без отстатка: " << endl;
            W = L2 / E2;
            cout << " " << endl;
            //cout << "Деление с остатком: " << endl;
            cout << "Остаток от деления: " << endl;
            W = L2 % E2;
            main();
            break;
        }
        case 14:
        {
            Pol L3;
            Pol E3;
            Pol W3;
            L3.AddN(8,3,0,0);
            L3.AddN(-27,0,3,0);
            E3.AddN(2,1,0,0);
            E3.AddN(-3,0,1,0);
            cout << "Первый многочлен: " << endl;
            L3.Vved2();
            cout << " " << endl;
            cout << "Второй многочлен: " << endl;
            E3.Vved2();
            cout << " " << endl;
            cout << "Сумма: " << endl;
            W3 = L3 + E3;
            cout << " " << endl;
            cout << "Разность: " << endl;
            W3 = L3 - E3;
            cout << " " << endl;
            cout << "Произведение: " << endl;
            W3 = L3 * E3;
            cout << " " << endl;
            cout << "Деление без отстатка: " << endl;
            L3.Sum();
            E3.Sum();
            L3.Sort();
            E3.Sort();
            W3 = L3 / E3;
            cout << " " << endl;
            //cout << "Деление с остатком: " << endl;
            cout << "Остаток от деления: " << endl;
            W3 = L3 % E3;
            main();
            break;

        }
        default:
        {
            cout << "Ошибка. Введите другую цифру" << endl;
            main();
            break;
        }
    }

    return 0;
}


