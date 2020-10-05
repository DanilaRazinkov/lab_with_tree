#include <string>

class Tree
{
    struct node
    {
        int value;
        int count;
        node* right;
        node* left;
        node* parent;
    };
    struct list
    {
        node* value;
        list* next;
    };
    node* head;
public:
    Tree();
    void add(int);
    node* found(int);
    void clean_tree();
    void show_strat();
    void show_back();
    void show_sim();
    void delete_el(node*);
    std::string tostring();
private:
    void add(int, node*&, node*);
    node* found(int, node*);
    void clean_tree(node*);
    void show_strat(node*);
    void show_back(node*);
    void show_sim(node*);
    node* right(node*);
    std::string tostring(node*);
};

