#include <iostream>
using namespace std;

// ���� ���������
struct node {
    int info;  // �������������� ����
    node *l;
    node *r;  // ����� � ������ ����� ������
};

node *tree = NULL;  // ��������� ����������, ��� ������� ��������� ������
node *tree1 = NULL;  // ��������� ����������, ��� ������� ��������� ������
int res = 0;

// ������ �������� � �������� ������
void push(int a, node **t) {
    if((*t) == NULL)  // ���� ������ �� ����������
    {
        (*t) = new node;  // �������� ������
        (*t)->info = a;  // ������ � ���������� ����� �������� a
        (*t)->l = (*t)->r = NULL;  // ������� ������ ��� ���������� �����
        return;  // �������� �������, �������
    }

// ������ ����
    if (a > (*t)->info)
        push(a, &(*t)->r);  // ���� �������� � ������ ��� ������� �������, ������ ��� ������
    else
        push(a, &(*t)->l);  // ����� ������ ��� �����
}


// ����� ������
void print(node *t, int u) {
    if (t == NULL)
        return;  // ���� ������ ������, �� ���������� ������, �������
    else
    {
        // �����
        print(t->l, ++u);  // � ������� �������� �������� ����� ���������
        for(int i = 0; i < u; ++i)
        {
            cout << "     ";
        }
        cout << t->info << endl;  // � ���������� �������

        u--;
        print(t->r,++u);  // � ������� �������� �������� ������ ���������
    }
}


int find1(node *t,int d)
{
    if(t==NULL)
    {
        return res;
    }
    if(t->info == d)
    {
        res = res + 1;
    }

    if(d <= t->info)
    {
        // left
        if(t->l != NULL)
        {
            find1(t->l,d);
        }
        else
        {
            return res;
        }
    }
    else
    {
        //right
        if(t->r)
        {
            find1(t->r,d);
        }
        else
        {
            return res;
        }
    }
}



int main() {
    setlocale(LC_ALL, "Russian");
    int k;
    int n;  // ���������� ���������
    int s;
    int fin;
    res = 0;
    cout << "������� ���������� ���������: \n";
    cin >> n;  // ������ ���������� ���������

    for (int i = 0; i < n; ++i)
    {
        cout << "������� �����: \n";
        cin >> s;  // ��������� ������� �� ���������
        push(s,&tree);  // � ������ ������ � ������
    }
    cout << "���� ������\n";
    print(tree,0);
    cout << "������� �����, ������� ������ �����: " << endl;
    cin >> fin;
    k = find1(tree,fin);

    if(k == 0)
    {
        cout << "����� �� �������" << endl;
    }
    else
        cout << "����� ������ � ������(���������� ���): " << k << endl;

    return 0;
}



