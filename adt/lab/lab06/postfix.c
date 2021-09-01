#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    float data;
    struct node *next;
}node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s,float value){
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->data = value;
    node->next = s;
    s = node;
    return node;
}

float pop(stack_t **s){
    float num = (*s)->data;
    (*s) = (*s)->next;
    return num;
}

int main(void){
    int n;
    char chr;
    stack_t *s = NULL;
    scanf("%d",&n);
    getchar();
    for(int i = 0;i<n;i++){
        chr = getchar();
        float value1,value2;
        if(chr >= '0' && chr<='9'){
            s = push(s,chr - '0');
        }else{
            value2 = pop(&s);
            value1 = pop(&s);
            //printf("value1 = %f value2 = %f\n",value1,value2);
            if(chr == '+')
                s = push(s,value1 + value2);
            else if(chr == '-')
                s = push(s,value1 - value2);
            else if(chr == '*')
                s = push(s,value1 * value2);
            else if(chr == '/')
                s = push(s,value1 / value2);
        }
    }
    printf("%.2f",pop(&s));
}
