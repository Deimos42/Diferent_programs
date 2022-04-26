#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


template <typename T>
class Stack
{
private:
    T *stackPtr; // ��������� �� ���������������� ������
    int size; // ������ ����������������� ������
    T top; // ������� ����������������� ������
public:
    Stack(int size = 10);// �� ��������� ������ ����������������� ������ ����� 10 ���������  // int = 10
    ~Stack(); // ����������
    bool push(const T); // ��������� ������� � ���������������� ������
    bool pop(); // ������� �� ����������������� ������ �������
    void printStack();
    inline const T &Peek(int) const; // n-� ������� �� ������� ����������������� ������
};


#endif // HEADER_H_INCLUDED
