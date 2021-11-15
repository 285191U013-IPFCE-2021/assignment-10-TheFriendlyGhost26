#include "../include/linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;

  return p;
}

/* free all nodes in the list p */
node *free_list (node * p) //Changed to node instead of void
{
  node *q = p;
  while (q != NULL)
    {
      node *t = q -> next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
    // Add your code for exercise 1
    // There is NO testcode for this
    if (p == NULL) 
    {
      printf("\n");
    }
    
    else 
    {
      printf("%d", p -> value); //Print value of the node
      print_list (p -> next); 
    }
}

int sum_squares (node * p)
{
    // Add your code for excercise 2
    // You can find the tests in tests.cpp
    if (p == NULL){
      return 0;
    }

    if (p -> next == NULL){
      return square(p -> value);
    }

    else{
      return square(p -> value) + sum_squares(p -> next); //recursion
    }
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3
    if (p == NULL){
      return NULL;
    }

    return (make_node((*f)(p -> value), map(p -> next, f))); //recursion
}


int square (int x)
{
  return x * x;
}

node *insert (node * p, int val)
{
  node * temp = malloc (sizeof (node));
  temp -> value = val;
  temp -> next = NULL; //to ensure that the tail of the list is empty
  if (p == NULL) //if empty list
    p = temp;
  else
  {
    node *temp1 = p;
    while (temp1 -> next != NULL) // wait until temp1 is at the end of linked list before inserting
      temp1 = temp1 -> next;
    temp1 -> next = temp;
  }
  
return p;
}