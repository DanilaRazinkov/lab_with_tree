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
        cout << "������� ������: ";
        cin >> x;
        while (x != -1)
        {
            tree.add(x);
            cin >> x;
        }

        char mot;
        tree.show();
        cout << "������: "; tree.show_strat(); cout << endl;
        cout << "��������: "; tree.show_back(); cout << endl;
        cout << "���.: "; tree.show_sim(); cout << endl;
        cout << "������ � ������� �����������: "; tree.increase_leafs(); cout << endl;
        do
        {
            cout << "������� ��������: 1 - ��������, 2 - �������, 3 - �����, 4 - ����� ������������: ";
            cin >> mot;
            switch (mot)
            {
            case '1':
            {
                int x;
                cout << "������� �������: ";
                cin >> x;
                tree.add(x);
            }
            break;
            case '2':
            {
                int x;
                cout << "������� �������: ";
                cin >> x;
                tree.delete_el(x);
            }
            break;
            case '3':
            {
                int x;
                cout << "������� �������: ";
                cin >> x;
                cout << "������: " << tree.find(x) << endl;
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
            cout << "������: "; tree.show_strat(); cout << endl;
            cout << "��������: "; tree.show_back(); cout << endl;
            cout << "���.: "; tree.show_sim(); cout << endl;
        } while (mot != 'e');
        tree.clean_tree();
        cout << "������� e ��� ������ : ";
        cin >> exit;
    } while (exit != 'e');
    return 0;
}