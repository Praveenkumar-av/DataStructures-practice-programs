// A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
// Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [,
// or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type.
// There are three types of matched pairs of brackets: [], {}, and ().
// A matching pair of brackets is not balanced if the set of brackets it encloses are not
// matched. For example, {[(])} is not balanced because the contents in between { and
// } are not balanced. The pair of square brackets encloses a single, unbalanced opening
// bracket, (, and the pair of parentheses encloses a single, unbalanced closing square
// bracket, ].

#include<stdio.h>
 
char arr[50];
int top = -1, n = 50;

int matchingPair(char *);
void push(char);
char pop();

void main()
{
    char str[50];
    printf("Enter the brackets :");
    scanf("%s",&str);
    int result = matchingPair(str);
    if(result)
    {
        printf("Matching pair");
    }
    else 
    {
        printf("Not a matching pair");
    }
}

int matchingPair(char *str)
{
    char ch, temp;
    int matching = 1;
    for(int i=0;str[i] != '\0';i++)
    {
        ch = str[i];
        if(ch == '(')
        {
            push(ch);
        }
        else if(ch == '{')
        {
            push(ch);
        }
        else if(ch == '[')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            temp = pop();
            if(temp != '(')
                matching = 0;
        }
        else if(ch == '}')
        {
            temp = pop();
            if(temp != '{')
                matching = 0;
        }
        else if(ch == ']')
        {
            temp = pop();
            if(temp != '[')
                matching = 0;
        }
    }

    return matching;
}

void push(char ch)
{
    if(top >= n-1)
    {
        printf("Stack full");
    }
    else
    {
        top++;
        arr[top] = ch;
    }
}

char pop()
{
    if(top == -1)
    {
        return '\0';
    }
    else 
    {
        char ch = arr[top];
        top--;
        return ch;
    }
}