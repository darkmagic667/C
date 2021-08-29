#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
// typedef struct node {
//    ...
// } node_t;
// typedef node_t tree_t;

// Write your code here
// ...

typedef struct node
{
  int value;
  struct node *child;
  struct node *sibling;
} node_t;

typedef node_t tree_t;

node_t *find(tree_t *t, int node)
{
  if (t == NULL)
  {
    return NULL;
  }
  //printf("t->value = %d == %d\n",t->value,node);
  if (t->value == node)
    return t;
  node_t *child = find(t->child, node);
  if (child != NULL)
    return child;
  else
    return find(t->sibling, node);
}

tree_t *attach(tree_t *t, int parent, int child)
{
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  newNode->value = child;
  newNode->sibling = NULL;
  newNode->child = NULL;
  if (t == NULL)
  {
    t = newNode;
    return t;
  }
  node_t *parentNode = find(t, parent);
  //printf("parent->value = %d\n",parentNode->value);
  if (parentNode->child != NULL)
  {
    parentNode = parentNode->child;
    while (parentNode->sibling != NULL)
      parentNode = parentNode->sibling;
    parentNode->sibling = newNode;
    return t;
  }
  else
  {
    parentNode->child = newNode;
    return t;
  }
  return NULL;
}

tree_t *detach(tree_t *t, int node)
{
  if (t == NULL)
    return NULL;
  node_t *temp = t;
  int count = 0;
  while (1)
  {
    // printf("temp->value = %d loop = %d\n",temp->value,count++);
    if (temp->child != NULL)
    {
      //printf("temp->value = %d, temp->child->value = %d\n",temp->value,temp->child->value);
      if (temp->child->value == node)
      {

        temp->child = temp->child->sibling;
        break;
      }
    }
    if (temp->sibling != NULL)
    {
      //printf("temp->value = %d, temp->sibling->value = %d\n",temp->value,temp->sibling->value);
      if (temp->sibling->value == node)
      {

        temp->sibling = temp->sibling->sibling;
        break;
      }
    }
    if (find(temp->child, node) != NULL)
    {
      // printf("Child\n");
      temp = temp->child;
    }
    else
    {
      //printf("Sibling\n");
      temp = temp->sibling;
    }
  }
  return t;
}

int search(tree_t *t, int value)
{
  t = find(t, value);
  if (t == NULL)
    return 0;
  return 1;
}

int degree(tree_t *t, int node)
{
  node_t *currentNode = find(t, node);
  if (currentNode->child == NULL)
    return 0;

  int count = 1;
  currentNode = currentNode->child;
  while (currentNode->sibling != NULL)
  {
    currentNode = currentNode->sibling;
    count++;
  }
  return count;
}

int is_root(tree_t *t, int value)
{
  if (t == NULL)
    return 0;

  //printf("t->value = %d\n",t->value);
  if (t->value == value)
    return 1;
  return 0;
}

int is_leaf(tree_t *t, int value)
{
  t = find(t, value);
  if (t->child != NULL)
    return 0;
  return 1;
}

void siblings(tree_t *t, int node)
{
  int found = 0;
  while (1)
  {
    node_t *temp = t;
    while (temp != NULL)
    {
      //printf("temp->value = %d\n",temp->value);
      if (temp->value == node)
      {
        found = 1;
        break;
      }
      if (temp->sibling == NULL)
        break;
      temp = temp->sibling;
    }
    if (temp->value == node)
    {
      break;
    }
    if (find(t->child, node) != NULL)
      t = t->child;
    else
      t = t->sibling;
  }
  if (!found)
  {
    printf("\n");
    return;
  }
  while (t != NULL)
  {
    //printf("t->value = %d ",t->value);
    if (t->value != node)
    {
      printf("%d ", t->value);
    }
    t = t->sibling;
  }
  printf("\n");
}

int depth(tree_t *t, int value)
{
  if (t == NULL || find(t, value) == NULL)
    return -1;
  int count = 0;
  while (t->value != value)
  {
    if (find(t->child, value) != NULL)
    {
      count += 1;
      t = t->child;
    }
    else
      t = t->sibling;
  }
  return count;
}

void print_path(tree_t *t, int start, int end)
{
  if (t == NULL)
    return;
  node_t *startNode = find(t, start);
  while (startNode->value != end){
    printf("%d ", startNode->value);
    if (find(startNode->child, end) != NULL)
    {
      startNode = startNode->child;
      if (startNode->value == end)
        break;
      while (1)
      {
        if (startNode->child != NULL)
        {
          if (find(startNode->child, end) != NULL)
            break;
        }
        if (startNode->value == end)
        {
          break;
        }
        startNode = startNode->sibling;
      }
    }
    else
    {
      while (find(startNode->child, end) == NULL)
      {
        startNode = startNode->sibling;
      }
    }
  }
  printf("%d \n", startNode->value);
}

