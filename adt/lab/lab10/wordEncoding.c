#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    int frequency;
    char *string;
    struct node *left;
    struct node *right;
} node;

typedef struct heap
{
    node **data;
    int last_index;
} heap_t;

node *delete_min(heap_t *heap)
{
    if (heap->last_index == 0)
        return NULL;
    if (heap->last_index == 1)
    {
        heap->last_index = 0;
        return (heap->data[1]);
    }
    node *min = heap->data[1];
    int i = 1;
    heap->data[1] = heap->data[heap->last_index];
    heap->last_index -= 1;
    while (i <= heap->last_index && ((2 * i + 1 <= heap->last_index && heap->data[i]->frequency > heap->data[2 * i + 1]->frequency) || (2 * i <= heap->last_index && heap->data[i]->frequency  > heap->data[2 * i]->frequency)))
    {
        if (heap->data[2 * i]->frequency > heap->data[2 * i + 1]->frequency)
        {
            node *temp = heap->data[2 * i + 1];
            heap->data[2 * i + 1] = heap->data[i];
            heap->data[i] = temp;
            i = 2 * i + 1;
        }
        else
        {
            node *temp = heap->data[2 * i];
            heap->data[2 * i] = heap->data[i];
            heap->data[i] = temp;
            i = 2 * i;
        }
    }
    return min;
}

/*void insert(heap_t *heap, int frequency, char* string)
{
  heap->last_index += 1;
  int index = heap->last_index;
  node* newnode = (node*)malloc(sizeof(node));
  newnode->frequency = frequency;
  newnode->string = string;
  heap->data[index] = newnode;
  while (index / 2 > 0 && heap->data[index / 2]->frequency > heap->data[index]->frequency)
  {
    node* temp = heap->data[index / 2];
    heap->data[index / 2] = newnode;
    heap->data[index] = temp;
    index /= 2;
  }
  return;
}*/

void insert(heap_t *heap, node *newnode)
{
    heap->last_index += 1;
    int index = heap->last_index;
    heap->data[index] = newnode;
    while (index / 2 > 0 && heap->data[index / 2]->frequency > heap->data[index]->frequency)
    {
        node *temp = heap->data[index / 2];
        heap->data[index / 2] = newnode;
        heap->data[index] = temp;
        index /= 2;
    }
    return;
}

void print_bfs(heap_t *heap)
{
    for (int i = 1; i <= heap->last_index; i++)
    {
        printf("stirng = %s, frequency = %d\n", heap->data[i]->string, heap->data[i]->frequency);
    }
}

void print_inorder(node* newnode)
{
  if (newnode == NULL)
    return;
  print_inorder(newnode->left);
  printf("string = %s frequency = %d\n", newnode->string,newnode->frequency);
  print_inorder(newnode->right);
}

void printArr(int arr[],int index){
    for(int i = 0;i<index;i++)
        printf("%d",arr[i]);
    printf("\n");
}
void printCodes(node* tree,int arr[],int index){
    if(tree->left != NULL){
        arr[index] = 0;
        printCodes(tree->left,arr,index+1);
    }
    if(tree->right != NULL){
        arr[index] = 1;
        printCodes(tree->right,arr,index+1);
    }
    if(tree->string != NULL){
        printf("%s: ",tree->string);
        printArr(arr,index);
    }
}

int count(node* tree){
    if(tree == NULL){
        return 0;
    }
    else{
        return 1 + count(tree->left) + count(tree->right);
    }
}

int main()
{
    int words;
    scanf("%d", &words);
    heap_t *huff = (heap_t *)malloc(sizeof(heap_t));
    huff->data = (node **)malloc(sizeof(node *) * words);
    huff->last_index = 0;
    for (int i = 0; i < words; i++)
    {
        char *string = (char *)malloc(sizeof(char) * 15);
        int frequency;
        scanf("%s %d", string, &frequency);
        node *newnode = (node *)malloc(sizeof(node));
        newnode->frequency = frequency;
        newnode->string = string;
        newnode->right = NULL;
        newnode->left = NULL;
        insert(huff, newnode);
    }
    int round = 1;
    //print_bfs(huff);
    while(huff->last_index > 1){
        
        //printf("--------------------------------------\nround %d\n",round);
        round++;
        node* temp1 = delete_min(huff);
        //printf("delete 1\n");
        //print_bfs(huff);
        node* temp2 = delete_min(huff);
        //printf("delete 2\n");
        //print_bfs(huff);
        node* temp3 = (node*)malloc(sizeof(node));
        temp3->string = NULL;
        temp3->left = temp1;
        temp3->right = temp2;
        temp3->frequency = temp1->frequency + temp2->frequency;
        insert(huff,temp3);
        //printf("insert\n");
        //print_bfs(huff);
    }
    //printf("----------------------------------------------------\n");
    //print_inorder(huff->data[1]);
    int arr[15];
    printCodes(huff->data[1],arr,0);
}