#include<stdio.h>
#include<stdlib.h>

typedef struct stack* pstack;
struct  stack
{
    int top_index;
    int capacity;
    char *p_array;
};

pstack create_stack(int max_size);
int push(pstack pst, char ch);
int pop(pstack pst);
char top_of_stack(pstack pst);

int main()
{
    int count=0;
    char *str = "ax^2+bx+c=0";
    pstack pst1;
    pst1 = create_stack(100);
    printf("str = %s\n", str);

    for(count=0; str[count]!='\0'; count++)
    {
        if(str[count]=='x^2')
        {
            push(pst1,'x^2');
            printf("push is %s\n", pst1->p_array);
        }
        else if(str[count] == '+')
        {
            push(pst1, '+');
            printf("push is %s\n", pst1->p_array);
        }
        else if(str[count] == '=')
        {
            push(pst1, '=');
            printf("push is %s\n", pst1->p_array);
        }
    }

    if((str[count]!='x^2')&&(top_of_stack(pst1)!='='))
        {
            printf("Equation error\n");
        }
    else
        {
            printf("Equation Correct\n");
        }
}

pstack create_stack(int max_size)
{
    pstack pstnew;
    pstnew = (pstack)malloc(sizeof(struct stack));
    pstnew->capacity = max_size;
    pstnew->top_index = -1;
    pstnew->p_array = (char *)malloc(max_size);
    return pstnew;
}

int push(pstack pst, char ch)
{
    int push_index=0, can_add=-1;
    if(pst->capacity > pst->top_index+2)
    {
        push_index = pst->top_index+1;
        pst->p_array[push_index] = ch;
        pst->p_array[push_index+1] = '\0';
        pst->top_index++;
        can_add = push_index;
    }
    else
    {
        printf("array is full!!!\n");
    }
    return can_add;
}

int pop(pstack pst)
{
    int can_pop = -1;
    if(pst->top_index>=0)
    {
        pst->top_index--;
        pst->p_array[pst->top_index+1] = '\0';
        can_pop = pst->top_index;
    }
    return can_pop;
}

char top_of_stack(pstack pst)
{
    char top = '\0';
    if(pst->top_index>=0)
    {
        top = pst->p_array[pst->top_index];
    }
    return top;
}