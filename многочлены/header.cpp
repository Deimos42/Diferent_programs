#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "header.h"
#include "stddef.h"

using namespace std;
// функции деления дописать, добавить знаки между слагаемыми, написать функцию удаляющую нулевые слагаемые, функцию удаления исправить

Pol::~Pol()
{
    while(head)
    {
        tail=head->next;
        delete head;
        head=tail;
    }
}

void Pol::AddN(float q,int w,int s,int d)
{
    elem *temp = new elem;
    temp->next=NULL;
    temp->a=q;
    temp->x=w;
    temp->y=s;
    temp->z=d;

    if(head != NULL)
    {
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
    else
    {
        temp->prev=NULL;
        head=tail=temp;
    }

    return;
}

void Pol::AddK(float q,int w,int s,int d)
{
    elem *temp = new elem;
    temp->prev=NULL;
    temp->a=q;
    temp->x=w;
    temp->y=s;
    temp->z=d;

    if(tail != NULL)  // prev
    {
        temp->next=head;
        head->prev=temp;            //
        head=temp;
    }
    else
    {
        temp->next=NULL;
        head=tail=temp;
    }

}

void Pol::DelN()
{
    head=tail->prev;
    delete tail;
    tail=head;
}                            // ошибка в выводе многочлена при удалении из начала и выводе с начала

void Pol::DelK()
{
    tail=head->next;
    delete head;
    head=tail;
}

void Pol::Vved2()      // Печать с начала
{
    elem *temp=head;
    while(temp != NULL)
    {
        //if((temp->a == 1)or(temp->a == -1))
        //    ;
        //else
        //    cout << temp->a;
        cout << temp->a;

        if(temp->x == 0)
            ;
        else if(temp->x == 1)
            cout << "x";
        else
            cout << "(x^" << temp->x << ")";

        if(temp->y == 0)
            ;
        else if(temp->y == 1)
            cout << "y";
        else
            cout << "(y^" << temp->y << ")";

        if(temp->z == 0)
            ;
        else if(temp->z == 1)
            cout << "z";
        else
            cout << "(z^" << temp->z << ")";

        if((temp->next)==NULL)
            ;
        else if((temp->next->a) >= 0)
            cout << "+";
        else
            ;
        temp=temp->next;
    }
}

void Pol::Sum()  // сложение всех слагаемых в многочлене(один экземпляр класса)
{
    elem *temp=head;
    elem *tip=head;
    while(temp != NULL)
    {
        while(tip != NULL)
        {
            if(temp == tip)
                ;
            else if(((temp->a)==0)and((temp->x)==0)and((temp->y)==0)and((temp->z)==0))
                ;
            else if((temp->x == tip->x)and(temp->y == tip->y)and(temp->z == tip->z))
            {
                temp->a=(temp->a+tip->a);
                temp->x=temp->x;  //
                temp->y=temp->y;  //
                temp->z=temp->z;  //
                tip->a=0;
                tip->x=0;
                tip->y=0;
                tip->z=0;

            }
            tip=tip->next;
        }
        tip=head;
        temp=temp->next;
    }
}

void Pol::Sort2()
{
    elem *tim=head;
    elem *tom=head;
    float q1,q2;
    int w1,w2,s1,s2,d1,d2;
    q1 = tim->a;
    w1 = tim->x;
    s1 = tim->y;
    d1 = tim->z;
    //if(tim->next != NULL)
    //{
    tim=tim->next;
    q2 = tim->a;
    w2 = tim->x;
    s2 = tim->y;
    d2 = tim->z;

    tim->a=q1;
    tim->x=w1;
    tim->y=s1;
    tim->z=d1;
        //tim=tim->prev;

    tom->a=q2;
    tom->x=w2;
    tom->y=s2;
    tom->z=d2;
    //}

}

void Pol::Sort()
{
    Pol J;
    bool flag1=true;
    while(flag1 == true)
    {
        elem *tim=head;
        int st=-1;
        int j=0;
        int k=0;
        while(tim != NULL)
        {
            if((tim->a) == 0)
                ;
            else if(((tim->x)+(tim->y)+(tim->z)) > st)
            {
                st = ((tim->x)+(tim->y)+(tim->z));
                k = j;
            }
            j+=1;
            tim=tim->next;
        }

        int i=0;
        elem *tam=head;
        while(i < k)
        {
            tam=tam->next;
            i+=1;
        }
        J.AddN(tam->a,tam->x,tam->y,tam->z);
        tam->a = 0;
        elem *tem=head;

        int v=0;
        while(tem != NULL)
        {
            if((tem->a) == 0)
                v = v + 1;
            tem=tem->next;
        }
        if(v == j)
            flag1 = false;
    }

    while(head)
    {
        tail=head->next;
        delete head;
        head=tail;
    }

    int x = 0;
    elem *tim=J.head;
    while(tim != NULL)
    {
        AddN(tim->a,tim->x,tim->y,tim->z);
        tim = tim->next;
        x += 1;
    }

}


Pol operator+(const Pol& L,const Pol& E)
{
    Pol S;
    elem *temp=L.head;
    elem *tip=E.head;
    int i=0;

    while(temp != NULL)
    {
        S.AddN(temp->a,temp->x,temp->y,temp->z);
        temp=temp->next;
        i++;
    }

    while(tip != NULL)
    {
        S.AddN(tip->a,tip->x,tip->y,tip->z);
        tip=tip->next;
        i++;
    }
    S.Sum();
    S.Sort();
    S.Vved2();
    return S;
}

Pol operator-(const Pol& L,const Pol& E)  // коэффиценты из второго экземпляра записываются с обратным знаком, поэтому необходимость в функции
{                                          // Minus() отпадает
    Pol N;
    elem *temp=L.head;
    elem *tip=E.head;
    int i=0;

    while(temp != NULL)
    {
        N.AddN(temp->a,temp->x,temp->y,temp->z);
        temp=temp->next;
        i++;
    }

    while(tip != NULL)
    {
        N.AddN((tip->a)*(-1),tip->x,tip->y,tip->z);
        tip=tip->next;
        i++;
    }

    N.Sum();
    N.Sort();
    N.Vved2();
    return N;
}

Pol operator*(const Pol& L,const Pol& E)
{
    Pol D;
    elem *temp=L.head;
    elem *tip=E.head;

    while(temp != NULL)
    {
        while(tip != NULL)
        {
            D.AddN((temp->a)*(tip->a),(temp->x)+(tip->x),(temp->y)+(tip->y),(temp->z)+(tip->z));
            tip=tip->next;
        }
        tip=E.head;
        temp=temp->next;
    }
    D.Sum();
    D.Sort();
    D.Vved2();
    return D;
}




Pol operator/(const Pol& L,const Pol& E)
{
    Pol Rez;
    Pol Ost;
    Pol Prov;
    elem *temp=L.head;
    elem *tip=E.head;
    Pol L1;
    Pol E1;
    Pol NK;
    int NKsize = 0;
    int L1size = 0;
    int L2size = 0;
    int E1size = 0;
    int Rezsize = 0;
    int Ostsize = 0;
    int Provsize = 0;

    while(temp != NULL)
    {
        L1.AddN(temp->a,temp->x,temp->y,temp->z);
        L1size += 1;
        temp = temp->next;
    }

    while(tip != NULL)
    {
        E1.AddN(tip->a,tip->x,tip->y,tip->z);
        E1size += 1;
        tip = tip->next;
    }

    if(L1size < E1size)
    {
        elem *temp=L1.head;
        elem *tip=E1.head;
        while(temp != NULL)
        {
            Ost.AddN(temp->a,temp->x,temp->y,temp->z);
            Ostsize += 1;
            temp=temp->next;
        }
        if(Rezsize == 0)
        {
            Rez.AddN(0,0,0,0); //
            Rezsize += 1;
        }
    }

    else if(L1size >= E1size)
    {
        float res;
        bool flagE;
        elem *temp=L.head;  // L1
        Pol L2;
        Pol E2;
        elem *temp2 = L2.head;
        float q;
        int w,s,d;
        int ti;
        int i;

        int i2;
        while(temp != NULL)  //
        {
            res = 0;
            flagE = true;

            elem *tom = new elem;
            elem *tap = new elem;
            elem *tep = new elem;

            elem *temp=L1.head; // L1
            elem *tip=E1.head;  // E1

            if(temp->a == 0)
            {
                if(Ostsize == 0)
                    Ost.AddN(temp->a,0,0,0);
                break;
            }

            res = temp->a/tip->a;

            if((temp->x < tip->x)or(temp->y < tip->y)or(temp->z < tip->z))  // позже избавиться от лишних переменных
            {
                flagE = false;
            }

            if(flagE == true)
            {
                tap->a = res;
                tap->x = (temp->x)-(tip->x);
                tap->y = (temp->y)-(tip->y);
                tap->z = (temp->z)-(tip->z);

                Rezsize += 1;
                Rez.AddN(tap->a,tap->x,tap->y,tap->z); //

            }

            if(flagE == false)
            {
                elem *tdp=L1.head;

                if(tdp->next != NULL)
                {
                    L1.Sort2();
                }

                if((temp->x >= tip->x)and(temp->y >= tip->y)and(temp->z >= tip->z))
                {
                    flagE = true;

                    res = (temp->a)/(tip->a);
                    tap->a = res;
                    tap->x = (temp->x)-(tip->x);
                    tap->y = (temp->y)-(tip->y);
                    tap->z = (temp->z)-(tip->z);

                    Rez.AddN(tap->a,tap->x,tap->y,tap->z); //
                    Rezsize += 1;

                }

                if(flagE == false)
                {
                    while(temp != NULL)
                    {
                        Ost.AddN(temp->a,temp->x,temp->y,temp->z);
                        Ostsize += 1;
                        temp=temp->next;
                    }
                    if(Rezsize == 0)
                    {
                        Rez.AddN(0,0,0,0); //
                        Rezsize += 1;
                    }
                    break;
                }
            }
            ti = 0;

            while(ti < E1size)  // tip != NULL
            {
                ti += 1;
                tom->a = (tap->a)*(tip->a);
                tom->x = (tap->x)+(tip->x);
                tom->y = (tap->y)+(tip->y);
                tom->z = (tap->z)+(tip->z);

                elem *tep = new elem;
                if((tom->a != 0)and(tom->a < 1000))  // tom->a < 1000
                {
                    tep->next=NULL;
                    tep->a = tom->a;
                    tep->x = tom->x;
                    tep->y = tom->y;
                    tep->z = tom->z;

                    if(Prov.head != NULL)   // пересмотреть отрывок
                    {
                        tep->prev=Prov.tail;
                        Prov.tail->next=tep;
                        Prov.tail=tep;
                    }
                    else
                    {
                        tep->prev=NULL;
                        Prov.head=Prov.tail=tep;
                    }
                    Provsize += 1;
                }
                tip=tip->next;
            }

            while(temp != NULL)
            {
                L2.AddN(temp->a,temp->x,temp->y,temp->z);
                temp=temp->next;
            }
            L2size = L1size;

            while(L1size > 0)     // заменить на код c head(По аналогии с Prov)
            {
                L1size = L1size - 1;
                L1.DelK();
            }

            elem *temp2=L2.head;
            elem *tip2=Prov.head;
            i2=0;

            while(temp2 != NULL)
            {
                L1.AddN(temp2->a,temp2->x,temp2->y,temp2->z);
                temp2=temp2->next;
                i++;
            }

            while(tip2 != NULL)
            {
                L1.AddN((tip2->a)*(-1),tip2->x,tip2->y,tip2->z);
                tip2=tip2->next;
                i++;
            }

            L1.Sum();
            L1.Sort();

            elem *jet=L1.head;
            while(jet != NULL)
            {
                L1size += 1;
                jet=jet->next;
            }

            while(L2size > 0)    // заменить на код c head(По аналогии с Prov)
            {
                L2size = L2size - 1;
                L2.DelK();
            }

            while(Prov.head)
            {
                Provsize=0;
                Prov.tail=Prov.head->next;
                delete Prov.head;
                Prov.head=Prov.tail;
            }

        }
    }

    Rez.Vved2();
    //cout << " " << endl;
    //cout << "Остаток: " << endl;
    //Ost.Vved2();
    //cout << " " << endl;
    //return Ost;
    return Rez;
}




Pol operator%(const Pol& L,const Pol& E)
{
    Pol Rez;
    Pol Ost;
    Pol Prov;
    elem *temp=L.head;
    elem *tip=E.head;
    Pol L1;
    Pol E1;
    Pol NK;
    int NKsize = 0;
    int L1size = 0;
    int L2size = 0;
    int E1size = 0;
    int Rezsize = 0;
    int Ostsize = 0;
    int Provsize = 0;

    while(temp != NULL)
    {
        L1.AddN(temp->a,temp->x,temp->y,temp->z);
        L1size += 1;
        temp = temp->next;
    }

    while(tip != NULL)
    {
        E1.AddN(tip->a,tip->x,tip->y,tip->z);
        E1size += 1;
        tip = tip->next;
    }

    if(L1size < E1size)
    {
        elem *temp=L1.head;
        elem *tip=E1.head;
        while(temp != NULL)
        {
            Ost.AddN(temp->a,temp->x,temp->y,temp->z);
            Ostsize += 1;
            temp=temp->next;
        }
        if(Rezsize == 0)
        {
            Rez.AddN(0,0,0,0); //
            Rezsize += 1;
        }
    }

    else if(L1size >= E1size)
    {
        float res;
        bool flagE;
        elem *temp=L.head;  // L1
        Pol L2;
        Pol E2;
        elem *temp2 = L2.head;
        float q;
        int w,s,d;
        int ti;
        int i;

        int i2;
        while(temp != NULL)  //
        {
            res = 0;
            flagE = true;

            elem *tom = new elem;
            elem *tap = new elem;
            elem *tep = new elem;

            elem *temp=L1.head; // L1
            elem *tip=E1.head;  // E1

            if(temp->a == 0)
            {
                if(Ostsize == 0)
                    Ost.AddN(temp->a,0,0,0);
                break;
            }

            res = temp->a/tip->a;

            if((temp->x < tip->x)or(temp->y < tip->y)or(temp->z < tip->z))  // позже избавиться от лишних переменных
            {
                flagE = false;
            }

            if(flagE == true)
            {
                tap->a = res;
                tap->x = (temp->x)-(tip->x);
                tap->y = (temp->y)-(tip->y);
                tap->z = (temp->z)-(tip->z);

                Rezsize += 1;
                Rez.AddN(tap->a,tap->x,tap->y,tap->z); //

            }

            if(flagE == false)
            {
                elem *tdp=L1.head;

                if(tdp->next != NULL)
                {
                    L1.Sort2();
                }

                if((temp->x >= tip->x)and(temp->y >= tip->y)and(temp->z >= tip->z))
                {
                    flagE = true;

                    res = (temp->a)/(tip->a);
                    tap->a = res;
                    tap->x = (temp->x)-(tip->x);
                    tap->y = (temp->y)-(tip->y);
                    tap->z = (temp->z)-(tip->z);

                    Rez.AddN(tap->a,tap->x,tap->y,tap->z); //
                    Rezsize += 1;

                }

                if(flagE == false)
                {
                    while(temp != NULL)
                    {
                        Ost.AddN(temp->a,temp->x,temp->y,temp->z);
                        Ostsize += 1;
                        temp=temp->next;
                    }
                    if(Rezsize == 0)
                    {
                        Rez.AddN(0,0,0,0); //
                        Rezsize += 1;
                    }
                    break;
                }
            }
            ti = 0;

            while(ti < E1size)  // tip != NULL
            {
                ti += 1;
                tom->a = (tap->a)*(tip->a);
                tom->x = (tap->x)+(tip->x);
                tom->y = (tap->y)+(tip->y);
                tom->z = (tap->z)+(tip->z);

                elem *tep = new elem;
                if((tom->a != 0)and(tom->a < 1000))  // tom->a < 1000
                {
                    tep->next=NULL;
                    tep->a = tom->a;
                    tep->x = tom->x;
                    tep->y = tom->y;
                    tep->z = tom->z;

                    if(Prov.head != NULL)   // пересмотреть отрывок
                    {
                        tep->prev=Prov.tail;
                        Prov.tail->next=tep;
                        Prov.tail=tep;
                    }
                    else
                    {
                        tep->prev=NULL;
                        Prov.head=Prov.tail=tep;
                    }
                    Provsize += 1;
                }
                tip=tip->next;
            }

            while(temp != NULL)
            {
                L2.AddN(temp->a,temp->x,temp->y,temp->z);
                temp=temp->next;
            }
            L2size = L1size;

            while(L1size > 0)     // заменить на код c head(По аналогии с Prov)
            {
                L1size = L1size - 1;
                L1.DelK();
            }

            elem *temp2=L2.head;
            elem *tip2=Prov.head;
            i2=0;

            while(temp2 != NULL)
            {
                L1.AddN(temp2->a,temp2->x,temp2->y,temp2->z);
                temp2=temp2->next;
                i++;
            }

            while(tip2 != NULL)
            {
                L1.AddN((tip2->a)*(-1),tip2->x,tip2->y,tip2->z);
                tip2=tip2->next;
                i++;
            }

            L1.Sum();
            L1.Sort();

            elem *jet=L1.head;
            while(jet != NULL)
            {
                L1size += 1;
                jet=jet->next;
            }

            while(L2size > 0)    // заменить на код c head(По аналогии с Prov)
            {
                L2size = L2size - 1;
                L2.DelK();
            }

            while(Prov.head)
            {
                Provsize=0;
                Prov.tail=Prov.head->next;
                delete Prov.head;
                Prov.head=Prov.tail;
            }

        }
    }

    //Rez.Vved2();
    //cout << " " << endl;
    //cout << "Остаток: " << endl;
    Ost.Vved2();
    cout << " " << endl;
    return Ost;
    //return Rez;
}


