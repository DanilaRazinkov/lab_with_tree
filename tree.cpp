#include <iostream>
#include "tree.h"

using namespace std;

Tree::Tree()
{
    head = NULL;
}

void Tree::add(int x)
{
    add(x, head);
}

void Tree::add(int x, node*& now)
{
    if (now == NULL)
    {
        now = new(node);
        now->value = x;
        now->count = 1;
        now->right = NULL;
        now->left = NULL;
    }
    else
        if (now->value < x)
            add(x, now->right);
        else
            if (now->value > x)
                add(x, now->left);
            else
                now->count++;
}

node* Tree::find(int x)
{
    return find(x, head);
}

node* Tree::find(int x, node* now)
{
    if (now == NULL) return NULL;
    else
        if (now->value == x) return now;
        else
            if (x < now->value) return find(x, now->left);
            else
                if (x > now->value) return find(x, now->right);
}

void Tree::clean_tree()
{
    clean_tree(head);
}

void Tree::clean_tree(node* now)
{
    if (now != NULL)
    {
        clean_tree(now->left);
        clean_tree(now->right);
        delete now;
    }
}

void Tree::show_strat()
{
    show_strat(head);
}

void Tree::show_strat(node* now)
{
    if (now != NULL)
    {
        cout << now->value << ' ';
        show_strat(now->left);
        show_strat(now->right);
    }
}

void Tree::show_back()
{
    show_back(head);
}

void Tree::show_back(node* now)
{
    if (now != NULL)
    {
        show_back(now->left);
        show_back(now->right);
        cout << now->value << ' ';
    }
}

void Tree::show_sim()
{
    show_sim(head);
}

void Tree::show_sim(node* now)
{
    if (now != NULL)
    {
        show_sim(now->left);
        cout << now->value << ' ';
        show_sim(now->right);
    }
}

void Tree::delete_el(int value)
{
    delete_el(head, value);
}

void Tree::delete_el(node*& now, int value)
{
    if (now != NULL)
    {
        if (now->value == value)
        {
            now->count--;
            if (now->count == 0)
                if (now->left == NULL)
                {
                    node* t = now;
                    now = now->right;
                    delete t;
                }
                else
                    if (now->right == NULL)
                    {
                        node* t = now;
                        now = now->left;
                        delete t;
                    }
                    else
                    {
                        node* the_right = now->left;
                        node* prev = the_right;
                        while (the_right->right != NULL)
                        {
                            prev = the_right;
                            the_right = the_right->right;
                        }
                        now->value = the_right->value;
                        now->count = the_right->count;
                        if (the_right == now->left)
                            now->left = the_right->left;
                        else
                            prev->right = the_right->left;
                        delete the_right;
                    }
        }
        else
            if (now->value < value)
                delete_el(now->right, value);
            else
                if (now->value > value)
                    delete_el(now->left, value);
    }
}

void Tree::show()
{
    show(head, 0);
}

void Tree::show(node* now, int l)
{
    if (now != NULL)
    {
        show(now->right, l + 1);
        for (int i = 0; i < l; i++)
            cout << "     ";
        cout << now->value << '(' << now->count << ')' << endl;
        show(now->left, l + 1);
    }
}

void Tree::increase_leafs()
{
    increase_leafs(head);
}

void Tree::increase_leafs(node* now)
{
    if (now != NULL)
    {
        increase_leafs(now->left);
        if (now->right == NULL && now->left == NULL)
            cout << now->value << '(' << now->count << "), ";
        else
            increase_leafs(now->right);
    }
}

node* Tree::find_max_count()
{
    return find_max_count(head);
}

node* Tree::find_max_count(node* now)
{
    if (now == NULL)
        return NULL;
    else
    {
        node* result = now;
        node* max_left = find_max_count(now->left);
        node* max_right = find_max_count(now->right);

        if (max_left != NULL && max_left->count > result->count)
            result = max_left;
        if (max_right != NULL && max_right->count > result->count)
            result = max_right;

        return result;
    }
}



string Tree::tostring()
{
    if (head != NULL) return "{ " + to_string(head->value) + "(" +
        to_string(head->count) + "), left:{" + tostring(head->left) +
        "}, right:{" + tostring(head->right) + "}";
    else return "{-}";
}

string Tree::tostring(node* now)
{
    if (now != NULL) return to_string(now->value) + "(" +
        to_string(now->count) + "), left:{" + tostring(now->left) +
        "}, right:{" + tostring(now->right) + "}";
    else return "-";
}