#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t queue_t;

// Write your code here
// ...

int main(void) {
  queue_t *q = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;
    }
  }
  return 0;
}