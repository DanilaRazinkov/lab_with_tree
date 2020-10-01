#include <iostream>
#include <clocale>
#include <fstream>
#include "tree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    char exit;
    do
    {

        Tree tree;
        tree.add(5);
        tree.add(4);
        tree.add(6);
        tree.add(2);
        tree.add(3);
        cout << tree.tostring();
        cout << "¬ведите e дл€ выхода : ";
        cin >> exit;
    } while (exit != 'e');
    return 0;
}