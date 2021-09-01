#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#define MAXARR 100

#ifndef __bin_tree__
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif

// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
// ...

int size(tree_t *t)
{
    if (t == NULL)
        return 0;
    return size(t->left) + size(t->right) + 1;
}

int height(tree_t *t)
{
    if (t == NULL)
        return -1;
    int hl = height(t->left);
    int hr = height(t->right);
    return (hl > hr) ? hl + 1 : hr + 1;
}

int pows(int base, int power)
{
    int sum = 1;
    for (int i = 0; i < power; i++)
        sum *= base;
    return sum;
}

tree_t **treeToList(tree_t *t)
{
    int count = size(t) - 1;
    tree_t **arr = (tree_t **)malloc(sizeof(tree_t *) * MAXARR);
    int index = 0, max = 1;
    arr[0] = t;
    while (count > 0)
    {
        if (arr[index] != NULL)
        {
            //printf("index = %d arr[%d]->data = %d ",index,index, arr[index]->data);
            arr[max] = arr[index]->left;
            //printf("arr[%d] = %d ",max,arr[index+1]->data);
            arr[max + 1] = arr[index]->right;
            //printf("arr[%d] = %d\n",max+1,arr[index+2]->data);
            max += 2;
            index++;
        }
        else
        {
            index++;
        }
        count--;
    }
    return arr;
}

int is_full(tree_t *t) //check ทุกกรณี
{
    if (t == NULL)
        return 1;
    if (t->left == NULL && t->right == NULL) //ไม่มีลูก
        return 1;
    if (t->left != NULL && t->right != NULL)               //มีลูกสองข้าง
        return (is_full(t->right) + is_full(t->left)) / 2; // (1+1)/2 = 1 == full    1 + 0 || 0 + 1 || 0 + 0 /2 == not full
    return 0;
}

int is_perfect(tree_t *t)
{
    int check = pows(2, height(t) + 1) - 1;
    int sizes = size(t);
    if (check != sizes)
        return 0;
    return 1;
}

int is_complete(tree_t *t)
{
    tree_t **arr = treeToList(t);
    int count = size(t);
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == NULL)
            return 0;
    }
    return 1;
}

int is_degenerate(tree_t *t)
{
    if (t->left != NULL && t->right != NULL)
        return 0;
    else
        return 1;
    int pos = is_degenerate(t->left);
    if (pos == 0)
        return pos;
    else
        return is_degenerate(t->right);
}

int is_skewed(tree_t *t)
{
    if (t == NULL)
        return 0;

    tree_t **arr = treeToList(t);
    int nodes = size(t);
    int count = 0,i;
    if (t->right != NULL && t->left != NULL)
        return 0;
    if (t->right != NULL && t->left == NULL)
        i = 1;
    else if (t->left != NULL && t->right == NULL)
        i = 2;
    while (count + 1 <= nodes)
        {
            if (arr[i] != NULL)
                return 0;
            i += 2;
            count += 1;
        }
    return 1;
}

int main(void)
{
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }

    printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

    return 0;
}
