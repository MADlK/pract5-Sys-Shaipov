// parct5 Sys n.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct Uzel {
    int znach;
    Uzel* sled;
    Uzel* pred;
    Uzel(int z)
    {
        znach = z;
        sled = nullptr;
        pred= nullptr;
    }
};

class DoublyLinkedList 
{
private:
    Uzel* nachalo;
    Uzel* end;
public:
    DoublyLinkedList() 
    {
        nachalo = nullptr;
        end = nullptr;
    }


    void push_front(int value)
    {
        Uzel* newU = new Uzel(value);
        if (nachalo == nullptr)
            nachalo = end = newU;
        else {
            newU->sled = nachalo;
            nachalo->pred= newU;
            nachalo = newU;
        }
    }

    void push_back(int value)
    {
        Uzel* newU = new Uzel(value);
        if (end == nullptr)
            end = nachalo = newU;
        else {
            newU->pred = end;
            end->sled = newU;
            end = newU;
        }
    }



    void pop_front()
    {
        if (nachalo == nullptr)
        {
            cout << "Список пуст\n\n";
            return;
        }
        Uzel* vrem = nachalo;
        nachalo = nachalo->sled;
        if (nachalo != nullptr)
            nachalo->pred = nullptr;
        else
            end = nullptr;
        delete vrem;
    }

    void pop_back()
    {
        if (end == nullptr)
        {
            cout << "Список пуст\n\n";
            return;
        }
        Uzel* vrem = end;
        end = end->pred;
        if (end != nullptr)
            end->sled = nullptr;
        else
            nachalo = nullptr;
        delete vrem;
    }
    
    void display()
    {
        Uzel* tek= nachalo;
        if (tek == nullptr) {
            cout << "Список пуст\n";
            return;
        }

        cout << "Список: ";
        while (tek != nullptr) {
            cout << tek->znach << " ";
            tek = tek->sled;
        }
        cout << "\n";
    }

    void sort() {
        if (nachalo == nullptr) {
            return;
        }

        bool swapped;
        do {
            swapped = false;
            Uzel* tek = nachalo;

            while (tek->sled)
            {
                if (tek->znach > tek->sled->znach) {

                    int vrem = tek->znach;
                    tek->znach = tek->sled->znach;
                    tek->sled->znach= vrem;

                    swapped = true;
                }
                tek = tek->sled;
            }
        } while (swapped);
    }
    void remove_duplicates() {
        Uzel* tek = nachalo;
        while (tek) {
            Uzel* q = tek->sled;

            while (q) {
                if (q->znach == tek->znach) {
                    Uzel* duplicate = q;
                    q = q->sled;

                    if (duplicate->pred) duplicate->pred->sled = duplicate->sled;
                    if (duplicate->sled) duplicate->sled->pred = duplicate->pred;
                    if (duplicate == end) end = duplicate->pred;

                    delete duplicate;
                }
                else
                {
                    q = q->sled;
                }
            }
            tek = tek->sled;
        }
    }
    ~DoublyLinkedList() {
        while (nachalo) {
            Uzel* vrem = nachalo;
            nachalo = nachalo->sled;
            delete vrem;
        }
    }
};

int main()
{
    setlocale(00, "rus");

    DoublyLinkedList list;
    int v, value;

    do
    {
        cout << "Меню \n"
            "1. Добавить элемент в начало\n"
            "2. Добавить элемент в конец\n"
            "3. Удалить элемент c начало\n"
            "4. Удалить элемент с конца\n"
            "5. Отобразить список\n"
            "6. Сортировать список\n"
            "7. Удалить дубликаты\n"
            "8. Выйти\n\n"
            "Выберите действие: ";

        cin >> v;

        switch (v)
        {
        case 1:
            cout << "Введите значение ";
            cin >> value;
            list.push_front(value);
            break;

        case 2:
            cout << "Введите значение ";
            cin >> value;
            list.push_back(value);
            break;

        case 3:
            list.pop_front();
            break;

        case 4:
            list.pop_back();
            break;

        case 5:
            list.display();
            break;

        case 6:
            list.sort();
            break;

        case 7:
            list.remove_duplicates();
            cout << "Дубликаты удалены\n";
            break;

        case 8:
            break;

        default:
            cout << "Неверный выбор\n";
        }
    } while (v != 8);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
