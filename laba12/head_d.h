#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>

template<typename T>
class Dek
{
private:
    T *dekPtr;     // указатель на дек
    const int size;  // максимальное количество элементов в деке
    int begin,       // начало очереди
        end;         // конец очереди
    int elemCT;      // счетчик элементов
public:
    Dek(int=10);          // конструктор по умолчанию
    Dek(const Dek<T> &); // конструктор копирования
    ~Dek();                // деструктор

    void endek(const T &); // добавить элемент в конец дека
    void indek(const T &); // добавить элемент в начало дека
    T dedek(); // удалить элемент из начала дека
    T didek(); // удалить элемент из конца дека
    T dydek(); // удалить элемент из середины дека
    T redek(); // возвращение элемента из начала дека
    T ridek(); // возвращение элемента из конца дека
    T sredek(int); // возвращение элемента из середины дека
    void printDek(); // печать дека
};

#endif // QUEUE_H
