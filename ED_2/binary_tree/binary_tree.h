#ifndef BINARY_TREE
#define BINARY_TREE

struct nodetype;

typedef struct nodetype* NODEPTR;

NODEPTR getnode();

NODEPTR binary_tree_create(int x);

void set_left(NODEPTR p, int x);

void set_right(NODEPTR p, int x);

void remove_node(NODEPTR p);

int node_info(const NODEPTR p);

NODEPTR left_node(const NODEPTR p);

NODEPTR right_node(const NODEPTR p);

NODEPTR father_node(const NODEPTR p);

bool is_brother(const NODEPTR p);

bool is_leaf(const NODEPTR p);

#endif
