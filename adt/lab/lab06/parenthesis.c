#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char chr;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, char chr){
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

stack_t *pop(stack_t *s){
    if (s == NULL)
    {
        return s;
    }
    return s->next;
}

int compare(stack_t *s, char chr){
    if(s == NULL)
        return 0;
    if (s->chr == '(' && chr == ')')
    {
        return 1;
    }
    else if (s->chr == '{' && chr == '}')
    {
        return 1;
    }
    else if (s->chr == '[' && chr == ']')
    {
        return 1;
    }
    return 0;
}

int main(void){
    int n, status;

    scanf("%d", &n);
    char *str = (char *)malloc(sizeof(char) * n + 1);
    stack_t *s = NULL;
    scanf("%s", str);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s = push(s, str[i]);
        }
        else
        {
            status = compare(s, str[i]);
            s = pop(s);
            if (!status)
                break;
        }
    }
    if(s!= NULL){
        status = 0;
    }
    printf("%d", status);
}