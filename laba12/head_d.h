#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>

template<typename T>
class Dek
{
private:
    T *dekPtr;     // ��������� �� ���
    const int size;  // ������������ ���������� ��������� � ����
    int begin,       // ������ �������
        end;         // ����� �������
    int elemCT;      // ������� ���������
public:
    Dek(int=10);          // ����������� �� ���������
    Dek(const Dek<T> &); // ����������� �����������
    ~Dek();                // ����������

    void endek(const T &); // �������� ������� � ����� ����
    void indek(const T &); // �������� ������� � ������ ����
    T dedek(); // ������� ������� �� ������ ����
    T didek(); // ������� ������� �� ����� ����
    T dydek(); // ������� ������� �� �������� ����
    T redek(); // ����������� �������� �� ������ ����
    T ridek(); // ����������� �������� �� ����� ����
    T sredek(int); // ����������� �������� �� �������� ����
    void printDek(); // ������ ����
};

#endif // QUEUE_H
