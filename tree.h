#include <string>

class Tree
{
	struct node
	{
		int value;
		int count;
		int level;
		node* right;
		node* left;
	};
	struct list
	{
		node* value;
		list* next;
	};
	node* head;
	int max_level;
public:
	Tree();
	void add(int);
	node* found(int);
	node* found(int, node*);
	void clean_tree();
	void clean_tree(node*);
	std::string tostring();
	std::string tostring(node*);
private:
	void add(int, int, node*&);
};