#include <stdio.h>
#include <stdlib.h>
#include <week9.h>
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t bst_t;

// Write your code here
// ...
bst_t* findBefore(bst_t *t,int data);
int find_min(bst_t *t);
void print_inorder(bst_t *t)
{
  if (t == NULL)
    return;
  print_inorder(t->left);
  printf("%d ", t->data);
  print_inorder(t->right);
}

bst_t *insert(bst_t* t,int data){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    if(t == NULL){
        t = node;
        return t;
    }
    node_t* temp = t;
    while(1){
        if(temp == NULL){
            printf("NULL\n");
        temp = node;
        break;
    }
    //printf("temp->data = %d\n",t->data);
        if(temp->data > data){
            if(temp->left == NULL){
                temp->left = node;
                break;
            }
            temp = temp->left;
        }else if(temp->data < data){
            if(temp->right == NULL){
                temp->right = node;
                break;
            }
            temp = temp->right;
    }
    }
    return t;
}

bst_t *delete(bst_t *t,int data){
    node_t *parent = findBefore(t,data);
    node_t *son;
    char s;
    if(t == NULL)
        return t;
    if(parent == NULL)
        son = t;
    else if(parent->left != NULL && parent->left->data == data){
        son = parent->left;
        s = 'l';
    }else{
        son = parent->right;
        s = 'r';
    }
    if(son->left == NULL && son->right == NULL){ //case 1
        //printf("Case 1\n");
        if(s == 'l')
            parent->left = NULL;
        else if(s == 'r')
            parent->right = NULL;
        return t;
    }else if(son->left != NULL && son->right == NULL){ //case 2.1
        //printf("case 2.1\n");
        if(s == 'l')
            parent->left = son->left;
        else if(s == 'r')
            parent->right = son->left;
        return t;
    }else if(son->right != NULL && son->left == NULL){ //case 2.2
        //printf("case 2.2\n");
        if(s == 'l')
             parent->left = son->right;
        else if(s == 'r')
            parent->right = son->right;
        return t;
    }else{ //case 3
       // printf("case3\n");
        int inttemp = find_min(son->right);
        delete(son,inttemp);
        son->data = inttemp;
        return t;
    }
}


bst_t* findBefore(bst_t *t,int data){
    if(t == NULL)
        return t;
    if(t->left != NULL && t->left->data == data)
        return t;
    else if(t->right != NULL && t->right->data == data)
        return t;
    if(t->data > data)
        return findBefore(t->left,data);
    else if(t->data < data)
        return findBefore(t->right,data);
    else
        return NULL;
}

int find(bst_t *t, int data){
    if(t == NULL)
        return 0;
    //printf("t->data = %d\n",t->data);
    if(t->data == data)
        return 1;
    if(t->data > data)
        return find(t->left,data);
    else if(t->data < data)
        return find(t->right,data);
}
int find_min(bst_t *t){
    if(t == NULL)
        return -1;
    while(t->left != NULL)
        t = t->left;
    return t->data;
}

int find_max(bst_t* t){
    if(t == NULL)
        return -1;
    while(t->right != NULL)
        t = t->right;
    return t->data;
}

int main(void){
  bst_t *t = NULL;
  int   n, i;
  int   command, data;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        t = insert(t, data);
        break;
      case 2:
        scanf("%d", &data);
        t = delete(t, data);
        break;
      case 3:
        scanf("%d", &data);
        printf("%d\n",find(t, data));
        break;
      case 4:
        printf("%d\n", find_min(t));
        break;
      case 5:
        printf("%d\n", find_max(t));
        break;
       case 6:
        print_inorder(t);
        break;
    }
  }
  return 0;
}
