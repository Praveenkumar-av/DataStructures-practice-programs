// Program to convert infix to postfix, may have some bugs

#include<stdio.h>

void find(char *);
int precedence(char);
void push(char *,char,int *,int);
char pop(char *,int *);

void main()
{
	char exp[50];
	printf("Enter the expression :");
	scanf("%s",exp);
	find(exp);
}

void find(char *exp)
{
	int i=0, top=-1, prch, prst;
	char st[50], out, ch;
	while(exp[i] != '\0')
	{
		ch = exp[i];
		if((ch >= 'A' && ch <= 'z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
			printf("%c",ch);
	
		else
		{
			prch = precedence(ch);  // precedence of character in expression
			while(ch != '\0')
			{
				prst = precedence(st[top]);  // precedence of top of stack 
				if(ch == '(')
				{
					push(st,ch,&top,50);
					break;
				}
				else if(ch == ')')
				{
					while(st[top] != '(')
					{
						out = pop(st,&top);
						printf("%c",out);
					}
					pop(st,&top);
					break;
				}
				else if(prst >= prch)
				{
					out = pop(st,&top);
					printf("%c",out);
				}
				
				else if(prst < prch)
				{
					push(st,ch,&top,50);
					break;
				}
			}
		}
		i++;
	}
	while(top > -1)
	{
		out = pop(st,&top);
		printf("%c",out);
	}
}

int precedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
			
		default :
			return 0;
	}
}

void push(char *st,char ch,int *top,int n)
{
	if((*top) >= n-1)
	{
		printf("Stack full!");
	}
	else
	{
		(*top)++;
		st[*top] = ch;
	}
}

char pop(char *st,int *top)
{
	if((*top) == -1)
	{
		return '\0';
	}
	else
	{
		char ch = st[*top];
		(*top)--;
		return ch;
	}
}
