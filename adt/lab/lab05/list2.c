#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 10
typedef struct node
{
    int type;
    int dataint;
    float datafloat;
    char str[MAXSTR + 1];
    struct node *next;
} node_t;

node_t *append(node_t *startNode)
{
    int type, n1;
    float n2;
    char str[11];
    scanf(" %d", &type);
    if (type == 0)
    {
        scanf(" %d", &n1);
    }
    else if (type == 1)
    {
        float n;
        scanf(" %f", &n2);
    }
    else if (type == 2)
    {
        scanf(" %s", str);
        //printf("Read %s ", str);
    }
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (type == 0)
    {
        node->dataint = n1;
        node->type = 0;
    }
    else if (type == 1)
    {
        node->datafloat = n2;
        node->type = 1;
    }
    else if (type == 2)
    {
        strcpy(node->str, str);
        node->type = 2;
    }
    if (startNode == NULL)
    {
        node->next = NULL;
        return node;
    }
    node_t *temp = startNode;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->next = NULL;
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
    if (startNode->type == 0)
        printf("%d\n", startNode->dataint);
    else if (startNode->type == 1)
        printf("%f\n", startNode->datafloat);
    else if (startNode->type == 2)
        printf("%s\n", startNode->str);
}

void show(node_t *startNode)
{
    while (startNode != NULL)
    {
        //printf("type = %d, " ,startNode->type);
        if (startNode->type == 0)
            printf("%d ", startNode->dataint);
        else if (startNode->type == 1)
            printf("%f ", startNode->datafloat);
        else if (startNode->type == 2)
            printf("%s ", startNode->str);
        startNode = startNode->next;
    }
    printf("\n");
}

node_t *reverse(node_t *startNode)
{
    if (startNode->next == NULL || startNode == NULL)
        return startNode;
    node_t *p1 = startNode->next;
    node_t *p2 = p1->next;
    startNode->next = NULL;
    while (p1 != NULL)
    {
        p1->next = startNode;
        startNode = p1;
        p1 = p2;
        if (p2 != NULL)
            p2 = p2->next;
    }
    return startNode;
}

node_t *show_reverse(node_t *startNode)
{
    startNode = reverse(startNode);
    show(startNode);
    startNode = reverse(startNode);
    return startNode;
}

void insert(node_t *startNode){
    int type, dataint, index;
    float datafloat;
    char str[MAXSTR + 1];

    scanf(" %d %d", &index, &type);
    node_t *temp = startNode;
    node_t *node = (node_t *)malloc(sizeof(node_t));
    while (index > 0)
    { //error if
        temp = temp->next;
        index--;
    }
    if (type == 0)
    {
        scanf(" %d", &dataint);
        node->dataint = dataint;
        node->type = 0;
    }
    else if (type == 1)
    {
        scanf(" %f", &datafloat);
        node->type = 1;
        node->datafloat = datafloat;
    }
    else if (type == 2)
    {
        scanf(" %s", str);
        node->type = 2;
        strcpy(node->str, str);
    }
    node->next = temp->next;
    temp->next = node;
}

node_t *delete (node_t *startNode)
{
    int index;
    scanf(" %d", &index);
    node_t *p1 = startNode;
    if(index == 0){
        startNode = startNode->next;
        p1->next = NULL;
        return startNode;
    }
    while (index-1 > 0)
    {
        p1 = p1->next;
        index--;
    }
    node_t*p2 = p1->next;
    p1->next = p2->next;
    p2->next = NULL;
    return startNode;
}

void change(node_t *startNode)
{
    int index, type, dataint;
    float datafloat;
    char str[MAXSTR + 1];
    scanf(" %d %d", &index, &type);
    while (index > 0)
    {
        startNode = startNode->next;
        index--;
    }
    if (type == 0)
    {
        scanf(" %d", &dataint);
        startNode->dataint = dataint;
        startNode->type = 0;
    }
    else if (type == 1)
    {
        scanf(" %f", &datafloat);
        startNode->datafloat = datafloat;
        startNode->type = 1;
    }
    else if (type == 2)
    {
        scanf(" %s", str);
        strcpy(startNode->str, str);
        startNode->type = 2;
    }
}

void is_empty(node_t *startNode){
    if(startNode == NULL)
        printf("Empty\n");
    else
        printf("Not Empty\n");
}
void length(node_t *startNode){
    int count = 0;
    while(startNode != NULL){
        count++;
        startNode = startNode->next;
    }
    printf("%d\n",count);
}

node_t *cut(node_t *startNode)
{
    int start, stop;
    scanf(" %d %d", &start, &stop);
    stop -= start;
    while (start > 0)           //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    {
        startNode = startNode->next;
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
            startNode = show_reverse(startNode);
            break;
        case 'I':
            insert(startNode);
            break;
        case 'D':
            startNode = delete (startNode);
            break;
        case 'C':
            change(startNode);
            break;
        case 'E':
            is_empty(startNode);
            break;
        case 'L':
            length(startNode);
        default:
            break;
        }
    }
    return 0;
}
