#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "stddef.h"

class Set
{
    private:
        int chislo;
        //int size1;
        //int s;
        //int *mas; // new int[size1];
    public:
        //int chislo;
        int size1;
        int *mas;
        Set() : size1(0),mas(new int[0]) {};
        //Set(const Set &X);
        ~Set();
        void Vvod();
        void Vivod();
        void Add(int elem);
        void Del(int chisl);
        void Poisk(int chisl);
        //void Pere(const Set &A,const Set &B);
        //void Ob(Set A,Set B);

        friend Set operator&(Set& A,Set& B); // Объединение   const Set& A,const Set& B
        friend Set operator|(Set& A,Set& B); // Пересечение  const Set& A,const Set& B


};




#endif // HEADER_H_INCLUDED
