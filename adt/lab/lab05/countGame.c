#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int maxdrink;
    int countdrink;
    int id;
    struct node *next;
    struct node *back;
} node_t;

int drink(node_t *currentNode, int count, int k);

void removeNode(node_t *previousNode, int length); //delete next node;
int count(node_t *node);
int checkdigit(int count, int k);

void show(node_t *startNode);
int main()
{
    int Nplayer, k, temp1;
    scanf("%d %d", &Nplayer, &k);
    node_t *startNode = (node_t *)malloc(sizeof(node_t));
    node_t *p1 = startNode;
    scanf("%d", &temp1);
    startNode->maxdrink = temp1;
    startNode->id = 1;
    startNode->countdrink = 0;
    for (int i = 0; i < Nplayer - 1; i++)
    {
        int numtemp;
        node_t *node = (node_t *)malloc(sizeof(node_t));
        scanf(" %d", &numtemp);
        node->id = i + 2;
        node->countdrink = 0;
        node->maxdrink = numtemp;
        p1->next = node;
        p1 = node;
    }
    p1->next = startNode;
    int count = 1, status = 1; //1 = รอด 0  =  ไม่รอด
    while (Nplayer > 1)
    {
        status = drink(startNode, count, k);                //p1 ตาม startnode
        //printf("%d :id = %d, drinkcount = %d, drinkmax = %d numberP = %d\n", count, startNode->id, startNode->countdrink, startNode->maxdrink, Nplayer);
        if (status == 1)
        {
            p1 = startNode;
            startNode = startNode->next;
        }
        else if (status == 0)
        {
            removeNode(p1, Nplayer);
            startNode = p1->next;
            Nplayer--;
        }
        count++;
    }
    //printf("startNode->id = %d",startNode->id);
    printf("%d\n", p1->id);
}

void removeNode(node_t *previousNode, int length)
{
    if (length == 2)
    {
        previousNode->next->next = NULL;
        previousNode->next = NULL;
        return;
    }
    node_t *p = previousNode->next;
    previousNode->next = p->next;
    p->next = NULL;
    return;
}

int drink(node_t *currentNode, int count, int k)
{
    if (count % k == 0 || checkdigit(count, k))
    {
        currentNode->countdrink += 1;
    }
    if (currentNode->countdrink > currentNode->maxdrink)
    {
        return 0;
    }
    return 1;
}

int checkdigit(int count, int k)
{
    while (count > 0)
    {
        if (count % 10 == k)
            return 1;
        count /= 10;
    }
    return 0;
}