int path_length(tree_t *t, int start, int end)
{
  if (t == NULL)
    return -1;
  node_t *startNode = find(t, start);
  int count = 1;
  while (startNode->value != end)
  {
    //printf("startNode->value = %d count = %d\n", startNode->value, count);
    if (find(startNode->child, end) != NULL)
    {
      startNode = startNode->child;
      if (startNode->value == end)
      {
        count++;
        break;
      }
      while (1)
      {
        if (startNode->child != NULL)
        {
          if (find(startNode->child, end) != NULL)
            break;
        }
        if (startNode->value == end)
        {
          break;
        }
        startNode = startNode->sibling;
      }
      count++;
    }
    else
    {
      while (find(startNode->child, end) == NULL)
      {
        startNode = startNode->sibling;
      }
      count++;
    }
  }
  return count;
}

void ancestor(tree_t *t, int node)
{
  if (t == NULL)
    return;
  print_path(t, t->value, node);
}

void descendant(tree_t *t, int node)
{
  node_t *temp = find(t, node);
  node_t *arr[MAXSIZE];
  int currentindex = 0;
  int maxindex = 0;
  arr[currentindex] = temp;
  while (arr[currentindex] != NULL && currentindex <= maxindex)
  {
    //printf("arr[currentindex]->value = %d, currentindex = %d maxindex = %d \n", arr[currentindex]->value,currentindex,maxindex);
    printf("%d ", arr[currentindex]->value);
    if (arr[currentindex]->child != NULL)
    {
      node_t *temp = arr[currentindex]->child;
      do
      {
        arr[++maxindex] = temp;
        temp = temp->sibling;
      } while (temp != NULL);
    }
    currentindex++;
  }
  printf("\n");
}

void bfs(tree_t *t)
{
  descendant(t, t->value);
}

void dfs(tree_t *t)
{
  node_t *arr[MAXSIZE];
  int currentIndex = 0;
  arr[currentIndex] = t;
  while (arr[currentIndex] != NULL && currentIndex >= -1)
  {
    printf("%d ", arr[currentIndex]->value);
    if (arr[currentIndex]->child != NULL)
    {
      node_t *temp = arr[currentIndex]->child;
      node_t *temparr[MAXSIZE];
      //printf("H");
      int i = -1;
      do
      {
        temparr[++i] = temp;
        temp = temp->sibling;
      } while (temp != NULL);
      //printf("i = %d ",i);
      while (i >= 0)
      {
        //printf("temparr[i] = %d\n",temparr[i]);
        arr[currentIndex++] = temparr[i];
        i--;
      }
      //printf("H");
      currentIndex--;
    }
    else
    {
      currentIndex--;
    }
    //printf("currentIndex = %d\n",currentIndex);
  }
  printf("\n");
}

void print_tree(tree_t *t)
{
  node_t *arr[MAXSIZE];
  int currentIndex = 0;
  arr[currentIndex] = t;
  while (arr[currentIndex] != NULL && currentIndex >= -1)
  {
    for (int j = 0; j < depth(t, arr[currentIndex]->value); j++)
      printf(" ");
    printf("%d\n", arr[currentIndex]->value);
    if (arr[currentIndex]->child != NULL)
    {
      node_t *temp = arr[currentIndex]->child;
      node_t *temparr[MAXSIZE];
      //printf("H");
      int i = -1;
      do
      {
        temparr[++i] = temp;
        temp = temp->sibling;
      } while (temp != NULL);
      //printf("i = %d ",i);
      while (i >= 0)
      {
        //printf("temparr[i] = %d\n",temparr[i]);
        arr[currentIndex++] = temparr[i];
        i--;
      }
      //printf("H");
      currentIndex--;
    }
    else
    {
      currentIndex--;
    }
    //printf("currentIndex = %d\n",currentIndex);
  }
}
int main(void)
{
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &command);
    switch (command)
    {
    case 1:
      scanf("%d %d", &parent, &child);
      t = attach(t, parent, child);
      break;
    case 2:
      scanf("%d", &node);
      t = detach(t, node);
      break;
    case 3:
      scanf("%d", &node);
      printf("%d\n", search(t, node));
      break;
    case 4:
      scanf("%d", &node);
      printf("%d\n", degree(t, node));
      break;
    case 5:
      scanf("%d", &node);
      printf("%d\n", is_root(t, node));
      break;
    case 6:
      scanf("%d", &node);
      printf("%d\n", is_leaf(t, node));
      break;
    case 7:
      scanf("%d", &node);
      siblings(t, node);
      break;
    case 8:
      scanf("%d", &node);
      printf("%d\n", depth(t, node));
      break;
    case 9:
      scanf("%d %d", &start, &end);
      print_path(t, start, end);
      break;
    case 10:
      scanf("%d %d", &start, &end);
      printf("%d\n", path_length(t, start, end));
      break;
    case 11:
      scanf("%d", &node);
      ancestor(t, node);
      break;
    case 12:
      scanf("%d", &node);
      descendant(t, node);
      break;
    case 13:
      bfs(t);
      break;
    case 14:
      dfs(t);
      break;
    case 15:
      print_tree(t);
      break;
    }
  }
  return 0;
}
