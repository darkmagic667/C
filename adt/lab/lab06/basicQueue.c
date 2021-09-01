#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t queue_t;

// Write your code here
// ...

queue_t* enqueue(queue_t *q,int num){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = num;
    node->next = q;
    return node;
}

queue_t* dequeue(queue_t *q){
    if(q == NULL){
        printf("Queue is empty.\n");
        return q;
    }else if(q->next == NULL){
        printf("%d\n",q->data);
        return NULL;
    }
    node_t *temp1 = q;
    node_t *temp2 = q->next;
    while(temp2->next != NULL){
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    printf("%d\n",temp2->data);
    temp1->next = NULL;
    return q;
}

/*void show(queue_t *q){
    if(q == NULL){
        printf("Queue is empty.\n");
        return;
    }
    while(q!= NULL){
        printf("%d ",q->data);
        q = q->next;
    }
    printf("\n");
}*/

void show(queue_t *q){
    if(q == NULL){
        printf("Queue is empty.\n");
        return;
    }
    if(q->next == NULL){
        printf("%d ",q->data);
        return;
    }
    show(q->next);
    printf("%d ",q->data);
}



void empty(queue_t *q){
    if(q == NULL)
        printf("Queue is empty.\n");
    else{
        printf("Queue is not empty.\n");
    }
}

void size(queue_t *q){
    int count = 0;
    while(q != NULL){
        q = q->next;
        count++;
    }
    printf("%d\n",count);
    return;
}

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