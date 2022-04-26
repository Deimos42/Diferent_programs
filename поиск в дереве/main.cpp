#include <iostream>
using namespace std;

// Наша структура
struct node {
    int info;  // Информационное поле
    node *l;
    node *r;  // Левая и Правая часть дерева
};

node *tree = NULL;  // Объявляем переменную, тип которой структура Дерево
node *tree1 = NULL;  // Объявляем переменную, тип которой структура Дерево
int res = 0;

// запись элемента в бинарное дерево
void push(int a, node **t) {
    if((*t) == NULL)  // Если дерева не существует
    {
        (*t) = new node;  // Выделяем память
        (*t)->info = a;  // Кладем в выделенное место аргумент a
        (*t)->l = (*t)->r = NULL;  // Очищаем память для следующего роста
        return;  // Заложили семечко, выходим
    }

// Дерево есть
    if (a > (*t)->info)
        push(a, &(*t)->r);  // Если аргумент а больше чем текущий элемент, кладем его вправо
    else
        push(a, &(*t)->l);  // Иначе кладем его влево
}


// вывод дерева
void print(node *t, int u) {
    if (t == NULL)
        return;  // Если дерево пустое, то отображать нечего, выходим
    else
    {
        // Иначе
        print(t->l, ++u);  // С помощью рекурсии посещаем левое поддерево
        for(int i = 0; i < u; ++i)
        {
            cout << "     ";
        }
        cout << t->info << endl;  // И показываем элемент

        u--;
        print(t->r,++u);  // С помощью рекурсии посещаем правое поддерево
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
    int n;  // Количество элементов
    int s;
    int fin;
    res = 0;
    cout << "введите количество элементов: \n";
    cin >> n;  // Вводим количество элементов

    for (int i = 0; i < n; ++i)
    {
        cout << "введите число: \n";
        cin >> s;  // Считываем элемент за элементом
        push(s,&tree);  // И каждый кладем в дерево
    }
    cout << "ваше дерево\n";
    print(tree,0);
    cout << "введите число, которое хотите найти: " << endl;
    cin >> fin;
    k = find1(tree,fin);

    if(k == 0)
    {
        cout << "число не найдено" << endl;
    }
    else
        cout << "число входит в дерево(количество раз): " << k << endl;

    return 0;
}



