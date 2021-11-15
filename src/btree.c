#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

int get_min_right (struct tree_node * t)
{
  struct tree_node * temp = t; 

  while(temp -> left != NULL)
    temp = temp -> left;
  
  return temp -> item; 
}

struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t

  // function to create a new tree_node which data cell will become the int value of x
  // with two NULL branches
  struct tree_node * temp = malloc(sizeof(struct tree_node)); //dynamically allocation memory to new node
    temp -> item = x;
    temp -> left = NULL;
    temp -> right = NULL;

  if (t == NULL) //base case
    return temp;
  
  if (x > t -> item) // if x is larger than item cell then go right
    t -> right = Insert(x, t -> right); // we use recursion

  else // else we go left
    t -> left = Insert(x, t -> left); // recursion

  return t;
}

struct tree_node * Remove (int x, struct tree_node *t)
{
 // Remove one item from the tree t

  if (t == NULL) // base case
    return t;
  
  if (x < t -> item) // if x is smaller than the present value, then it is in the left branch
    t -> left = Remove (x, t -> left);

  else if (x > t -> item) // if x is larger than the present value, then it is in the right branch
    t -> right = Remove (x, t -> right);

  
  else //if x has the same value as the root then we just remove it
  {
    if (t -> left == NULL && t -> right == NULL)
    {
      free(t);
      return NULL;
    }

    //if tree_node has either only left or right then replace the tree_node with left or right
    else if (t -> left == NULL || t -> right == NULL)
    {
      struct tree_node * temp = t -> left;
      if (t -> right == NULL)
        temp = t -> left;
     
      else
        temp = t -> right;
      
      free(t);
      return temp;
    }

    // if the both left and right is present we remove the smallest in the right with our get_min_right function implented above
    else
    {
    int min_right = get_min_right(t -> right); //recursion
    t -> item = min_right;
    t -> right = Remove(min_right, t -> right); //recursion
    }

  }
  return t;
}


int Contains (int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.

  if (t == NULL) // base case if the tree is empty
    return 0;

  else if (t -> item == x) // base case - if x is allready present in tree
    return 1;

  else if (x > t -> item) // base case - if x is larger than the trees item
    return Contains(x, t -> right);
  
  else
    return Contains(x, t -> left); // base case - if x is samller

}


struct tree_node * Initialize (struct tree_node *t)
{
  // Create an empty tree
  return t = NULL;
}

int Empty (struct tree_node *t)
{
  // Test if empty
  if (t == NULL)
    return 1;
  
  return 0;
}

int Full (struct tree_node *t)
{
    // Test if full
    // Not possible since a binary tree consistin of linked list always will be able to contain more
    return 0;
}
