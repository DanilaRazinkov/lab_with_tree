#include <iostream>
#include "tree.h"

using namespace std;

Tree::Tree()
{
    head = NULL;
}

void Tree::add(int x)
{
    add(x, head, NULL);
}

void Tree::add(int x, node*& now, node* parent)
{
    if (now == NULL)
    {
        now = new(node);
        now->value = x;
        now->count = 1;
        now->right = NULL;
        now->left = NULL;
        now->parent = parent;
    }
    else
        if (now->value > x)
            add(x, now->right, now);
        else
            if (now->value < x)
                add(x, now->left, now);
            else
                now->count++;
}


Tree::node* Tree::found(int x)
{
    return found(x, head);
}

Tree::node* Tree::found(int x, node* now)
{
    if (now == NULL) return NULL;
    else
        if (now->value == x) return now;
        else
            if (x < now->value) return found(x, now->left);
            else
                if (x > now->value) return found(x, now->right);
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

void Tree::delete_el(node* now)
{
    if (now->right != NULL && now->left != NULL)
    {
        node* the_right = right(now->left);
        now->value = the_right->value;
        now->count = the_right->count;
        if (the_right->left != NULL)
        {
            node* t = the_right;
            the_right = the_right->left;
            delete t;
        }
        else
        {
            node* t = the_right;
            the_right = NULL;
            delete t;
        }

    }
}

Tree::node* Tree::right(node* now)
{
    if (now != NULL)
        if (now->right != NULL)
            return right(now->right);
        else
            return now;
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