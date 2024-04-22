#include<stdio.h>

int f(int x, int y)
{
	int delta = x - y;

	if (y > delta)
		return 2 * ((y - delta) / 3) + delta;
	else
		return delta - 2 * ((delta - y) / 4);
}

void main()
{
	int result = f(2,4);
	printf("%d",result);
}