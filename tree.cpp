#include <iostream>
#include "tree.h"

using namespace std;

Tree::Tree()
{
	head = NULL;
}

void Tree::add(int x)
{
	add(x, 1, head);
}

void Tree::add(int x, int level,  node* &now)
{
	if (now == NULL)
	{
		now = new(node);
		now->value = x;
		now->count = 1;
		now->level = level;
		now->right = NULL;
		now->left = NULL;
		if (level > max_level)
			max_level = level;
	}
	else
		if (now->value > x)
			add(x, level + 1, now->right);
		else
			if (now->value < x)
				add(x, level + 1, now->left);
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

string Tree::tostring()
{
	if (head != NULL) return "{ " + to_string(head->value) + "(" + to_string(head->count) + "), left:{" + tostring(head->left) +
		"}, right:{" + tostring(head->right) + "}";
	else return "{-}";
}

string Tree::tostring(node* now)
{
	if (now != NULL) return to_string(now->value) + "(" + to_string(now->count) + "), left:{" + tostring(now->left) +
		"}, right:{" + tostring(now->right) + "}";
	else return "-";
}