#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 1000000

typedef struct node
{
    char chr;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, char chr)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->chr = chr;
    node->next = NULL;
    if (s == NULL)
    {
        return node;
    }
    node->next = s;
    s = node;
    return s;
}

char pop(stack_t **s)
{
    if (*s == NULL)
    {
        return ' ';
    }
    char temp = (*s)->chr;
    *s = (*s)->next;
    return temp;
}

void show(stack_t *s)
{
    while (s != NULL)
    {
        printf("%c ", s->chr);
        s = s->next;
    }
    printf("\n");
}

int main(void)
{
    int i = 0, countx = 0, county = 0, status = 1;
    char chr, temp;
    stack_t *s = NULL;
    while ((chr = getchar()) != 'x' && chr != EOF)
    {
        s = push(s, chr);
        countx++;
    }
    //show(s);
    // printf("countx = %d\n",countx);
    //printf("getchar() = %c\n",getchar());
    while ((chr = getchar()) != 'y' && chr != EOF && countx > county && chr != '\n')
    {
        //printf("county = %d\n",county);
        temp = pop(&s);
        //printf("pop(s) = %c, chr = %c\n", temp, chr);
        if (temp != chr)
        {
            status = 0;
            break;
        }
        county++;
    }
    if(s != NULL)
        status = 0;
    printf("%d", status);
    return 0;
}
