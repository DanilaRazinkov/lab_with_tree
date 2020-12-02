#include <string>

struct node
{
    int value;
    int count;
    node* right;
    node* left;
};

class Tree
{
    node* head;
public:
    Tree();
    void add(int);
    node* find(int);
    void clean_tree();
    void show_strat();
    void show_back();
    void show_sim();
    void show();
    void delete_el(int);
    void increase_leafs();
    node* find_max_count();
    std::string tostring();
private:
    void add(int, node*&);
    node* find(int, node*);
    void clean_tree(node*);
    void show_strat(node*);
    void show_back(node*);
    void show_sim(node*);
    void show(node*, int);
    void delete_el(node*&, int);
    void increase_leafs(node*);
    node* find_max_count(node*);
    std::string tostring(node*);
};

