#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
  int *data;
  int last_index;
} heap_t;

// Write your code here
// ...

int find_max(heap_t *heap);
void bfs(heap_t *heap);

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

heap_t *init_heap(int m)
{
  heap_t *tree = (heap_t *)malloc(sizeof(heap_t));
  tree->data = (int *)malloc(sizeof(int) * (m + 1));
  tree->last_index = 0;
  return tree;
}

void insert(heap_t *heap, int data)
{
  heap->last_index += 1;
  int index = heap->last_index;
  heap->data[index] = data;
  while (index / 2 > 0 && heap->data[index / 2] < data)
  {
    int temp = heap->data[index / 2];
    heap->data[index / 2] = data;
    heap->data[index] = temp;
    index /= 2;
  }
  return;
}

int delete_max(heap_t *heap)
{
  if (heap->last_index == 0)
    return -1;
  if (heap->last_index == 1)
  {
    heap->last_index = 0;
    return (heap->data[1]);
  }
  int max = heap->data[1];
  int i = 1;
  heap->data[1] = heap->data[heap->last_index];
  heap->last_index -= 1;
  while (i <= heap->last_index && ((2 * i + 1 <= heap->last_index && heap->data[i] < heap->data[2 * i + 1]) || (2 * i <= heap->last_index && heap->data[i] < heap->data[2 * i])))
  {
    if (heap->data[2 * i] < heap->data[2 * i + 1])
    {
      int temp = heap->data[2 * i + 1];
      heap->data[2 * i + 1] = heap->data[i];
      heap->data[i] = temp;
      i = 2 * i + 1;
    }
    else
    {
      int temp = heap->data[2 * i];
      heap->data[2 * i] = heap->data[i];
      heap->data[i] = temp;
      i = 2 * i;
    }
  }
  return max;
}

void update_key(heap_t *heap, int old_key, int new_key)
{
  if (heap->last_index == 0)
    return;
  int i;
  for (i = 1; i <= heap->last_index; i++)
  {
    if (heap->data[i] == old_key)
    {
      heap->data[i] = new_key;
      break;
    }
  }
  while ((i / 2 > 0 && heap->data[i] > heap->data[i / 2]) || ((2 * i + 1 <= heap->last_index && heap->data[i] < heap->data[2 * i + 1]) || (2 * i <= heap->last_index && heap->data[i] < heap->data[2 * i])))
  {
    //printf("i = %d, ",i);
    if (heap->data[i] > heap->data[i / 2])
    {
      int temp = heap->data[i / 2];
      heap->data[i / 2] = heap->data[i];
      heap->data[i] = temp;
      i /= 2;
      //bfs(heap);
    }
    else
    {
      if (heap->data[2 * i] < heap->data[2 * i + 1])
      {
        int temp = heap->data[2 * i + 1];
        heap->data[2 * i + 1] = heap->data[i];
        heap->data[i] = temp;
        i = 2 * i + 1;
       // bfs(heap);
      }
      else
      {
        int temp = heap->data[2 * i];
        heap->data[2 * i] = heap->data[i];
        heap->data[i] = temp;
        i = 2 * i;
       // bfs(heap);
      }
    }
  }
}
int find_max(heap_t *heap)
{
  if (heap->last_index == 0)
    return -1;
  return heap->data[1];
}

void bfs(heap_t *heap)
{
  for (int i = 1; i <= heap->last_index; i++)
  {
    printf("%d ", heap->data[i]);
  }
  printf("\n");
}

int main(void)
{
  heap_t *max_heap = NULL;
  int m, n, i;
  int command, data;
  int old_key, new_key;

  scanf("%d %d", &m, &n);
  max_heap = init_heap(m);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &command);
    switch (command)
    {
    case 1:
      scanf("%d", &data);
      insert(max_heap, data);
      break;
    case 2:
      delete_max(max_heap);
      break;
    case 3:
      printf("%d\n", find_max(max_heap));
      break;
    case 4:
      scanf("%d %d", &old_key, &new_key);
      update_key(max_heap, old_key,
                 new_key);
      break;
    case 5:
      bfs(max_heap);
      break;
    }
  }
  return 0;
}
