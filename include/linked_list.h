#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node
{
   int value;
   struct node * next;
} node;

node *make_node (int v, node * q);
node *free_list (node * p); //changed to node from void
void print_list (node * p);
int sum_squares (node * p);
node *map (node * p, int (*f) (int));
int square (int x);
node *insert (node * p, int val);

/* terminal node at the end of the list */
static node SENTINEL_node = { 0, 0 };

#endif // LINKED_LIST_H