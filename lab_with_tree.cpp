#include <iostream>
#include <clocale>
#include "tree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    char exit;
    do
    {

        Tree tree;
        int x;
        cout << "Введите дерево: ";
        cin >> x;
        while (x != -1)
        {
            tree.add(x);
            cin >> x;
        }

        char mot;
        tree.show();
        cout << "Прямой: "; tree.show_strat(); cout << endl;
        cout << "Обратный: "; tree.show_back(); cout << endl;
        cout << "Сим.: "; tree.show_sim(); cout << endl;
        cout << "Листья в порядке возрастания: "; tree.increase_leafs(); cout << endl;
        do
        {
            cout << "Введите действие: 1 - добавить, 2 - удалить, 3 - найти, 4 - найти максимальный: ";
            cin >> mot;
            switch (mot)
            {
            case '1':
            {
                int x;
                cout << "Введите элемент: ";
                cin >> x;
                tree.add(x);
            }
            break;
            case '2':
            {
                int x;
                cout << "Введите элемент: ";
                cin >> x;
                tree.delete_el(x);
            }
            break;
            case '3':
            {
                int x;
                cout << "Введите элемент: ";
                cin >> x;
                cout << "Адресс: " << tree.find(x) << endl;
            }
            break; 
            case '4':
            {
                node* result = tree.find_max_count();
                cout << result->value << ":" << result->count << endl;
            }
            break;
            }
            tree.show();
            cout << "Прямой: "; tree.show_strat(); cout << endl;
            cout << "Обратный: "; tree.show_back(); cout << endl;
            cout << "Сим.: "; tree.show_sim(); cout << endl;
        } while (mot != 'e');
        tree.clean_tree();
        cout << "Введите e для выхода : ";
        cin >> exit;
    } while (exit != 'e');
    return 0;
}