#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *append(node_t *startNode)
{
    int n;
    //printf("startNode = %d\n", startNode);
    scanf(" %d", &n);
    if (startNode == NULL)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->data = n;
        node->next = NULL;
        return node;
    }
    //printf("H");
    node_t *temp = startNode;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    temp->next = newnode;
    newnode->data = n;
    newnode->next = NULL;
    return startNode;
}

void get(node_t *startNode)
{
    int index;
    scanf(" %d", &index);
    while (index > 0)
    {
        startNode = startNode->next;
        index--;
    }
    printf("%d\n", startNode->data);
}

node_t *reverse(node_t *startNode)
{
    if (startNode->next == NULL || startNode == NULL)
        return startNode;
    node_t *p1 = startNode->next;
    //printf("H\n");
    node_t *p2 = p1->next;
    //printf("H\n");
    startNode->next = NULL;
    //printf("H\n");
    while (p1 != NULL)
    {
        //printf("p1->data = %d p2->data = %d\n",p1->data,p2->data);
        //printf("a");
        p1->next = startNode;
        //printf("b");
        startNode = p1;
        p1 = p2;
        if (p2 != NULL)
            p2 = p2->next;
        //printf("e");
    }
    //printf("out");
    return startNode;
}

node_t *cut(node_t *startNode)
{
    int start, stop;
    //printf("S");
    scanf(" %d %d", &start, &stop);
    stop -= start;
    //printf("Start = %d stop = %d\n", start, stop);
    while (start > 0)
    {
        startNode = startNode->next;
        //printf("startnode = %d\n",startNode->data);
        start--;
    }
    node_t *temp = startNode;
    while (stop > 0)
    {
        temp = temp->next;
        stop--;
    }
    temp->next = NULL;
    return startNode;
}

void show(node_t *startNode)
{
    while (startNode != NULL)
    {
        printf("%d ", startNode->data);
        startNode = startNode->next;
    }
    printf("\n");
}

int main(void)
{
    node_t *startNode;
    int n, i;
    char command;

    startNode = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &command);
        //printf("%d",sizeof(command));
        switch (command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        default:
            break;
        }
    }
    return 0;
}
