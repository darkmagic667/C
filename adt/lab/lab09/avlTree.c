#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node
{
  int data;
  int height;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t avl_t;
#endif

// Write your code here
// ** Note that the print_tree() function
// has been implemented already and
// included in the week9.h header
// ...
avl_t *rr(avl_t *t);
avl_t *lr(avl_t *t);
int balanceCheck(avl_t *t);
avl_t *balacing(avl_t *t, int data);

int height(avl_t *t)
{
    if (t == NULL)
        return -1;
    int hl = height(t->left);
    int hr = height(t->right);
    return (hl > hr) ? hl + 1 : hr + 1;
}
int abs(int num)
{
  if (num < 0)
    return num * -1;
  return num;
}
int find_min(avl_t *t)
{
  if (t == NULL)
    return -1;
  while (t->left != NULL)
    t = t->left;
  return t->data;
}

avl_t *delete (avl_t *t, int data)
{
  if (t == NULL)
  {
    return t;
  }

    
  if (t->data > data)
  {
    t->left = delete (t->left, data);
  }
  else if (t->data < data)
  {
    t->right = delete (t->right, data);
  }
  else
  {
    if (t->left == NULL && t->right == NULL)
    {
      return NULL;
    }
    else if (t->left == NULL)
    {
      avl_t *tmp = t->right;
      free(t);
      return tmp;
    }
    else if (t->right == NULL)
    {
      avl_t *tmp = t->left;
      free(t);
      return tmp;
    }
    else
    {
      int tmp = find_min(t->right);
      t->data = tmp;
      t->right = delete (t->right, tmp);
    }
  }
  t->height = height(t);
  if (balanceCheck(t) != 1)
    t = balacing(t, data);

  return t;
}

int balanceCheck(avl_t *t)
{
  if(t == NULL)
    return 1;
  if (t->left == NULL && t->right == NULL)
  {
    //printf("t->left == NULL ,t->right == NULL\n");
    return 1;
  }
  else if (t->left == NULL && abs(t->right->height + 1) < 2)
  {
   //printf("t->left == NULL, different = %d\n", -1 + t->right->height);
    return 1;
  }
  else if (t->right == NULL && abs(t->left->height + 1) < 2)
  {
   // printf("t->right == NULL, different = %d\n", -1 + t->left->height);
    return 1;
  }
  else if (t->right != NULL && t->left != NULL && abs(t->right->height - t->left->height) < 2)
  {
   // printf("diffrent = %d\n", t->right->height - t->left->height);
    return 1;
  }
  return 0;
}

avl_t *balacing(avl_t *t, int data)
{
  if ((t->left != NULL)&& (t->left->data > data))
  { //case 1
   // printf("balancing case 1\n");
    return rr(t);
  }
  else if (t->right != NULL && t->right->data < data)
  { //case 2
   // printf("balancing case 2\n");
    return lr(t);
  }
  else if (t->left != NULL && t->left->data < data && t->data > data)
  { //case 3 left-right
   // printf("balancing case 3\n");
    t->left = lr(t->left);
    return rr(t);
  }
  else if (t->right != NULL && t->right->data > data && t->data < data)
  { //case 4
   //printf("balancing case 4\n");
    t->right = rr(t->right);
    return lr(t);
  }
  return t;
}

avl_t *rr(avl_t *t)
{
  node_t *temp = t;
  t = t->left;
  temp->left = t->right;
  t->right = temp;
  if (temp != NULL)
    temp->height = height(temp);
  if (t != NULL)
    t->height = height(t);
  return t;
}

avl_t *lr(avl_t *t)
{
  node_t *temp = t;
  t = t->right;
  temp->right = t->left;
  t->left = temp;
  if (temp != NULL)
    temp->height = height(temp);
  if (t != NULL)
    t->height = height(t);
  return t;
}

avl_t *insert(avl_t *t, int data)
{
  if (t == NULL)
  {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->right = NULL;
    node->left = NULL;
    node->data = data;
    node->height = 0;
    return node;
  }
  if (t->data > data)
    t->left = insert(t->left, data);
  else
    t->right = insert(t->right, data);
  t->height = height(t);
 // printf("t->height = %d,t->data = %d ", t->height, t->data);
  if (balanceCheck(t) != 1)
    t = balacing(t, data);
  return t;
}

int main(void)
{
  avl_t *t = NULL;
  int n, i;
  int command, data;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &command);
    switch (command)
    {
    case 1:
      scanf("%d", &data);
      t = insert(t, data);
      break;
    case 2:
      scanf("%d", &data);
      t = delete (t, data);
      break;
    case 3:
      print_tree(t);
      break;
    }
  }
  return 0;
}