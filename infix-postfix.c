#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[50], postfix[50], ch;
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    strcat(infix, ")");
    push('(');

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(ch == '(')
            push(ch);

        else if(isalnum(ch))
            postfix[j++] = ch;

        else if(ch == ')')
        {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }

        else
        {
            while(stack[top] != '(' &&
                  priority(stack[top]) >= priority(ch))
                postfix[j++] = pop();

            push(ch);
        }
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}