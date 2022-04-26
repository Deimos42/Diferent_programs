#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include "stddef.h"


struct elem
{
    public:
        float a; // коэффицент
        int x; // степень x
        int y; // степень y
        int z; // степень z
        elem *next;  // следующий
        elem *prev;  // предыдущий
};


class Pol
{
    private:
        elem *head; // начало списка
        elem *tail;  // конец списка
    public:
        Pol():head(NULL),tail(NULL){}; // Конструктор
        Pol(const Pol&a); // Конструктор копирования
        ~Pol();  // Деструктор
        void AddN(float,int,int,int); // добавление в начало
        void AddK(float,int,int,int); // добавление в конец
        void DelN(); // удаление из начала
        void DelK(); // удаление из конца
        void Poisk(); // Поиск узла
        void Vved2(); // Печать с начала
        void Sort(); // Сортировка
        void Sort2();
        void Sum();

        friend Pol operator+(const Pol& L,const Pol& E);   // Сложение
        friend Pol operator-(const Pol& L,const Pol& E);    // Вычитание
        friend Pol operator*(const Pol& L,const Pol& E);  // Произведение
        friend Pol operator/(const Pol& L,const Pol& E);  // Деление
        friend Pol operator%(const Pol& L,const Pol& E);   // Остаток от деления


};


#endif // HEADERS_H_INCLUDED

