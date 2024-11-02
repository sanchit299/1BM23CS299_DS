#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
char stack[MAX];
int top = -1;
int main()
{

    char exp[MAX];
    int valid;
    printf("enter an algebraic expression:");
    gets(exp);
    valid = check(exp);
    if (valid == 1)
    {
        printf("VALID EXPRESSION\n");
    }
    else{
        printf("invalid expression\n");
    }
    return 0;
}

int check(char exp[])
{
    int i;
    char temp;
    for ( i = 0; i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            {
                push(exp);
            }
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == -1)
            {
                printf("right parenthesis is more than left");
            }
            else
            {
                temp = pop();
                if(!match(temp,exp[i]))
                {
                    printf("mismatched parenthesis are :");
                    printf("%c and %c",temp,exp[i]);
                    return 0;
                }
            }
        }
    }
    if(top == -1)
    {
        printf("balanced parenthesis\n");
        return 1;
    }
    else
    {
        printf("left parenthesis are more than right parenthesis \n");
        return 0;
    }
}

void match(char a , char b)
{
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        {
            return 1;
        }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}

void push(char item)
{
    if(top == (MAX -1))
    {
        printf("stack overflow");
        return;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        top--;
    }
}
