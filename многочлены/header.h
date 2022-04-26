#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include "stddef.h"


struct elem
{
    public:
        float a; // ����������
        int x; // ������� x
        int y; // ������� y
        int z; // ������� z
        elem *next;  // ���������
        elem *prev;  // ����������
};


class Pol
{
    private:
        elem *head; // ������ ������
        elem *tail;  // ����� ������
    public:
        Pol():head(NULL),tail(NULL){}; // �����������
        Pol(const Pol&a); // ����������� �����������
        ~Pol();  // ����������
        void AddN(float,int,int,int); // ���������� � ������
        void AddK(float,int,int,int); // ���������� � �����
        void DelN(); // �������� �� ������
        void DelK(); // �������� �� �����
        void Poisk(); // ����� ����
        void Vved2(); // ������ � ������
        void Sort(); // ����������
        void Sort2();
        void Sum();

        friend Pol operator+(const Pol& L,const Pol& E);   // ��������
        friend Pol operator-(const Pol& L,const Pol& E);    // ���������
        friend Pol operator*(const Pol& L,const Pol& E);  // ������������
        friend Pol operator/(const Pol& L,const Pol& E);  // �������
        friend Pol operator%(const Pol& L,const Pol& E);   // ������� �� �������


};


#endif // HEADERS_H_INCLUDED

