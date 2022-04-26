#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


template <typename T>
class Stack
{
private:
    T *stackPtr; // указатель на однонаправленный список
    int size; // размер однонаправленного списка
    T top; // вершина однонаправленного списка
public:
    Stack(int size = 10);// по умолчанию размер однонаправленного списка равен 10 элементам  // int = 10
    ~Stack(); // деструктор
    bool push(const T); // поместить элемент в однонаправленный список
    bool pop(); // удалить из однонаправленного списка элемент
    void printStack();
    inline const T &Peek(int) const; // n-й элемент от вершины однонаправленного списка
};


#endif // HEADER_H_INCLUDED
